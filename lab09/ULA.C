/*
 ============================================================================
 Name        : ULA.c
 Author      : Roberto
 Version     :
 Copyright   : Free to use, copy, modify
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <lab09.h>


/* Objetivo: Debug function only. Prints PC value and Registers. Not used when final
 */
void print_registers(int pc, int *r){
	int i;
	printf("PC = %d\t ", pc);
	for (i=0; i<=12;i++) {printf("\t%d ",*(r+i));}
	return;
}


/* Objetivo: A replacement for atoi(), because stdlib.h is not permitted
 */
int numstr_to_numint (char *number) {
	int dec, i, length;
	dec=0;
	length = strlen(number);
	if (*number != '-') {	for(i=0; i<length; i++) { dec = dec * 10 + ( *(number+i) - '0' ); } }
	else if (*number == '-') {for(i=1; i<length; i++){ dec = dec * 10 + ( *(number+i) - '0' ); } dec = -dec; }
	return dec;
}

/* Objetivo: função que extrai a próxima palavra da frase de entrada a partir do índice início.
 *
 * Entrada: - a string frase que será analisada
 *          - a string palavra onde vai ser copiada a palavra encontrada
 *          - um inteiro que representa o índice do início da palavra na frase
 * Saida:   devolve -1 se a string s chegou ao fim, caso contrário, devolve o índice de início da próxima palavra
 */
int next_word(char *frase, char *palavra, int inicio)   /*warning: it assumes frase doesn´t start with space, nor has multiple spaces between words */
{
	int i,j;
	for (i=inicio, j=0; (*(frase+i) != ' ') && (*(frase+i) != '\0'); i++, j++)
	{
		*(palavra+j)= *(frase+i);
	}
	*(palavra+j) = '\0';
	if(*(frase+i) =='\0') {return -1;} else return i+1; /*careful because if multiple spaces between words, next word would be a space */
}


/* Objetivo: Converter linha de source code em comandos e parametros separadamente.
 *			"linha" vira "comando[4]", "reg_or_numA[5]", "reg_or_numB[5]", mas os 3 parâmetros retornam escritors em *ptr, *(ptr+1), *(ptr+2)
 * Entrada: - a string linha que será analisada
 *          - pointeiro para onde escrever os 3 parâmetros
 * Saida:   void
 *
 */
void line_to_command (char linha[], int *ptr)
{
	int i, index;
	char comando[4], num[4];
	char reg_or_numA[5], reg_or_numB[5];

	*reg_or_numA = '\0'; /*initialing content for cases line doesn't have all 3 parameters */
	*reg_or_numB = '\0';
	*ptr = -1;
	*(ptr+1) = 0;
	*(ptr+2) = 0;

	index = next_word (linha, comando, 0); /* get 1st */
	index = next_word (linha, reg_or_numA, index); /* get 2nd */
	if (index!=-1) { index = next_word (linha, reg_or_numB, index);} /* get 3rd, if existent */

	/* convert command to 1 to 9 number and store in *ptr; 1st position of 3 integers per command lines */
	if (strcmp(comando, "MOV") == 0 ) {*ptr = 1;}
	if (strcmp(comando, "MOC") == 0 ) {*ptr = 2;}
	if (strcmp(comando, "ADD") == 0 ) {*ptr = 3;}
	if (strcmp(comando, "ADC") == 0 ) {*ptr = 4;}
	if (strcmp(comando, "SUB") == 0 ) {*ptr = 5;}
	if (strcmp(comando, "SUC") == 0 ) {*ptr = 6;}
	if (strcmp(comando, "JMP") == 0 ) {*ptr = 7;}
	if (strcmp(comando, "PTN") == 0 ) {*ptr = 8;}
	if (strcmp(comando, "PTC") == 0 ) {*ptr = 9;}

	/* convert first argument Rn to n and store in *(ptr+1); 2nd position of 3 integers per command lines */
	if (*reg_or_numA == 'R') {
		for (i=0; *(reg_or_numA+i+1) != '\0'; i++) {*(num+i) = *(reg_or_numA+i+1);}
		*(num+i) = '\0';
	/*	*(ptr+1) = atoi(num); */   /* removing atoi() because stdli.h not permitted */
		*(ptr+1) = numstr_to_numint(num);
	}
/*	else *(ptr+1) = atoi(reg_or_numA); */
	else *(ptr+1) = numstr_to_numint(reg_or_numA);

	/* convert second argument Rn (or a number) to n and store in *(ptr+2); 3rd position of 3 integers per command lines */
	if (*reg_or_numB == 'R') {
		for (i=0; *(reg_or_numB+i+1) != '\0'; i++) {*(num+i) = *(reg_or_numB+i+1);}
		*(num+i) = '\0';
	/*	*(ptr+2) = atoi(num); */     /* removing atoi() because stdlib.h not permitted */
		*(ptr+2) = numstr_to_numint(num);
	}
/*	else *(ptr+2) = atoi(reg_or_numB); */
	else *(ptr+2) = numstr_to_numint(reg_or_numB);
	return;
}


int main()
{
	int lines; /* number of lines in input */
	char line[100]; /* string to store input lines one at a time for parsing */
	int comms_and_params[450]; /* list of commands and 2 parameters per command 150x3=450 */
	int *index; /*used to carry addresses of elements of comms_and_params array, just because [ ] not permitted. *index = comms_and_params[0] */
	int commandstotal; /* number of commands in code to be executed */
	int PC;   /* Program Counter has the position in array of commands and parameters, as in comms_and_params[PC] */
	int end_of_code; /*last value of PC to test when program has finished */
	int R[13] = {0,0,0}; /* array of registers. Not using R0 to make it easier to understand*/
	int i,j; /* loop variables */


	scanf("%d\n",&lines);
	printf("%d\n",lines);


/* let´s build a vector with 3 ints per line: Command, param1, param2 */

	PC = 0; /* index of first element of array comms_and_params */
	index=comms_and_params; /*index points to first element of coms_and_params */
	for (i=0,j=0;i<lines; i++,j++){
		scanf("%[^\n]%*c",line);
		if (*line=='#') {j--;printf("comment line: %d - %s\n", i, line);}
		else {line_to_command (line,(index+PC)); PC=PC+3; printf ("linha #%d - %s \n", i, line);}
	}
	commandstotal = j;
	printf("total command lines = %d\n",commandstotal);

	for (i=0,index=comms_and_params;i<commandstotal;i++, index=index+3) {
		printf ("command #%d \t%d %d %d\n",i, *index, *(index+1), *(index+2));
	}



/* now let´s run the code from start to finish */

	PC = 0; /* PC now has index of first element of comms_and_params to begin*/
	end_of_code = 3*(commandstotal-1); /*this is the index for last command line in the code (there are up to 2 parameters still after that) */
	index=comms_and_params; /* initializing index to point to comm_and_params[0] */

/*	printf("PC = %d\t end_of_code is when PC = %d\n",PC, end_of_code); */
/*	printf("\t\tR0\tR1\tR2\tR3\tR4\tR5\tR6\tR7\tR8\tR9\tR10\tR11\tR12\n"); */
/*	print_registers(PC,R); */

	do {							/* main program loop */
/*		print_registers(PC,R); */
		switch (*(index+PC)) {
				case 1: /* MOV */
						mov(R+*(index+PC+1),R+*(index+PC+2), &PC);
						break;
				case 2: /* MOC */
						moc(R+*(index+PC+1),*(index+PC+2), &PC);
						break;
				case 3: /* ADD */
						add(R+*(index+PC+1),R+*(index+PC+2), &PC);
						break;
				case 4: /* ADC */
						adc(R+*(index+PC+1),*(index+PC+2), &PC);
						break;
				case 5: /* SUB */
						sub(R+*(index+PC+1),R+*(index+PC+2), &PC);
						break;
				case 6: /* SUC */
						suc(R+*(index+PC+1),*(index+PC+2), &PC);
						break;
				case 7: /* JMP */
						jmp(R+*(index+PC+1),*(index+PC+2), &PC);
						break;
				case 8: /* PTN */
						ptn(*(R+*(index+PC+1)),&PC);
						break;
				case 9: /* PTC */
						ptc(*(R+*(index+PC+1)),&PC);
						break;
		}
/*			printf("\tPC = %d\n", PC); */
	} while (PC<=end_of_code);

	return 0;
}


void mov(int *rd, int *ro, int *pc) {
	*rd = *ro;
	*pc = *pc +3;
}

void moc(int *rd, int n, int *pc) {
	*rd = n;
	*pc = *pc +3;
}

void add(int *rd, int *ro, int *pc){
	*rd = *rd + *ro;
	*pc = *pc + 3;
}

void adc(int *rd, int n, int *pc){
	*rd = *rd + n;
	*pc = *pc +3;
}

void sub(int *rd, int *ro, int *pc){
	*rd = *rd - *ro;
	*pc = *pc + 3;
}

void suc(int *rd, int n, int *pc){
	*rd = *rd - n;
	*pc = *pc +3;
}

void jmp(int *ro, int n, int *pc){
	if (*ro>=0){*pc=*pc+3*n; return;}
	else *pc=*pc+3;
}

void ptn(int valor, int *pc){
	printf ("%d ", valor);
	*pc = *pc+3;
}

void ptc(int valor, int *pc){
	printf ("%c", valor);
	*pc = *pc+3;
}

