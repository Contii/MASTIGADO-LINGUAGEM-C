#ifndef ESTAVAZIA_FILA_H
#define ESTAVAZIA_FILA_H

int filaVazia(pDFila pdFila){

    if (pdFila != NULL)
        if (pdFila->pdLista->quantidade == 0)
           return 1;

    return 0;
}
#endif
