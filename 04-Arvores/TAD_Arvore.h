#ifndef TAD_ARVORE_H
#define TAD_ARVORE_H
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

typedef struct dFila  DFila;
typedef DFila*        pDFila;

typedef struct dPilha  DPilha;
typedef DPilha*        pDPilha;

typedef struct nohArvore  NohArvore;
typedef NohArvore*        pNohArvore;

typedef struct dArvore  DArvore;
typedef DArvore*        pDArvore;

/* ---------------------- PONTEIROS PARA FUNÇÃO ----------------------- */
typedef int   (*FuncaoComparacao)(void *, void *);
typedef void  (*FuncaoImpressao) (void *);
typedef void* (*FuncaoAlocacao)  (void *);
typedef void  (*FuncaoLiberacao) (void *);
typedef int   (*FuncaoPredicado) (void *);
typedef pNohd (*FuncaoLocalizar) (pDLista, FuncaoComparacao);

/* ---------------------------- OPERAÇÕES ----------------------------- */

pDArvore   criarArvore(int);
void       incluirInfo    (pDArvore, void *, FuncaoComparacao);
int        excluirInfo    (pDArvore, void *, FuncaoComparacao);
pNohArvore buscarInfo     (pDArvore, void *, FuncaoComparacao);
int        quantidadeNohs (pDArvore);

/* ---------------------------- PERCURSOS ----------------------------- */
void      emOrdem  (pNohArvore, FuncaoImpressao);
void      preOrdem (pNohArvore, FuncaoImpressao);
void      posOrdem (pNohArvore, FuncaoImpressao);

int       grau            (pDArvore);
int       nivel           (pDArvore, void *, FuncaoComparacao);
int       quantidadeFolhas(pNohArvore);
int       ehFolha         (pDArvore, void *, FuncaoComparacao);
int       arvoreVazia     (pDArvore);

#endif

