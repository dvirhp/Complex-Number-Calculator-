#include "complex.h"
#define LINE_LEN 100

/* Global complex variables */
complex A, B, C, D, E, F;
char line[LINE_LEN];

/* Function to get a line of input from the user */
void get_line(char line[]) {
        printf("\nPlease enter a command:\n"); /* User prompt */
        
        /* Reading a line from the user */
        if (scanf("%[^\n]", line) != 1) {
                printf("\nReached EOF before the stop command\n");
                exit(0);
        }

        /* Clear the input buffer: discard the newline character */
        while (getchar() != '\n'); 

        /* Print the line the user entered */
        printf("You entered the line:\n");
        printf("%s\n", line);
}

/* Main function */
int main() {
        /* Initialize all complex variables to zero */
        memset(&A, 0, sizeof(A));
        memset(&B, 0, sizeof(B));
        memset(&C, 0, sizeof(C));
        memset(&D, 0, sizeof(D));
        memset(&E, 0, sizeof(E));
        memset(&F, 0, sizeof(F));

        /* Main loop to continuously get user input */
        while (1) {
                get_line(line);        /* Get a line of input */
                executeCommandFromLine(line);  /* Process the input line */
        }
        
        return 0;
}

