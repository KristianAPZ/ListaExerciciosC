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

void converterBinario(int numero, char *binario)
{
    Pilha p;
    inicializarPilha(&p);

    while (numero > 0)
    {
        int resto = numero % 2;
        push(&p, resto + '0'); // '0' sirve para convertir int en str
        numero = numero / 2;
    }

    int i = 0;             // uso i como si fuera for para el while
    while (!estaVazia(&p)) // esto seria, "Mientras la lista este llena", o negacion de la funcion estaVazia
    {
        binario[i++] = pop(&p); // agarra el ultimo item añadido, y suma 1 a i en cada iteración
    }
}

int main(void)
{
    int numero = 10;
    char binario[MAX]; // usamos MAX para fijar un limite
    converterBinario(numero, binario);
    printf("binario de %d: %s", numero, binario);
}