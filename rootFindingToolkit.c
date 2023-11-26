#include <stdio.h>
#include <math.h>

// Function for which roots are to be found
double f(double x) {
    return x * x - 4; // Change this function as per your requirements
}

// Derivative of the function (for Newton-Raphson)
double derivative(double x) {
    return 2 * x; // Change this derivative function accordingly
}

// Bisection method
double bisection(double a, double b, double eps) {
    double c;
    while ((b - a) >= eps) {
        c = (a + b) / 2;
        if (f(c) == 0.0)
            break;
        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    }
    return c;
}

// Newton-Raphson method
double newtonRaphson(double x, double eps) {
    double h = f(x) / derivative(x);
    while (fabs(h) >= eps) {
        h = f(x) / derivative(x);
        x = x - h;
    }
    return x;
}

// Secant method
double secant(double x1, double x2, double eps) {
    double x0;
    do {
        x0 = ((x1 * f(x2)) - (x2 * f(x1))) / (f(x2) - f(x1));
        x1 = x2;
        x2 = x0;
    } while (fabs(f(x0)) >= eps);
    return x0;
}

int main() {
    int choice;
    double a, b, x0, x1, eps, root;

    printf("Enter the range [a, b]: ");
    scanf("%lf %lf", &a, &b);

    printf("Enter initial guess or points x0 and x1: ");
    scanf("%lf %lf", &x0, &x1);

    printf("Enter the tolerance epsilon: ");
    scanf("%lf", &eps);

    printf("Select a method to find the root:\n");
    printf("1. Bisection\n2. Newton-Raphson\n3. Secant\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            root = bisection(a, b, eps);
            break;
        case 2:
            root = newtonRaphson(x0, eps);
            break;
        case 3:
            root = secant(x0, x1, eps);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    printf("Root: %.6lf\n", root);

    return 0;
}
