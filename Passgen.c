#include <stdio.h>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
void printResult(int result);

int main(void) 
{
	int a = 10;
	int b = 5;

	int sum = add(a, b);
	printResult(sum);
	
	int difference = subtract(a, b);
	printResult(difference);
	
	int product = multiply(a, b);
	printResult(product);
	
	int quotient = divide(a, b);
	printResult(quotient);
	
	return(0);
}

int add(int a, int b) 
{
	return a + b;
}

int subtract(int a, int b) 
{
	return a - b;
}
int multiply(int a, int b) 
{
	return a * b;
}

int divide(int a, int b) 
{
	return a / b;
}

void printResult(int result) 
{
	printf("Result: %d\n", result);
}

