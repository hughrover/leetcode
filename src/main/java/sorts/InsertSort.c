#include <stdio.h>
#include <stdlib.h>

#define LEN	10

void insertSort(int*);
void insertSortByRecursion(int *, int);
void insertSortByDivideSearch(int *, int);

int findPosition(int *, int, int, int);

int main()
{
	int		i;
	int*	buff;

	buff = (int*)malloc(sizeof(int) * LEN);
	if (buff == NULL) 
		return 0;
	
	for (i = 0; i < LEN; i++) {
		scanf("%d", &buff[i]);
	}

	printf("Before sort:\n");
	for (i = 0; i < LEN; i++) {
		printf("%d ", buff[i]);
	}

//	insertSort(buff);
//	insertSortByRecursion(buff, LEN -1);
	insertSortByDivideSearch(buff, LEN - 1);

	printf("\nSort result:\n");
	for (i = 0; i < LEN; i++) {
		printf("%d ", buff[i]);
	}
	printf("\n");
}

void insertSort(int* buffer)
{
	int		i, j;
	int		temp;
	
	for (j = 1; j < LEN; j++) {
		temp = buffer[j];
		i = j - 1;
		while ((i >= 0) && (buffer[i] > temp)) {
			buffer[i+1] = buffer[i];
			i--;
		}
		buffer[i+1] = temp;
	}
}


void insertSortByRecursion(int *buffer, int tail)
{
	int		i, tmp;

	if (0 == tail)
		return;

	insertSortByRecursion(buffer, tail - 1);
	
	for (i = tail; i > 0; i--) {
		if (buffer[i] <= buffer[i - 1]) {
			tmp = buffer[i];
			buffer[i] = buffer[i - 1];
			buffer[i - 1] = tmp;
		}
		else {
			break;
		}
	} 
}

void insertSortByDivideSearch(int *buffer, int tail)
{
	int		i, temp;
	int		posi;

	if (0 == tail)
		return;

	insertSortByDivideSearch(buffer, tail - 1);
		
	temp = buffer[tail];
	posi = findPosition(buffer, 0, tail - 1, temp);
	for (i = tail; i > posi; i--) {
		buffer[i] = buffer[i - 1];
	} 
	buffer[i] = temp;
}

int findPosition(int *buf, int left, int right, int target)
{	
	int		i, mid;

	mid = (left + right)/2;
	while(right > left) {
		if (target == buf[mid])
			return mid;
		else if (target < buf[mid])
			right = mid - 1;
		else
			left = mid + 1;
		mid = (left + right)/2;
	} 

//	if (buf[mid] > target)
	printf("\n");
	for (i = left; i <= right; i++)
		printf("%d ", buf[i]);

	printf("\n%d", mid);

}









