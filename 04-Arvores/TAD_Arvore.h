#ifndef ARVORE_TAD_H
#define ARVORE_TAD_H
/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/

typedef struct nohArvore  NohArvore;
typedef NohArvore*        pNohArvore;


typedef struct dArvore  DArvore;
typedef DArvore*        pDArvore;


typedef int  (*FuncaoComparacao)(void*, void*);
typedef void (*FuncaoImpressao) (void*);

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDArvore   criarArvore(int);

void       incluirInfo    (pDArvore, void *, FuncaoComparacao);
int        excluirInfo    (pDArvore, void *, FuncaoComparacao);
pNohArvore buscarInfo     (pDArvore, void *, FuncaoComparacao);
int        quantidadeNohs (pDArvore);

/* percursos */
void      emOrdem  (pNohArvore, FuncaoImpressao);
void      preOrdem (pNohArvore, FuncaoImpressao);
void      posOrdem (pNohArvore, FuncaoImpressao);

int       grau            (pDArvore);
int       nivel           (pDArvore, void *, FuncaoComparacao);
int       quantidadeFolhas(pNohArvore);
int       ehFolha         (pDArvore, void *, FuncaoComparacao);
int       arvoreVazia     (pDArvore);

#endif

