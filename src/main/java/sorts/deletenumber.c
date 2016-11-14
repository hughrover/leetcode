#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 240

int inputNumber(char*);
int findDecrease(char*);
int deleteNumber(char*, int);

int main()
{
	int		decrease;
	char*	number;
	int		cycle;
	int		i;

	number = (char*)malloc(LEN * sizeof(char));
	if (number == NULL) {
		printf("Malloc Error!\n");
		return 0;
	}

	if (inputNumber(number) != 1) {
		printf("Input Error!\n");
		return 0;
	}
	puts(number);

	printf("Input the cycle:");
	scanf("%d", &cycle);

	for (i = 0; i < cycle; i++) {
		decrease = findDecrease(number);
		deleteNumber(number, decrease);
		printf("Now the number is:");
		puts(number);
	}

}

int inputNumber(char* buffer)
{
	int		i;
	char	tmp;

	printf("Input the number:\n");

	i = 0;
	while ((tmp = getchar()) != EOF) {
		if (tmp >= '0' && tmp <= '9')
			buffer[i++] = tmp;
	}
	buffer[i] = '\0'; 
	
	return 1;
}

int findDecrease(char* buffer)
{
	int		i;
	int		len;

	len = strlen(buffer);

	for (i = 0; i < len; i++) {
		if (buffer[i] > buffer[i+1])
			return i;
	}
}

int deleteNumber(char* buffer, int index)
{
	int		i;
	int		len;

	len = strlen(buffer);

	for (i = index; i < len; i++) {
		buffer[i] = buffer[i+1];
	}

	buffer[len] = '\n';
	return 1;
}
