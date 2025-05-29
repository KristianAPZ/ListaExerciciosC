#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // tamanho mnáximo

typedef struct 
{
   int itens[MAX];
   int frente, tras;
   int tamanho;
} Fila;

void inicializarFila(Fila *f){
    f->frente =0;
    f->tras = -1;
    f->tamanho = 0; 
}

int estaVazia(Fila *f){
    return(f->tamanho == 0);
}

int estaCheia(Fila *f){
    return(f->tamanho == MAX);
}

// Função enfileirar - inseri valor no final
void enqueue(Fila *f, int valor){
    if(estaCheia(f)){
        printf("Fila está cheia!");
        return;
    }

    f->itens[f->tras] = valor;
    f->tamanho++;
}

//desenfileirar
int dequeue(Fila *f){
    if(estaVazia(f)){
        printf("Fila está vazia!");
        return;
    }

    int valor = f->itens[f->frente];
    f->tamanho--;
    return valor;
}

int front(Fila *f){
     if(estaVazia(f)){
        printf("Fila está vazia!");
        return;
    }

    return f->itens[f->frente];
}