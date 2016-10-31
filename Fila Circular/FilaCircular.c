/*
    Autores: Eric Dias e Juan Maciel
    FilaCircularEncadeada v1.0
    Data: 25/04/2016
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

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
}Lista;

//Fim Declaração Structs

void clrbufkey()
{
    while((getchar() != '\n') && (!EOF));
}

void pause()
{
      char PAUSA;
      printf("\nPressione <ENTER> para avancar...");
      PAUSA = getchar();
}

Lista inicializar(Lista * lista)
{
    return NULL;
}

int incremento(int V)
{
    return ((V + 1) % MAX);
}

void inserir(int x, struct Fila *f)
{
    //int V = f->fim;

   if(incremento(f->fim) == f->inicio)
    {
        printf("\nFila Cheia!\n");
    }
    else
    {
        f->vetor[f->fim] = x;
        f->fim = incremento(f->fim);
    }
}

void remover(struct Fila *f)
{
  //int V = f->inicio;

  if(f->fim == f->inicio)
  {
      printf("\nFila Vazia!\n");
  }
  else
  {
      int aux = f->vetor[f->inicio];
      f->vetor[f->inicio] = 0;

      f->inicio = incremento(f->inicio);
  }


}

int main(void)
{
  struct Fila fila01;
  int OPCAO = 1, RESP = 1, N, I;



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

              pause();

              clrscr();

              printf("\n\nDESEJA REMOVER O PROXIMO VALOR DA FILA? <TECLE 1 PARA [SIM] E QUALQUER NUMERO PARA [NAO]>\n");
              scanf("%d", &RESP); clrbufkey();
            }
        }
        if(OPCAO == 3)
        {
            clrscr();
            I = fila01.inicio;
            printf("\n\n");

            while(I != fila01.fim)
            {
                printf(" %d ||", fila01.vetor[I] ) ;
                I = incremento(I);

            }
            printf("\n\n");
            pause();
        }
    }




  return 0;
}
