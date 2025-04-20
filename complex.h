#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h> /* for atof */

/* Structure to represent a complex number */
typedef struct {
    double real;      /* Real part of the complex number */
    double imaginary; /* Imaginary part of the complex number */
} complex;

/* Enumeration for command names */
enum names {
    READ_COMP,
    PRINT_COMP,
    ADD_COMP,
    SUB_COMP,
    MULT_COMP_REAL,
    MULT_COMP_IMG,
    MULT_COMP_COMP,
    ABS_COMP,
    STOP
};

/*-------------------------------------------------------------------------*/

/* Function to read a complex number from real and imaginary parts */
void read_comp(complex *, double, double);

/* Function to print a complex number */
void print_comp(complex *);

/* Function to add two complex numbers */
void add_comp(complex *, complex *);

/* Function to subtract two complex numbers */
void sub_comp(complex *, complex *);

/* Function to multiply a complex number by a real number */
void mult_comp_real(complex *, double);

/* Function to multiply a complex number by an imaginary number */
void mult_comp_img(complex *, double);

/* Function to multiply two complex numbers */
void mult_comp_comp(complex *, complex *);

/* Function to compute the absolute value of a complex number */
void abs_comp(complex *);

/*-------------------------------------------------------------------------*/

/* Function to process a line of input and execute the corresponding command */
void executeCommandFromLine(char line[]);

/* Function to check if a line is blank and print a message if it is */
void checkForBlankLine(char *p);

/* Function to check if a character represents a complex variable */
int isComplexVariable(char x);

/* Function to check if the command name is valid */
int getCommandIndex(char *temp);

/* Function to remove spaces from a string */
void removeSpaces(char *str);

/* Function to skip spaces and tabs in a string */
char *skipLeadingSpaces(char *s);

/* Function to stop the program and print a goodbye message */
void terminateProgram();

/* Function to get a pointer to the complex variable based on its character */
complex *getComplexVariable(char x);

/* Function to skip over a number in a string and return the pointer to the next character */
char *skipNumber(char *s);

