/*   ch12_9.c                 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 4
void sort(char *[]);
int main()
{
    char *season[] = {"Spring",
				     "Summer",
					 "Autumn",
					 "Winter"};
    int i;
    
	sort(season);
	for (i = 0; i < LEN; i++ )
		printf("%s\n",season[i]); 	/* ¿é¥X¦r¦ê¤º®e */  
    system("pause");
    return 0;
}
void sort(char *str[])
{
	char *tmp;
	int i, j;
	
	for (i = 1; i < LEN; i++)
	{
		for (j = 0; j < (LEN - 1); j++)
		{
			if (strcmp(str[j], str[j+1]) > 0)
			{
				tmp = str[j];
				str[j] = str[j+1];
				str[j+1] = tmp;
			}
		}
	}
}


