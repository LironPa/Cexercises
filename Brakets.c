
#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)
int Findfirsbraket1(char str[], int index)
{
	int j, firstbraket;
	for (j = index; j > 0 && str[j] != '('; j--)
	{
		firstbraket = j;
	}

		return j -1;
}
int Findlastbraket1(char str[], int index)
{
	int j, lastbraket;
	for ( j = index ; j < strlen(str) && str[j] != ')'; j++)
	{
		lastbraket = j +1;
	}



	return j;
}
int Findnextbraket1(char str[], int index)
{
	int j, nextbraket;
	for (j = index; j < strlen(str) && str[j] != '('; j++)
	{
		nextbraket = j + 1;
	}
	return j;
}
int findnextindex1(char str[], int index)
{
	int j, nextindex = 0;

	for (j = index; j < strlen(str) && str[j] != '-' && str[j] != '+' && str[j] != 'X' && str[j] != '/'; j++)
	{
		nextindex = j + 1;

	}


	return nextindex;
}
int findeprevindex1(char str[], int index)
{
	int j, previndex;

	for (j = index; j >= 0 && str[j] != '-' && str[j] != '+' && str[j] != 'X' && str[j] != '/'; j--)
	{
		previndex = j - 1;

	}


	return previndex;
}
int findnumber1(char str[], int index)
{
	int multiplier = 1, j, tmp;
	int current = 0;
	for (j = index; j < strlen(str) && str[j] != '-' && str[j] != '+' && str[j] != 'X' && str[j] != '/' && str[j] != ')'; j++)
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



int main11() 
{
	char str[10000], tempstr[10000];
	strcpy(str, "520X2+(1000-985)X14+90/10+(850/50)-8/4+255+(425X10)-80X50+140000");
	strcpy(tempstr, "");
	int i, j, p, b,btemp =0, a, firstTime = 1;
	int   beforeindex = 0, beforenum = 0, afternum, summultiply = 0, total = 0;
	int braketbeforenum = 0, braketafternum =0, braketsum = 0;
	for (b = 0; b < strlen(str); b++)
	{
		if (str[b] == '(') {
			Findlastbraket(str, b);
			btemp = Findlastbraket(str, btemp);


			for (b = b; b < strlen(str) && b < btemp; b++)
			{
				
				braketbeforenum = findnumber(str, b + 1);
				b = findnextindex(str, b + 1);
				braketafternum = findnumber(str, b + 1);

				if (str[b] == 'X' || str[b] == '/') {
					braketsum = str[b] == 'X' ? braketbeforenum * braketafternum : braketbeforenum / braketafternum;
				}
				else if (str[b] == '+' || str[b] == '-') {
					braketsum = str[b] == '+' ? braketbeforenum + braketafternum : braketbeforenum - braketafternum;

				}
				b = btemp;
				b = Findfirstbraket(str, b) + 1;
				for (a = 0; a < b; a++)
				{
					tempstr[a] = str[a];
				}
				tempstr[a] = '\0';
				char sumbraket[1000];
				sprintf(sumbraket, "%d", braketsum);
				strcat(tempstr, sumbraket);
				b = Findlastbraket(str, b) + 1;
				int newindex = strlen(tempstr);
				int tmpindex = newindex;
				for (a = b; a < strlen(str); a++)
				{

					tempstr[tmpindex] = str[a];
					tmpindex++;
					tempstr[a + 1] = 0;
				}

				strcpy(str, tempstr);

				b = btemp;

			}
			b = Findnextbraket(str, b) - 1;
		}
	}
	    

//multi and div
	
	for (p = 0; p < strlen(str); p++)
	{		
		if (str[p] == 'X' || str[p] == '/')
		{
			beforeindex = findeprevindex(str, p - 1);
			beforenum = findnumber(str, beforeindex + 1);
			afternum = findnumber(str, p + 1);
			summultiply = str[p] == 'X' ? beforenum * afternum : beforenum / afternum;

			
			for (a = 0; a < beforeindex + 1; a++)
			{
				tempstr[a] = str[a];
			}
			tempstr[a] = '\0';
			char summultiplystr[1000];
			sprintf(summultiplystr, "%d", summultiply);
			strcat(tempstr, summultiplystr);
			p = findnextindex(str, p + 1);
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


			total = str[i - 1] == '+' ? total + current : total;
			total = str[i - 1] == '-' ? total - current : total;


		}




		i = findnextindex(str, i);
	}
	printf("the answer is:\n%d", total);
}
