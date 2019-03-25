/* André Barros de Medeiros
Ra: 194060
Lab 04
Space Invaders
*/

#include <stdio.h>
int main() 

{
int n; /*Size (nxn) of the square "game space"*/
int i1, j1, i2, j2, i3, j3, i4, j4, i5, j5; /*positions (in,jn) of the alien spaceships*/
int ship; /*Horizontal mothership coordinate*/
int i, j, point, kill; /* Control variables*/
int iteration; /*variable to control the number of iterations*/
int posincr; /*determines alien ship movement*/
int shothight, shotrecoil, lowestkill; /*variables for the mothership's shot*/
scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &n, &i1, &j1, &i2, &j2, &i3, &j3, &i4, &j4, &i5, &j5, &ship);

shothight = n;
shotrecoil = n;
lowestkill = 0;


for (iteration=1; iteration<=10; iteration++)
	{
	kill=0;
	for (i=1; i<=n; i++)
		{
		for(j=1; j<=n; j++)
			{
			point=0;
				if (i==i1)
				{
					if (j==j1)
					{
						if(j!=ship)
						{
						printf("* ");
						point=1;
						}
						else if (i>=shothight)
						{
						printf (". ");
						point=1;
						kill++;
						shotrecoil = i + 1;
						j1=101;
						}
						else
						{
						printf("* ");
						point=1;
						}
					}
				}
				if (i==i2)
				{
					if (j==j2)
					{
						if(j!=ship)
						{
						printf("* ");
						point=1;
						}
						else if (i>=shothight)
						{
						printf (". ");
						j2=102;
						point=1;
						kill++;
						shotrecoil = i + 1;
						} 
						else
						{
						printf("* ");
						point=1;
						}
					}	
				}
				if (i==i3)
				{
					if (j==j3)
					{
						if(j!=ship)
						{
						printf("* ");
						point=1;					
						}
						else if (i>=shothight)
						{
						printf (". ");
						point=1;
						j3=103;
						kill++;
						shotrecoil = i + 1;
						}
						else
						{
						printf("* ");
						point=1;
						}
					}
				}
				if (i==i4)
				{
					if (j==j4)
					{
						if(j!=ship)
						{
						printf("* ");	
						point=1;				
						}
						else if (i>=shothight)
						{
						printf (". ");
						point=1;
						j4=104;
						kill++;
						shotrecoil = i + 1;
						}
						else
						{
						printf("* ");
						point=1;
						}
					}
				}
				if (i==i5)
				{
					if (j==j5)
					{
						if(j!=ship)
						{
						printf("* ");
						point=1;
						}
						else if (i>=shothight)
						{
						printf (". ");
						point=1;
						j5=120;
						kill++;
						shotrecoil = i + 1;
						}
						else
						{
						printf("* ");
						point=1;
						}
					}
				}
				if (i==n)
				{
					if (j==ship)
					{
					printf("X ");
					point=1;
					}
					
				}
				if (j==ship && i>=shothight && shothight!=n && i!=n && kill==0 && i>lowestkill)
				{
				printf("| ");
				point=1;
				}
				
		
				if (j==ship && i>=shothight && shothight!=n && i!=n && kill!=0 && i>lowestkill)
				{
					if(i>=shotrecoil)
					{
					printf("| ");
					point=1;
					}
					if(point==0)
					{
					printf(". ");
					}
				}
				if(point==0)
				{
				printf(". ");
				}
				
			}
		printf("\n");
		}

	printf("\n");
	
	if(kill!=0)
	{
	shothight = shotrecoil - 1;
	}
	else
	shothight = shothight - 1;

	posincr = ((((iteration)/2)%2*(-2))+1);/*determines, based on which iteration we are in, the how much to add to the jn variables*/
		
		if ((j1==1 && posincr>0) || (j1==n && posincr<0) || (j1!=1 && j1!=n))
			{
			j1 = j1 + posincr;
			}
		if ((j2==1 && posincr>0) || (j2==n && posincr<0) || (j2!=1 && j2!=n))
			{
			j2 = j2 + posincr;
			}
		if ((j3==1 && posincr>0) || (j3==n && posincr<0) || (j3!=1 && j3!=n))
			{
			j3 = j3 + posincr;
			}
		if ((j4==1 && posincr>0) || (j4==n && posincr<0) || (j4!=1 && j4!=n))
			{
			j4 = j4 + posincr;
			}
		if ((j5==1 && posincr>0) || (j5==n && posincr<0) || (j5!=1 && j5!=n))
			{
			j5 = j5 + posincr;
			}
	
	lowestkill = 0;
		for(i=1; i<n; i++)
		{
		j = ship;
			if((i==i1) && (j==j1) && (i>=shothight))
			{
				if(i>lowestkill)
				lowestkill = i;
			}
			if((i==i2) && (j==j2) && (i>=shothight))
			{
				if(i>lowestkill)
				lowestkill = i;
			}
			if((i==i3) && (j==j3) && (i>=shothight))
			{
				if(i>lowestkill)
				lowestkill = i;
			}
			if((i==i4) && (j==j4) && (i>=shothight))
			{
				if(i>lowestkill)
				lowestkill = i;
			}
			if((i==i5) && (j==j5) && (i>=shothight))
			{
				if(i>lowestkill)
				lowestkill = i;
			}
		}

	}

return 0;
}

