#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
/**
 * acctgen - generates account numbers based on bank code
 * Return: 0 always
 */
int acctgen(void)
{
	char bank[100];
	int code;
	int acct_num[7], count = 0;

	printf("Enter bank name and 3 digit code:\n");
	scanf("%s %d", bank, &code);
	srand(time(NULL));
	while (count < 6)
	{
		acct_num[count] = rand();
		count++;
	}
	count = 0;
	printf("Your account Number is %d", code);
	while (count < 7)
	{
		printf("%d", acct_num[count] % 10);
		count++;
	}
	printf("\n");
	return (0);
}
int main(void)
{
	acctgen();
	return (0);
}
