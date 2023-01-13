#ifndef CRIAR_FILA_H
#define CRIAR_FILA_H

pDFila criarFila(){
    /* aloca memoria para o descritor */
    pDFila pd = (pDFila) malloc(sizeof(DFila));
    /* o descritor da fila tem os mesmos campos do descritor de lista */
    pd->pdLista = criarLista();
    return pd;
}

#endif
