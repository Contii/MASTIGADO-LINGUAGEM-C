#ifndef DESENFILEIRAR_INFO_FILA_H
#define DESENFILEIRAR_INFO_FILA_H

void* desenfileirarInfo(pDFila pdFila){

   if (pdFila != NULL && filaVazia(pdFila)==0)
       return excluirInfoPos(pdFila->pdLista, 1);

   /* indica que a fila está vazia */
   return NULL;
}

#endif
