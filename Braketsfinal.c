
#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)
int Stringcalculator(char str[])
{
	int i, j, p, firstTime = 1;
	int   beforeindex, beforenum, afternum, summultiply, total = 0;
	char tempstr[10000] = "";
	for (p = 0; p < strlen(str); p++)
	{
		if (str[p] == 'X' || str[p] == '/')
		{
			beforeindex = findeprevindex(str, p - 1);
			beforenum = findnumber(str, beforeindex + 1);
			afternum = findnumber(str, p + 1);
			summultiply = str[p] == 'X' ? beforenum * afternum : beforenum / afternum;

			int a;
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
	return total;
}
int Findfirstbraket(char str[], int index)
{
	int j, firstbraket;
	for (j = index; j > 0 && str[j] != '('; j--)
	{
		firstbraket = j;
	}

	return j - 1;
}
int Findlastbraket(char str[], int index)
{
	int j, lastbraket;
	for (j = index; j < strlen(str) && str[j] != ')'; j++)
	{
		lastbraket = j + 1;
	}



	return j;
}
int Findnextbraket(char str[], int index)
{
	int j, nextbraket;
	for (j = index; j < strlen(str) && str[j] != '('; j++)
	{
		nextbraket = j + 1;
	}
	return j;
}
int Resetbraket(char str[], int index)
{
	int j, resetbraket;
	for (j = index; j < strlen(str) && str[j] != '('; j++)
	{
		resetbraket = j;
	}



	return j;

}
int findnextindex(char str[], int index)
{
	int j, nextindex = 0;

	for (j = index; j < strlen(str) && str[j] != '-' && str[j] != '+' && str[j] != 'X' && str[j] != '/' && str[j] != '(' && str[j] != ')'; j++)
	{
		nextindex = j + 1;

	}


	return nextindex;
}
int findeprevindex(char str[], int index)
{
	int j, previndex;

	for (j = index; j >= 0 && str[j] != '-' && str[j] != '+' && str[j] != 'X' && str[j] != '/' && str[j] != '(' && str[j] != ')'; j--)
	{
		previndex = j - 1;

	}


	return previndex;
}
int findnumber(char str[], int index)
{
	int multiplier = 1, j, tmp;
	int current = 0;
	for (j = index; j < strlen(str) && str[j] != '-' && str[j] != '+' && str[j] != 'X' && str[j] != '/' && str[j] != '(' && str[j] != ')'; j++)
	{
		multiplier = multiplier * 10;

	}

	multiplier = multiplier / 10;


	for (j = index; j < strlen(str) && str[j] != '-' && str[j] != '+' && str[j] != 'X' && str[j] != '/' && str[j] != '(' && str[j] != ')'; j++)
	{
		tmp = str[j] - '0';
		tmp = tmp * multiplier;
		current += tmp;
		multiplier /= 10;

	}
	return current;
}
int Stringcut(char str[], int firstindex, int lastindex, char str2[])
{
	int   beforeindex, beforenum, afternum, summultiply, p, total = 0, current = 0, a, ifonlyonce = 1, opcount = 0;
	char tempstr[10000] = "", summultiplystr[1000];

	opcount = operatorcount(str, firstindex, lastindex);
	for (p = firstindex; p < lastindex; p++)
	{
		if (opcount == 1) {
			if (str[p] == '+' || str[p] == '-') {
				beforenum = findnumber(str, firstindex + 1);
				afternum = findnumber(str, p + 1);
				total = str[p] == '+' ? beforenum + afternum : beforenum - afternum;
				sprintf(summultiplystr, "%d", total);
				strcat(tempstr, summultiplystr);
				strcpy(str2, tempstr);
				return;
			}
		}
		if (str[p] == 'X' || str[p] == '/')
		{
			if (opcount == 1) {
				if (str[p] == 'X' || str[p] == '/') {
					beforenum = findnumber(str, firstindex + 1);
					afternum = findnumber(str, p + 1);
					summultiply = str[p] == 'X' ? beforenum * afternum : beforenum / afternum;
					sprintf(summultiplystr, "%d", summultiply);
					strcat(tempstr, summultiplystr);
					strcpy(str2, tempstr);
					return;
				}
			}
			if (opcount == 2) {
				beforenum = findnumber(str, firstindex + 1);
				afternum = findnumber(str, p + 1);
				summultiply = str[p] == 'X' ? beforenum * afternum : beforenum / afternum;
				sprintf(summultiplystr, "%d", summultiply);
				strcat(tempstr, summultiplystr);
				p = findeprevindex(str, lastindex - 1);
				int newindex = strlen(tempstr);
				int tmpIndex = newindex;

				for (a = p; a < lastindex; a++)
				{

					tempstr[tmpIndex] = str[a];
					tmpIndex++;
					tempstr[a + 1] = 0;
				}
				strcpy(str2, tempstr);
				return;
			}
			if (opcount >= 3) {
				if(str[p] == 'X' || str[p] == '/') {
				beforenum = findnumber(str, firstindex + 1);
				afternum = findnumber(str, p + 1);
				summultiply = str[p] == 'X' ? beforenum * afternum : beforenum / afternum;
				sprintf(summultiplystr, "%d", summultiply);
				strcat(tempstr, summultiplystr);
				p = findnextindex(str, p + 1);
				int newindex = strlen(tempstr);
				int tmpIndex = newindex;

				for (a = p; a < lastindex; a++)
				{

					tempstr[tmpIndex] = str[a];
					tmpIndex++;
					tempstr[a + 1] = 0;
				}
				strcpy(str2, tempstr);

				return;
			}



			}
		}
		
	}
	return;
}
int operatorcount(char str[], int firstindex, int lastindex)
{
	int opcount = 0;
	for (int i = firstindex; i < lastindex; i++)
	{
		if (str[i] == 'X' || str[i] == '/' || str[i] == '+' || str[i] == '-')
		{
			opcount++;
		}
	}


	return opcount;
}


int main()
{
	char str[10000], tempstr[10000], calstr[1000] = "";
	strcpy(str, "520X2+(1000X2-985X2)X14+90/10+(850/50+13-10)-8/2+255+(425X10)-80X50+(457+3)+140000"); 
	strcpy(tempstr, "");
	int i, j, p, b, btemp = 0, a, firstTime = 1, firstbraket =1;
	int   beforeindex = 0, beforenum = 0, afternum, summultiply = 0, replace = 0;
	int braketbeforenum = 0, braketafternum = 0, braketsum = 0, total = 0;;
	
	for (b = 0; b < strlen(str); b++)
	{
		if (str[b] == '(') {
			i = Findnextbraket(str, b);
			btemp = Findlastbraket(str, btemp);
			Stringcut(str, i, btemp, calstr);
			replace = Stringcalculator(calstr);

			for (b = b; b < strlen(str) && b < btemp; b++)
			{

				for (a = 0; a < b; a++)
				{
					tempstr[a] = str[a];
				}
				tempstr[a] = '\0';
				char sumbraket[1000];
				sprintf(sumbraket, "%d", replace);
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
			b = Resetbraket(str, 0);
			b = Findnextbraket(str, b) -1;
		}
	}
	int Solution = Stringcalculator(str);

	

	printf("the answer is:\n%d", Solution);
}
