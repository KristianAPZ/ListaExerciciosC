#include <stdio.h>
#include <stdlib.h>

int somaLista(int lista[], int posicao, int tamanho)
{
    if (posicao >= tamanho)
    {
        return 0;
    }

    return lista[posicao] + somaLista(lista, posicao + 1, tamanho);
    // sumo la posicion de la lista con la funcion, llamando de nuevo a
    // lista, sumando 1 a la posición para avanzar en la lista
}

int main(void)
{
    int lista[] = {1, 2, 3, 4};
    int tamanho = 4;
    int resultado = somaLista(lista, 0, tamanho);
    printf("A soma da lista é %d\n", resultado);
}