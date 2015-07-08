#include <stdio.h>
#include <stdlib.h>

typedef struct intlist {
	int i;
	struct intlist* next;
} intlist;

intlist *addToList(intlist *list, int i) {
	if( list == NULL) {
		intlist *new = malloc(sizeof(intlist));
		if(new == NULL){
			return NULL;
		}
	new -> i =  i;		//zwei Schreibweisen (*new).i oder new -> i
	new -> next = NULL;
	return new;
	} 
	if(list -> i >= i){
		intlist *new = addToList(NULL, i);
		if(new == NULL) return NULL;
		new -> next = list;
		return new;
	}
	list -> next = addToList(list -> next, i);
	return list;
}


void printList(intlist *list){
	while(list != NULL){
		printf("%d\n", list -> i);
		list = list -> next;
	}
}

void freeList(intlist *list){
	if(list == NULL){
	freeList(list -> next);
	free(list);			//Standardfunktion zum freigeben von Speicher
	}
}

int main(void){
	intlist *list = NULL;
	list = addToList(list, 5);
	list = addToList(list, 2);
	list = addToList(list, 4);
	printList(list);
	freeList(list);
}


// compiling mit Warnungen -> gcc -Wall -Wextra (weil in Wall nicht alle Fehler enthalten) -pedantic -g (debuginfos) -std=c99 -o List list.c
//valgrind <prog> Programm zum testen der Speichernutzung
