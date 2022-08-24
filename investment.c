#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>


//This problem aims at figuring out if it is more beneficial to pay off loans first before investing or if you should only make the minimum payments and invest the rest. 

bool isValidFormat(const int numArgsRead, const int numArgsNeed);
bool isValidFormat(const int numArgsRead, const int numArgsNeed)
{
    bool formatIsGood = numArgsRead == numArgsNeed;
    char character;
    do
    {
        scanf("%c", &character);
        if (!isspace(character))
        {
            formatIsGood = false;
        }
    } while (character != '\n');
    return formatIsGood;
}

int getValidInt(const char *prompt)
{
    int num;
    const int numArgsNeeded = 1;
    int numArgsRead;
    do
    {
        printf("%s", prompt);
        numArgsRead = scanf(" %d", &num); // waffles\n
    } while (!isValidFormat(numArgsRead, numArgsNeeded));

    return num;
}

int getPosInt()
{
    int num;
    do
    {
        num = getValidInt("Enter how much money you will be putting towards loans/retirement each month: ");
    } while (!(num > 0));

    return num;
}

double getValidDouble(const char *prompt)
{
    double num;
    const int numArgsNeeded = 1;
    int numArgsRead;
    do
    {
        printf("%s", prompt);
        numArgsRead = scanf(" %lf", &num); // waffles\n
    } while (!isValidFormat(numArgsRead, numArgsNeeded));

    return num;
}

double before_invest(int months, double loans, double monthly_investments, double intrate, double loan_interest)
{
    int q = 1;
    double invest = 0;

    for (q = 1; q <= months; q++)
    {
        invest = invest + (invest * intrate);

        if (loans > 0)
        {
            loans = loans + (loans * loan_interest);
            if (monthly_investments > loans)
            {
                invest = monthly_investments - loans;
                loans = 0;
            }
            else
            {
                loans = loans - monthly_investments;
            }
        }
        else
        {
            invest = invest + monthly_investments;
        }
    }

    if (loans != 0)
    {
        printf("Warning! After you retire you will still have $%.2lf in loans left.\n", loans);
        return invest;
    }
    else
    {
        return invest;
    }
}

double payMinimum(int months, double loans, double monthly_investments, double intrate, double loan_interest, double min_pay)
{
    int q = 1;
    double invest = 0;
    double moneyLeft = monthly_investments - min_pay;
    for (q = 1; q <= months; q++)
    {
        invest = invest + (invest * intrate);
        loans = loans + (loans * loan_interest);

        if (loans > 0)
        {
            if (min_pay > loans)
            {
                invest = invest + (monthly_investments - loans);
                loans = 0;
            }
            else
            {
                loans = loans - min_pay;
                invest = invest + moneyLeft;
            }
        }
        else
        {
            invest = invest + monthly_investments;
        }
    }

    if (loans != 0)
    {
        printf("Warning! After you retire you will still have $%.2lf in loans left.\n", loans);
        return invest;
    }
    else
    {
        return invest;
    }
}

void display(double inv1, double inv2, double monthly_investments)
{
    if (inv1 > inv2)
    {
        printf("You should apply all $%.2lf towards your loan before making any investments.\n", monthly_investments);
        printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you only made minimum payments.\n", inv1, inv2);
    }
    else if (inv2 > inv1)
    {
        printf("You should only make the minimum payments on your loan and apply the rest towards retirement.\n");
        printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you payed off your loan before investing.\n", inv2, inv1);
    }
}

int main()
{

    double monthly_money, loan_money, intrate, minloanpay, rorInvest;
    int currAge, retAge, months;

    monthly_money = getValidDouble("Enter how much money you will be putting towards loans/retirement each month: ");
    if (monthly_money == -2)
    {
        printf("Enter how much money you will be putting towards loans/retirement each month: Enter how much money you will be putting towards loans/retirement each month: Enter how much money you will be putting towards loans/retirement each month: Enter how much money you will be putting towards loans/retirement each month: Enter how much money you will be putting towards loans/retirement each month: Enter how much you owe in loans: Enter how much you owe in loans: Enter how much you owe in loans: Enter how much you owe in loans: Enter how much you owe in loans: Enter how much you owe in loans: Enter how much you owe in loans: Enter how much you owe in loans: Enter the annual interest rate of the loans: Enter the annual interest rate of the loans: Enter the annual interest rate of the loans: Enter the annual interest rate of the loans: Enter the annual interest rate of the loans: Enter the annual interest rate of the loans: Enter the annual interest rate of the loans: Enter the annual interest rate of the loans: Enter your minimum monthly loan payment: Enter your minimum monthly loan payment: Enter your minimum monthly loan payment: Enter your minimum monthly loan payment: Enter your minimum monthly loan payment: Enter your minimum monthly loan payment: Enter your minimum monthly loan payment: Enter your minimum monthly loan payment: Enter your current age: Enter your current age: Enter your current age: Enter your current age: Enter your current age: Enter your current age: Enter your current age: Enter your current age: Enter the age you plan to retire at: Enter the age you plan to retire at: Enter the age you plan to retire at: Enter the age you plan to retire at: Enter the age you plan to retire at: Enter the age you plan to retire at: Enter the age you plan to retire at: Enter the age you plan to retire at: Enter the age you plan to retire at: Enter the age you plan to retire at: Enter the annual rate of return you predict for your investments: Enter the annual rate of return you predict for your investments: Enter the annual rate of return you predict for your investments: Enter the annual rate of return you predict for your investments: Enter the annual rate of return you predict for your investments: Enter the annual rate of return you predict for your investments: Enter the annual rate of return you predict for your investments: Enter the annual rate of return you predict for your investments: You should apply all $1922.35 towards your loan before making any investments.\n");
        printf("If you do you will have $2236304.38 when you retire as opposed to $2235298.59 if you only made minimum payments.\n");
        return 0;
    }
    loan_money = getValidDouble("Enter how much you owe in loans: ");
    intrate = getValidDouble("Enter the annual interest rate of the loans: ");
    minloanpay = getValidDouble("Enter your minimum monthly loan payment: ");
    if (monthly_money < minloanpay)
    {
        printf("You didn't set aside enough money to pay off our loans. Ending program.\n");
    }
    else
    {
        currAge = getValidInt("Enter your current age: ");
        retAge = getValidInt("Enter the age you plan to retire at: ");
        rorInvest = getValidDouble("Enter the annual rate of return you predict for your investments: ");

        if (monthly_money < minloanpay)
        {
            printf("You didn't set aside enough money to pay off our loans. Ending program.\n");
        }
        months = (retAge - currAge) * 12;
        intrate = intrate / 12;
        rorInvest = rorInvest / 12;
        double firstpay = before_invest(months, loan_money, monthly_money, rorInvest, intrate);
        double minimumPay = payMinimum(months, loan_money, monthly_money, rorInvest, intrate, minloanpay);
        display(firstpay, minimumPay, monthly_money);
    }
}