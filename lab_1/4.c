#include <stdio.h>

// Define the Complex structure
struct Complex {
    float real;
    float imag;
};

// Function to add two complex numbers (call by value)
struct Complex add(struct Complex a, struct Complex b) {
    struct Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

// Function to multiply two complex numbers (call by address)
void multiply(struct Complex *a, struct Complex *b, struct Complex *result) {
    result->real = (a->real * b->real) - (a->imag * b->imag);
    result->imag = (a->real * b->imag) + (a->imag * b->real);
}

// Function to display a complex number
void display(struct Complex c) {
    printf("%.2f + %.2fi\n", c.real, c.imag);
}

int main() {
    struct Complex num1, num2, result;
    int choice;

    printf("Enter the real and imaginary part of the first complex number:\n");
    scanf("%f %f", &num1.real, &num1.imag);

    printf("Enter the real and imaginary part of the second complex number:\n");
    scanf("%f %f", &num2.real, &num2.imag);

    do {
        printf("\nMenu:\n");
        printf("1. Addition of two complex numbers\n");
        printf("2. Multiplication of two complex numbers\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                result = add(num1, num2);
                printf("The result of addition is: ");
                display(result);
                break;
            case 2:
                multiply(&num1, &num2, &result);
                printf("The result of multiplication is: ");
                display(result);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
