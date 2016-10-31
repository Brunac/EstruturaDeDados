#include<stdio.h>
#include<stdlib.h>

void clrbufkey(){
while((getchar() != '\n') && (!EOF));
}

typedef struct no{
	int valor, posicao;
	struct no *proximo;
	struct no *anterior;
}No;

typedef struct lista
{
	struct no *primeiro;
	struct no *ultimo;
}lista;

lista L;

void inicializar(lista *L)
{
	L->primeiro = NULL;
	L->ultimo = NULL;
}



void inserirInicio(lista *L, int x)
{
    No *p1 = (No*)malloc(sizeof(No));
    p1->valor = x;
    p1->proximo = L->primeiro;
    if (L->primeiro != NULL)
    {
        L->primeiro->anterior = p1;
    }
    else
    {
       L->primeiro = p1;
    }

}

void inserirMeio(lista *L, int x, int pos)
{
    //inserir no meio
    if(L->primeiro == NULL)
    {
        printf("Lista Vazia!\n");
        getchar();
        return;
    }
    else
    {
        if(pos == 1)
        {
            inserirInicio(L, x);
            return;
        }

    No *p1 = L->primeiro;
    while(--pos != 0)
    {
        p1 = p1->proximo;
        if (p1->proximo == NULL)
        {
           printf("Erro");
            return;
        }
    }
    No *p2 = p1->proximo;
    No *p3 = (No*)malloc(sizeof(No));
    p3->valor = x;
    p3->proximo = p2;
    p2->anterior = p3;
    p1->proximo = p3;
    p3->anterior = p1;
    }

}

void inserirFim(lista *L, int x)
{
    No *p1 = (No*)malloc(sizeof(No));
    p1->valor = x;
    L->ultimo->proximo = p1;
    p1->anterior = L->ultimo;
    L->ultimo = p1;
}

void mostrar(lista *L)
{
    No *p;

}

int main(void)
{
    int x, pos;
    inicializar(&L);

    printf("Onde deseja inserir?\n1 para Inicio\n2 para Meio\n3 para fim\n");
    scanf("%i", &pos); clrbufkey();
    printf("Insira o valor:");
    scanf("%i", &x); clrbufkey();
    if (pos == 1 )
        inserirInicio(&L, x);
    else{
        printf("Insira o valor:");
        scanf("%i", &x); clrbufkey();
        inserirMeio(&L, x, pos);
    }


    return 0;

}


