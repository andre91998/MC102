/*  Laborat�rio 07: Hip�tese de Sapir�Whorf
 *  Arquivo de Cabe�alho: lab07.h
 *  Descri��o:   Este arquivo cont�m a fun��o para transformar uma string em letras min�sculas e o cabe�alho das fun��es
 *               a serem implementadas neste laborat�rio. Cada fun��o cont�m uma breve descri��o sobre o seu objetivo,
 *               a sa�da esperada e uma pequena explica��o dos par�metros de entrada.
 */


/*Define os marcadores temporais. Voce pode armazenar os marcadores da seguinte forma:
  char nome_da_sua_variavel[N_MARCADORES][TAM_MARCADORES] = MARCADORES;
*/
#define MARCADORES {"ontem", "hoje", "amanha", "agora", "logo", "cedo", "tarde", "breve", "nunca", "sempre", "jamais"}
/*Define tamanho m�ximo de um marcador temporal*/
#define TAM_MARCADORES 7
/*Define o n�mero de marcadores temporais*/
#define N_MARCADORES 11


/* Fun��o fornecida para o laborat�rio. */

/*  Objetivo: fun��o que remove caracteres especiais e transforma uma string em min�sculas.
 *
 *  Entrada:  string s que sera processada
 *  Saida:    string de entrada s, no qual os caracteres foram transformados para letras min�sculas
 */
void minusculas(char s[]){
    int i, j;
	for (i = 0, j = 0; s[i] != '\0'; i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') s[j++] = s[i]-'A'+'a';
		else if ((s[i] >= 'a' && s[i] <= 'z') || s[i] == ' ') s[j++] = s[i];
	}
	s[j] = '\0';
}



/* Fun��es a serem implementadas */

/* Objetivo: fun��o que extrai a pr�xima palavra da frase de entrada a partir do �ndice in�cio.
 *
 * Entrada: - a string frase que ser� analisada
 *          - a string palavra onde vai ser copiada a palavra encontrada
 *          - um inteiro que representa o �ndice do in�cio da palavra na frase
 * Saida:   devolve -1 se a string s chegou ao fim, caso contr�rio, devolve o �ndice de in�cio da pr�xima palavra
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


/* Objetivo: verifica se palavra de entrada � um marcador temporal.
 *
 * Entrada: - recebe a matriz de marcadores temporais marcVetor;
 *          - e a palavra a ser analisada palavra.
 * Saida:   Se a palavra for um marcador, devolve o �ndice correspondente em marcVetor, sen�o devolve -1
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


