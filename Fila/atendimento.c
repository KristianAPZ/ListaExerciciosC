#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    int items[MAX];
    int frente, tras;
    int tamanho;
} Fila;

void inicializarFila(Fila *f)
{
    f->frente = 0;
    f->tras = -1;
    f->tamanho = 0;
}

int estaVazia(Fila *f) { return (f->tamanho == 0); }
int estaCheia(Fila *f) { return (f->tamanho == MAX); }

void enqueue(Fila *f, int valor)
{
    if (estaCheia(f))
    {
        printf("Fila cheia");
        return;
    }
    f->tras = (f->tras + 1);
    f->items[f->tras] = valor;
    f->tamanho++;
    printf("O turno %d foi adicionado\n", valor);
}
int dequeue(Fila *f)
{
    if (estaVazia(f))
    {
        printf("Fila vazia");
        return;
    }
    int valor = f->items[f->frente];
    f->frente = (f->frente + 1);
    f->tamanho--;
    printf("Atendendo ao turno %d\n", valor);
    return valor;
}

void mostrarFila(Fila *f)
{
    if (estaVazia(f))
    {
        printf("Fila vazia");
        return;
    }
    printf("Clientes em fila:\n");
    for (int i = 0; i < f->tamanho; i++)
    {
        int pos = (f->frente + i);
        printf("- Turno %d\n", f->items[pos]);
    }
}
int main(void)
{
    Fila f;
    inicializarFila(&f);

    enqueue(&f, 1);
    enqueue(&f, 2);
    enqueue(&f, 3);
    enqueue(&f, 4);

    mostrarFila(&f);
}