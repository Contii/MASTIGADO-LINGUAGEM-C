#ifndef TAD_LISTALINEAR_H
#define TAD_LISTALINEAR_H

/* -------------------------- TIPOS DE DADOS -------------------------- */

typedef struct noh  Noh;       /*<-- Agora, struct noh			 se chamar�:	Noh */
typedef Noh*        pNoh;      /*<-- Agora, ponteiro para Noh    se chamar�:    pNoh */

typedef struct nohd  Nohd;     /*<-- Agora, struct nohd          se chamar�:	Nohd  */
typedef Nohd*        pNohd;    /*<-- Agora, ponteiro para Nohd   se chamar�:	pNohd */

typedef struct dLista DLista;  /*<-- Agora, struct dLista 		 se chamar�:	DLista  */
typedef DLista*       pDLista; /*<-- Agora, ponteiro para DLista se chamar�:	pDLista */

typedef struct data  Data;
typedef Data*        pData;

typedef struct formula  For;
typedef For*            pFor;

/* ---------------------- PONTEIROS PARA FUN��O ----------------------- */

typedef int   (*FuncaoComparacao)(void *, void *);
typedef void  (*FuncaoImpressao) (void *);
typedef void* (*FuncaoAlocacao)  (void *);
typedef void  (*FuncaoLiberacao) (void *);
typedef int   (*FuncaoPredicado) (void *);
typedef pNohd (*FuncaoLocalizar) (pDLista, FuncaoComparacao);

/* ---------------------------- OPERA��ES ----------------------------- */

pDLista  criarLista    ();
void     incluirInfo   (pDLista, void *);
void     incluirInfoNoInicio(pDLista pd, void *info1);
int      excluirInfo   (pDLista, void *, FuncaoComparacao); /* o retorno int indica se a informacao procurada foi excluida*/
void*    excluirInfoPos(pDLista, int);
int      contemInfo    (pDLista, void *, FuncaoComparacao); /* o retorno int indica a posicao da informacao procurada dentro da lista*/
void*    obtemInfo     (pDLista, int);
void     imprimirLista (pDLista, FuncaoImpressao);
void     destruirLista (pDLista);
void     resetarLista  (pDLista);
pDLista  duplicarLista (pDLista, FuncaoAlocacao);
pDLista  dividirLista  (pDLista,void*, FuncaoComparacao); /* o parametro int estabelece a posicao da lista onde a divisao deve acontecer */
pDLista  dividirLista2(pDLista pListaOriginal, int pos);
#endif