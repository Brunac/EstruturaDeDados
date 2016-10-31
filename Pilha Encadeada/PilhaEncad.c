//PROGRAMA PILHA ENCADEADA
//AUTORES: ERIC E JUAN
//DATA 18/04/2016
//VERSÃO: 1.0

#include <stdio.h>
#include <stdlib.h>

void clrbufkey(){
    while((getchar() != '\n') && (!EOF));
}
struct no{
    char valor;
    struct no *proximo;
};

typedef struct no *No;

struct fila{
    struct no *inicio, *fim;
}F;

void Inicializar(struct fila *F){
    F->inicio = NULL;
    F->fim = NULL;
}

void Inserir(struct fila *F, char x){
    No p;
    if((p = (No) malloc(sizeof(No))) == NULL){
        printf("Shibata!!!");
        return ;
    }
    p->valor = x;
    p->proximo = NULL;
    if(F->fim == NULL)
        F->inicio = p;
    else
        (F->fim)->proximo = p;
    F->fim = p;

}

void Remover(struct fila *F){
    if(F->inicio != NULL){
        No p = F->inicio;
        F->inicio = p->proximo;
        if(F->inicio == NULL)
        {
            F->fim == NULL;
            printf("FILA VAZIA!!");
        }
        free(p);
    }
}

void Mostrar(struct fila *F){
    No p = F->inicio;
    while(p != NULL){
        printf(" %c |", p->valor);
        p = p->proximo;
    }
}

int main(void)
{
    char valor, PAUSA;
    int RESP = 0, OPCAO;
    Inicializar(&F);
    do
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
    return 0;
}
