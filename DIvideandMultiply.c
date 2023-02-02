
#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)
int findnextindex(char str[], int index)
{
	int j, nextindex = 0;

	for (j = index; j < strlen(str) && str[j] != '-' && str[j] != '+' && str[j] != 'X' && str[j] != '/'; j++)
	{
		nextindex = j +1;

	}


	return nextindex;
}
int findeprevindex(char str[], int index)
{
	int j , previndex;
	
	for (j = index; j >= 0 && str[j] != '-' && str[j] != '+' && str[j] != 'X' && str[j] != '/'; j--)
	{
		previndex = j -1 ;

	}

	
	return previndex;
}
int findnumber(char str[], int index)
{
	 int multiplier = 1 , j, tmp;
	 int current = 0;
	for (j = index; j < strlen(str) && str[j] != '-' && str[j] != '+' && str[j] != 'X' && str[j] != '/'; j++)
	{
		multiplier = multiplier * 10;

	}

	multiplier = multiplier / 10;


	for (j = index; j < strlen(str) && str[j] != '-' && str[j] != '+' && str[j] != 'X' && str[j] != '/'; j++)
	{
		tmp = str[j] - '0';
		tmp = tmp * multiplier;
		current += tmp;
		multiplier /= 10;

	}
	return current;
}



int main() {
	char str[10000] ,tempstr[10000];
	strcpy(str, "520X2+480-9850X14+90/10+8/4+255+80X50+140000");
	strcpy(tempstr, "");
	int i, j, p, firstTime = 1;
	int   beforeindex, beforenum, afternum, summultiply, total = 0;
	for (p = 0; p < strlen(str); p++)
	{
		if (str[p] == 'X' || str[p] == '/')
		{
				beforeindex = findeprevindex(str, p -1);
				beforenum = findnumber(str, beforeindex +1);
				afternum = findnumber(str, p +1);
				summultiply = str[p] == 'X' ? beforenum * afternum : beforenum / afternum;
				
				int a;
				for (a = 0; a < beforeindex +1; a++)
				{
					tempstr[a] = str[a];
				}
				tempstr[a] = '\0';
				char summultiplystr[1000];
				sprintf(summultiplystr, "%d", summultiply);
				strcat(tempstr, summultiplystr);
				p = findnextindex(str, p +1);
				int newindex = strlen(tempstr);
				int tmpIndex = newindex;
				for (a = p; a < strlen(str); a++)
				{
					
					tempstr[tmpIndex] = str[a];
					tmpIndex++;
					tempstr[a + 1] = 0;
				}
				
				strcpy(str, tempstr);
				
				p = newindex;
		}
		
	}
	total = 0;
	for (i = 0; i < strlen(str); i++)
	{
		int current = 0;	
		current = findnumber(str, i);


		if (firstTime)
		{
			total = current;
			firstTime = 0;
		}
		else {


			total = str[i -1] == '+' ? total + current : total;
			total = str[i -1] == '-' ? total - current : total;
			

		}
		
		

		
		i = findnextindex(str, i);
	}
 	printf("the answer is\n%d", total);
}