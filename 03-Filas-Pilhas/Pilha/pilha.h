#ifndef PILHA_H
#define PILHA_H

#include "../structs.h"
#include "TAD_Pilha.h"
#include "../ListaLinear/lista.h"

/* ----------------------------------------------------------------------------------- */
/* ----------------------------------- FUNÇÕES BASE ---------------------------------- */
/* ----------------------------------------------------------------------------------- */

pDPilha criarPilha(){
    /* aloca memoria para o descritor */
    pDPilha pd = (pDPilha) malloc(sizeof(DPilha));
    /* o descritor da pilha tem os mesmos campos do descritor de lista */
    pd->pdLista = criarLista();
    return pd;
}

void empilharInfo(pDPilha pilha, void *info){

   if (pilha != NULL)
       incluirInfo(pilha->pdLista, info);
}

void* desempilharInfo(pDPilha pilha){

   if (pilha != NULL && pilhaVazia(pilha)==0)
       return excluirInfoPos(pilha->pdLista, pilha->pdLista->quantidade);

   /* indica que a pilha está vazia */
   return NULL;
}

int pilhaVazia(pDPilha pilha){

    if (pilha != NULL)
       if (pilha->pdLista->quantidade == 0)
           return 1;

    return 0;
}

/* ----------------------------------------------------------------------------------- */
/* ---------------------------------- OUTRAS FUNÇÕES --------------------------------- */
/* ----------------------------------------------------------------------------------- */
void troca (pDPilha pilha, int posicao){///////////////////////// exercicio 3
   pDFila fila = criarFila();
   pNoh aux     = malloc(sizeof(Noh));
   int*  auxtopo = pilha->pdLista->ultimo->info;
   int  cont    = 1;

   if(posicao == pilha->pdLista->quantidade){
      return;
   }
   while(pilha->pdLista->quantidade != 0){
      void* info = desempilharInfo(pilha); printf("remove topo\n");
      enfileirarInfo(fila,info); printf("adiciona na fila\n");
   }
   while(cont <= fila->pdLista->quantidade){
      if(cont == posicao){ printf(" se esta na hora de trocar\n");
         empilharInfo(pilha,auxtopo); printf(" empilha o topo na posicao\n");
         cont++; printf("cont ++\n");
      }
      else
      empilharInfo(pilha,desenfileirarInfo(fila)); printf("empilha normalmente\n");
      cont++; printf("cont ++\n");
   }
   printf("troca concluida \n");
}
#endif
