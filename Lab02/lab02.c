/* André Barros de Medeiros
ra 194060
Lab 02
Esplorador de Estrelas*/

#include <stdio.h>

int main(int argc, char* argv[]) 

{

int A, B, C, D, E, F, G, H, I, J, K; /*declare time variables*/
int t, t0, t1, t2, t3, t4, t5, t6, t7, t8; /*declare total time variables*/
int minimum;


scanf("%d %d %d %d %d %d %d %d %d %d %d", &A, &B, &C, &D, &E, &F, &G, &H, &I, &J, &K); /*scan time variables*/

t0 = A + D + G + K; /*Setting total times for all possible routes to destination*/
t1 = A + D + F + J;
t2 = A + D + F + I + K;
t3 = A + E + J;
t4 = A + E + I + K;
t5 = B + F + J;
t6 = B + F + I + K;
t7 = B + G + K;
t8 = C + H + K;

minimum = t0;

if (minimum >= t1)  /*Determine which total time is the the smallest*/
	minimum = t1;

if (minimum >= t2)
	minimum = t2;

if (minimum >= t3)
	minimum = t3;

if (minimum >= t4)
	minimum = t4;

if (minimum >= t5)
	minimum = t5;

if (minimum >= t6)
	minimum = t6;

if (minimum >= t7)
	minimum = t7;

if (minimum >= t8)
	minimum = t8;





if (A<B && A<C) /* if A is the shortest trip, take A) */
	{
	t = A;
	goto rukh;
	}

if (B<A && B<C) /* if B is the shortest trip, take B */
	{
	t = B;
	goto sadr;
	}

if (C<A && C<B) /*if C is the shortest trip, take C */
	{
	t = C;
	goto gienah;
	}


			rukh: /*marks first of three planet possibilities*/

if (E<D)
	{ 
	t = t + E;
	goto vega;
	}

if (D<E)
	{
	t = t + D;
	goto sadr;
	}

			sadr: /*marks second of three planet possiblilities*/

if (G<F)
	{
	t = t + G;
	goto albireo;
	}

if (F<G)
	{
	t = t + F;
	goto vega;
	}
			gienah: /*marks third of three planet possibilities*/

t = t + H;
goto albireo;

			vega: /*marks first of two second level planet possibilities*/

if (I<J)
	{
	t = t + I;
	goto albireo;
	}

if (J<I)
	{
	t = t + J;
	goto altair;
	}

			albireo: /*marks second of two second level planet possibilities*/

t = t + K;
goto altair;

			altair: /*print fase*/

if (t % 6 == 0)
	printf ("0\n");
	
else 
	printf ("%d\n", minimum);


return 0;

}






			





