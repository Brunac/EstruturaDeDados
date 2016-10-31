#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *prox;
}no;

typedef struct{
    no *fim;
}Lista;

no *Alocar()
{
    return ((no *) malloc(sizeof(no)));
}

void Inicializar(Lista *F)
{
    F->fim = NULL;
}

void Inserir(Lista *F, int X)
{
    no *P;
    P = Alocar();
    if (P == NULL)
        printf("Nao ha espaco na memoria.");
    else
    {
        P->valor = X;
        if (F->fim == NULL)
            P->prox = P;
        else
        {
            P->prox = F->fim->prox;
            F->fim->prox = P;
        }
        F->fim = P;
    }
}

void Remover(Lista *F)
{
    no *P;
    if (F->fim != NULL)
    {
        P = F->fim->prox;
        //preferencialmente usa-se: if(P-prox == F->fim->prox). Apenas no caso do IF
        if (P->prox == F->fim->prox)
            F->fim = NULL;
        else
            F->fim->prox = P->prox;
        free(P);
    }
    else
        printf("Fila vazia!");
}

void Limpar(Lista *F)
{
    no *P;
    no *aux;
    P = F->fim->prox;
    do
    {
        printf("\nRemovendo: %d", P->valor);
        aux = P->prox;
        free(P);
        P = aux;
    }
    while (P != F->fim->prox);
    printf("\nMemoria liberada.\n");
}
void Mostrar(Lista *F)
{
    no *P;
    P = F->fim;
    if (P == NULL)
        printf("\n\nFila vazia!");
    else
    {
        P = F->fim->prox;
        do
        {
            printf("%d ", P->valor);
            P = P->prox;
        }
        while (P != F->fim->prox);
    }
}

int main(void)
{
    int VALOR, OPC, RESP, OPS;
    Lista F;

    OPS = 1;

    Inicializar(&F);

    while (OPS == 1)
    {
        RESP = 1;

        printf("\n\n1 - Inserir\n2 - Mostrar\n3 - Remover\n0 - Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &OPC);

        switch (OPC)
        {
            case 1:
                while(RESP == 1)
                {
                    printf("\n\nInsira um valor: "); scanf("%d", &VALOR);
                    Inserir(&F, VALOR);
                    printf("\nDeseja inserir mais? 1 = Sim: "); scanf("%d", &RESP);
                }
                break;
            case 2: Mostrar(&F); break;
            case 3: Remover(&F); break;
            case 0:
                printf("Encerrando o programa");
                OPS = 0; break;
        }
    }



    //Função que percorrerá toda a lista! Tipo o remover, só que sem parar!
    Limpar(&F);
    return 0;
}
