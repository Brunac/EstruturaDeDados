/*
    ListaDuplamenteEncadeada.c v1.0

    Autores: Juan Maciel, Pablo Juan, Eric Dias,
    Gabriel Souza, Gabriel Ikeda, Janaina Trindade

    Data: 27/04/2016

*/

#include<stdio.h>
#include<stdlib.h>

#if WIN32 || WIN64  //Cross-Plataform
    void clrscr()
    {
        system("cls");
    }
#else

    void clrscr()
    {
        system("clear");
    }

#endif // WIN32

//Inicio Structs

typedef struct No
{
    int valor;
    struct No *prox, *ant;
}no;

typedef struct
{
    no *primeiro, *ultimo;
}ListaDupla;

//Fim Structs

//Inicio Funções Simples e Procedimentos

void clrbufkey()
{
    while((getchar() != '\n') && (!EOF));
}

void pause()
{
      char PAUSA;
      printf("\nPressione <ENTER> para prosseguir...");
      PAUSA = getchar();
}

int valor()
{
    int x;
    clrscr();
    printf("Insira o valor desejado: ");
    scanf("%d", &x); clrbufkey();
    return x;
}

int posicao()
{
  int pos;

  clrscr();
  printf("Insira a posicao: ");
  scanf("%d", &pos); clrbufkey();
  return pos;
}

void inicializar(ListaDupla *L)
{
    L->primeiro = NULL;
    L->ultimo = NULL;
}

//Fim Funções Simples e Procedimentos

//!Inserir

//Inicio Funções Auxiliares de Inserção

void inserir_primeiro(ListaDupla *ld)
{
    no *pn = (no *) malloc(sizeof(no));
    no *p1 = ld->primeiro;

    if(ld->primeiro == NULL)
    {
        ld->primeiro = pn;
        ld->ultimo = pn;
        pn->valor = valor();
        pn->prox = NULL;
        pn->ant = NULL;
    }
    else
    {
        pn->valor = valor();
        pn->prox = p1;
        p1->ant = pn;
        ld->primeiro = pn;
    }



    printf("Valor Inserido com Sucesso!");
    pause();
}

void inserir_definido(ListaDupla *ld)
{
    if(ld->primeiro == NULL)
    {
        clrscr();
        printf("Lista Vazia!\n");
        pause();
        return;
    }
    else
    {
        int k = posicao();
        if(k == 1)
        {
            inserir_primeiro(ld);
            return;
        }
         no *pa = ld->primeiro; //pa = P anterior (P1)


        while(--k != 0)
        {
            pa = pa->prox;
            if(pa->prox == NULL)
            {
                clrscr();
                printf("ERRO! - Posicao inexistente!");
                pause();
                return;
            }
        }
        no *pp = pa->prox; //pp = P Próximo (P2)
        no *pn = (no *) malloc(sizeof(no)); //pn = P Novo (P3)
        pn->valor = valor();
        pn->prox = pp;
        pp->ant = pn;
        pn->prox = pn;
        pa->ant = pa;

    }
    printf("Valor Inserido com Sucesso!");
    pause();

}

void inserir_ultimo(ListaDupla *ld)
{
    no *pn = (no *) malloc(sizeof(no));
    if(ld->primeiro == NULL)
    {
        ld->primeiro = pn;
        ld->ultimo = pn;
        pn->valor = valor();
        pn->prox = NULL;
        pn->ant = NULL;
    }
    else
    {
        no *p2 = ld->ultimo;

        pn->valor = valor();
        pn->prox = NULL;
        pn->ant = p2;
        p2->prox = pn;
        ld->ultimo = pn;
    }

    printf("Valor Inserido com Sucesso!");
    pause();
}

//Fim Funções Auxiliares de Inserção



void menu_inserir(ListaDupla *ld)
{
    int OP = 1, RESP;

    while(OP != 3)
    {
        clrscr();
        printf("1-INSERIR NO PRIMEIRO\n2-INSERIR EM LUGAR DEFINIDO\n3-INSERIR NO FINAL\n4-VOLTAR\n");
        printf("OPCAO: ");
        scanf("%d", &OP); clrbufkey();

        switch(OP)
        {
            case 1: inserir_primeiro(ld); break;
            case 2: inserir_definido(ld); break;
            case 3: inserir_ultimo(ld); break;
            case 4: return; break;
            default: clrscr(); printf("Opcao invalida"); break;
        }

    }
}

//!Fim Inserir

//!Mostrar

void mostrar(ListaDupla *ld)
{
    if(ld->primeiro == NULL)
    {
        clrscr();
        printf("Lista Vazia!\n");
        pause();
        return;
    }
    else
    {
        clrscr();
        no *p = ld->primeiro;
        do
        {
            printf("%d ", p->valor);
            p = p->prox;
        }while(p != ld->ultimo->prox);
    }
    printf("\n\n");
    pause();
}

//!Fim Mostrar

//!Limpar

void limpar(ListaDupla *LD)
{
    if(LD->primeiro == NULL)
    {
      return;
    }
    else
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
        }while (P != NULL);
    }
}

//!Fim Limpar

//!Programa Principal

int main(void)
{

    ListaDupla LD;

    inicializar(&LD);

    int OPCAO = 1, RESP = 1;


    while(OPCAO != 4)
    {
        clrscr();
        printf("1-INSERIR\n2-REMOVER\n3-MOSTRAR\n4-SAIR\n");
        printf("OPCAO: ");
        scanf("%d", &OPCAO); clrbufkey();

        switch(OPCAO)
        {
            case 1: menu_inserir(&LD); break;
            case 2: clrscr(); printf("Em Construcao"); pause();/*remover(&LD);*/ break;
            case 3: mostrar(&LD); break;
            case 4: limpar(&LD); break;
            default: clrscr(); printf("Opcao invalida"); break;
        }
    }
    return 0;
}

//!Fim
