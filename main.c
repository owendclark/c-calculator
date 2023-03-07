#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

double Calculate(double num1, double num2, char operation);

int main(void)
{
  double userNum1, userNum2, result;
  char operation;

  printf("Enter first number:\n");
  //Validates Input
  if (scanf("%lf", &userNum1) != 1)
  {
    printf("Error: Invalid input.\n");
    return 1;
  }

  printf("Enter second number:\n");
  //Validates Input
  if (scanf("%lf", &userNum2) != 1)
  {
    printf("Error: Invalid input.\n");
    return 1;
  }

  printf("Enter operation (+, -, *, /):\n");
  //Validates Input
  if (scanf(" %c", &operation) != 1 || !strchr("+-*/", operation))
  {
    printf("Error: Invalid operation.\n");
    return 1;
  }

  result = Calculate(userNum1, userNum2, operation);

  if (isnan(result))
  {
    // Error occured
    printf("Error: Invalid calculation.\n");
    return 1;
  }

  printf("Result: %lf\n", result);

  return 0;
}

// Runs calculation given the two numbers and the operation, and returns the result or NAN if error
double Calculate(double num1, double num2, char operation)
{
  double result = 0;

  if (operation == '/' && num2 == 0)
  {
    printf("Division by zero is undefined. Please enter a non-zero second number.\n");
    return NAN;
  }
  else
  {
    switch (operation)
    {
    case '+':
      result = num1 + num2;
      break;
    case '-':
      result = num1 - num2;
      break;
    case '*':
      result = num1 * num2;
      break;
    case '/':
      result = num1 / num2;
      // Overflow protection
      if (!isinf(result) && fabs(result - (double)((long)result)) > 1e-9)
      {
        return NAN;
      }
      break;
    default:
      printf("Invalid operation. Please enter a valid operation (+, -, *, /).\n");
      return NAN;
    }
  }

  return result;
}