#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

//In collectible/trading card games like Magic The Gathering and HearthStone it is important for some
//decks to draw a specific card by a certain turn. For this problem you will be calculating the probability
//of drawing at least one copy of a specific card by a given turn. 

bool isValidFormat(const int numArgsRead, const int numArgsNeed);
bool isValidFormat(const int numArgsRead, const int numArgsNeed) { // help from professor butner's code
  bool formatIsGood = numArgsRead == numArgsNeed;
  char character;
  do {
    scanf("%c", & character);
    if (!isspace(character)) {
      formatIsGood = false;
    }
  } while (character != '\n');
  return formatIsGood;}
int getValidInt(const char * prompt) {
  int num;
  const int numArgsNeeded = 1;
  int numArgsRead;
  do {
    printf("%s", prompt);
    numArgsRead = scanf(" %d", & num);
  } while (!isValidFormat(numArgsRead, numArgsNeeded));
  return num;
}
double firstd(int cards, int copies, int hsize)
{
  double de;
  double val = 1;

  for (int i = 0; i < hsize; ++i)
  {
    de = (((double)cards - i) - copies) / ((double)cards - i);
    val = val * de;
  }
  return val;
}

int main()
{

  int numb = getValidInt("Enter how many total cards there are in the deck: ");
  int ncopies = getValidInt("Enter how many copies of the card that you are looking for are in the deck: ");
  int hand = getValidInt("Enter your initial hand size: ");
  int mul = getValidInt("Enter how many cards you are mulliganing: ");
  int sw = getValidInt("Enter what turn you want to draw the card by: ");

  double ifd = firstd(numb, ncopies, hand);
  numb = numb - hand;
  double fmul = firstd(numb, ncopies, mul);
  double fDET = firstd(numb, ncopies, sw);
  double fp = ifd * fmul * fDET;
  printf("The probability of drawing at least one of the cards by turn %d given you mulliganed %d cards is %.2lf", sw, mul, 1 - fp);
  return 0;
}
