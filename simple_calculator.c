#include <stdio.h>

int main(void) {
    char operator;
    double num1, num2, result;

    printf("Simple Calculator\n");
    printf("Enter operator (+, -, *, /, %%): ");
    if (scanf(" %c", &operator) != 1) {
        printf("Error: Failed to read operator.\n");
        return 1;
    }

    printf("Enter two numbers: ");
    if (scanf("%lf %lf", &num1, &num2) != 2) {
        printf("Error: Please enter two valid numbers.\n");
        return 1;
    }

    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("%.2f + %.2f = %.2f\n", num1, num2, result);
            break;

        case '-':
            result = num1 - num2;
            printf("%.2f - %.2f = %.2f\n", num1, num2, result);
            break;

        case '*':
            result = num1 * num2;
            printf("%.2f * %.2f = %.2f\n", num1, num2, result);
            break;

        case '/':
            if (num2 == 0.0) {
                printf("Error: Division by zero is not allowed.\n");
            } else {
                result = num1 / num2;
                printf("%.2f / %.2f = %.2f\n", num1, num2, result);
            }
            break;

        case '%':
            /* Modulus is defined for integers in C. */
            if (num1 != (int)num1 || num2 != (int)num2) {
                printf("Error: Modulus requires whole-number operands.\n");
            } else if ((int)num2 == 0) {
                printf("Error: Modulus by zero is not allowed.\n");
            } else {
                result = (int)num1 % (int)num2;
                printf("%.0f %% %.0f = %.0f\n", num1, num2, result);
            }
            break;

        default:
            printf("Invalid operator.\n");
            break;
    }

    return 0;
}
