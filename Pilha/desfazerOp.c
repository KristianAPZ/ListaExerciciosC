#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define TAM_TEXTO 100

typedef struct
{
    char items[MAX][TAM_TEXTO];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p) { p->topo = -1; }
int estaCheia(Pilha *p) { return (p->topo == MAX - 1); }
int estaVazia(Pilha *p) { return (p->topo == -1); }

void adicionar(Pilha *p, const char *texto) // el codigo no necesita modificar el texto, solo leerlo
{
    if (estaCheia(p))
    {
        printf("Pilha Cheia\n");
        return;
    }
    else
    {
        printf("Adicionando %s\n", texto);
        p->topo++;

        int i = 0;
        while (texto[i] != '\0')
        {
            p->items[p->topo][i] = texto[i];
            i++;
        }
    }
}

int desfazer(Pilha *p)
{
    if (!estaVazia(p))
    {
        printf("Desfazendo %s\n", p->items[p->topo]);
        p->topo--;
    }
    else
    {
        printf("Lista vazia\n");
        return;
    }
}

void mostrarPilha(Pilha *p)
{
    printf("Pilha atual\n:");
    for (int i = 0; i <= p->topo; i++)
    {
        printf("- %s\n", p->items[i]);
    }
}

int main(void)
{
    Pilha p;
    inicializarPilha(&p);

    adicionar(&p, "Hola mundo!");
    adicionar(&p, "Como están");
    adicionar(&p, "Todos");

    mostrarPilha(&p);

    desfazer(&p);
    desfazer(&p);

    mostrarPilha(&p);
    return 0;
}