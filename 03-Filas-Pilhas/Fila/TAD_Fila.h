#ifndef FILA_TAD_H
#define FILA_TAD_H

/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/
/* descritor da fila */
typedef struct dFila  DFila;
typedef DFila*        pDFila;

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDFila   criarFila        ();
void     enfileirarInfo   (pDFila, void *);
void*    desenfileirarInfo(pDFila);
int      filaVazia        (pDFila);

#endif

