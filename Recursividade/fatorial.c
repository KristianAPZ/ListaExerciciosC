#include <stdio.h>
#include <stdlib.h>

int fatorial(int num) // creo una funcion factorial
{
    if (num == 1) // si el numero es igual a uno retornará uno
    {
        return 1;
    }

    return num * (fatorial(num - 1)); // el numero quedará y el factorial se repetirá
}

int main(void) // uso void porque la funcion "main" no tiene retorno de nada
{
    int num = 4;
    int resultado = fatorial(num);
    printf("o fatorial do número %d é %d", num, resultado); // uso %d para números
    return 0;
}
