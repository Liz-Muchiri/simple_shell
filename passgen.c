#include <stdio.h>
#include <stdlib.h>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
void printResult(int result);
/**
 * main - performs mathematical operations
 */
int main(void)
{
	int a, b, sum, difference, product, quotient;

	printf("enter the values of a and b:");
	scanf("%d %d\n", &a, &b);
	if (a || b < 0)
	{
		printf("invalid input");
		return (-1);
	}
	sum = add(a, b);
	printResult(sum);

	difference = subtract(a, b);
	printResult(difference);

	product = multiply(a, b);
	printResult(product);

	quotient = divide(a, b);
	printResult(quotient);

	return (0);
}

/**
 * add - adds two integers
 * @a: integer
 * @b: integer
 * Return: sum of a and b
 */
int add(int a, int b)
{
	return (a + b);
}

/**
 * subtract - subtracts b from a
 * @a: integer
 * @b: integer
 * Return: difference
 */
int subtract(int a, int b)
{
	return (a - b);
}
/**
 * multiply - multiplies two integers
 * @a: integer
 * @b: integer
 * Return: quotient
 */
int multiply(int a, int b)
{
	return (a * b);
}

/**
 * divide - divides a by b
 * @a: integer
 * @b: integer
 * Return: quotient
 */
int divide(int a, int b)
{
	return (a / b);
}

/**
 * printResult - prints result
 * @result: variable to be printed
 */
void printResult(int result)
{
	printf("Result: %d\n", result);
}
