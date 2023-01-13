#ifndef DESEMPILHAR_INFO_PILHA_H
#define DESEMPILHAR_INFO_PILHA_H

void* desempilharInfo(pDPilha pdPilha){

   if (pdPilha != NULL && pilhaVazia(pdPilha)==0)
       return excluirInfoPos(pdPilha->pdLista, pdPilha->pdLista->quantidade);

   /* indica que a pilha está vazia */
   return NULL;
}

#endif
