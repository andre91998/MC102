/*
lab 00 
mc102 
andre medeiros 
ra194060
*/

/*entradas: dois numeros*/
/*saídas: soma dos dois numeros*/

#include <stdio.h>
int main (int argc, char* argv[])
{
    int number1, number2, answer; /*declare variables*/ 
    printf("Digite os dois numeros que deseja somar"); /*command to enter two numbers*/
    scanf("%d %d", &number1, &number2); /*scan variables entered*/
    answer = number1 + number2; /*update value of "answer"*/
    printf("%d + %d = %d\n", number1, number2, answer); /*print the operation and result*/

    return 0;

}



