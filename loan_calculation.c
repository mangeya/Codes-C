#include <stdio.h>
#include <math.h>
// code written in collaboration with a peer
// This code takes the following inputs: $ borrowed, annual interest rate, number of instalments
// then returns the amount payed monthly calculated using the formula: iP/(1-(1+i)^(-n)) where i is the interest rate, p is the principal amount, n is the number of instalments

int main(void){
    double total, loancost, payment, amountBorrowed, annualInterest;
    int numPayments;
    printf("Please enter the amount of money you borrowed: $");
    scanf("%lf", &amountBorrowed);
    printf("Please enter the annual interest rate: ");
    scanf("%lf", &annualInterest);
    printf("Please enter the number of payments to be made: ");
    scanf("%d", &numPayments);
    

    payment = ((((double) 1/12) * annualInterest) * amountBorrowed)/(1- (pow((1+(((double) 1/12) * annualInterest)),-numPayments))); // monthly interest rate will be 1/12th of of the annual interest rate
    
    
    printf("A loan of $%.2f with an annual interest of %.2f payed off over %.2d months will have monthly payments of $%.2f.\n", amountBorrowed, annualInterest, numPayments, payment); 

    total = payment * numPayments;
    loancost = total - amountBorrowed;

    printf("In total you will pay $%.2lf, making the cost of your loan $%.2lf.\n", total, loancost);

    return 0;
}