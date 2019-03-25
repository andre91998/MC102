
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

/* int islandsi, islandsj; Total number of islands on the map*/
int map[300][300], mapprev[300][300]; /*map matrix*/
int mapstable;
int color; /* mincolor; */
char a, b; /*file format char variables*/
int width, height; /*width and hight of map*/
int i, j,k; /*FOR loop variables*/
int total[1000], neighbor[1000];
int minneighbor;
/* int temneighbor; */
int answer;

i=0; j=0;  color=2; mapstable=0; minneighbor=100; /*islandsi=0; islandsj=0;*/
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


while (mapstable==0) {

/*start: */


for(i=0;i<height;i++) {for (j=0;j<width;j++) {mapprev[i][j]=map[i][j];}}

for(i=0; i<height; i++)
	{
	for (j=0; j<width; j++)
		{
		/*mapprev[i][j]=map[i][j]; */
		if((map[i][j]==1)&&((map[i-1][j-1]<=1)&&(map[i-1][j]<=1)&&(map[i-1][j+1]<=1)&&(map[i][j-1]<=1)&&(map[i][j+1]<=1)&&(map[i+1][j-1]<=1)&&(map[i+1][j]<=1)&&(map[i+1][j+1]<=1)))
			{map[i][j]=color;
			color++;}
		if ((map[i][j]==1)&&((map[i-1][j-1]>1)||(map[i-1][j]>1)||(map[i-1][j+1]>1)||(map[i][j-1]>1)||(map[i][j+1]>1)||(map[i+1][j-1]>1)||(map[i+1][j]>1)||(map[i+1][j+1]>1)))
			{
			neighbor[0]=map[i-1][j-1];
			neighbor[1]=map[i-1][j];
			neighbor[2]=map[i-1][j+1];
			neighbor[3]=map[i][j-1];
			neighbor[4]=map[i][j+1];
			neighbor[5]=map[i+1][j-1];
			neighbor[6]=map[i+1][j];
			neighbor[7]=map[i+1][j+1];

			minneighbor=100;
	/*		temneighbor = 0; */
	/*		for (k=0; k<8; k++) {if(neighbor[k]>1) {temneighbor++;}} */

			for (k=0; k<8; k++) {if((neighbor[k]<minneighbor)&&(neighbor[k]>1)) {minneighbor=neighbor[k]; map[i][j]=minneighbor;}   }

/*			if (temneighbor>0) {map[i][j]=minneighbor;} */

			}


		else if(map[i][j]>1) {
			if ((map[i][j]>map[i-1][j-1])&&(map[i-1][j-1]!=1)&&(map[i-1][j-1]!=0)) {map[i][j]=map[i-1][j-1]; printf("a  ");}
			if ((map[i][j]>map[i-1][j])&&(map[i-1][j]!=1)&&(map[i-1][j]!=0))       {map[i][j]=map[i-1][j];  printf("b  ");}
			if ((map[i][j]>map[i-1][j+1])&&(map[i-1][j+1]!=1)&&(map[i-1][j+1]!=0)) {map[i][j]=map[i-1][j+1];printf("c  ");}
			if ((map[i][j]>map[i][j-1])&&(map[i][j-1]!=1)&&(map[i][j-1]!=0))       {map[i][j]=map[i][j-1];  printf("d  ");}
			if ((map[i][j]>map[i][j+1])&&(map[i][j+1]!=1)&&(map[i][j+1]!=0))       {map[i][j]=map[i][j+1];  printf("e  ");}
			if ((map[i][j]>map[i+1][j-1])&&(map[i+1][j-1]!=1)&&(map[i+1][j-1]!=0)) {map[i][j]=map[i+1][j-1];printf("f  ");}
			if ((map[i][j]>map[i+1][j])&&(map[i+1][j]!=1)&&(map[i+1][j]!=0))       {map[i][j]=map[i-1][j];  printf("g  ");}
			if ((map[i][j]>map[i+1][j+1])&&(map[i+1][j+1]!=1)&&(map[i+1][j+1]!=0)) {map[i][j]=map[i+1][j+1];printf("h  ");}
			}

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

printf("\n");*/




mapstable=1;

for (i=0; i<height; i++)
	{
	for (j=0; j<width; j++)
		{
		if (mapprev[i][j]!=map[i][j]) {mapstable=0;}
		}
	}

}


if (mapstable==1){
for (i=0; i<1000; i++) {total[i]=0;}

for (i=0; i<height; i++)
	{
	for (j=0; j<width; j++)
		{
		if (map[i][j]>1) {total[map[i][j]]++;}
		}
	}

answer=0;
for (i=0; i<1000; i++) {
	if (total[i]!=0) {answer++;}
}

printf("%d\n", answer);

}
return 0;
}
