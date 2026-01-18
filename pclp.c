#include <stdio.h>
#include <stdlib.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <conio.h> 

double sin_taylor(double x, int n_terms) {
    double sum = 0.0;
    double term = x;
    
    for (int i = 0; i < n_terms; i++) {
        sum += term;
        term = term * (-x * x) / ((2 * i + 2) * (2 * i + 3));
    }
    return sum;
}

int main() {
    double angle, rad;
    char option;

    do {
        printf("\n--- Sine Calculation (Taylor Series) ---");
        printf("\nEnter the angle in degrees: ");
        
        if (scanf("%lf", &angle) != 1) {
            printf("Invalid input! Exiting...\n");
            exit(1);
        }

        rad = angle * (M_PI / 180.0);

        printf("\n1. Taylor Series (10 terms): %.10f", sin_taylor(rad, 10));
        printf("\n2. Standard math.h sin():     %.10f", sin(rad));
        printf("\n3. Absolute Error:            %.10e\n", fabs(sin_taylor(rad, 10) - sin(rad)));

        printf("\nWould you like to continue? (n/N to Exit, any other key to continue): ");
        scanf(" %c", &option);

        if (option == 'n' || option == 'N') {
            break;
        }

    } while (1);

    printf("\nProgram finished. Press any key to close...");
    getch();
    return 0;
}