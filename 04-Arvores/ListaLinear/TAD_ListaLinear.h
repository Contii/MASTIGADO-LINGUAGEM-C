#ifndef LISTA_TAD_H
#define LISTA__TAD_H
/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/
typedef struct noh  Noh;
typedef Noh*        pNoh;

/* descritor da lista */
typedef struct dLista  DLista;
typedef DLista*        pDLista;

/* 3 tipos que representam ponteiros para função */
typedef int   (*FuncaoComparacao)(void *, void *);
typedef void  (*FuncaoImpressao) (void *);
typedef void* (*FuncaoAlocacao)  (void *);

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDLista  criarLista    ();
void     incluirInfo   (pDLista, void *);
int      excluirInfo   (pDLista, void *, FuncaoComparacao);
void*    excluirInfoPos(pDLista, int);
int      contemInfo    (pDLista, void *, FuncaoComparacao);
void*    obtemInfo     (pDLista, int);
void     imprimirLista (pDLista, FuncaoImpressao);
void     destruirLista (pDLista);
pDLista  duplicarLista (pDLista, FuncaoAlocacao);
/* o parametro int estabelece a posicao da lista onde a divisao deve acontecer */
pDLista  dividirLista  (pDLista, int);

#endif

