#include<stdio.h>
    // code written in collaboration with a peer
    // A simple code with only the main function.The goal is to multiply two imarginary numbers input by the user
int main(void) {
    int ar, ai, br, bi;
    int x, y;
    printf("Enter the first complex number in the form ai + b: \n"); // first number will be in the the form ai + b so var ai will get the value of a and ar of b
    scanf("%di + %d", &ai, &ar);
    printf("Enter the second complex number in the form ai + b: \n"); // first number will be in the the form ai + b so var bi will get the value of a and br of b
    scanf("%di + %d", &bi, &br);


// multiplying the two imaginary numbers using: (ai + n)(ci + m)
    y = ar * bi + ai * br;
    x = ar * br - ai * bi;
    printf("(%di + %d) * (%di + %d) = %di + %d \n", ai, ar, bi, br, y, x); // outputs all the values. y hold the imaginary value x holds the real value, output is in the form yi + x
    
    return 0;
}