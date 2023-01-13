int excluirInfo(pDLista pd, void *info, FuncaoComparacao pfc){

    pNoh atual, ant;

    atual = pd->primeiro;
    ant   = NULL;

    /* encontra a informação na lista */
    while(atual != NULL){
       if (pfc(atual->info, info) == 0)
          break;
       ant   = atual;
       atual = atual->prox;
    }

    /* verifica se a info existe na lista */
    if (atual != NULL){
        /* eh o primeiro da lista */
        if (atual == pd->primeiro)
            pd->primeiro = atual->prox;
        else
        /* eh o ultimo da lista */
        if (atual == pd->ultimo){
            pd->ultimo = ant;
            ant->prox  = NULL;
        } else
             /* estah no meio da lista */
             ant->prox = atual->prox;

        pd->quantidade--;
        free(atual);
        return 1;
    }

    return 0;
}
