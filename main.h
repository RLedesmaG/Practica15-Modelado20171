#ifndef MAIN_H // Guarda para evitar include circulares
#define MAIN_H
/* ------ Se hacen todos los includes necesarios ------ */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ------ Definición de tus estructuras ------ */
//Voy a usar las listas de la práctica 14, que el valor sea las veces que aparecen las palabras en el texto, y un nuevo "valor" que guarde la palabra, como en los diccionarios. No usaré las funciones que no me sirve, como cmp_int o ordena_lista.
struct elemento{
	struct elemento *siguiente;
	int *valor;
	char *str;
};

typedef struct elemento Elemento;
typedef Elemento** Lista;


/* ------ Definición de tus funciones ------ */

/*Imprime las instrucciones de uso del programa*/
void imprime_instrucciones();
int procesa_archivo(char archivo[]);
void borra_lista(Lista);
Lista crea_lista();
int inserta_elemento(Lista lista, char *str);
bool busca_lista(Lista lista, char *str);
size_t longitud(Lista lista);

#endif //MAIN_H
