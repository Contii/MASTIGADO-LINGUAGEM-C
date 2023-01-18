#ifndef FILA_H
#define FILA_H

#include "TAD_Fila.h"

#include "../ListaLinear/Lista.h"

/* ------------------------------- */
struct dFila{
    pDLista pdLista;
};

/* ----------------------------------------------------------------------------------- */
/* ----------------------------------- FUNÇÕES BASE ---------------------------------- */
/* ----------------------------------------------------------------------------------- */

pDFila criarFila(){
    /* aloca memoria para o descritor */
    pDFila pd = (pDFila) malloc(sizeof(DFila));
    /* o descritor da fila tem os mesmos campos do descritor de lista */
    pd->pdLista = criarLista();
    return pd;
}

void enfileirarInfo(pDFila fila, void *info){

   if (fila != NULL)
       incluirInfo(fila->pdLista, info);
}

void* desenfileirarInfo(pDFila fila){

   if (fila != NULL && filaVazia(fila)==0)
       return excluirInfoPos(fila->pdLista, 1);

   /* indica que a fila está vazia */
   return NULL;
}

int filaVazia(pDFila fila){

    if (fila != NULL)
        if (fila->pdLista->quantidade == 0)
           return 1;

    return 0;
}

pDLista NGE(pDFila fila, FuncaoComparacao pfc){ /// Não consegui fazer a função ordenar os itens,
                                                ///  por algum motivo a lista sai sempre com o primeiro valor e -1.
   pDLista listaNge = criarLista();

   pNoh      atual   = fila->pdLista->primeiro;
   pNoh      maior   = atual->prox;
   pNoh      aux     = maior->prox;

   pInfoNGE  infoNge = malloc(sizeof(InfoNGE));

   while(atual != NULL){
      printf("atual dif null\n");
      infoNge->info = atual->info;
      printf("%d\n", infoNge->info);
      while(aux != NULL){
         printf("aux dif null\n");
         if(pfc(aux->info,maior->info) < 0){
            maior = aux;
            printf("maior recebe aux\n");
         }
         printf("aux++ \n");
         aux = aux->prox;
      }
      printf("aux = null\n");
      if(maior->info < atual->info){
         maior->info = -1;
         printf("nge = -1 \n");
      }

      infoNge->nge  = maior->info;
         printf("nge recebe info2 \n");

   incluirInfo(listaNge,infoNge);
      printf("nge incluido na lista \n");
   atual = atual->prox;
      printf("      atual ++\n");
         if(atual->prox == NULL){
            infoNge->info = atual->info;
            infoNge->nge = alocaInt(-1);
            incluirInfo(listaNge,infoNge);
            atual = atual->prox;
         }
         else{
            maior = atual->prox;
            printf("      maior ++\n");
            aux   = atual->prox->prox; // atual->prox buga pois null nao aponta para nada.
            printf("        aux ++\n");
           }
   }
   printf("lista implementada, fim da funcao\n"); // nao é possivel imprimir a lista sem uma função imprimeStruct.
   return listaNge;
}


pDFila fatoracaoPrima(int n){ /// exercicio 2

   pDFila primos = criarFila();
   pNoh   novo   = malloc(sizeof(Noh));

   int primo = 2;
   int aux = 0;
                                                            printf("inicio da funcao\n");
   while (n > 1){
                                                            printf("encontrando primeiro primo\n");
      aux = 0;
      while (n % primo == 0){
         aux ++;
                                                            printf("achei um primo \n");
         n = n/primo;
      }
      if (aux != 0){
                                                            printf("existe primo \n");
          while(aux > 0){
                                                            printf("enquanto primo existe iunclua-o\n");
            incluirInfo(primos->pdLista,alocaInt(primo));
            aux--;
          }
      }
      primo++;
                                                            printf("procurar proximo primo\n");
   }
   return primos;
}










/* ----------------------------------------------------------------------------------- */


#endif // FILA_H
