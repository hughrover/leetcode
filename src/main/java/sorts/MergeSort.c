#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define LEN 15

void mergeSort(int*, int, int);
void Merge(int*, int, int, int);

int main()
{
	int		i;
	int buff[] = {21, 34, 16, 76, 54, 43, 37, 82, 41, 99};
	mergeSort(buff, 0, 9);

	for (i = 0; i < 10; i++)
		printf("%d ", buff[i]);
}

void mergeSort(int* buf, int l, int r)
{
	if (l < r) {
		int m = (l + r)/2;
		mergeSort(buf, l, m);
		mergeSort(buf, m + 1, r);
		Merge(buf, l, m, r);
	}
}

void Merge(int* buf, int left, int mid, int right)
{
	int		i, j, k;
	int		len1, len2;
	int*	tmpbuf1;
	int*	tmpbuf2;

	len1 = mid - left + 1;
	len2 = right - mid;

	tmpbuf1 = (int*)malloc(len1 * sizeof(int));
	tmpbuf2 = (int*)malloc(len2 * sizeof(int));

	if (tmpbuf1 == NULL || tmpbuf2 == NULL) {
		printf("Malloc Error!\n");
		return;
	}

	j = 0;
	for (i = left; i <= mid; i++)
		tmpbuf1[j++] = buf[i];

	j = 0;
	for (i = mid + 1; i <= right; i++)
		tmpbuf2[j++] = buf[i];

	i = j = 0;
	k = left;

	while ((i < len1) && (j < len2)) {
		if (tmpbuf1[i] <= tmpbuf2[j])
			buf[k++] = tmpbuf1[i++];
		else
			buf[k++] = tmpbuf2[j++];
	}

	if (i == len1)
		while (j < len2)
			buf[k++] = tmpbuf2[j++];
	else
		while (i < len1)
			buf[k++] = tmpbuf1[i++];
}


