#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double f, x, error;
    char option;

    do {
        printf("Enter number of terms (f) and exponent (x): ");
        if (scanf("%lf %lf", &f, &x) != 2) {
            printf("Error: Invalid input data!\n");
            break;
        }

        double e_taylor = 1.0;
        double current_term = 1.0;
        int n_terms = (int)fabs(f);

        for (int i = 1; i < n_terms; i++) {
            current_term = current_term * x / i;
            e_taylor += current_term;
        }

        error = fabs(e_taylor - exp(x));

        printf("Taylor: %g | exp(x): %g\n", e_taylor, exp(x));
        printf("Absolute Error: %g\n", error);

        printf("Continue? (Y/N): ");
        scanf(" %c", &option);

    } while (option != 'n' && option != 'N');

    return 0;
}