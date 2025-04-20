#include "complex.h"

/* 
 Function to read a complex number from its real and imaginary parts
 */
void read_comp(complex *temp, double real1, double imag1) {
        (*temp).real = real1;        /* Assign the real part */
        (*temp).imaginary = imag1;   /* Assign the imaginary part */
}

/* 
  Function to print a complex number 
 */
void print_comp(complex *temp) {
        if ((*temp).imaginary < 0)
                printf("The complex number is: %3.2f - (%3.2f)i", (*temp).real, -(*temp).imaginary);
        else
                printf("The complex number is: %3.2f + (%3.2f)i", (*temp).real, (*temp).imaginary);
}

/*
  Function to add two complex numbers and print the result 
 */
void add_comp(complex *a_temp, complex *b_temp) {
        complex temp; /* Temporary variable to hold the result */
        temp.real = (*a_temp).real + (*b_temp).real;                /* Add real parts */
        temp.imaginary = (*a_temp).imaginary + (*b_temp).imaginary; /* Add imaginary parts */
        print_comp(&temp); /* Print the result */
}

/* 
  Function to subtract two complex numbers and print the result 
 */
void sub_comp(complex *a_temp, complex *b_temp) {
        complex temp; /* Temporary variable to hold the result */
        temp.real = (*a_temp).real - (*b_temp).real;                /* Subtract real parts */
        temp.imaginary = (*a_temp).imaginary - (*b_temp).imaginary; /* Subtract imaginary parts */
        print_comp(&temp); /* Print the result */
}

/* 
  Function to multiply a complex number by a real number and print the result 
 */
void mult_comp_real(complex *a_temp, double temp_num) {
        complex temp; /* Temporary variable to hold the result */
        temp.real = (*a_temp).real * temp_num;                /* Multiply real part */
        temp.imaginary = (*a_temp).imaginary * temp_num;      /* Multiply imaginary part */
        print_comp(&temp); /* Print the result */
}

/* 
  Function to multiply a complex number by an imaginary number and print the result 
 */
void mult_comp_img(complex *a_temp, double temp_imaginary) {
        complex temp; /* Temporary variable to hold the result */
        temp.real = ((*a_temp).imaginary) * (-temp_imaginary); /* Calculate the real part */
        temp.imaginary = (*a_temp).real * temp_imaginary;      /* Calculate the imaginary part */
        print_comp(&temp); /* Print the result */
}

/* 
  Function to multiply two complex numbers and print the result 
 */
void mult_comp_comp(complex *a_temp, complex *b_temp) {
        complex temp; /* Temporary variable to hold the result */
        temp.real = ((*a_temp).real * (*b_temp).real) - ((*a_temp).imaginary * (*b_temp).imaginary); /* Calculate real part */
        temp.imaginary = ((*a_temp).real * (*b_temp).imaginary) + ((*a_temp).imaginary * (*b_temp).real); /* Calculate imaginary part */
        print_comp(&temp); /* Print the result */
}

/* 
  Function to compute and print the absolute value of a complex number 
 */
void abs_comp(complex *a_temp) {
        printf("%f\n", sqrt(((*a_temp).real) * ((*a_temp).real) + ((*a_temp).imaginary) * ((*a_temp).imaginary))); /* Calculate absolute value */
}

