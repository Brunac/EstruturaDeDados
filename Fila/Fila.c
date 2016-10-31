/*
    Eric e Juan
    22/03/2016
    Fila 01
*/
#include<stdio.h>
#define MAX  5

struct fila{
    int inicio, fim;
    int a[MAX];
};

void inserir(int x, struct fila *f)

{
    if(f->fim == MAX - 1)
        printf("\n\nFila cheia !!!");
    else
    {
        f->fim++;
        f->a[f->fim] = x;
    }
}

void remover(struct fila *f)
{
  if(f->inicio > f->fim)
  {
      printf("\nFila vazia!\n");

  }
  else
  {
      int aux = f->a[f->inicio];
      f->inicio++;

    printf("\n\nValor %d foi removido\n\n", aux);
  }


}

int main (void)

{
    struct fila fila01;
    int OPCAO = 1, RESP = 1, N;

    fila01.inicio = 0;
    fila01.fim = -1;


    while (OPCAO != 3)

    {
        printf("ESCOLHA UMA OPERACAO: \n1-ADICIONAR\n2-REMOVER\n3-SAIR\n\n");
        scanf("%d", &OPCAO);
        while((getchar() != '\n') && (!EOF));

        if(OPCAO == 1)
        {
            RESP = 1;
            while(RESP == 1)
            {
              printf("%d || %d\n", fila01.fim, fila01.inicio);
              printf("INSIRA UM VALOR: ");
              scanf("%d", &N);
              while((getchar() != '\n') && (!EOF));

              inserir(N, &fila01);

              printf("DESEJA INSERIR UM OUTRO VALOR? <TECLE 1 PARA [SIM] E QUALQUER NUMERO PARA [NAO]>\n");
              scanf("%d", &RESP);
            }
        }
        if(OPCAO == 2)
        {
            RESP = 1;
            while(RESP == 1)
            {
              remover(&fila01);

              printf("\n\nDESEJA REMOVER O PROXIMO VALOR DA FILA? <TECLE 1 PARA [SIM] E QUALQUER NUMERO PARA [NAO]>\n");
              scanf("%d", &RESP);
              while((getchar() != '\n') && (!EOF));
            }
        }
    }

    return 0;
}
