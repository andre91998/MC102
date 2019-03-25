 /* MC102 Algoritmos e Programa��o de Computadores
  * Laborat�rio 09: A entrada do meu programa � um programa?
  * Arquivo lab09.h
  *
  * Todas as fun��es aqui declaradas DEVEM ser implementadas
  * Voc� pode implementar outras fun��es se desejar
  *
  * As MACROS definidas s�o apenas sugest�es.
 */


/* Define as instru��es poss�veis. Voc� pode armazen�-las da seguinte forma:
 * char nome_da_sua_variavel[N_INSTRUCOES][4] = INSTRUCOES;
 */
#define INSTRUCOES {"MOV","MOC","ADD","ADC","SUB","SUC","JMP","PTN","PTC"}
/* N�mero de instru��es definidas na linguagem MCASSEMBLY102 */
#define N_INSTRUCOES 9
/* N�mero m�ximo de instru��es que um programa pode conter */
#define MAX_PROGRAMA 150
/* N�mero de registradores dispon�veis no computador MC102 */
#define N_REGISTRADORES 12


/* Implementa instru��o MOV
 * Recebe dois apontadores para registradores e um apontador para o Program Counter
 * N�o retorna nada
 */
void mov(int *rd, int *ro, int *pc);

/* Implementa instru��o MOC
 * Recebe um apontador para um registrador, um inteiro n e um apontador para o Program Counter
 * N�o retorna nada
 */


void moc(int *rd, int n, int *pc);

/* Implementa instru��o ADD
 * Recebe dois apontadores para registradores e um apontador para o Program Counter
 * N�o retorna nada
 */
void add(int *rd, int *ro, int *pc);

/* Implementa instru��o ADC
 * Recebe um apontador para um registrador, um inteiro n e um apontador para o Program Counter
 * N�o retorna nada
 */
void adc(int *rd, int n, int *pc);

/* Implementa instru��o SUB
 * Recebe dois apontadores para registradores e um apontador para o Program Counter
 * N�o retorna nada
 */
void sub(int *rd, int *ro, int *pc);

/* Implementa instru��o SUC
 * Recebe um apontador para um registrador, um inteiro n e um apontador para o Program Counter
 * N�o retorna nada
 */
void suc(int *rd, int n, int *pc);

/* Implementa instru��o JMP
 * Recebe um apontador para um registrador, um inteiro n e um apontador para o Program Counter
 * N�o retorna nada
 */
void jmp(int *ro, int n, int *pc);

/* Implementa instru��o PTN
 * Recebe um inteiro valor e um apontador para o Program Counter
 * N�o retorna nada
 */
void ptn(int valor, int *pc);

/* Implementa instru��o PTC
 * Recebe um inteiro valor e um apontador para o Program Counter
 * N�o retorna nada
 */
void ptc(int valor, int *pc);
