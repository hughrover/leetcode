#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define TotalWeight 100
#define LEN 10

int knapsack(int, int);

int weight[LEN] = {90, 21, 21, 31, 34, 44, 55, 60, 70, 10};

int choosedNumber[LEN];
int	tmp = 0;

int main()
{
	int		i;

	printf("The total is : %d\n", TotalWeight);
	printf("The array is : ");
	for (i = 0; i < LEN; i++)
		printf("%d ", weight[i]);

	printf("\n");
	if (knapsack(TotalWeight, LEN - 1) == TRUE) {
		printf("Matched!\n");
		printf("The choosed number are : ");
		for (i = 0; i < tmp; i++)
			printf("%d ", choosedNumber[i]);
	}
	else {
		printf("Unmatched\n!");
	}
	printf("\n");
}

/*
 *	Several number choosed from the array weight[LEN] 
 *	can be added to equal the TotalWeight
 */
int knapsack(int wei, int n)
{
	if (wei == 0)		
		return TRUE;

	// all number have been choosed ,but can not reach TotalWeight
	if ((wei < 0) || (wei > 0 && n < 0))
		return FALSE;

	if (knapsack(wei, n - 1) == TRUE)
		return TRUE;
	else {
		if (knapsack(wei - weight[n], n - 1) == TRUE) {
			choosedNumber[tmp++] = weight[n];
			return TRUE;
		} 
	}
}






