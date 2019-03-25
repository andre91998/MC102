/*
==============================================================
Author: André Barros de Medeiros
RA: 194060
Title: A entrada do meu programa é um programa?
Date: 11/05/2017
Copyright: free to use and modify
==============================================================
*/

#include <stdio.h>
#include <string.h>
#include "lab09.h"

#define REGISTERS 13
#define MAXINSTR 150

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
int str_to_int (char *number) {
	int dec, i, length;
	dec=0;
	length = strlen(number);
	if (*number != '-') {	for(i=0; i<length; i++) { dec = dec * 10 + ( *(number+i) - '0' ); } }
	else if (*number == '-') {for(i=1; i<length; i++){ dec = dec * 10 + ( *(number+i) - '0' ); } dec = 0-(dec); }
	return dec;
}


/* Objetivo: função que extrai a próxima palavra da frase de entrada a partir do índice início.
 *
 * Entrada: - a string frase que será analisada
 *          - a string palavra onde vai ser copiada a palavra encontrada
 *          - um inteiro que representa o índice do início da palavra na frase
 * Saida:   devolve -1 se a string s chegou ao fim, caso contrário, devolve o índice de início da próxima palavra
 */
int proxima_palavra(char *frase, char *palavra, int inicio)
{
	int i,j;
	while ((frase[inicio]==' ') && (frase[inicio] != '\0')) {inicio++;} /* in case there are multiple spaces between words */

	for (i=inicio, j=0; (frase[i] != ' ') && (frase[i] != '\0'); i++, j++)
	{
		palavra[j]=frase[i];
	}
	palavra[j] = '\0';
	if(frase[i]=='\0') {return -1;} else return i+1; /*careful because if multiple spaces between words, next word would be a space */
}

int argtoint (char *palavra) {
	int result;
	char arg[10];
	int i;
	for(i=0; *(palavra+i)!='\0'; i++){
		if(*palavra=='R') {*(arg+i)= *(palavra+i+1);}
		if(*palavra!='R') {*(arg+i)= *(palavra+i);}
	}
	*(arg+i)='\0';
	/*result=atoi(arg);*/
	result = str_to_int(arg);
	return result; }

int com2int (char *palavra) {
	int result;
	result=0;
	if (strcmp(palavra, "MOV") == 0) {result=1;}
	if (strcmp(palavra, "MOC") == 0) {result=2;}
	if (strcmp(palavra, "ADD") == 0) {result=3;}
	if (strcmp(palavra, "ADC") == 0) {result=4;}
	if (strcmp(palavra, "SUB") == 0) {result=5;}
	if (strcmp(palavra, "SUC") == 0) {result=6;}
	if (strcmp(palavra, "JMP") == 0) {result=7;}
	if (strcmp(palavra, "PTN") == 0) {result=8;}
	if (strcmp(palavra, "PTC") == 0) {result=9;}
	return result; }
	
/* Implementa instrução MOV
 * Recebe dois apontadores para registradores e um apontador para o Program Counter
 * Não retorna nada
 */
void mov(int *rd, int *ro, int *pc){
	*rd=*ro;
	*pc=(*pc)+1;}

/* Implementa instrução MOC
 * Recebe um apontador para um registrador, um inteiro n e um apontador para o Program Counter
 * Não retorna nada
 */

void moc(int *rd, int n, int *pc){
	*rd=n;
	*pc=(*pc)+1;}

/* Implementa instrução ADD
 * Recebe dois apontadores para registradores e um apontador para o Program Counter
 * Não retorna nada
 */
void add(int *rd, int *ro, int *pc){
	*rd=(*rd)+(*ro);
	*pc=(*pc)+1;}

/* Implementa instrução ADC
 * Recebe um apontador para um registrador, um inteiro n e um apontador para o Program Counter
 * Não retorna nada
 */
void adc(int *rd, int n, int *pc){
	*rd=(*rd)+n;
	*pc=(*pc)+1;}

/* Implementa instrução SUB
 * Recebe dois apontadores para registradores e um apontador para o Program Counter
 * Não retorna nada
 */
void sub(int *rd, int *ro, int *pc){
	*rd=(*rd)-(*ro);
	*pc=(*pc)+1;}

/* Implementa instrução SUC
 * Recebe um apontador para um registrador, um inteiro n e um apontador para o Program Counter
 * Não retorna nada
 */
void suc(int *rd, int n, int *pc){
	*rd=(*rd)-n;
	*pc=(*pc)+1;}

/* Implementa instrução JMP
 * Recebe um apontador para um registrador, um inteiro n e um apontador para o Program Counter
 * Não retorna nada
 */
void jmp(int *ro, int n, int *pc){
	if(*ro>=0){*pc=(*pc)+n;}
	else {*pc=(*pc)+1;} }

/* Implementa instrução PTN
 * Recebe um inteiro valor e um apontador para o Program Counter
 * Não retorna nada
 */
void ptn(int valor, int *pc){
	printf("%d ", valor);
	*pc=(*pc)+1;}

/* Implementa instrução PTC
 * Recebe um inteiro valor e um apontador para o Program Counter
 * Não retorna nada
 */
void ptc(int valor, int *pc){
	printf("%c", valor);
	*pc=(*pc)+1;}




int main() {

int lines;
int R[REGISTERS]={0,0,0};
int i, index;
int j;
char string[50], word[10];
int commandint[MAXINSTR], arg1int[MAXINSTR], arg2int[MAXINSTR];
int PC;
int stop;


scanf ("%d", &lines);

j=0;

for(i=0; i<lines; i++){
	scanf(" %[^\n]%*c", string);
	/*printf("%s\n", string);*/
	index=0;
	if(*string != '#') { 
		index = proxima_palavra(string, word, index);
		/*printf("%s\n", word);*/
		*(commandint+j)=com2int(word);
		index = proxima_palavra(string, word, index);
		*(arg1int+j)=argtoint(word);
		if (index!=-1) {index = proxima_palavra(string, word, index); *(arg2int+j)= argtoint(word);}
		else {*(arg2int+j)=0;}
		j++;
	}
}

/*for(i=0; i<j; i++){	
	printf("%d %d %d %d\n", i, *(commandint+i), *(arg1int+i), *(arg2int+i));}*/

PC=0;
stop=j;

while (PC<stop){
	/*print_registers(PC, R);*/
	switch (*(commandint+PC)){

		case 1: /*MOV*/
			mov(R+*(arg1int+PC), R+*(arg2int+PC), &PC);
			break;

		case 2: /*MOC*/
			moc(R+*(arg1int+PC), *(arg2int+PC), &PC);
			break;

		case 3: /*ADD*/
			add(R+*(arg1int+PC), R+*(arg2int+PC), &PC);
			break;

		case 4: /*ADC*/
			adc(R+*(arg1int+PC), *(arg2int+PC), &PC);
			break;

		case 5: /*SUB*/
			sub(R+*(arg1int+PC), R+*(arg2int+PC), &PC);
			break;

		case 6: /*SUC*/
			suc(R+*(arg1int+PC), *(arg2int+PC), &PC);
			break;

		case 7: /*JMP*/
			jmp(R+*(arg1int+PC), *(arg2int+PC), &PC);
			break;

		case 8: /*PTN*/
			ptn(*(R+*(arg1int+PC)), &PC);
			break;

		case 9: /*PTC*/
			ptc(*(R+*(arg1int+PC)), &PC);
			break;

		}

if(PC>=j) {printf("\n");}
	}

return 0;
}
