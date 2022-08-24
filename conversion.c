#include <stdio.h>

#include <stdbool.h>

#include <stdlib.h>

#include <ctype.h>


//This programme is converting measurements from one unit to another.
//From	Farenheit	Celsius	Kelvin
//Farenheit (F)	F	(F - 32) * 5/9	(F-32)*5/9+273.15
//Celsius(C	(C * 9/5) +32	C	C + 273.15
//Kelvin(K)	(K - 273.15) * 9/5 + 32	K -273.15	K


//From	Inches	Feet	Yards	Miles
//Inches(I)	I	I / 12	I / 36	I / 63360
// Feet(F)	F * 12	F	F / 3	F / 5280
//Yards(Y)	 Y* 36	Y * 3	Y	Y / 1760
//Miles(M)	M * 63360	M * 5280	M * 1760	M

// The input is first converted into a common unit (Yards for distance and Farenheit for temperature)

// input validation
bool isValidFormat(const int numberreader,
  const int numberArgsNeed);
char getValidTempType(const char * prompt);

// function for temperature
double Temperature(double tempinput, char tempuser, char tempoutput) {
  if (tempuser == tempoutput) {                            // if the input unit is equal to the output then the value is returned
    return tempinput;
  }
  if (tempuser == 'F' || tempuser == 'f') {                // if user inputs temperature in f or F 
    if (tempoutput == 'C' || tempoutput == 'c') {          // if user wants to convert to c or C
      return (tempinput - 32) * (5.0 / 9.0);               // Formula for conversion
    } else if (tempoutput == 'K' || tempoutput == 'k') {   // if user wants to convert to K or k
      return (tempinput - 32) * 5.0 / 9.0 + 273.15;        // formula for conversion
    } else {
      exit(0);
    }
  } else if (tempuser == 'C' || tempuser == 'c') {         // if user inputs temperature in C or C
    if (tempoutput == 'F' || tempoutput == 'f') {          // if user wants to convert to F or f
      return (tempinput * (9.0 / 5.0)) + 32;               // Formula for conversion
    } else if (tempoutput == 'K' || tempoutput == 'k') {   // if user wants to convert to c or C
      return tempinput + 273.15;                           // Formula for conversion
    } else {
      exit(0);
    }
  } else if (tempuser == 'K' || tempuser == 'k') {         // if user inputs temperature in k or K
    if (tempoutput == 'F' || tempoutput == 'f') {          // if user wants to convert to F or f
      return (tempinput - 273.15) * (9.0 / 5.0) + 32;      // Formula for conversion
    } else if (tempoutput == 'C' || tempoutput == 'c') {   // if user wants to convert to C or c
      return (tempinput - 273.15);                         // Formula for conversion
    } else {
      exit(0);
    }
  } else {
    exit(0);
  }
}

void getValidTemperature(const char * prompt)              //function to get temp
{
  char temp;
  char Type;
  double validvalue;
  double finaltemp;
  const int numberneeded = 2;
  int numberreader;
  printf("%s", prompt);
  numberreader = scanf(" %lf %c", & validvalue, & temp);
  temp = toupper(temp);
  if (!(isValidFormat(numberreader, numberneeded))) {
    printf("Invalid formatting. Ending program.\n");
    exit(0);
  } else if (temp != 'K' && temp != 'C' && temp != 'F') {
    printf("%c is not a valid temperature type. Ending program.\n", temp);
    exit(0);
  } else {}
  Type = getValidTempType("Enter the new unit type (F, C, or K): ");
  temp = toupper(temp);
  Type = toupper(Type);
  finaltemp = Temperature(validvalue, temp, Type);
  printf("%.2lf%c is %.2lf%c\n", validvalue, temp, finaltemp, Type); // Output
}
char getValidTempType(const char * prompt) {
  char c;
  const int numberneeded = 1;
  int numberreader;
  printf("%s", prompt);
  numberreader = scanf(" %c", & c);
  if (!isValidFormat(numberreader, numberneeded)) {
    printf("Invalid formatting. Ending program.\n");
    exit(0);
  }
  if (c == 'K' || c == 'k' || c == 'C' || c == 'c' || c == 'F' || c == 'f') {} else {
    printf("%c is not a valid temperature type. Ending program.\n", c);
    exit(0);
  }
  return c;
}
double Distance(double tempinput, char tempuser, char tempoutput) {
  if (tempuser == tempoutput) {                                      // if the input unit is equal to the output then the value is returned
    return tempinput;
  }
  if (tempuser == 'F' || tempuser == 'f') {                          // if user inputs distance in f or F
    {
      if (tempoutput == 'I' || tempoutput == 'i') {                   // if user wants to convert to i or I
        return tempinput * 12;                                        // Formula for conversion
      } else if (tempoutput == 'M' || tempoutput == 'm') {            // if user wants to convert to m or M
        return tempinput / 5280;                                      // Formula for conversion
      } else if (tempoutput == 'Y' || tempoutput == 'y') {            // if user wants to convert to Y or y
        return tempinput / 3;                                         // Formula for conversion 
      } else {
        exit(0);
      }
    }
  } else if (tempuser == 'Y' || tempuser == 'y') {                   // if user inputs distance in y or Y
    if (tempoutput == 'F' || tempoutput == 'f') {                    // if user wants to convert to f or F
      return tempinput * 3;                                          // Formula for conversion
    } else if (tempoutput == 'I' || tempoutput == 'i') {             // if user wants to convert to i or I
      return tempinput * 36;                                         // Formula for conversion
    } else if (tempoutput == 'M' || tempoutput == 'm') {             // if user wants to convert to m or M
      return tempinput / 1760;                                       // Formula for conversionn 
    } else {
      exit(0);
    }
  } else if (tempuser == 'I' || tempuser == 'i') {                   // if user inputs distance I or i
    if (tempoutput == 'F' || tempoutput == 'f') {                    // if user wants to convert to f or F
      return tempinput / 12;                                         // Formula  for conversion
    } else if (tempoutput == 'M' || tempoutput == 'm') {             // if user wants to convert to M or m
      return tempinput / 63360;                                      // Formula for conversion
    } else if (tempoutput == 'Y' || tempoutput == 'y') {             // if user wants to convert to Y or y
      return tempinput / 36;                                         // Formula for conversion
    } else {
      exit(0);
    }
  } else if (tempuser == 'M' || tempuser == 'm') {                   // if user inputs distance M or m
    if (tempoutput == 'F' || tempoutput == 'f') {                    // if user wants to convert to F or f
      return tempinput * 5280;                                       // Formula foor conversion
    } else if (tempoutput == 'Y' || tempoutput == 'y') {             // if user wants to convert to Y or y
      return tempinput * 1760;                                       // Formula for conversion
    } else if (tempoutput == 'I' || tempoutput == 'i') {             // if user wants to convert to I or i
      return tempinput * 63360;                                      // Formula for conversion
    } else {
      exit(0);
    }
  } else {
    exit(0);
  }
}

char getValidDistType(const char * prompt) {
  char c;
  const int numberneeded = 1;
  int numberreader;
  printf("%s", prompt);
  numberreader = scanf(" %c", & c);
  if (!isValidFormat(numberreader, numberneeded)) { 
    printf("Invalid formatting. Ending program.\n"); 
    exit(0);
  }
  if (c == 'I' || c == 'i' || c == 'F' || c == 'f' || c == 'Y' || c == 'y' || c == 'M' || c == 'm') {} else {
    printf("%c is not a valid distance type. Ending program.\n", c); 
    exit(0); 
  }
  return c;
}
void getValidDistance(const char * prompt) {
  char temp;
  char Type;
  double validvalue;
  double finaltemp;
  const int numberneeded = 2;
  int numberreader;
  printf("%s", prompt);
  numberreader = scanf(" %lf %c", & validvalue, & temp);
  temp = toupper(temp);
  if (!isValidFormat(numberreader, numberneeded)) { 
    printf("Invalid formatting. Ending program.\n"); 
    exit(0);
  } else if (temp != 'I' && temp != 'F' && temp != 'Y' && temp != 'M') {
    printf("%c is not a valid distance type. Ending program.\n", temp); 
    exit(0);
  } else {}
  Type = getValidDistType("Enter the new unit type (I,F,Y,M): ");
  temp = toupper(temp);
  Type = toupper(Type);
  finaltemp = Distance(validvalue, temp, Type);
  printf("%.2lf%c is %.2lf%c\n", validvalue, temp, finaltemp, Type);
}

bool isValidFormat(const int numberreader,
  const int numberArgsNeed) {
  bool formatIsGood = numberreader == numberArgsNeed;
  char charactertemp;
  do {
    scanf("%c", & charactertemp);
    if (!isspace(charactertemp)) {
      formatIsGood = false;
    }
  } while (charactertemp != '\n');
  return formatIsGood;
}

char getValidChar(const char * prompt) {
  char number;
  const int numberneeded = 1;
  int numberreader;
  printf("%s", prompt);
  numberreader = scanf(" %c", & number);
  if (!isValidFormat(numberreader, numberneeded)) {
    printf("Invalid formatting. Ending program. \n");
    exit(0);
  }

  return number;
}

int main() {
  char choice;
  printf("Pick the type of conversion that you would like to do.\n");
  printf("T or t for temperature\n");
  printf("D or d for distance\n");
  choice = getValidChar("Enter your choice: ");
  if (choice == 't' || choice == 'T') {
    getValidTemperature("Enter the temperature followed by its suffix (F, C, or K): ");
  } else if (choice == 'd' || choice == 'D') {
    getValidDistance("Enter the distance followed by its suffix (I,F,Y,M): ");
  } else {
    printf("Unknown conversion type %c chosen. Ending program.\n", choice);
    exit(0);
  }
  return 0;
}