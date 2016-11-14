#include <stdio.h>
#include <stdlib.h>

#define LEN 10

void selectSort(int*);
void anotherSelectSort(int*);

int main()
{
	int		i, j;
	int*	buff;

	buff = (int*)malloc(sizeof(int) * LEN);
	if (buff == NULL)
		return 0;

	for (i = 0; i < LEN; i++) 
		scanf("%d", &buff[i]);

	printf("\nBefore sort:\n");
	for (i = 0; i < LEN; i++)
		printf("%d ", buff[i]);

	selectSort(buff);

	printf("\nSort result:\n");
	for (i = 0; i < LEN; i++)
		printf("%d ", buff[i]);

	printf("\n");
	return 1;
}

void selectSort(int* buf)
{
	int		i, j;
	int		min, temp;

	for (j = 0; j < (LEN - 1); j++) {
		min = buf[j];
		for (i = (j + 1); i < LEN; i++) {
			if (min > buf[i]) {
				temp = buf[i];
				buf[i] = min;
				min = temp;
			}
		}
		buf[j] = min;
	}
}

void anotherSelectSort(int* buf)
{
	int		i, j;
	int		min, temp;

	for (j = 0; j < (LEN - 1); j++) {
		min = j;
		temp = buf[j];
		for (i = (j + 1); i < LEN; i++) {
			if (temp > buf[i])
				min = i;
		}

		if (min != j) {
			temp = buf[min];
			buf[min] = buf[j];
			buf[j] = temp;
		}
	}
}
