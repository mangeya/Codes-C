
#include <stdio.h>
#include <math.h>
// code written in collaboration with a peer
// pls see: The tax system is so odd I don't even want to start explaining what this code does.    
// There are individual tax brackets and each is taxed at a different percentage. The first $9875 will be taxed at 10%, then 12% till 40,126 and so on. For whichever bracket you income falls into..
// You subtract the previous taxed amount (if applicable) then tax that brackets specified percentage to the ramining amount
double taxrate(double income, double totaltax, double taxr10, double taxr12, double taxr22, double taxr24, double taxr32, double taxr35) {
    if (income <= 9875) {   // income bracket between $0 & $9,875
    totaltax = income * 0.1;
    printf("You were taxed 10.00%% on the first $%.2lf you made which is $%.2lf.\n", income, income * 0.1);
    } else if (income > 9876 && income <= 40125) {   // income bracket between $9,876 & $40,125   
    totaltax = ((income - 9875) * 0.12) + taxr10;  // calculating the tax if your income falls into this bracket
    printf("You were taxed 10.00%% on the first $9875.00 you made which is $987.50.\n");
    printf("You were taxed 12.00%% on the next $%.2lf you made which is $%.2lf.\n", (income - 9875), ((income - 9875) * 0.12));
    } else if (income > 40126 && income <= 85525) {   // income bracket between $$40,126 & $85,525   
    totaltax = ((income - 40125) * 0.22) + taxr12 + taxr10; // calculating the tax if your income falls into this bracket
    printf("You were taxed 10.00%% on the first $9875.00 you made which is $987.50.\n");
    printf("You were taxed 12.00%% on the next $30250.00 you made which is $3630.00.\n");
    printf("You were taxed 22.00%% on the next $%.2lf you made which is $%.2lf.\n", (income - 40125), ((income - 40125) * 0.22));
    } else if (income > 85526 && income <= 163300) {   // income bracket between $85,526 & $163,300   
    totaltax = ((income - 85525) * 0.24) + taxr22 + taxr12 + taxr10// calculating the tax if your income falls into this bracket
    printf("You were taxed 10.00%% on the first $9875.00 you made which is $987.50.\n");
    printf("You were taxed 12.00%% on the next $30250.00 you made which is $3630.00.\n");
    printf("You were taxed 22.00%% on the next $45400.00 you made which is $9988.00.\n");
    printf("You were taxed 24.00%% on the next $%.2lf you made which is $%.2lf.\n", (income - 85525), ((income - 85525) * 0.24));
    } else if (income > 163301 && income <= 207350) {   // income bracket between $163,301 & $207,350   
    totaltax = ((income - 163300) * 0.32) + taxr24 + taxr22 + taxr12 + taxr10; // calculating the tax if your income falls into this bracket
    printf("You were taxed 10.00%% on the first $9875.00 you made which is $987.50.\n");
    printf("You were taxed 12.00%% on the next $30250.00 you made which is $3630.00.\n");
    printf("You were taxed 22.00%% on the next $45400.00 you made which is $9988.00.\n");
    printf("You were taxed 24.00%% on the next $77775.00 you made which is $18666.00.\n");
    printf("You were taxed 32.00%% on the next $%.2lf you made which is $%.2lf.\n", (income - 163300), ((income - 163300) * 0.32));
    } else if (income > 207351 && income <= 518400) {   // income bracket between $207,3501 & $518,400    
    totaltax = ((income - 207350) * 0.35) + taxr32 + taxr24 + taxr22 + taxr12 + taxr10;// calculating the tax if your income falls into this bracket
    printf("You were taxed 10.00%% on the first $9875.00 you made which is $987.50.\n");
    printf("You were taxed 12.00%% on the next $30250.00 you made which is $3630.00.\n");
    printf("You were taxed 22.00%% on the next $45400.00 you made which is $9988.00.\n");
    printf("You were taxed 24.00%% on the next $77775.00 you made which is $18666.00.\n");
    printf("You were taxed 32.00%% on the next $44050.00 you made which is $14096.00.\n");
    printf("You were taxed 35.00%% on the next $%.2lf you made which is $%.2lf.\n", (income - 207350), ((income - 207350) * 0.35));
    } else {   // income bracket of $518,401 or more 
    totaltax = ((income - 518400) * 0.37) + taxr35 + taxr32 + taxr24 + taxr22 + taxr12 + taxr10; // final bracket, calculating the tax if your income falls into this bracket
    printf("You were taxed 10.00%% on the first $9875.00 you made which is $987.50.\n");
    printf("You were taxed 12.00%% on the next $30250.00 you made which is $3630.00.\n");
    printf("You were taxed 22.00%% on the next $45400.00 you made which is $9988.00.\n");
    printf("You were taxed 24.00%% on the next $77775.00 you made which is $18666.00.\n");
    printf("You were taxed 32.00%% on the next $44050.00 you made which is $14096.00.\n");
    printf("You were taxed 35.00%% on the next $311050.00 you made which is $108867.50.\n");
    printf("You were taxed 37.00%% on the next $%.2lf you made which is $%.2lf.\n", (income - 518400), ((income - 518400) * 0.37));
    }
  return totaltax;
}
int main(void) { 
  printf("Enter your income for the year: ");
  double income = 1.0;
  double totaltax = 1.0; 
  double flattaxrate = 1.0;
  double taxr10 = 1.0;
  double taxr12 = 1.0;
  double taxr22 = 1.0;
  double taxr24 = 1.0;  
  double taxr32 = 1.0 ;
  double taxr35 = 1.0;
  scanf(" %lf", &income);
  taxr10 = 9875 * 0.1;
  taxr12 = 30250 * 0.12;
  taxr22 = 45400 * 0.22;
  taxr24 = 77775 * 0.24;
  taxr32 = 44050 * 0.32;
  taxr35 = 311050 * 0.35;
  totaltax = taxrate(income, totaltax, taxr10, taxr12, taxr22, taxr24, taxr32, taxr35); // calling the function and assigning the var totaltax to the returned value
  printf("In total you will pay $%.2lf in taxes on the $%.2lf you made this year.\n", totaltax, income);
  flattaxrate = (totaltax / income) * 100;
  printf("This would amount to a FLAT tax of %.2lf%% on all of your income.\n", flattaxrate);
  return 0;
}