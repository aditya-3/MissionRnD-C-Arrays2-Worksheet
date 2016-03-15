/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int compareDate(int **a, int i, int **b, int j)
{
	int day1, day2, mon1, mon2, year1, year2;
	day1 = a[i][0]; mon1 = a[i][1]; year1 = a[i][2];
	day2 = b[j][0]; mon2 = b[j][1]; year2 = b[j][2];

	if (year1 == year2 && mon1 == mon2 && day1 == day2)
		return 0;
	else if (year1 <= year2)
	{
		if (mon1 <= mon2)
		{
			if (day1 <= day2)
				return 1;
			else
				return 2;
		}
		else if (day1 <= day2)
			return 2;
		else
			return 1;
	}
	else
		return 2;

}
/*struct transaction *sort(int **arrDates1, int len1, int **arrDates2, int len2, struct transaction *second, struct transaction *result)
{
	int i = len1 - 1, j = len2 - 1, k = len1 + len2 - 1,value=-1;
	while (i >= 0 && j >= 0)
	{
		value = compareDate(arrDates1, i, arrDates2, j);
		if (value == 1)
		{
			result[k--] = second[j--];
		}
		else
			result[k--] = result[i--];
	}
	if (i == -1 && j != -1)
	{
		while (j>=0)
		{
			result[k--] = second[j--];
		}
	}


	return result;
}*/
struct transaction *sort(int **arrDates1, int len1, int **arrDates2, int len2, struct transaction *A, struct transaction *B,struct transaction *result)
{
	int i = 0, j =0, k = 0, value = -1;
	while (i <len1 && j < len2)
	{
		value = compareDate(arrDates1, i, arrDates2, j);
		printf("i=%d\tj=%d\tvalue=%d  after  ",i,j,value);
		if (value == 1)
		{
			result[k++] = A[i++];
		}
		else
			result[k++] = B[j++];
		printf("k=%d\ti=%d\tj=%d\n",k, i, j);
	}
	if (i == len1 && j != len2)
	{
		while (j < len2)
		{
			result[k++] = B[j++];
		}
	}
	else if (j == len2 && i != len1)
	{
		while (i < len1)
		{
			result[k++] = A[i++];
		}
	}


	return result;
}
void convertToNumber(char *date, int **a, int k)
{	//date[i][0]=day, date[i][1]=month ,date[i][2]=year
	int i = 0, j = 0, sum = 0, t;
	while (date[i] != '\0')
	{
		if (date[i] != '-')
		{
			t = date[i] - 48;
			sum *= 10;
			sum = sum + t;

		}
		else if (date[i] == '-')
		{
			printf("%d-", sum);
			a[k][j++] = sum;
			sum = 0;
		}
		i++;
	}
	printf("%d\n", sum);
	a[k][j] = sum;

}

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i, j,*a[100],*b[100];
	char *input;
	if (A == NULL || B == NULL)
		return NULL;
	
	else
	{
		for (i = 0; i < ALen; i++)
			a[i] = (int *)malloc(3 * sizeof(int));
		for (i = 0; i < BLen; i++)
			b[i] = (int *)malloc(3 * sizeof(int));
		input = (char *)malloc(11 * sizeof(char));
		printf("Tr1\n");
		for (i = 0; i < ALen; i++)
		{
			for (j = 0; j < 11; j++)
				input[j] = A[i].date[j];
			input[j] = '\0';
			convertToNumber(input, a, i);

		}
		printf("Tr2\n");
		for (i = 0; i < BLen; i++)
		{
			for (j = 0; j < 11; j++)
				input[j] = B[i].date[j];
			input[j] = '\0';
			convertToNumber(input, b, i);

		}
		//if (ALen > BLen)
		//{
			
			struct transaction *result = (struct transaction *)malloc(((ALen + BLen)*sizeof(struct transaction)));
			//result = sort(a,ALen,b,BLen,B,A);
			result = sort(a, ALen, b, BLen, A, B,result);
			printf("\n");
			for (i = 0; i < ALen + BLen; i++)
			{
				for (j = 0; j < 11; j++)
					printf("%c", result[i].date[j]);
				printf("\n");
			}
			return result;
		//}
		/*else
		{
			printf("before Berror");
			
			
			struct transaction *result = (struct transaction *)malloc(( (ALen + BLen)*sizeof(struct transaction)));
			//printf("%d", (ALen + BLen));
			
			B = sort(b,BLen,a,ALen,A, B);
			
			for (i = 0; i < ALen + BLen; i++)
			{
				for (j = 0; j < 11; j++)
					printf("%c", B[i].date[j]);
				printf("\n");
			}
			return B;
		}*/
	}
}