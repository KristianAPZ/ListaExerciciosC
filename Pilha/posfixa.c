#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    char items[MAX];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p) { p->topo = -1; }
int estaCheia(Pilha *p) { return (p->topo == MAX - 1); }
int estaVazia(Pilha *p) { return (p->topo == -1); }

void push(Pilha *p, int valor)
{
    if (estaCheia(p))
    {
        printf("Fila cheia");
    }
    p->topo++;
    p->items[p->topo] = valor;
}

int pop(Pilha *p)
{
    if (estaVazia(p))
    {
        printf("Lista vazia\n");
        exit(1);
    }

    int valor = p->items[p->topo];
    p->topo--;
    return valor;
}

int eDigito(char caracter) // verifico si el numero es mayor= que 0 y menor= que 9
{
    return (caracter >= '0' && caracter <= '9');
}

int charToInt(char caracter) // convertimos los caracteres de la expresion dada a numeros
{
    return caracter - '0';
}

int posfixa(const char *exprecao)
{
    Pilha p;
    inicializarPilha(&p);

    int i = 0;

    while (exprecao[i] != '\0')
    {
        if (exprecao[i] == ' ') // si es un espacio salta al siguiente valor
        {
            i++;
            continue;
        }

        if (eDigito(exprecao[i]))
        {
            // aqui lo que hacemos es colocar los numeros de más de 1 cifra, como 10, 100, etc.
            int numero = 0;
            while (eDigito(exprecao[i]))
            {
                numero = numero * 10 + charToInt(exprecao[i]); // convertimos el numero a entero, ya que esta en char
                i++;
            }
            push(&p, numero);
            // si el numero es por ejemplo 100, entonces seria
            // 0*10+1= 1 | se suma 1 a i, asi que pasa al siguiente digito, además numero ahora seria 1
            // 1*10+0 = 10
            // 10*10+0 = 100
        }
        else
        {
            // creamos dos variables donde almacenaremos con un pop
            int b = pop(&p);
            int a = pop(&p);
            switch (exprecao[i]) // switch para este caso es mejor que else if
            {
            case '+':
                push(&p, a + b);
                break;
            case '-':
                push(&p, a - b);
                break;
            case '*':
                push(&p, a * b);
                break;
            case '/':
                push(&p, a / b);
                break;
            default:
                printf("Operador invalido");
                exit(1);
            }
            i++;
        }
    }
    return pop(&p);
}

int main(void)
{
    const char *exprecao = "2 3 +";
    int resultado = posfixa(exprecao);
    printf("Resultado: %d\n", resultado);
    return 0;
}