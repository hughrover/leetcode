#include <stdio.h>
#include <stdlib.h>

#define LENTH 10

void max_heap_build(int *, int);
void max_heap_adjust(int *, int, int);
void swap(int *, int, int);

int main()
{
	int		i, tmplen;
	int sortarray[LENTH] = {19, 18, 37, 26, 15, 4, 53, 42, 21, 10};


	max_heap_build(sortarray, LENTH - 1);

	printf("\n");
	for (i = 0; i < LENTH; i++) {
		printf("%d ", sortarray[i]);
	}
	printf("\n");

	tmplen = LENTH - 1;

	for (i = LENTH - 1; i >= 1; i--) {
		swap(sortarray, 0, i);
		tmplen--;
		max_heap_adjust(sortarray, 0, tmplen);
	}

	printf("\n");
	for (i = 0; i < LENTH; i++) {
		printf("%d ", sortarray[i]);
	}
	printf("\n");
}

void max_heap_build(int *array, int len)
{
	int		i;
	int		startnode;

	startnode = (len - 1)/2;
	
	for (i = startnode; i >= 0; i--)
		max_heap_adjust(array, i, len);
}

void max_heap_adjust(int *array, int root, int len)
{
	int		left, right;
	int		largest;
	int		tmp;

	largest = root;
	// The first node of heap is location 0
	left = 2 * root + 1;
	right = 2 * root + 2;

	if ((left <= len) && (array[root] < array[left])) {
		largest = left;
	}  else {
		largest = root;
	}

	if ((right <= len) && (array[largest] < array[right])) {
		largest = right;
	}

	if (largest != root) {
		swap(array, root, largest);

		// Now the small number is at the largest
		// location ,so go on the adjusting
		max_heap_adjust(array, largest, len);
	}
}

void swap(int *array, int loc1, int loc2)
{
	int		tmp;

	tmp = array[loc1];
	array[loc1] = array[loc2];
	array[loc2] = tmp;
}
