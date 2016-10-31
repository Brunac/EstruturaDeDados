/*
    Autores: Eric Dias e Juan Maciel
    FilaCircularEncadeada v1.0
    Data: 25/04/2016
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

//Declaração Structs

typedef struct No
{
    int valor;
    struct No *prox;
}no;

typedef struct
{
    no *fim;
}Fila;

//Fim Declaração Structs

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

no *alocar()
{
    return ((no *) malloc(sizeof(no)));
}

void inicializar(Fila *F)
{
    F->fim = NULL;
}

void inserir(int x, Fila *f)
{
    no *p;
    p = alocar();
    if(p == NULL)
    {
        clrscr();
        printf("\aSem espaço suficente na memoria!");
        return;
    }

    p->valor = x;

    if(f->fim == NULL)
    {
        p->prox = p;
    }
    else
    {
        p->prox = f->fim->prox;
        f->fim->prox = p;
    }
    f->fim = p;
}

void remover(Fila *f)
{
  no *p;
  if(f->fim != NULL)
  {
     p = f->fim->prox;
     if (p->prox == f->fim->prox)
     {
         f->fim = NULL;
     }
     else
     {
         f->fim->prox = p->prox;
     }
     free(p);
  }
  else
  {
     clrscr();
     printf("Fila Vazia!");
  }


}

int main(void)
{
  Fila fila01;
  int OPCAO = 1, RESP = 1, N, I;

  inicializar(&fila01);


    while (OPCAO != 4)

    {
        clrscr();
        printf("ESCOLHA UMA OPERACAO: \n1-ADICIONAR\n2-REMOVER\n3-MOSTRAR FILA\n4-SAIR\n\n");
        scanf("%d", &OPCAO); clrbufkey();

        if(OPCAO == 1)
        {
            RESP = 1;
            while(RESP == 1)
            {
              clrscr();

              printf("INSIRA UM VALOR: ");
              scanf("%d", &N); clrbufkey();

              inserir(N, &fila01);

              printf("\n\nDESEJA INSERIR UM OUTRO VALOR? <TECLE 1 PARA [SIM] E QUALQUER NUMERO PARA [NAO]>\n");
              scanf("%d", &RESP); clrbufkey();
            }
        }
        if(OPCAO == 2)
        {
            RESP = 1;
            while(RESP == 1)
            {
              clrscr();
              remover(&fila01);

              printf("\nValor Removido");

              printf("\n\nDESEJA REMOVER O PROXIMO VALOR DA FILA? <TECLE 1 PARA [SIM] E QUALQUER NUMERO PARA [NAO]>\n");
              scanf("%d", &RESP); clrbufkey();
            }
        }
        if(OPCAO == 3)
        {
             clrscr();
             no *P;
             P = fila01.fim;
             if (P == NULL)
             {
                printf("\n\nFila vazia!");
             }
             else
             {
                P = fila01.fim->prox;
                do
                {
                    printf("%d ", P->valor);
                    P = P->prox;
                }while (P != fila01.fim->prox);
             }
             pause();
        }
    }




  return 0;
}
