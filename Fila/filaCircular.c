#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// estrutura

typedef struct
{
    int items[MAX];
    int frente, tras;
    int tamanho;
} Fila;

void inicializarFila(Fila *f)
{
    f->frente = 0;
    f->tras = 0;
    f->tamanho = 0;
}

int estaVazia(Fila *f) { return (f->tamanho == 0); }
int estaCheia(Fila *f) { return (f->tamanho == MAX); }

void enqueue(Fila *f, int valor)
{
    if (estaCheia(f))
    {
        printf("Fila cheia!\n");
        return;
    }
    f->items[f->tras] = valor;
    f->tras = (f->tras + 1) % MAX;
    f->tamanho++;
}
int dequeue(Fila *f)
{
    if (estaVazia(f))
    {
        printf("Fila vazia!\n");
        return;
    }
    int valor = f->items[f->frente];
    f->frente = (f->frente + 1) % MAX;
    f->tamanho--;
    return valor;
}

void mostrarFila(Fila *f)
{
    if (estaVazia(f))
    {
        printf("Fila Vazia");
        return;
    }
    printf("Fila: ");
    for (int i = 0; i < f->tamanho; i++)
    {
        int indice = (f->frente + i) % MAX;
        printf("%d ", f->items[indice]);
    }
    printf("\n");
}

// main

int main(void)
{
    Fila f;
    inicializarFila(&f);

    enqueue(&f, 1);
    enqueue(&f, 2);
    enqueue(&f, 3);
    enqueue(&f, 4);
    enqueue(&f, 5);

    mostrarFila(&f);

    dequeue(&f);
    dequeue(&f);
    dequeue(&f);

    enqueue(&f, 6);
    mostrarFila(&f);
}