/*
 ============================================================================
 Name        : Lab12.c
 Author      : André Medeiros
 RA          : 194060
 Version     :
 Copyright   : Free to use, copy, modify
 Description : Find center of labyrinth
 ============================================================================
 */

#include <stdio.h>

#define MAXLAYERS 10  /*maximum number of layers in a labyrinth*/
#define MAXGATES  100 /*maximum number of gates in a layer of a labyrinth*/
#define MAXWALLS  100 /*maximum number of walls between layers of a labyrinth*/
#define MAXMOVES 100 /*maximum number of moves to solve the maze*/
struct way {char  entrasai;  int  level; int  gate;} ;
typedef struct way Way;
struct door {int level; int gate;};
typedef struct door Door;


/*int find=0; */ /* global variable just get an idea how many times the recursion happens */

/* Function to visualize a flattened maze
 * inputs: program inputs in levels, gates, and barriers
 */
void printmaze(int levels, int g[10][100], int gc[10], int w[10][100], int wc[10]) {

	int i,j,k;
	char icon;
	for(i=0; i<(2*levels-1); i++){
		if(i%2==0) {
			printf("wall and gates    :");
			for (j=0;j<360;j++) {
				icon = '#';
				for (k=0;k<gc[i/2];k++){
					if (j==g[i/2][k]) {icon=' ';}
				}
				printf("%c",icon);
			}
			printf("\n");
		}

		else {
			printf("space and barriers:");
			for (j=0;j<360;j++) {
				icon = '.';
				for (k=0;k<wc[i/2];k++){
					if (j==w[i/2][k]) {icon='W';}
				}
				printf("%c",icon);
			}
			printf("\n");
		}
	}
	printf("                            ******* Center of the maze ******   \n");
	return;
}

/* Function to find the two walls that restrict the search are for new doors
 * inputs: current level and position(angle), array of barriers
 * output: position of left and right walls
 */
void twowalls(int level, int angle,int w[10][100], int wc[10], int *left, int *right) {

	int i,j;
	*left=-1;
	for (i=angle;i<360;i++){
		for (j=0;j<wc[level];j++) {
			if (i==w[level][j]) {*left=i; i=360;}
		}
	}
	if(*left==-1) {  /* no wall found going left till 359 */
		for (i=0;i<angle;i++){
			for (j=0;j<wc[level];j++) {
				if (i==w[level][j]) {*left=i; i=angle;}
			}
		}
	}
	*right=-1;
	for (i=angle;i>=0;i--){
		for (j=0;j<wc[level];j++) {
			if (i==w[level][j]) {*right=i; i=-1;}
		}
	}
	if(*right==-1) {  /* no wall found going right till 0 */
		for (i=359;i>angle;i--){
			for (j=0;j<wc[level];j++) {
				if (i==w[level][j]) {*right=i; i=angle;}
			}
		}
	}
	return;
}

/*Function that returns the amount of doors available as viewed from a given position
 * inputs: current level and position(angle), direction, all gates, all barriers
 * outputs: # of doors(excluding current position) and array with position of doors
 */
int availabledoors (int level, int angle, int inout, int g[10][100], int gc[10], int w[10][100], int wc[10], Door *doors){

	int i,j,k,pos;
	int shift;
	int leftwall, rightwall;

	shift=(inout-1)/2;
/*	printf("level %d at door position %d => direction %d\n",level,angle,inout); printf("wall count %d\t", wc[level+shift]); */
	twowalls(level+shift, angle, w, wc, &leftwall, &rightwall);
/*	printf("left wall = %d\t",leftwall); printf("right wall = %d\n",rightwall); */

	i=0;
	if(leftwall==rightwall) {leftwall=359;rightwall=0;}
	if(rightwall>=leftwall) {rightwall=rightwall-360;}
	for (k=leftwall;k>=rightwall;k--){
		pos = (k+360)%360;
		for (j=0;j<gc[level+inout];j++) { if (pos==g[level+inout][j] ) {doors[i].level=level+inout; doors[i].gate=pos; i++;} }
		for (j=0;j<gc[level];j++) { if (pos==g[level][j] && pos!=angle) {doors[i].level=level; doors[i].gate=pos; i++; } }
	}
	return i;
}

/* recursive function to find path
 * returns amount of steps so far
 */
int findpath(int depth, int endlevel, int currlevel, int level, int angle, int inout, int g[10][100], int gc[10], int w[10][100], int wc[10], Way *caminho ) {
	int i;
	int result;
	int repeated;
	int toggle;
	Door alternatives[100];
	int options;

	/*find++;*/
	/*printf("find =%d depth = %d\n",find, depth);*/
/*	printf("currlevel = %d level = %d at door angle = %d\n",currlevel, level, angle); */

	result = 0;
	repeated = 0;
	options = 0;

	/*printf("caminho :\t");*/
	for (i=0;i<depth;i++){
		/*printf("(%d,%d)\t",caminho[i].level,caminho[i].gate);*/
		if(caminho[i].level==level && caminho[i].gate==angle) {repeated = 1;}
	}
	/*printf("\n");*/

/*	if(repeated==1){printf("REPEATED\n");} */

	caminho[depth].level=level;
	caminho[depth].gate=angle;
	if(depth==0) {caminho[depth].entrasai = 'E';}
	if(depth>0) {
		if (caminho[depth].level!=caminho[depth-1].level) { caminho[depth].entrasai = caminho[depth-1].entrasai;}
		else if (caminho[depth-1].entrasai == 'S') {caminho[depth].entrasai = 'E'; } else {caminho[depth].entrasai = 'S'; }
	}


	if (repeated==0) {
		if(level==endlevel) {result = depth;}
		else {
			if(currlevel==level) {/*printf("TOGGLE")*/;inout=-inout;toggle=inout;} else {toggle=inout;}
			options = availabledoors (level, angle,toggle, g, gc, w, wc, alternatives);

			currlevel=level; /* printf("currlevel assigned = %d\n",currlevel); */
/*			printf("options = %d\n",options); */
/*			for (i=0;i<options && result==0;i++) {printf("alternative[%d](%d,%d)]\n",i,alternatives[i].level,alternatives[i].gate);} */
			for (i=0;i<options && result==0;i++) {
				result = findpath(depth+1,endlevel, currlevel,alternatives[i].level, alternatives[i].gate, inout, g, gc, w, wc,caminho);
/*				printf("DEPTH %d result=%d\n",depth,result); */
			}
		}
	}

	return result;
}

int main(){

int layers, level ;
int doorscount;
int gates[MAXLAYERS][MAXGATES], walls[MAXLAYERS][MAXWALLS];
int gatescount[MAXLAYERS], wallscount[MAXLAYERS];
Way path[MAXMOVES];
Door portas2[100];
int i, j, k, l;
char string[100];
int slot;
int amiin;

/* Reading program inputs */

scanf("%d", &layers);
/*printf("\n");*/

for(k=0; k<(2*layers-1); k++){
	scanf(" %[^\n]%*c", string);

	if(k%2==0){									/*reading gates*/
		i=0; j=0; slot=0; gatescount[k/2]=0;
		while (string[i]!='\0'){
			sscanf(string+slot, "%d", &gates[k/2][j]);
			if (gates[k/2][j]/100>0) {slot=slot+4;}
			else if(gates[k/2][j]/10>0) {slot=slot+3;}
			else slot=slot+2;
			/*printf("gates[%d][%d]=%d\t", k/2, j, gates[k/2][j]);*/
			i=(slot-1);
			j++;
			gatescount[k/2]++;
		}
/*		printf("gatescount[%d] = %d\n",k/2,gatescount[k/2]); */
		/*printf("\n");*/
	}

	else{							           /* reading walls */
		i=0; j=0; slot=0; wallscount[k/2]=0;
		while (string[i]!='\0'){
			sscanf(string+slot, "%d", &walls[k/2][j]);
			if (walls[k/2][j]/100>0) {slot=slot+4;}
			else if(walls[k/2][j]/10>0) {slot=slot+3;}
			else slot=slot+2;
			/*printf("walls[%d][%d]=%d\t", k/2, j, walls[k/2][j]);*/
			i=(slot-1);
			j++;
			wallscount[k/2]++;
		}
/*		printf("wallscount[%d] = %d\n",k/2,wallscount[k/2]); */
		/*printf("\n");*/
	}
}

/*printmaze(layers, gates, gatescount, walls, wallscount);*/

/* till this point we have read the inputs and built the maze */


/*printf("\n**scan of all doors and alternatives**\n"); */   /*only to read on the screen if array of available gates is built correctly */
for(level=0;level<layers-1;level++){
	for(l=0;l<gatescount[level];l++){
	doorscount = availabledoors (level, gates[level][l], 1, gates, gatescount, walls, wallscount, portas2);
	/*printf ("# of doors = %d\n",doorscount);*/
	for (i=0;i<doorscount;i++) {/*printf("portas[%d;(%d,%d)]\n",i,portas2[i].level,portas2[i].gate);*/}
	}
}


/*printf("\n *** RECURSION ***\n");*/

level=0;
amiin = findpath(0,layers-1, -1, level, gates[level][0], 1, gates, gatescount, walls, wallscount, path);
/*printf("\nAm I in? %d\n\n",amiin);*/
/*for (i=0;i<=amiin;i++){ printf("(%d,%c,%d) ",path[i].level,path[i].entrasai,path[i].gate); }*/

/*printf("\n\n");*/                       /* final output in desired format */
for (i=0;i<=amiin;i++){
	printf("%c %d\n",path[i].entrasai,path[i].gate);
}

return 0;
}
