#ifndef FILA_H
#define FILA_H

#include "../structs.h"
#include "TAD_Fila.h"
#include "../ListaLinear/lista.h"

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

/* ----------------------------------------------------------------------------------- */
/* ---------------------------------- OUTRAS FUNÇÕES --------------------------------- */
/* ----------------------------------------------------------------------------------- */

#endif