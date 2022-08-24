#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

// implementing a Monte Carlo method for the estimation of pi. Imagine that you have a circle of radius 1 whose center is at (0,0) surrounded by a square with sides of length 2.
//If we randomly choose points within the square the probability of a point being inside the circle is proportional to the area of the square that it occupies. This means that pi = P(point inside circle)*4 where P is the probability that a point is inside the circle.
//The probability for pi can be approximiated by picking a large number of points between [-1, 1] and counting the number that are inside the circle. The number of points inside the circle divided by the the total number of points picked is the probability of being inside the circle. pi = [probability of being inside the circle] * 4


// input validation
bool isValidFormat(const int numArgsRead, const int numArgsNeed)
{

    bool formatIsGood = numArgsRead == numArgsNeed;
    char character;
    do
    {
        scanf("%c", &character); // 45 \n

        if (!isspace(character))
        { // found a non whitespace character on the way to the end of the line
            formatIsGood = false;
        }
    } while (character != '\n'); // read characters until the end of the line
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
        numArgsRead = scanf(" %d", &num); 

    } while (!isValidFormat(numArgsRead, numArgsNeeded));

    return num;
}


// Function to run the number of iterations specified
int getPosInt(){
	int num;
  do{
    num = getValidInt("Enter the number of iterations to run: ");
  }while(!(num > 0));

  return num;
}


// function to generate random points for every iteration and then return the number of points inside the circle
int inside_circle(int iter)
{
    int hi = 1;
    int lo = -1;
    int count = 0;

    for (int i = 0; i < iter; ++i) 
    {

        double x;
        double y;

        x = lo + ((double)rand()) / (((double)RAND_MAX) / (hi - lo)); //generating a random double between the upper limit and lower limit
        y = lo + ((double)rand()) / (((double)RAND_MAX) / (hi - lo)); //generating a random double between the upper limit and lower limit

        double dist = pow(x, 2) + pow(y, 2); // calculating the distance uing the formula x^2 + y^2 so that the number of points in the circle can be calculated

        // printf("x and y : %lf , %lf \n",x , y);

        if (dist <= 1) // if the distance between calculated above is less than or equal to 1 then the point is inside the circle.
        {
            count += 1; // the number of points in the circle is stored in 'count'
        }
        // printf("count: %d\n",count);
    }
    return count; 
}

double prob_inside_circle(int count, int iter)
{
    double prob = (double)count / iter; // calculates prob(being inside the circle) using [count(number of points in circle)/ iter (total number of points)]
    // printf("probability = %lf\n",prob);
    double pi = prob * 4;  // calculates the value of pi by multiplying the probability by 4
    // printf("pi = %lf\n",pi);
    return pi;
}



int main()
{
    int count;

    int seed_val = getValidInt("Enter the seed for the random number generator: "); 
    int iter = getPosInt("Enter the number of iterations to run: ");

    srand((int)(seed_val));

    count = inside_circle(iter);

    double pi = prob_inside_circle(count, iter);

    printf("The value of pi is %.3lf.\n", pi);

    return 0;
}