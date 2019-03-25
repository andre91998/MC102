/*lab01
Paleocontato
André Barros de Medeiros
RA 194060

Obs: bn é a base da sequência de símbolos
	 cn é o diacrítico da sequência de símbolos
*/

#include <stdio.h>

int main(int argc, char* argv[]) 

{
/*Part 1*/
	int x1, x2, x3, x4, x5, x6, x7, x8; /*declare x-vector variables*/
	int b1, b2, b3, b4, b5, b6, b7, b8; /*declare b-vector variables*/
	int c1, c2, c3, c4, c5, c6, c7, c8; /*declare c-vector variables*/
	int C; /*declare C variable*/
	scanf("%d %d %d %d %d %d %d %d", &b1, &b2, &b3, &b4, &b5, &b6, &b7, &b8); /*scan bn vector*/
	scanf("%d %d %d %d %d %d %d %d", &c1, &c2, &c3, &c4, &c5, &c6, &c7, &c8); /*scan cn vector*/

/*Part 2*/
	
	/*substitute xn vectorbn vector*/

	x1 = b1;
	x2 = b2;
	x3 = b3;
	x4 = b4;
	x5 = b5;
	x6 = b6;
	x7 = b7;
	x8 = b8;
	C = c1*c2*c3*c4*c5*c6*c7*c8;

	if ((c4 != 2) && (c4 != 9)) /*translate condition1*/
		{
		x1 = x1 + 3;
		x2 = x2 + 3;
		x3 = x3 + 3;
		x4 = x4 + 3;
		x5 = x5 + 3;
		x6 = x6 + 3;
		x7 = x7 + 3;
		x8 = x8 + 3;
		}

	if ((11 <= c1) && (c1 <= 42)) /*translate condition2*/
		{
		x7 = x7 + 8;
		x8 = x8 + 7;
		}

	if ((c1 % 2 != 0) &&   /*translate condition3*/
		(c2 % 2 != 0) &&
		(c3 % 2 != 0) &&
		(c4 % 2 != 0) &&
		(c5 % 2 != 0) &&
		(c6 % 2 != 0) &&
		(c7 % 2 != 0) &&
		(c8 % 2 != 0))
		{
		x1 = x1 + (2 * c5);
		} 

	if ((c3 < 20 && c6 >= 20) || (c3 >= 20 && c6 < 20)) /*translate condition4*/
		{
		x4 = x4 + 6;
		x5 = x5 + 6;
		}

	if (c8 != 3 && c8 >= c7) /*translate condition5*/
		{
		x3 = x3 + c2;
		}

	if ((C % 5 == 0 && C % 10 != 0) || (C == 30)) /*translate condition6*/
		{
		x6 = x6 + 1;
		}

	if ((c2 == c8) || (c3 == c7)) /*translate condition7*/
		{
		x6 = x6 + 1;
		}
		

/*printf("%d %d %d %d %d %d %d %d\n", x1, x2, x3, x4, x5, x6, x7, x8); [test printf]*/


/*Part 3*/

	x1 = x1 + 64; /*Ajust variables to ASCII table*/
	x2 = x2 + 64;
	x3 = x3 + 64;
	x4 = x4 + 64;
	x5 = x5 + 64;
	x6 = x6 + 64;		
	x7 = x7 + 64;			
	x8 = x8 + 64;

	if (x1 == 91) /*Correct space contradiction acording to ASCII table*/ 
		{
		x1 = 32;
		}

	if (x2 == 91) /*Correct space contradiction acording to ASCII table*/ 
		{
		x2 = 32;
		}

	if (x3 == 91) /*Correct space contradiction acording to ASCII table*/ 
		{
		x3 = 32;
		}
	
	if (x4 == 91) /*Correct space contradiction acording to ASCII table*/ 
		{
		x4 = 32;
		}

	if (x5 == 91) /*Correct space contradiction acording to ASCII table*/ 
		{
		x5 = 32;
		}

	if (x6 == 91) /*Correct space contradiction acording to ASCII table*/ 
		{
		x6 = 32;
		}

	if (x7 == 91) /*Correct space contradiction acording to ASCII table*/ 
		{
		x7 = 32;
		}

	if (x8 == 91) /*Correct space contradiction acording to ASCII table*/ 
		{
		x8 = 32;
		}

/*printf("%d %d %d %d %d %d %d %d\n", x1, x2, x3, x4, x5, x6, x7, x8); */

	/*Print, but dont print numbers outside range*/

	if ((x1 >= 65 && x1 <= 90) || (x1 == 32))
		{
		printf("%c", x1);
		}

	if ((x2 >= 65 && x2 <= 90) || (x2 == 32))
		{
		printf("%c", x2);
		}

	if ((x3 >= 65 && x3 <= 90) || (x3 == 32))
		{
		printf("%c", x3);
		}

	if ((x4 >= 65 && x4 <= 90) || (x4 == 32))
		{
		printf("%c", x4);
		}

	if ((x5 >= 65 && x5 <= 90) || (x5 == 32))
		{
		printf("%c", x5);
		}

	if ((x6 >= 65 && x6 <= 90) || (x6 == 32))
		{
		printf("%c", x6);
		}

	if ((x7 >= 65 && x7 <= 90) || (x7 == 32))
		{
		printf("%c", x7);
		}

	if ((x8 >= 65 && x8 <= 90) || (x8 == 32))
		{
		printf("%c", x8);
		}

	printf ("\n");

	return 0;

}


