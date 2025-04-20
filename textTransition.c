#include "complex.h"
#define NUM_FUNCTIONS 9

/* External complex variables */
extern complex A, B, C, D, E, F;

/* Command names for functions */
char *commandNames[NUM_FUNCTIONS] = {"read_comp", "print_comp", "add_comp", "sub_comp", "mult_comp_real",
                                       "mult_comp_img", "mult_comp_comp", "abs_comp", "stop"};

/* Function to process a line of input and execute the corresponding command */
void executeCommandFromLine(char inputLine[]) {
        int commandLength = 0;
        int commandIndex;
        char *currentPointer;
        char *secondNumberPointer;

        currentPointer = inputLine;
        currentPointer = skipLeadingSpaces(currentPointer); /* Skip leading spaces and tabs */

        if (currentPointer[0] == '\n') { /* Check if the line is only whitespace */
                printf("(blank line)\n");
                return;
        }

	commandIndex = getCommandIndex(currentPointer); /* Check if the command is valid */

        if (commandIndex == -1) {
                printf("Undefined command name\n");
                return;
        }

        commandLength = strlen(commandNames[commandIndex]);
        currentPointer += commandLength; /* Move pointer past the command name */

        removeSpaces(currentPointer); /* Remove spaces from the command */

        if (currentPointer[0] == ',') {
                printf("Illegal comma\n");
                return;
        }

        if (commandIndex == STOP) { /* Handle stop command */
                if (currentPointer[0]) {
                        printf("Extraneous text after end of command\n");
                        return;
                }
                terminateProgram(); /* Stop the program */
        }

        if (!currentPointer[0]) {
                printf("Missing parameter\n");
                return;
        }

        if (!isComplexVariable(currentPointer[0])) {
                printf("Undefined complex variable\n");
                return;
        }

        if (commandIndex == ABS_COMP) { /* Need only one complex name */
                if (currentPointer[1]) {
                        printf("Extraneous text after end of command\n");
                        return;
                }
                abs_comp(getComplexVariable(currentPointer[0]));
                return;
        }

        if (commandIndex == PRINT_COMP) { /* Need only one complex name */
                if (currentPointer[1]) {
                        printf("Extraneous text after end of command\n");
                        return;
                }
                print_comp(getComplexVariable(currentPointer[0]));
                return;
        }

        if (currentPointer[1] != ',') {
                printf("Missing comma\n");
                return;
        }

        if (commandIndex == ADD_COMP || commandIndex == SUB_COMP || commandIndex == MULT_COMP_COMP) { /* Need 2 complex names */
                if (!isComplexVariable(currentPointer[2])) { /* Validate second complex variable */
                        if (!currentPointer[2]) {
                                printf("Missing parameter\n");
                                return;
                        }
                        if (currentPointer[2] == ',') {
                                printf("Multiple consecutive commas\n");
                                return;
                        }
                        printf("Undefined complex variable\n");
                        return;
                }

                if (currentPointer[3]) {
                        printf("Extraneous text after end of command\n");
                        return;
                }

                /* Perform the corresponding operation */
                if (commandIndex == ADD_COMP)
                        add_comp(getComplexVariable(currentPointer[0]), getComplexVariable(currentPointer[2]));
                else if (commandIndex == SUB_COMP)
                        sub_comp(getComplexVariable(currentPointer[0]), getComplexVariable(currentPointer[2]));
                else
                        mult_comp_comp(getComplexVariable(currentPointer[0]), getComplexVariable(currentPointer[2]));

                return;
        }

        if (!isdigit(currentPointer[2])) { /* Validate numeric parameter */
                if (!currentPointer[2]) {
                        printf("Missing parameter\n");
                        return;
                }
                if (currentPointer[2] == ',') {
                        printf("Multiple consecutive commas\n");
                        return;
                }
                if (currentPointer[2] != '-' || !isdigit(currentPointer[3])) { /* Check for negative number */
                        printf("Invalid parameter - not a number\n");
                        return;
                }
        }

        if (commandIndex == READ_COMP) { /* Handle read_comp command */
                secondNumberPointer = skipNumber(currentPointer + 2);

                if (*secondNumberPointer != ',') {
                        printf("Missing comma\n");
                        return;
                }
                secondNumberPointer += 1; /* Move to the first digit of the number */

                if (!isdigit(secondNumberPointer[0])) { /* Validate the numeric parameter */
                        if (!secondNumberPointer[0]) {
                                printf("Missing parameter\n");
                                return;
                        }
                        if (secondNumberPointer[0] == ',') {
                                printf("Multiple consecutive commas\n");
                                return;
                        }
                        if (secondNumberPointer[0] != '-' || !isdigit(secondNumberPointer[1])) { /* Check for negative number */
                                printf("Invalid parameter - not a number\n");
                                return;
                        }
                }

                if (*skipNumber(secondNumberPointer)) {
                        printf("Extraneous text after end of command\n");
                        return;
                } /* Check for extraneous text after the second number */

                /* Read the complex number */
                read_comp(getComplexVariable(currentPointer[0]), atof(currentPointer + 2), atof(secondNumberPointer));
                return;
        }

        if (*skipNumber(currentPointer + 2)) {
                printf("Extraneous text after end of command\n");
                return;
        }

        /* Perform multiplication based on the command */
        if (commandIndex == MULT_COMP_REAL)
                mult_comp_real(getComplexVariable(currentPointer[0]), atof(currentPointer + 2));
        else /* commandIndex = MULT_COMP_IMG */
                mult_comp_img(getComplexVariable(currentPointer[0]), atof(currentPointer + 2));
}

/* Function to check for blank lines */
void checkForBlankLine(char *p) {
        if (p[0] == '\n') { /* Check if the line is only whitespace */
                printf("(blank line)\n");
        }
}

/* Function to check if a character represents a complex variable */
int isComplexVariable(char x) {
        switch (x) {
                case 'A':
                case 'B':
                case 'C':
                case 'D':
                case 'E':
                case 'F':
                        return 1; 
                default:
                        return 0; 
        }
}

/* Function to validate the command name */
int getCommandIndex(char *temp) {
        int i;
        int count = 0;

        for (i = 0; temp[i] && temp[i] != ' ' && temp[i] != '\t' && temp[i] != ',' && temp[i] != '\n'; i++) {
                count++; /* Count the characters in the command name */
        }

        for (i = 0; i < NUM_FUNCTIONS; i++) { /* Compare the command name with known functions */
                if (strlen(commandNames[i]) == count && !strncmp(commandNames[i], temp, count)) /* Equals */
                        return i;
        }
        return -1; /* Invalid command name */
}

/* Function to remove spaces from a string */
void removeSpaces(char *str) {
        char *src = str; /* Pointer to source */
        char *dst = str; /* Pointer to destination */

        while (*src) {
                if (*src != ' ' && *src != '\t' && *src != '\n') {
                        *dst++ = *src; /* Move character to destination */
                }
                src++; /* Advance to next character in source */
        }

        *dst = '\0'; /* End the string */
}

/* Function to skip spaces and tabs in a string */
char *skipLeadingSpaces(char *s) { 
        int count = 0;
        while (s[count] != 0 && (s[count] == ' ' || s[count] == '\t')) {
                count++;
        }
        return s + count; /* Return pointer to the first non-space character */
}

/* Function to stop the program and print a goodbye message */
void terminateProgram() {
        printf("The operation was successful, and the program is terminating as requested."); 
        exit(0);
}

/* Function to get a pointer to the complex variable based on its character */
complex *getComplexVariable(char x) {
        switch (x) {
                case 'A':
                        return &A;
                case 'B':
                        return &B;
                case 'C':
                        return &C;
                case 'D':
                        return &D;
                case 'E':
                        return &E;
                case 'F':
                        return &F;
                default:
                        return NULL; 
        }
}

/* Function to skip a numeric value in a string */
char *skipNumber(char *s) {
        int hadDot = 0;

        if (*s == '-') {
                s++;
        }

        while (isdigit(*s) || *s == '.') {
                if (*s == '.') {
                        if (hadDot || !isdigit(*(s + 1))) { 
                                return s;
                        }
                        hadDot = 1; 
                }
                s++; /* Advance to the next character */
        }

        return s; /* Return a pointer to the character after the number */
}

