#include <math.h>
#include <stdio.h>

// code written in collaboration with a peer
// importing math library to use sqrt()

int main() { 
    double a, b, c, root1, root2;

    printf(" Given a quadratic equation of the form a*x^2 + b * x + c\n"); // input values for a b c in eqn of form ax^2 + bx + c
    printf(" Please enter a: ");
    scanf("%lf", &a);
    printf(" Please enter b: ");
    scanf("%lf", &b);
    printf(" Please enter c: ");
    scanf("%lf", &c);


    
    // formula for -D/2ac where D = (b^2-4ac)

    double d = (b * b) - (4 * a * c ); 

    if (d == 0) {
        root1 = -b / (2 * a);
        printf("There is one real solution: %.2lf \n", root1); // if D is equal to zero, there is one real zero which is then caluculated using the formula above
    }
    
    else if (d > 0) { // if D > 0 then there are 2 real solutions which are then calculated using the formula above
        root1 = (-b + sqrt(d)) / (2 * a);
        root2 = (-b - sqrt(d)) / (2 * a);
        printf("There are 2 real solutions \n"); 
        printf("Solution 1: %.2lf \n", root1); 
        printf("Solution 2: %.2lf \n", root2);
    }

    else {
        printf("There are no real solutions \n"); // if D < 0 there are no real zeroes
    }

    return 0;
} 
