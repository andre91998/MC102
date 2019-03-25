/*
=======================================================================
Author: André Barros de Medeiros
RA: 194060
Title: Labirinto
Description: Final Lab, recursão, escabe the labyrinth
Date: 19/11/2017
Copyright: free to use and modify
=======================================================================
*/

#include <stdio.h>

#define MAXLAYERS 10  /*maximum number of layers in a labyrinth*/
#define MAXGATES  100 /*maximum number of gates in a layer of a labyrinth*/
#define MAXWALLS  100 /*maximum number of walls between layers of a labyrinth*/

int recursao(){

return shit;
}

int main(){

int layers;
int gates[MAXLAYERS][MAXGATES], walls[MAXLAYERS][MAXWALLS];
int i, j, k;
char string[100];
int slot;

/*Part1:
Read and allocate input to the correct variables in the correct format
*/

scanf("%d", &layers);
	

for(k=0; k<(2*layers-1); k++){
	/*printf("k: %d\n", k);*/
	scanf(" %[^\n]%*c", string);
	/*printf("string: %s\n", string);*/
	if(k%2==0){
		i=0; j=0; slot=0;
		while (string[i]!='\0'){
			sscanf(string+slot, "%d", &gates[k/2][j]);
			if (gates[k/2][j]/100>0) {slot=slot+4;}	
			else if(gates[k/2][j]/10>0) {slot=slot+3;}
			else slot=slot+2;
			printf("gates[%d][%d] is: %d\n", k/2, j, gates[k/2][j]);
			i=(slot-1);
			j++;
		}
	}

	else{
		i=0; j=0; slot=0;
		while (string[i]!='\0'){
			sscanf(string+slot, "%d", &walls[k/2][j]);
			if (walls[k/2][j]/100>0) {slot=slot+4;}	
			else if(walls[k/2][j]/10>0) {slot=slot+3;}
			else slot=slot+2;
			printf("walls[%d][%d] is: %d\n", k/2, j, walls[k/2][j]);
			i=(slot-1);
			j++;
		}
	}
}
	
/*Part 2:
Call function of type "recursão"
*/

	

	
return 0;
}
