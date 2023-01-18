#ifndef TAD_PILHA_H
#define TAD_PILHA_H

/* -------------------------- TIPOS DE DADOS -------------------------- */

typedef struct noh  Noh;       /*<-- Agora, struct noh			 se chamará:	Noh */
typedef Noh*        pNoh;      /*<-- Agora, ponteiro para Noh    se chamará:    pNoh */

typedef struct nohd  Nohd;     /*<-- Agora, struct nohd          se chamará:	Nohd  */
typedef Nohd*        pNohd;    /*<-- Agora, ponteiro para Nohd   se chamará:	pNohd */

typedef struct dLista DLista;  /*<-- Agora, struct dLista 		 se chamará:	DLista  */
typedef DLista*       pDLista; /*<-- Agora, ponteiro para DLista se chamará:	pDLista */

typedef struct data  Data;
typedef Data*        pData;

typedef struct formula  For;
typedef For*            pFor;

typedef struct dPilha  DPilha;
typedef DPilha*        pDPilha;

/* ---------------------- PONTEIROS PARA FUNÇÃO ----------------------- */
typedef int   (*FuncaoComparacao)(void *, void *);
typedef void  (*FuncaoImpressao) (void *);
typedef void* (*FuncaoAlocacao)  (void *);
typedef void  (*FuncaoLiberacao) (void *);
typedef int   (*FuncaoPredicado) (void *);
typedef pNohd (*FuncaoLocalizar) (pDLista, FuncaoComparacao);

/* ---------------------------- OPERAÇÕES ----------------------------- */
pDPilha  criarPilha     ();
void     empilharInfo   (pDPilha, void *);
void*    desempilharInfo(pDPilha);
int      pilhaVazia     (pDPilha);

#endif