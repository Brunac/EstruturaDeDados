#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *prox;
    struct No *ant;
}no;

typedef struct{
    no *primeiro;
    no *ultimo;
}ListaDup;

no *Alocar()
{
    return ((no *) malloc(sizeof(no)));
}

void Inicializar(ListaDup *LD)
{
    LD->primeiro = NULL;
    LD->ultimo = NULL;
}

void InserirInicio(ListaDup *LD, int X)
{
    no *PN = Alocar();
    no* P1 = LD->primeiro;
    PN->valor = X;
    PN->prox = P1;
    P1->ant = PN;
    LD->primeiro = PN;
}

void InserirMeio(ListaDup *LD, int X, int POS)
{
    if (LD->primeiro == NULL)
        printf("\nErro! Lista vazia.\n");
    else{
        if (POS == 1)
        {
            InserirInicio(LD, X);
            return;
        }
        no *P1 = LD->primeiro;
        while (--POS != 1)
        {
            P1 = P1->prox;
            if(P1->prox == NULL)
                {
                    printf("\nErro. Possicao nao acessivel\n");
                    return;
                }
        }
        no *P2 = P1->prox;
        no *PN = Alocar();
        PN->valor = X;
        PN->prox = P2;
        P2->ant = PN;
        P1->prox = PN;
        PN->ant = P1;
    }

}

void Inserir(ListaDup *LD,int X)
{
    no *PN = Alocar();
    if(LD->primeiro == NULL)
    {
        LD->primeiro = PN;
        LD->ultimo = PN;
        PN->valor = X;
        PN->prox = NULL;
        PN->ant = NULL;
    }
    else
    {
        no *P2 = LD->ultimo;
        PN->valor = X;
        PN->prox = NULL;
        PN->ant = P2;
        P2->prox = PN;
        LD->ultimo = PN;
    }

}

void Remover(ListaDup *LD)
{

}

void Limpar(ListaDup *LD)
{
    no *P;
    no *aux;
    P = LD->primeiro;
    do
    {
        printf("\nRemovendo: %d", P->valor);
        aux = P->prox;
        free(P);
        P = aux;
        LD->primeiro = P;
    }
    while (P != NULL);
    printf("\nMemoria liberada.\n");
}
void Mostrar(ListaDup *LD)
{
    if (LD->primeiro == NULL)
        printf("\nLista Vazia");
    else
    {
        no *P = LD->primeiro;
        do
        {
            printf("%d ", P->valor);
            P = P->prox;
        }
        while(P != LD->ultimo->prox);
    }
}

int main(void)
{
    int VALOR, OPC, RESP, OPS, POS;
    ListaDup LD;

    OPS = 1;

    Inicializar(&LD);

    while (OPS == 1)
    {
        RESP = 1;

        printf("\n\n1 - Inserir\n2 - Mostrar - Manutencao\n3 - Inserir no Meio\n4 - Inserir no Inicio\n0 - Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &OPC);

        switch (OPC)
        {
            case 1:
                while(RESP == 1)
                {
                    printf("\n\nInsira um valor: "); scanf("%d", &VALOR);
                    Inserir(&LD, VALOR);
                    printf("\nDeseja inserir mais? 1 = Sim: "); scanf("%d", &RESP);
                }
                break;
            case 2: Mostrar(&LD); break;
            case 3:
                printf("\nInforme a Posicao: "); scanf("%d", &POS);
                printf("\nInforme o valor: "); scanf("%d", &VALOR);
                InserirMeio(&LD, VALOR, POS);
                break;
            case 4:
                printf("\nInforme o valor: "); scanf("%d",&VALOR);
                InserirInicio(&LD, VALOR);
                break;
            case 0:
                printf("Encerrando o programa");
                OPS = 0; break;
        }
    }



    //Função que percorrerá toda a lista! Tipo o remover, só que sem parar!
    Limpar(&LD);
    return 0;
}
