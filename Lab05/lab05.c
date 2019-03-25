/*
==================================================================
Name: André Barros de Medeiros
ID:194060
Date:18/09/2017
Copyright: --
Description: Pareamento de Hipogrifos ; vetores unidimencionais
==================================================================
*/

#include <stdio.h>
int main()

{

int tf, tm; /*Number of female and male steps, respectively*/
int fdir, mdir, fdis, mdis; /*for loop control variables*/
int print, dirok, revok, dirsizeok, revsizeok; /*switch-case t/f variable*/
int fem1[1000], male1[1000], fem2[1000], male2[1000];
int revdir[1000], revsize[1000];
int i;
int sum, crossproduct, mnext, fnext, stepb, shiftm, shiftf;
int upf, upm, downf, downm, leftf, leftm, rightf, rightm, f1, m1, f5, m5, f7, m7, f3, m3;

upf=0; upm=0; downf=0; leftf=0; leftm=0, rightf=0; rightm=0; f1=0; m1=0; f5=0; m5=0; f7=0; m7=0; f3=0; m3=0; shiftm=0; shiftf=0; print=5; dirok=1; revok=1; dirsizeok=1; revsizeok=1;


scanf("%d %d", &tf, &tm);


for(fdir=0; fdir<tf; fdir++) /*scan female movement vectors*/
	{
	fdis=fdir;
	scanf("%d", &fem1[fdir]); /*orientation vector*/
	scanf("%d", &fem2[fdis]); /*size vector*/
	}

for(mdir=0; mdir<tm; mdir++)
	{
	mdis=mdir;
	scanf("%d", &male1[mdir]); /*orientation vector*/
	scanf("%d", &male2[mdis]); /*size vector*/
	}

printf("female directions    "); for(i=0; i<tf; i++) {printf("%d ", fem1[i]);} printf ("\n");
printf("male directions      "); for(i=0; i<tm; i++) {printf("%d ", male1[i]);} printf ("\n");
printf("female lengths       "); for(i=0; i<tf; i++) {printf("%d ", fem2[i]);} printf ("\n");
printf("male lengths         "); for(i=0; i<tm; i++) {printf("%d ", male2[i]);} printf ("\n");

if(tf!=tm)
	{
	dirok=0;
	revok=0; /*print=0 >>> Incompatibilidade total*/
	goto switchcase;
	}

if (male1[0]!=0)
	{ 
	shiftm=male1[0];
	}

if (fem1[0]!=0)
	{ 
	shiftf=fem1[0];
	}

for (mdir=0; mdir<tm; mdir++) /*rotate to fix both trajectories to first direction 0*/
	{
	fdir=mdir;
	male1[mdir]=male1[mdir]-shiftm;
	fem1[fdir]=fem1[fdir]-shiftf;
	if (male1[mdir]<0) { male1[mdir]= male1[mdir] + 8;}
	if (fem1[fdir]<0) { fem1[fdir]= fem1[fdir] + 8;}
	}

printf("female directions    "); for(i=0; i<tf; i++) {printf("%d ", fem1[i]);} printf ("\n");
printf("male directions      "); for(i=0; i<tm; i++) {printf("%d ", male1[i]);} printf ("\n");



for(i=0; i<tm; i++) /*male steps always bigger*/
	{
	if (male2[i]<=fem2[i])
		{
		dirsizeok=0;
		}
	}

for(i=0; i<tf; i++) /*checking start and finish*/
	{
	if (fem1[i]==0)
		{
		upf=upf+fem2[i];
		}
	if (fem1[i]==4)
		{
		downf=downf+fem2[i];
		}
	if (fem1[i]==2)
		{
		rightf=rightf+fem2[i];
		}
	if (fem1[i]==6)
		{
		leftf=leftf+fem2[i];
		}
	if (fem1[i]==1)
		{
		f1= f1+fem2[i];
		}
	if(fem1[i]==5)
		{
		f5=f5+fem2[i];
		}
	if(fem1[i]==3)
		{
		f3=f3+fem2[i];
		}
	if(fem1[i]==7)
		{
		f7=f7+fem2[i];
		}
	}

printf("sum of axi %d %d %d %d %d %d %d %d \n", upf, downf, leftf, rightf, f1, f5, f3, f7);

if ((upf!=downf) || (leftf!=rightf) || (f1!=f5) || (f3!=f7)) /*If starting point isn't the same as the ending point*/
	{
	dirok=0;
	}


for (fdis=0; fdis<tf-1; fdis++)          /*mantain ratio between male and female steps*/
	{
	mdis=fdis;
	if (fem2[fdis]*male2[mdis + 1]!=male2[mdis]*fem2[fdis + 1])
		{
		printf("wrong ratio, i= %d\n", fdis);
		dirsizeok=0;
		}
	}


for (i=0; i<tm; i++)
	{
	if (dirok==1) {if (male1[i]!=fem1[i]) {dirok=0;}}
	}





	
/*---------------------------------------------------------------------------------------------*/



shiftm=0;
shiftf=0;




if (male1[tm-1]!=0)
	{ 
	shiftm=male1[tm-1];
	}

for (mdir=0; mdir<tm; mdir++) /*rotate to fix both trajectories to first direction 0*/
	{
	revdir[mdir]=male1[tm-mdir-1]-shiftm;
	if (revdir[mdir]<0) { revdir[mdir]= revdir[mdir] + 8;}
	}

printf("reverse male directions      "); for(i=0; i<tm; i++) {printf("%d ", revdir[i]);} printf ("\n");

for (mdir=0; mdir<tm; mdir++)
	{
	male1[mdir]=revdir[mdir];
	}




for (i=0; i<tm; i++)
	{
	revsize[i]=male2[tm-i-1];
	}



for (mdir=0; mdir<tm; mdir++)
	{
	male2[mdir]=revsize[mdir];
	}

printf("reverse male size      "); for (i=0; i<tm; i++) {printf("%d ", male2[i]);} printf("\n");


for(i=0; i<tm; i++) /*reverse male steps always bigger*/
	{
	if (male2[i]<=fem2[i])
		{
		revsizeok=0;
		}
	}

for(i=0; i<tf; i++)
	{
	if (fem1[i]==0)
		{
		upf=upf+fem2[i];
		}
	if (fem1[i]==4)
		{
		downf=downf+fem2[i];
		}
	if (fem1[i]==2)
		{
		rightf=rightf+fem2[i];
		}
	if (fem1[i]==6)
		{
		leftf=leftf+fem2[i];
		}
	if (fem1[i]==1)
		{
		f1= f1+fem2[i];
		}
	if(fem1[i]==5)
		{
		f5=f5+fem2[i];
		}
	if(fem1[i]==3)
		{
		f3=f3+fem2[i];
		}
	if(fem1[i]==7)
		{
		f7=f7+fem2[i];
		}
	}
printf("sum of axi %d %d %d %d %d %d %d %d \n", upf, downf, leftf, rightf, f1, f5, f3, f7);


if ((upf!=downf) || (leftf!=rightf) || (f1!=f5) || (f3!=f7)) /*If starting point isn't the same as the ending point*/
	{
	revok=0;
	}


for (fdis=0; fdis<tf-1; fdis++)          /*mantain ratio between male and female steps*/
	{
	mdis=fdis;
	if (fem2[fdis]*male2[mdis+1]!=male2[mdis]*fem2[fdis+1])
		{
		revsizeok=0;
		}
	}

for (i=0; i<tm; i++)
	{
	if (revok==1) {if (revdir[i]!=fem1[i]) {revok=0;}}
	}

printf("%d %d %d %d \n", dirok, dirsizeok, revok, revsizeok);





if ((dirok==1) && (dirsizeok==1)) {print=5;}
else if (( revok==1) && (revsizeok==1)) {print=1;}
else {print=0;}

printf("print igual    %d \n", print);
switchcase:

switch (print)
	{
	case(0) : printf("Incompatibilidade total.\n");
	break;
	case(1) : printf("Reverso tem compatibilidade.\n");
	break;
	case(5) : printf("Compatibilidade Natural.\n");
	break;
	}


return 0;
}

