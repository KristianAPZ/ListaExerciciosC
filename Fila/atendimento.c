#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int items[MAX];
    int frente, tras;
    int tamanho;
} Fila;

inicializarFila(Fila *f)
{
    f->frente = 0;
    f->tras = -1;
    f->tamanho = 0;
}

estaVazia(Fila *f) { return (f->tamanho = 0); }
estaCheia(Fila *f) { return (f->tamanho == MAX); }

void enqueue(Fila *f, int valor)
{
    if (estaCheia(f))
    {
        printf("Fila cheia");
        return;
    }
    f->items[f->tras] = valor;
    f->tamanho++;
}
int dequeue(Fila *f)
{
    if (estaVazia(f))
    {
        printf("Fila vazia");
        return;
    }
    int valor = f->items[f->tras];
    f->tamanho--;
    return valor;
}

int front(Fila *f)
{
    if (estaVazia(f))
    {
        printf("Fila vazia");
        return;
    }
}