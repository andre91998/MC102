/*
================================================================================
Author: André Barros de Medeiros
RA:194060
Title: Gremlins
Description: Recursão
Date:11/16/17
Copyright: free to use and modify
================================================================================
*/


#include <stdio.h>

int even (int in){
	int out;
	if (in%2==0) {out=1;}
	else out=0;
	return out;}

int is3or4 (int in){
	int out;
	int u, t;
	if ((in%3==0)||(in%4==0)) {
		u=in%10;
		t=((in/10)%10);
		out=u*t;}
	else out=0;
	return out;}

int by5 (int in){
	int out;
	if (in%5==0) {out=1;}
	else out=0;
	return out;}

int recursao (int in){
	int out;
	int f;
	int a,b,c;
	a=0;b=0;c=0;
	out=0;
	f=is3or4(in);
	if (in<42) { out=0;}
	if (in==42){ out=1;}
	if (in>42) { 
		if(even(in)==1){a=recursao(in/2);}
		if(f>0){b=recursao(in-f);}
		if(by5(in)==1){c=recursao(in-42);}
		}
	if((a==1)||(b==1)||(c==1)){out=1;}
	return out;
	}



int main(){

int input;
int output;

scanf("%d", &input);

output=recursao(input);

if(output==0){printf("Nao\n");}
if(output==1){printf("Sim\n");}

return 0;
}

