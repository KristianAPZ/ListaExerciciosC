#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // definimos el tamaño de la pila

typedef struct
{
    char items[MAX];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p)
{
    p->topo = -1; // iniciamos pila desde -1, para que el siguiente sea 0 y asi consecutivamente
}

int estaVazia(Pilha *p)
{
    return (p->topo == -1); // si el ultimo elemento es -1, significa que la pila esta vacia
}

int estaCheia(Pilha *p)
{
    return (p->topo == MAX - 1);
}

void push(Pilha *p, int valor)
{
    p->topo++;                 // suma 1 al valor de la cima
    p->items[p->topo] = valor; // en items usamos el numero de topo, y le damos el valor
}

int pop(Pilha *p)
{
    int valor = p->items[p->topo]; // guardamos en "valor" el ultimo elemento de la pila
    p->topo--;                     // borramos
    return valor;                  // retornamos el valor
}
