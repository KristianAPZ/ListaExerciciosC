#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // definimos el tamaño de la pila

typedef struct
{
    char items[MAX];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p) { p->topo = -1; }

int estaVazia(Pilha *p) { return (p->topo == -1); }

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

int verificarParenteses(const char *expressao)
{
    Pilha p;
    inicializarPilha(&p);

    for (int i = 0; expressao[i] != '\0'; i++) // '\0' siempre esta en los textos al final, diciendo que acabo la expresion
    {
        char caracter = expressao[i];

        if (caracter == '(' || caracter == '[' || caracter == '{') // || es el op logico "O"
        {
            push(&p, caracter);
        }
        else if (caracter == ')' || caracter == ']' || caracter == '}')
        {
            if (estaVazia(&p)) // si esta vacia significa que esta desbalanceado
            {
                return 0;
            }

            char acima = pop(&p);

            if ((caracter == ')' && acima != '(') || // && es el op logico "Y"
                (caracter == ']' && acima != '[') ||
                (caracter == '}' && acima != '{')) // verificamos si los caracteres estan balanceados
            {
                return 0;
            }
        }
    }

    return estaVazia(&p);
}

// recordando que 0 es equivalente a false, y 1 a true

int main(void)
{
    const char *expressao = "{[()]}";

    if (verificarParenteses(expressao))
    {
        printf("Expressão Balanceada\n");
    }
    else
    {
        printf("Expressão Desbalanceada\n");
    }
    return 0;
}