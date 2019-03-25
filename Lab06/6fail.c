/* 
===============================================================
Name: André Barros de Medeiros
ID: 194060
Date: 10/01/17
Copyright: ---------------
Description: It's me, Mário! ; Matrizes
===============================================================
*/

#include <stdio.h>

int main() {

int islandsi, islandsj; /*Total number of islands on the map*/
int islandnumb; 
int map[300][300]; /*map matrix*/
char a, b; /*file format char variables*/
int width, height; /*width and hight of map*/
int i, j; /*FOR loop variables*/

i=0; j=0; islandsi=0; islandsj=0; islandnumb=2;
scanf("%c%c %d %d",&a,&b,&width,&height); /*scan file format and size of mabp*/

for(i=0; i<height; i++)
	{
	for (j=0; j<width; j++)
		{
		scanf("%d", &map[i][j]);
		}
	}
/*
for(i=0; i<height; i++)
	{
	for (j=0; j<width; j++)
		{
		printf("%d ", map[i][j]);
		}
	printf("\n");
	}

printf("\n"); */

for(i=0; i<height; i++)
	{
	for (j=0; j<width; j++)
		{
		if ((map[i][j]==1)&&((map[i][j]!=map[i-1][j])&&(map[i][j]!=map[i-1][j+1])&&(map[i][j]!=map[i-1][j-1])&&(map[i][j]!=map[i][j-1]))) 
			{islandsi++; 
			printf("Position =  %d %d\n", i, j);}
		}
	}

/*for(i=0; i<height; i++)
	{
	for (j=0; j<width; j++)
		{
		printf("%d ", map[i][j]);
		}
	printf("\n");
	}*/

islandnumb=0;
for(j=0; j<width; j++)
	{
	for (i=0; i<height; i++)
		{
		if ((map[i][j]==1)&&((map[i][j]!=map[i-1][j])&&(map[i][j]!=map[i-1][j-1])&&(map[i][j]!=map[i][j-1])&&(map[i][j]!=map[i+1][j-1]))) 
			{islandsj++;
			printf("Position =  %d %d\n", i, j);}
		}
	}

/*for(i=0; i<height; i++)
	{
	for (j=0; j<width; j++)
		{
		printf("%d ", map[i][j]);
		}
	printf("\n");
	}*/

printf("Islands I = %d\n", islandsi);
printf("Islands J = %d\n", islandsj);

if (islandsi!=islandsj) 
	{
	if (islandsi<=islandsj) {printf("%d\n", islandsi);}
	if (islandsi>islandsj) {printf("%d\n", islandsj);}
	}





return 0;
}




