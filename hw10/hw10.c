#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// define the signature of the pointer
typedef double (*F)(double, int); 

// define a power function
double power(double x, int n){ 
    return pow(x, n); // raise x to the power of n (x^n)
}

// define a multiplication function
double multiply(double x, int n){ 
    return x*n; // return a multiplication value between x and n in double form
}

/*define a function that divides x by n which the return value is still 
in double format*/
double divide(double x, int n){ 
    return x/n; // return a value which is x divided by n
}

/* a function that used the one of the functions above then 
raise it to the power of m*/
double powerpower(F func, double x, int n, int m){ 
    return power(func(x, n), m);   
}

int main(int argc, char *argv[]){ // for example the command: ./hw10 3 4 5

    // Parse command line arguments
    double x = atof(argv[1]); // turning the string x or "3" in this case into a floating point 3.000000
    int n = atoi(argv[2]); // turning the string n or "4" in this case into an integer 4
    int m = atoi(argv[3]); // turning the string "5" into an integer 5

    // define function pointers
    F powerfunc = power; // powerfunc points to power function
    F divfunc = divide; // divfunc points to divide function
    F multiplyfunc = multiply; //multiplyfunc points to multiply function

    // print the output
    printf("((%lf)^%d)^%d = %lf\n", x, n, m, powerpower(powerfunc, x, n, m)); // print ((3.000000)^4)^5 = 3486784401.000000 
        if(n!=0){ // check whether divisior is zero
            printf("(%lf/%d)^%d = %lf\n", x, n, m, powerpower(divfunc, x, n, m)); // print (3.000000/4)^5 =0.237305
        } else {
            printf("Error! Divisor can't be zero\n"); // divisior of a division can't be zero
        } 
    printf("(%lf*%d)^%d = %lf\n", x, n, m, powerpower(multiplyfunc, x, n, m)); // print (3.000000*4)^5 = 248832.000000
    return 0;
}