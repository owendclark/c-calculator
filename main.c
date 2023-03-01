#include <stdio.h>

float Calculate(float num1, float num2, char operation);

int main(void)
{
  float userNum1, userNum2, result;
  char operation;

  printf("Enter first number:\n");
  scanf("%f", &userNum1);

  printf("Enter second number:\n");
  scanf("%f", &userNum2);

  printf("Enter operation (+, -, *, /):\n");
  scanf(" %c", &operation);

  result = Calculate(userNum1, userNum2, operation);

  if (result == -__FLT_MAX__)
  {
    // Error occured
    printf("Error: Result out of range.\n");
    return 1;
  }

  printf("Result: %.2f\n", result);

  return 0;
}

float Calculate(float num1, float num2, char operation)
{
  float result = 0;

  if (operation == '/' && num2 == 0)
  {
    printf("Division by zero is undefined. Please enter a non-zero second number.\n");
    result = -__FLT_MAX__;
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
      break;
    default:
      printf("Invalid operation. Please enter a valid operation (+, -, *, /).\n");
      result = -__FLT_MAX__;
      break;
    }
  }

  return result;
}