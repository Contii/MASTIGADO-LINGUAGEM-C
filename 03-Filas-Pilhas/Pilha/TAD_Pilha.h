#ifndef PILHA_TAD_H
#define PILHA_TAD_H
/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/
/* descritor da pilha */
typedef struct dPilha  DPilha;
typedef DPilha*        pDPilha;

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDPilha  criarPilha     ();
void     empilharInfo   (pDPilha, void *);
void*    desempilharInfo(pDPilha);
int      pilhaVazia     (pDPilha);

#endif

