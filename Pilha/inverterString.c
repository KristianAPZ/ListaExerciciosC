#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // definimos el tamaño de la pila

typedef struct
{
    char items[MAX];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p) { p->topo = -1; }

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

void inverterString(char *letra)
{
    Pilha p;
    inicializarPilha(&p);

    for (int i = 0; letra[i] != '\0'; i++)
    {
        push(&p, letra[i]); // vamos a ingresar letra por letra a la pila
    }

    for (int i = 0; letra[i] != '\0'; i++)
    {
        letra[i] = pop(&p); // ahora vamos a agarrar letra por letra pero con el metodo FIFO (First in First out)
    }
}

int main(void)
{
    char frase[] = "Python";
    printf("Frase inicial: %s\n", frase);
    inverterString(frase);
    printf("Frase final: %s", frase);
}