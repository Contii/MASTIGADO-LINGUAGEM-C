#ifndef PILHA_H
#define PILHA_H

#include "TAD_Pilha.h"

#include "../ListaLinear/Lista.h"

/* ------------------------------- */
struct dPilha{
    pDLista listinha;
};

/* ----------------------------------------------------------------------------------- */
/* ----------------------------------- FUNÇÕES BASE ---------------------------------- */
/* ----------------------------------------------------------------------------------- */

pDPilha criarPilha(){
    /* aloca memoria para o descritor */
    pDPilha pd = (pDPilha) malloc(sizeof(DPilha));
    /* o descritor da pilha tem os mesmos campos do descritor de lista */
    pd->listinha = criarLista();
    return pd;
}

void empilharInfo(pDPilha pilha, void *info){

   if (pilha != NULL)
       incluirInfo(pilha->listinha, info);
}

void* desempilharInfo(pDPilha pilha){

   if (pilha != NULL && pilhaVazia(pilha)==0)
       return excluirInfoPos(pilha->listinha, pilha->listinha->quantidade);

   /* indica que a pilha está vazia */
   return NULL;
}

int pilhaVazia(pDPilha pilha){

    if (pilha != NULL)
       if (pilha->listinha->quantidade == 0)
           return 1;

    return 0;
}


void troca (pDPilha pilha, int posicao){///////////////////////// exercicio 3

   pDFila fila = criarFila();

   pNoh aux     = malloc(sizeof(Noh));
   int*  auxtopo = pilha->listinha->ultimo->info;
   int  cont    = 1;

   if(posicao == pilha->listinha->quantidade){
      return;
   }

   while(pilha->listinha->quantidade != 0){
      void* info = desempilharInfo(pilha); printf("remove topo\n");
      enfileirarInfo(fila,info); printf("adiciona na fila\n");
   }
   while(cont <= fila->listinha->quantidade){
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

/* ----------------------------------------------------------------------------------- */


#endif
