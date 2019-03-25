/*
================================================================================
Author: André Barros de Medeiros
RA:194060
Title: Autômato Musical
Description: Alocação de Memória Dinâmica ; estrutura de variável ; pointers
Date:11/09/17
Copyright: free to use and modify
================================================================================
*/

#include <stdlib.h> /*only malloc(), realloc(), free(), and calloc()*/
#include "lab10.h"


void swapevents (TpEvento *eventA, TpEvento *eventB){                        /*switch two events in 4 vectors, used in bubble sort*/
	TpEvento temp;

	temp.instante  = (*eventA).instante;
	temp.instrumento = (*eventA).instrumento;
	temp.nota = (*eventA).nota;
	temp.intensidade = (*eventA).intensidade;

	(*eventA).instante = (*eventB).instante;
	(*eventA).instrumento = (*eventB).instrumento;
	(*eventA).nota = (*eventB).nota;
	(*eventA).intensidade = (*eventB).intensidade;

	(*eventB).instante = temp.instante;
	(*eventB).instrumento = temp.instrumento;
	(*eventB).nota = temp.nota;
	(*eventB).intensidade = temp.intensidade;
	return;
}


int main(){

int a, b, c, d, e;
int i;
int nomemory;
int slots;
int TeventsT;
int swap;
TpEvento *events;

nomemory=0;
i=0;

/*scan input and allocate memory*/
slots=sizeof(TpEvento);
events=(TpEvento *)malloc(2*slots);
if (events==NULL) {nomemory=1;}

if(nomemory==0){

	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	while(!(a==0 && b==0 && c==0 && d==0 && e==0)){
		events[i].instante = d;
		events[i].instrumento = a;
		events[i].nota = b;
		events[i].intensidade = c;                                   /*two events per entry line: beginning and end of sound*/
	
		events[i+1].instante = d+e;
		events[i+1].instrumento = a;
		events[i+1].nota = b;
		events[i+1].intensidade = 0;

		i=i+2;
		events=(TpEvento *)realloc(events, (i+2)*slots);
		if (events==NULL) {nomemory=1;}
		if(nomemory==0){scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);}
		else {a=0; b=0; c=0; d=0; e=0;}
	}
}
TeventsT=i;		

/*sort events using bubble sort*/
if(nomemory==0){
swap = 1;
	while (swap==1){
		swap = 0;
		for (i=1; i<TeventsT; i++) {
			if (events[i-1].instante > events[i].instante) {swapevents(&events[i-1], &events[i]); swap=1;}
			if (events[i-1].instante == events[i].instante) {
				if (events[i-1].instrumento > events[i].instrumento) {swapevents(&events[i-1], &events[i]); swap=1;}
				if (events[i-1].instrumento == events[i].instrumento) {
					if (events[i-1].nota > events[i].nota) {swapevents(&events[i-1], &events[i]); swap=1;}
					if (events[i-1].nota == events[i].nota) {
						if (events[i-1].intensidade > events[i].intensidade) {swapevents(&events[i-1], &events[i]); swap=1;}
					}
				}
			}
		}
	}
}

if(nomemory==1) { printf("Error when allocating memory");}
else {saida(0, TeventsT, events);}
free (events);

return 0;
}
