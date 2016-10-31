#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *prox;
}no;

typedef struct{
    no *primeiro;
    no *ultimo;
}Lista;

no *Alocar()
{
    return ((no *) malloc(sizeof(no)));
}

void Inicializar(Lista *F)
{
    F->primeiro = NULL;
    F->ultimo = NULL;
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
        P->prox = NULL;
        if (F->ultimo == NULL)
            F->primeiro = P;
        else
            F->ultimo->prox = P;
        F->ultimo = P;
    }
}

void Remover(Lista *F)
{
    no *P;
    if (F->primeiro != NULL)
    {
        P = F->primeiro;
        printf("Remover: %d", F->primeiro->valor);
        F->primeiro = F->primeiro->prox;
        if (F->primeiro == NULL)
            F->ultimo = NULL;
        free(P);
        printf("\nItem removido\n");
    }
    else
        printf("Fila vazia!");
}

void Limpar(Lista *F)
{
    no *P;
    no *aux;
    P = F->primeiro;
    while (P != NULL)
    {
        printf("\nRemovendo: %d", P->valor);
        aux = P->prox;
        free(P);
        P = aux;
    }
    printf("\nMemoria liberada.\n");
}
int Mostrar(Lista *F)
{
    no *P;
    P = F->primeiro;
    if (P == NULL)
        printf("\n\nFila vazia!");
    else
    {
        while (P != NULL)
        {
            printf("%d ", P->valor);
            P = P->prox;
        }
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
