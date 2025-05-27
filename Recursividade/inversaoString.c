#include <stdio.h>
#include <stdlib.h>
#include <string.h>                                     // para facilitar sacar el tamaño de la palabra/frase
void palavraInvertida(char *letra, int inicio, int fim) // uso * para apuntar al primer caracter de la palabra
{
    if (inicio >= fim)
    {
        return; // no retorno nada ya que es un void, y la palabra está siendo cambiada desde ya
    }

    char k = letra[inicio];
    // "k" seria igual a h
    letra[inicio] = letra[fim];
    letra[fim] = k;
    // h se volveria ! y viceversa, "!ello worldh"

    palavraInvertida(letra, inicio + 1, fim - 1);
    // aumento y disminuyo para avanzar en el texto
}

int main(void)
{
    char palavra[] = "hello world!";
    int tamanho = strlen(palavra);
    palavraInvertida(palavra, 0, tamanho - 1);
    printf("A palavra invertida é %s", palavra);
    return 0;
}