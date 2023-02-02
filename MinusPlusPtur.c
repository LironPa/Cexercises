
#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)

int main() {
	char str[1000];
	strcpy(str, "123+456-50+809X503/1000");
	int i, multiplier, j, current, total = 0, tmp, firstTime = 1;


	for ( i = 0; i < strlen(str); i++)
	{

		// get the multiplier
		multiplier = 1;
		for ( j = i; j < strlen(str) && str[j] != '-' && str[j] != '+'; j++)
		{
			multiplier =  multiplier * 10;

		}

		multiplier = multiplier / 10;


		// get the number
		current = 0;
		for (j = i; j < strlen(str) && str[j] != '-' && str[j] != '+'; j++)
		{
			tmp = str[j] - '0';
			tmp = tmp * multiplier;
			current += tmp;
			multiplier /= 10;

		}
		 

		if (firstTime)
		{
			total = current;
			firstTime = 0;
		}
		else {
			

			total = str[i -1] == '+'? total + current: total;
			total = str[i -1] == '-' ? total - current : total;
		
			
		}

		i = j;

		
	}
	printf("the answer is\n%d", total); 
}