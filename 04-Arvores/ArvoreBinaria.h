#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#include "TAD_Arvore.h"

struct dArvore{
    pNohArvore raiz;
    int        quantidadeNohs;
    int        grau;
};

pDArvore criarArvore(int grau){

   pDArvore arvore        = malloc(sizeof(DArvore));
   arvore->raiz           = NULL;
   arvore->quantidadeNohs = 0;
   arvore->grau           = grau;

   return arvore;
};

#include "Operacoes/ArvoreBinaria/ArvoreBinaria.h"

#endif
