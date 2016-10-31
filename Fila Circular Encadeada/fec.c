//PROGRAMA FILA CIRCULAR ENCADEADA
//AUTORES: ERIC E JUAN
//DATA 18/04/2016
//VERSÃO: 1.0

#include <stdio.h>
#include <stdlib.h>

void clrbufkey(){
    while((getchar() != '\n') && (!EOF));
}
typedef struct No{
    char valor;
    struct No *proximo;
}no;

struct fila{
    struct no *fim;
}F;

void Inicializar(struct fila *F){
    F->fim = NULL;
}

void Inserir(struct fila *F, char x){
    No p;
    if((p = (No) malloc(sizeof(No))) == NULL){
        printf("Shibata!!!");
        return ;
    }
    p->valor = x;
    if(F->fim == NULL)
        p->proximo = p;
    else
    {
        p->proximo = F->fim->proximo;
        F->fim = p;
    }
}

void Remover(struct fila *F){
    if(F->fim->proximo != NULL){
        No p = F->fim->proximo;
        F->fim->proximo = p->proximo;
        if(F->fim->proximo == NULL)
        {
            F->fim == NULL;
            printf("FILA VAZIA!!");
        }
        free(p);
    }
}

void Mostrar(struct fila *F){
    No p = F->fim->proximo;
    while(p != NULL){
        printf(" %c |", p->valor);
        p = p->proximo;
    }
}

int main(void)
{
    char valor, PAUSA;
    int RESP = 0, OPCAO = 1;
    Inicializar(&F);

    while(OPCAO != 4)
    {
        printf("\nMENU\n");
        printf("\n1-Adicionar\n2-Remover\n3-Mostrar\n4-Encerrar\n");
        printf("\nOPCAO: ");
        scanf("%d", &OPCAO); clrbufkey();

        if(OPCAO == 1)
        {
             do
            {
              printf("Entre com um valor: ");
              scanf("%c", &valor);clrbufkey();
              Inserir(&F, valor);
              printf("\n\nDeseja continuar ?");
              printf("\nTecle 0 para Sim, qualquer numero para Nao ...\n\n");
              scanf("%d", &RESP); clrbufkey();
            }while(RESP == 0);
        }

        if(OPCAO == 2)
        {
          do{
            Remover(&F);
            printf("\n\n");
            Mostrar(&F);
            printf("\n\nDeseja continuar ?");
            printf("\nTecle 0 para Sim, qualquer numero para Nao ...\n\n");
            scanf("%d", &RESP); clrbufkey();
          }while(RESP == 0);
        }

        if(OPCAO == 3)
        {
            Mostrar(&F);
        }

    }

 /*   do
    {
        printf("Entre com um valor: ");
        scanf("%c", &valor);clrbufkey();
        Inserir(&F, valor);
        printf("\n\nDeseja continuar ?");
        printf("\nTecle 0 para Sim, qualquer numero para Nao ...\n\n");
        scanf("%d", &RESP); clrbufkey();
    }while(RESP == 0);

    printf("\n\n");
    Mostrar(&F);
    RESP = 0;

    printf("\n\nAgora vamos remover\n\n");
    printf("Tecle <Enter> para continuar ...");
    PAUSA = getchar();
    do{
        Remover(&F);
        printf("\n\n");
        Mostrar(&F);
        printf("\n\nDeseja continuar ?");
        printf("\nTecle 0 para Sim, qualquer numero para Nao ...\n\n");
        scanf("%d", &RESP); clrbufkey();
    }while(RESP == 0);
   */
    return 0;
}
