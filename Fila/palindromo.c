#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // lo uso para isalpha (verificar si es una letra) y con tolower(para convertir min en mayusculas)

#define MAX 100

// ---- estruturas ----

typedef struct
{
    char items[MAX]; // Pilha (LIFO – ultimo en entrar - primero en salir)
    int topo;
} Pilha;

typedef struct // Fila (FIFO – Primero en entrar - primero en salir)
{
    char items[MAX];
    int frente, tras;  // frente - posicion del primer elemento, tras - posicion del ultimo elemento
    int tamanho; // cantidad de elementos en la fila
} Fila;

// ---- pilha ----

void inicializarPilha(Pilha *p) { p->topo = -1; }
int pilhaCheia(Pilha *p) { return (p->topo == MAX - 1); }
int pilhaVazia(Pilha *p) { return (p->topo == -1); }

void push(Pilha *p, char valor)
{
    p->topo++;
    p->items[p->topo] = valor;
}

int pop(Pilha *p)
{
    char valor = p->items[p->topo];
    p->topo--;// remover
    return valor; 
}

// ---- fila ----

void inicializarFila(Fila *f)
{
    f->frente = 0;
    f->tras = -1;
    f->tamanho = 0;
}

int filaVazia(Fila *f) { return (f->tamanho == 0); }
int filaCheia(Fila *f) { return (f->tamanho == MAX); }

void enqueue(Fila *f, int valor)
{
    if (filaCheia(f))
    {
        printf("Fila cheia");
        return;
    }
    f->tras = (f->tras + 1);
    f->items[f->tras] = valor;
    f->tamanho++;
}
int dequeue(Fila *f)
{
    if (filaVazia(f))
    {
        printf("Fila vazia");
        return;
    }
    int valor = f->items[f->frente];
    f->frente = (f->frente + 1);
    f->tamanho--;
    return valor;
}

// ------ palindromo -------

int ehPalindromo(char palavra[])
{
    Pilha p;
    Fila f;
    inicializarPilha(&p);
    inicializarFila(&f);
    // inicializar pilha e fila
    for (int i = 0; palavra[i] != '\0'; i++) // percorrer cada caracter do string
    {
        if (isalpha(palavra[i])) //ctype.h
        {
            char caracter = tolower(palavra[i]); //ctype.h
            push(&p, caracter);
            enqueue(&f, caracter);
        }
    }

    while (!filaVazia(&f)) // mientras la fila este llena
    {
        char daFila = dequeue(&f); // variables
        char daPilha = pop(&p);
        if (daFila != daPilha)
            return 0;
    }
    return 1;
}

// ----- main -----

int main(void)
{
    char *palavra = "Tacocat";
    if (ehPalindromo(palavra))
        printf("\"%s\" é um palíndromo.\n", palavra);
    else
        printf("\"%s\" não é um palíndromo.\n", palavra);

    return 0;
}
