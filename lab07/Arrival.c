/*
 ============================================================================
 Name        : Arrival.c
 Author      : Roberto
 Version     :
 Copyright   : Free to use, copy, modify
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <lab07.h>

#define MAX_FRASES 50
#define MAX_PALAVRAS 250
#define MAX_BUSCAS 10

/*
Uma palavra tem no máximo 20 caracteres.
Uma frase tem no máximo 250 caracteres.
Um texto de entrada tem no máximo 50 frases e 250 palavras.
Palavras de busca <= 10
 */



/* Objetivo; verificar se uma palavra de entrada está presente em vetor de palavras
 *
 * Entrada: string a ser buscado
 * Saida: Se presente retorna quantas vezes presente; se ausente retorna 0
 */
int ocorrencias(char frase[], char palavra[])
{
	int estah;
	char word[20];
	estah = 0;
	int index = 0;
	while (index != -1)
	{
	index = proxima_palavra(frase, word, index) ;
	if (strcmp (palavra, word)==0) {estah++;}
	}
	return estah;
}

int verifica_marcador(char marcVetor[][TAM_MARCADORES], char palavra[]);
int proxima_palavra(char frase[], char palavra[], int inicio);

int main()
{
	char palavra[21]; /* variable to hold words temporarily for manipulation, using in loops, etc */
	char frase[251]; /* same as above, but for entire sentences */
	char sentences[MAX_FRASES][MAX_PALAVRAS]; /*array of sentences already numbered 0..n small caps, with special characters removed */
	char markers[N_MARCADORES][TAM_MARCADORES] = MARCADORES; /* fixed array of 11 temporal markers defined in .h file */
	int vetorocorrencias[MAX_FRASES][MAX_PALAVRAS]; /* for each sentence i it goes from 0...n unique words saying 1 if present 0 if absent */
	char searchwords[9][21]; /* words to look for in the sentences */
	char uniquewords[250][20]; /* array of all words without repetition */
	int uniquewordstotal; /*length of above */
	int uniquewordsoccur[250]; /*how many times each word occurs in the text - not used */
	int uniquewordspresence[250];  /*in how many sentences the word occurs */
	int buscaresult_words[MAX_BUSCAS][MAX_FRASES]; /*for each  search word, which sentences they occur or not */
	int buscaresult_markers[MAX_BUSCAS][N_MARCADORES]; /* for each search-word and marker pair, amount of sentences they occur together */
	int totalocor_searchwords[MAX_BUSCAS] = {0,0,0,0,0,0,0,0,0,0};  /* in how many sentences each search word occurs */
	int esta, none; /*true or false type variables */
	int next_index; /* variable to help get word by word from sentences */
	int ratio; /* used for % answer */
	int quantifrases, quantibuscas; /*inputs */
	int i,j,k; /*loop variables */


/* first lets read the inputs and store them after using minusculas()*/

	scanf("%d\n",&quantifrases);
	for (i=0;i<quantifrases;i++)
	{
		fgets(frase,251,stdin);
		minusculas(frase);
		strcpy(sentences[i],frase);
		printf("A frase digitada foi: %s\n", sentences[i]);
	}
	scanf("%d\n",&quantibuscas);
	for (i=0;i<quantibuscas;i++)
	{
		fgets(palavra,21,stdin);
		minusculas(palavra);
		strcpy(searchwords[i], palavra);
		printf("Buscar: %s\n", searchwords[i]);
	}


/* loop to build the vector with the unique words of all sentences */

	j=0;
	for (i=0;i<quantifrases;i++)
	{
		next_index=0;
		while (next_index != -1)
		{
			next_index = proxima_palavra(sentences[i], palavra, next_index) ;

			esta=0;
			for (k=0; k<j;k++)
			{
				if (strcmp(uniquewords[k],palavra) == 0) {esta=1; uniquewordsoccur[k]++; k=j;} else {esta=0;}
			}
			if (esta==0)
			{
				strcpy(uniquewords[j], palavra);
				uniquewordsoccur[j]=1;
	/*			printf("proxima palavra = %s  ", palavra); printf("test = %d  ",next_index); printf("unique word %d = %s\n", j, uniquewords[j]); */
			}
			else {j--;}
			j++;
		}
	}
	uniquewordstotal = j; /* it means it goes from 0 until j-1 */


/* using function verifica_marcador for no reason */
	for (i=0;i<uniquewordstotal; i++) { printf ("%s temporal? #%d\n",uniquewords[i],verifica_marcador(markers, uniquewords[i]));	}


/* build vetores de ocorrencia */ /* not used */
	for (i=0; i<quantifrases; i++)
	{
		for (j=0; j<uniquewordstotal; j++)
		{
			vetorocorrencias[i][j] = 0;
			vetorocorrencias[i][j]= ocorrencias(sentences[i],uniquewords[j]);
		}
	}
	printf("vetor de ocorrencias\n");
	for (i=0; i<quantifrases; i++) { for (j=0; j<uniquewordstotal; j++) { printf("%d ", vetorocorrencias[i][j]);} printf("\n"); }/*just to view vetor de ocorrencias */



/* loop of search words */
	for (i=0;i<quantibuscas;i++)
	{
		for (j=0;j<quantifrases;j++)
		{
			buscaresult_words[i][j] = ocorrencias(sentences[j], searchwords[i]); /* counts actual amount of occurrences per sentence */
	/*		if (ocorrencias(sentences[j], searchwords[i])>0) {buscaresult_words[i][j]=1;} else {buscaresult_words[i][j]=0;}   counts only once per sentence */
			for (k=0; k<N_MARCADORES; k++)
			{
				if(buscaresult_words[i][j]>0) {buscaresult_markers[i][k] = buscaresult_markers[i][k]+ ocorrencias(sentences[j],markers[k]);}
			}
		}
	}

	for (i=0;i<quantibuscas;i++) { for (j=0;j<quantifrases;j++) { printf("busca #%d: %s na frase #%d - buscaresult_words[%d][%d] = %d\n",i,searchwords[i],j, i, j, buscaresult_words[i][j]);} }
	for (i=0;i<quantibuscas;i++) { for (j=0;j<N_MARCADORES;j++) { printf("busca #%d: %s com marcador #%d: %s - buscaresult_markers[%d][%d] = %d\n",i,searchwords[i],j, markers[j], i, j, buscaresult_markers[i][j]);} }

	for (i=0;i<quantibuscas;i++)
	{
		for (j=0;j<quantifrases;j++)
		{
			if (buscaresult_words[i][j]>0) {totalocor_searchwords[i]++;}
		}
		printf ("busca: %s aparece em %d frases\n", searchwords[i], totalocor_searchwords[i]);
	}

/* First part of the output */
	printf("\n");

	for (i=0;i<quantibuscas;i++)
		{
			none=1;
			for (j=0;j<N_MARCADORES;j++)
			{
				if (buscaresult_markers[i][j]>0)
				{
					none=0;
					ratio = (100*buscaresult_markers[i][j])/totalocor_searchwords[i];
					printf ("<%s> se relaciona com <%s> em %d %% das ocorrencias.\n", searchwords[i], markers[j], ratio);
				}
			}
			if (none==1) {printf("<%s> nao se relacionou com nenhum marcador temporal.\n", searchwords[i]);}
		}

/* Second part of the output */
/*	printf ("%d unique words:\n",uniquewordstotal); */

	for (i=0; i<uniquewordstotal; i++)
	{
		uniquewordspresence[i]=0;
		for (j=0;j<quantifrases;j++)
		{
			{
				if (ocorrencias(sentences[j], uniquewords[i])>0)
				{
					uniquewordspresence[i]++;
				}
			}
		}
	}

	for (i=0; i<uniquewordstotal; i++) {printf("%s ",uniquewords[i]); }     printf("\n");
	for (i=0; i<uniquewordstotal; i++) {printf("%d ",uniquewordspresence[i]);} printf("\n");





return 0;

}


