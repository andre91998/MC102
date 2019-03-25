/*
==================================================================
Name: André Barros de Medeiros
ID:194060
Date:21/10/2017
Copyright: --
Description: Hipótese de Sapir-Whorf
==================================================================
*/

#include <stdio.h>
#include <string.h>
#include "lab07.h"


/* Objetivo: verifica se palavra de entrada é um marcador temporal.
 *
 * Entrada: - recebe a matriz de marcadores temporais marcVetor;
 *          - e a palavra a ser analisada palavra.
 * Saida:   Se a palavra for um marcador, devolve o índice correspondente em marcVetor, senão devolve -1
 */
int verifica_marcador(char marcVetor[][TAM_MARCADORES], char palavra[])
{
	int i, index;
	index=-1;
	for (i=0;i<N_MARCADORES;i++)
	{
		if (strcmp (marcVetor[i], palavra)==0) {index = i;}
	}
	return index;
}


/* Objetivo: função que extrai a próxima palavra da frase de entrada a partir do índice início.
 *
 * Entrada: - a string frase que será analisada
 *          - a string palavra onde vai ser copiada a palavra encontrada
 *          - um inteiro que representa o índice do início da palavra na frase
 * Saida:   devolve -1 se a string s chegou ao fim, caso contrário, devolve o índice de início da próxima palavra
 */
int proxima_palavra(char frase[], char palavra[], int inicio)
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

/* Objetivo; verificar se uma palavra de entrada está presente em vetor de palavras
 *
 * Entrada: string a ser buscado
 * Saida: Se presente retorna quantas vezes presente; se ausente retorna 0
 */
int ocorrencias(char frase[], char palavra[])
{
	/*int proxima_palavra(char frase[], char palavra[], int inicio);*/
	int estah;
	char word[21];
	int index = 0;
	estah = 0;
	while (index != -1)
	{
	index = proxima_palavra(frase, word, index) ;
	if (strcmp (palavra, word)==0) {estah++;}
	}
	return estah;
}



int main(){

/*void minusculas(char s[]);
int proxima_palavra(char frase[], char palavra[], int inicio);
int verifica_marcador(char marcVetor[][TAM_MARCADORES], char palavra[]);
int ocorrencias(char frase[], char palavra[]);*/

int numbfrases, numbwords; /*entries*/
int i, j, k; /*for variable*/
int ratio;
char frase[251];
char allfrases[50][251];
char word[21];
char searchwords[10][21]; /*search words*/
char uniquewords[250][21];
int numbuniquewords[250];
int index;
int yes, notfound; /*yes=1 true, yes=0 false*/
int iterations;
int wordsinsentence[10][50], wordsandmarkers[11][50];
char markers[11][7]= MARCADORES;
int total[11];
int vetorocorrencia[50][251];
int markersmax[10];


scanf("%d\n", &numbfrases);
for (i=0; i<numbfrases; i++){
	fgets(frase, 251, stdin);
	minusculas(frase);
	strcpy(allfrases[i], frase);}

scanf("%d\n", &numbwords);
for (i=0; i<numbwords; i++){
	fgets(word, 21, stdin);
	minusculas(word);
	strcpy(searchwords[i], word);}

/*for (i=0; i<numbfrases; i++){printf("frase digitada: %s\n", allfrases[i]);}


for (i=0; i<numbwords; i++){printf("search word:  %s\n", searchwords[i]);}*/

iterations=0;
for (i=0; i<numbfrases; i++){
	index=0;
	while(index!=-1){
		index=proxima_palavra(allfrases[i], word, index);
		yes=0;
		for (j=0; j<iterations; j++){
			/*printf("%s %s\n", uniquewords[j], word);*/
			if (strcmp(uniquewords[j], word)==0){ 
			yes=1; j=iterations;}
			else {yes=0;}
			}
		/*printf("yes= %d\n ", yes);*/
		if(yes==0) {
			strcpy(uniquewords[iterations], word);}
		else {iterations--;}
		iterations++;}
	}

for (i=0; i<iterations; i++){ 
	numbuniquewords[i]=0;
	for(j=0; j<numbfrases; j++){ 
		if(ocorrencias(allfrases[j], uniquewords[i])>0){numbuniquewords[i]++;}
	}
}


for(i=0; i<numbwords; i++){
	for(j=0; j<numbfrases; j++){
		wordsinsentence[i][j]=ocorrencias(allfrases[j], searchwords[i]);
		for(k=0; k<11; k++){
			if(wordsinsentence[i][j]>0) {wordsandmarkers[i][k]=wordsandmarkers[i][k] + ocorrencias(allfrases[j], markers[k]);}
		}
	}
}

/*for(i=0; i<numbwords; i++){ for(j=0; j<numbfrases; j++){ printf("busca #%d: %s na frase %d - wordsinsentence[%d][%d] = %d\n", i, searchwords[i], j, i, j, wordsinsentence[i][j]);}}	

for(i=0; i<numbwords; i++){ for(j=0; j<11; j++){ printf("busca #%d: %s com marcador %d - wordsandmarkers[%d][%d] = %d\n", i, searchwords[i], j, i, j, wordsandmarkers[i][j]);}}*/


for(i=0; i<numbwords; i++){
	for(j=0; j<numbfrases; j++){
		if(wordsinsentence[i][j]>0){total[i]++;}
	}
	/*printf("busca: %s aparece em %d frases \n", searchwords[i], total[i]);*/
}


for (i=0; i<numbfrases; i++){           /*building vetor de ocorrencia for no reason*/
	for(j=0; j<iterations; j++){
		vetorocorrencia[i][j] = ocorrencias(allfrases[i], uniquewords[j]);
	}
}

/*printf("vetor de ocorrencias\n");*/
for (i=0; i<numbfrases; i++){for(j=0; j<iterations; j++){k=vetorocorrencia[i][j];}}

for (i=0; i<iterations; i++){verifica_marcador(markers, uniquewords[i]);} /*chamando funcao for no reason*/

for (i=0; i<numbwords; i++){    
	markersmax[i]=0;      
	for(j=0; j<11; j++){
		if(wordsandmarkers[i][j]>markersmax[i]){markersmax[i]=wordsandmarkers[i][j];}
	}
}
		


for(i=0; i<numbwords; i++){
	notfound=1;
	for(j=0; j<11; j++){
		if((wordsandmarkers[i][j]>0)&&(wordsandmarkers[i][j]==markersmax[i])) {
		notfound=0;
		ratio=(100*wordsandmarkers[i][j])/total[i];
		printf("<%s> se relaciona com <%s> em %d %% das ocorrencias.\n", searchwords[i], markers[j], ratio);}
	}	
	if(notfound==1){printf("<%s> nao se relacionou com nenhum marcador temporal.\n", searchwords[i]);}
}






for(i=0; i<iterations; i++){ printf("%s ", uniquewords[i]);}
printf("\n");
for(i=0; i<iterations; i++){ printf("%d ", numbuniquewords[i]);}
printf("\n");


return 0;
}
























