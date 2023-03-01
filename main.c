#include <stdio.h>

int Calculate(int num1, int num2, char operation);

int main(void)
{
  int userNum1, userNum2, result;
  char operation;

  printf("Enter first number:\n");
  scanf("%d", &userNum1);

  printf("Enter second number:\n");
  scanf("%d", &userNum2);

  printf("Enter operation (+, -, *, /):\n");
  scanf("%c", &operation);

  result = Calculate(userNum1, userNum2, operation);

  printf("Result: %d\n", result);

  return 0;
}

Calculate(int num1, int num2, char operation)
{
  int result;

  if (operation == '/' && num2 == 0)
  {
    printf("Division by zero is undefined. Please enter a non-zero second number.\n");
    return result;
  }

  switch(operation)
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
      break;
  }

  return result;
}