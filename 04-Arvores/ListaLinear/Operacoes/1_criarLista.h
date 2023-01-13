#ifndef CRIAR_LISTA_H
#define CRIAR_LISTA_H

pDLista criarLista(){
    /* aloca memoria para o descritor */
    pDLista pd = malloc(sizeof(DLista));
    /* seta os campos com os valores default */
    pd->quantidade = 0;
    pd->primeiro   = NULL;
    pd->ultimo     = NULL;
    return pd;
}

#endif
