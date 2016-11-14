#include <stdio.h>
#include <stdlib.h>

//#define LENTH 10
#define LENTH 11

void quickSort(int *, int, int);
int partition(int *, int, int);
void swap(int *, int, int);

int main()
{
	int		i;

	int sortarray[LENTH] = {21, 33, 22, 14, 31, 32, 11, 15, 14, 32, 45};
	quickSort(sortarray, 0, LENTH - 1);
	
	for (i = 0; i < LENTH; i++)
		printf("%d ", sortarray[i]);

	printf("\n");
}

// Quicksort is a divide-and-conquer algorithm
// as well as MergeSort
void quickSort(int *array, int s, int e)
{
	int		dividelocation;

	if (s < e) {
		dividelocation = partition(array, s , e);
		quickSort(array, s, dividelocation - 1);
		quickSort(array, dividelocation + 1, e);
	}
}

int partition(int *array, int start, int end)
{
	int		i, j;
	int		divide;

	// After partition , the divide number is at
	// its sorted position
	divide = array[end];
	i = start - 1;

	for (j = start; j <= end - 1; j++) {
		if (array[j] <= divide) {
			i++;
			swap(array, i, j);
		}
	}

	i++;
	swap(array, i, end);

	return i;
}

void swap(int * array, int fst, int snd)
{
	int		tmp;
	tmp = array[fst];
	array[fst] = array[snd];
	array[snd] = tmp;
}
