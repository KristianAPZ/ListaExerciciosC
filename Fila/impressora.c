#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct
{
    char nome[50];
    int paginas;
} Documento;

typedef struct
{
    Documento fila[MAX];
    int tamanho;
} Impressora;

void inicializar(Impressora *imp)
{
    imp->tamanho = 0;
}

void adicionar(Impressora *imp, const char *nome, int paginas)
{
    if (imp->tamanho == MAX)
    {
        printf("Fila cheia.\n");
        return;
    }

    strcpy(imp->fila[imp->tamanho].nome, nome);
    imp->fila[imp->tamanho].paginas = paginas;
    imp->tamanho++;

    printf("Documento %s foi adicionado à fila.\n", nome);
}

void imprimir(Impressora *imp)
{
    if (imp->tamanho == 0)
    {
        printf("\nNão tem documentos na fila.\n");
        return;
    }

    Documento doc = imp->fila[0];
    printf("\nImprimindo %s com %d páginas.\n", doc.nome, doc.paginas);

    for (int i = 1; i < imp->tamanho; i++)
    {
        imp->fila[i - 1] = imp->fila[i];
    }
    imp->tamanho--;
}

void verFila(Impressora *imp)
{
    if (imp->tamanho == 0)
    {
        printf("\nNão tem documentos na fila.\n");
        return;
    }

    printf("\nDocumentos na fila:\n");
    for (int i = 0; i < imp->tamanho; i++)
    {
        printf("%s - %d páginas\n", imp->fila[i].nome, imp->fila[i].paginas);
    }
}

int main()
{
    Impressora imp;
    inicializar(&imp);

    adicionar(&imp, "Relatório", 10);
    adicionar(&imp, "Apresentação", 5);

    verFila(&imp);

    imprimir(&imp);
    imprimir(&imp);
    imprimir(&imp);

    return 0;
}
