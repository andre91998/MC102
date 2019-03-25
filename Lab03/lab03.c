/* André Barros de Medeiros
Ra 194060
Mc102
Joisas Siderais
04/09/17
*/

#include <stdio.h>
int main ()

{ 
unsigned long int max = 4000000000U; /*defines highest possible value for a bill*/
unsigned long int s2; /*second smallest value in the safe ; input*/
unsigned long int u1; /*smallest value absent in the universe ; input*/
unsigned long int u2; /*second smallest value absent in the universe ; input*/
unsigned long int v0; /*Payment's value in galactic currency ; input*/
unsigned long int q; /*Geometric progressions's increment*/
unsigned long int pg, pgprev; /*pgprevprev; Current value for arithmetic and geometric progression, respectively*/
unsigned long int n1; /*number of bills that will be used*/

scanf("%lu %lu %lu %lu", &s2, &u1, &u2, &v0);

/*part 1 ; values present in the safe*/

q = s2;

findbill:

pg = 1;
pgprev = pg;

while (pg<=v0 && pg<=max && pg>=pgprev)
	{
	/*pgprevprev = pgprev;*/
	pgprev = pg;
	pg = pg*q;
	}
pg = pgprev;



teste:

while (v0 > 0)
{
	/*printf("%lu %lu %lu", v0, pg, pgprev);*/
	/*scanf("%lu", &xx);*/
	if ((pg == s2) && (pg<=v0))
		{
		n1 = v0 / pg;
		printf ("%lu %lu\n", n1, pg);
		v0 = v0 - pg*n1;
		goto findbill;
		}

	else if ( (pg-u1)%(u2-u1) != 0 )
		{
		n1 = v0 / pg;
		printf ("%lu %lu\n", n1, pg);
		v0 = v0 - pg*n1;
		goto findbill;
		}

	else if ((pg == s2) && (pg>v0))
		{
		printf ("%lu 1", v0);
		}

	else
		{
		pg = pg/q;
		goto teste;
		}
}

return 0;

}




