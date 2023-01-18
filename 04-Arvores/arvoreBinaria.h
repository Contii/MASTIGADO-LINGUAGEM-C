#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#include "structs.h"
#include "TAD_Arvore.h"


pDArvore criarArvore(int grau){

   pDArvore arvore        = malloc(sizeof(DArvore));
   arvore->raiz           = NULL;
   arvore->quantidadeNohs = 0;
   arvore->grau           = grau;

   return arvore;
};
pNohArvore paiFolhaMaisAEsquerda(pNohArvore raiz){

    if (raiz->esquerda != NULL)
    {
        if (raiz->esquerda->esquerda == NULL)
            return raiz;
    }
    return paiFolhaMaisAEsquerda(raiz->esquerda);
}

pNohArvore paiFolhaMaisADireita(pNohArvore raiz){///

    if (raiz->direita->direita == NULL)
        return raiz;

    return paiFolhaMaisADireita(raiz->direita);
}

void emOrdem(pNohArvore raiz, FuncaoImpressao fi){

   if (raiz != NULL){
       emOrdem(raiz->esquerda, fi);
       fi(raiz->info);
       emOrdem(raiz->direita, fi);
   }
}

void preOrdem(pNohArvore raiz, FuncaoImpressao fi){

   if (raiz != NULL){
       fi(raiz->info);
       preOrdem(raiz->esquerda, fi);
       preOrdem(raiz->direita, fi);
   }
}

void posOrdem(pNohArvore raiz, FuncaoImpressao fi){

   if (raiz != NULL){
       posOrdem(raiz->esquerda, fi);
       posOrdem(raiz->direita, fi);
       fi(raiz->info);
   }
}

int quantidadeFolhas(pNohArvore raiz){

   if (raiz == NULL)
    return 0;

   if (raiz->esquerda == NULL && raiz->direita == NULL)
      return 1; /*  é uma folha */

   return quantidadeFolhas(raiz->esquerda) +
          quantidadeFolhas(raiz->direita);

}

int grau(pDArvore arvore){

   if(arvore->grau != NULL){
      return arvore->grau;
   }
   else
      return NULL;
}



///................................REMOVER RECURSIVO...................................................
pNohArvore excluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao fc){

    if (raiz != NULL){

     if (fc(raiz->info, info) == 0) {
        /* antes de liberar a memoria do noh, salva a esquerda e a direita */
        pNohArvore auxEsquerda = raiz->esquerda;
        pNohArvore auxDireita  = raiz->direita;
        free(raiz);

        /* caso 1 - remover noh folha*/
        if (auxEsquerda == NULL && auxDireita == NULL){
           return NULL;
        }

        /* caso 3 - remover noh interno com 2 filhos */
        if (auxEsquerda != NULL && auxDireita != NULL){
            pNohArvore paiFolhaEsquerda;
            paiFolhaEsquerda = paiFolhaMaisAEsquerda(auxDireita);

            pNohArvore auxFolhaEsquerda = paiFolhaEsquerda->esquerda;
            auxFolhaEsquerda->esquerda = auxEsquerda;
            auxFolhaEsquerda->direita  = auxDireita;

            paiFolhaEsquerda->esquerda = NULL;

            return auxFolhaEsquerda;
        }
        else{
           /* caso 2 - remover noh interno com 1 filho*/
           if (auxEsquerda != NULL)
              return auxEsquerda;

           return auxDireita;
        }
    }
    else if (fc(raiz->info, info) < 0)
        raiz->esquerda = excluirInfoRecursivo(raiz->esquerda, info, fc);
    else
        raiz->direita = excluirInfoRecursivo(raiz->direita, info, fc);
    }

    return raiz;
}

int excluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc){

   arvore->raiz = excluirInfoRecursivo(arvore->raiz, info, pfc);
   /* estah assumindo que sempre excluira */
   arvore->quantidadeNohs--;
   return 1;
}
///....................................................................................................

///................................EH FOLHA RECURSIVO..................................................
int ehFolhaRecursiva(pNohArvore raiz, void* info1, FuncaoComparacao pfc){

   if(raiz->info == NULL){
    return 0;
   }

   if((pfc(raiz->info,info1) == 0)&& (raiz->esquerda == NULL) && (raiz->direita == NULL)){
     return 1;
   }

   if((pfc(raiz->info,info1) < 0)){
      ehFolhaRecursiva(raiz->esquerda, info1, pfc);
   }

   else
   if((pfc(raiz->info,info1) > 0)){
      ehFolhaRecursiva(raiz->direita, info1, pfc);
   }
}

int ehFolha(pDArvore arvore, void * info1, FuncaoComparacao pfc){

   ehFolhaRecursiva(arvore->raiz, info1, pfc);

}
///....................................................................................................

///................................INCLUIR RECURSIVO...................................................
pNohArvore incluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc){

    /* caso recursivo */
    if (raiz != NULL){
        if (pfc(info, raiz->info) >= 0)
            raiz->esquerda = incluirInfoRecursivo(raiz->esquerda, info, pfc);
        else
            raiz->direita = incluirInfoRecursivo(raiz->direita, info, pfc);

        return raiz;
    }
    else{
       /* caso base */
       pNohArvore novo = malloc(sizeof(NohArvore));
       novo->info     = info;
       novo->esquerda = NULL;
       novo->direita  = NULL;
       return novo;
    }
}

void incluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc){

   arvore->raiz = incluirInfoRecursivo(arvore->raiz, info, pfc);
   arvore->quantidadeNohs++;
}
///....................................................................................................





///................................PERFEITA RECURSIVO...................................................
int eh_Perfeita(pNohArvore raiz){

   if(raiz->direita == NULL && raiz->esquerda == NULL)
      return 0;

   if((raiz->direita != NULL && raiz->esquerda == NULL) || (raiz->direita == NULL && raiz->esquerda != NULL))
      return 1;

   if(raiz->direita!=NULL && raiz->esquerda!=NULL)
      return eh_Perfeita(raiz->direita) + eh_Perfeita(raiz->esquerda);
}
///                                                                                 EXERCICIO 4
int eh_PerfeitaRecursiva(pDArvore araucaria){
   return eh_Perfeita(araucaria->raiz);
}
///....................................................................................................


///................................É DE BUSCA RECURSIVO................................................
int eh_ABB(pNohArvore raiz, void *min, void *max, FuncaoComparacao pfc){

   if(raiz->info == NULL)
      return 0;

   if(pfc(raiz->esquerda,max) <= 0 || pfc(raiz->direita,min) >= 0)
      return 1;

   return (eh_ABB(raiz->esquerda, min, raiz->info, pfc) && eh_ABB(raiz->direita, raiz->info, max, pfc));
}
///                                                                                 EXERCICIO 1
int eh_ABBRecursiva(pDArvore maple, void *min, void *max, FuncaoComparacao pfc){
   return eh_ABB(maple->raiz, maple->raiz, maple->raiz, pfc)
}
///....................................................................................................


///................................DEADEND RECURSIVO...................................................
int deadEnd(pNohArvore raiz, void* min, void* max, FuncaoComparacao pfc){

   if (raiz->info == NULL)
      return 0;

   if (max - min == 2)
      return 1;

   return (deadEnd(raiz->esquerda, min, raiz->info, pfc) || deadEnd(raiz->direita, raiz->info, max, pfc));
}
///                                                                                 EXERCICIO 2
int deadEndRecursivo(pDArvore cerejeira, FuncaoComparacao pfc){
   return deadEnd(cerejeira->raiz, cerejeira->raiz, cerejeira->raiz, pfc);
}
///....................................................................................................


///................................SOMACAMINHO RECURSIVO...............................................
int somaCaminho(PNohArvore raiz, int n){

   if(raiz == NULL && n == 0)
    return 0;

   if(raiz == NULL && n <> 0)
    return 1;
                                        /* função converteInt em utils.h linha 9. */
   return (somaCaminho(raiz->esquerda, (converteInt(n) - raiz->info)) && somaCaminho(raiz->direita, (converteInt(n) - raiz->info)))
}
///                                                                                 EXERCICIO 3
int somaCaminhoRecursivo(pDArvore pinheiro, int n){
   return somaCaminho(pinheiro->raiz, 146);
}
///....................................................................................................
#endif
