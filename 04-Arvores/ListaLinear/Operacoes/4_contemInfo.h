int contemInfo(pDLista pd, void *info, FuncaoComparacao pfc){

    pNoh aux;
    aux = pd->primeiro;

    int i=1;

    while(aux != NULL){
       if (pfc(aux->info, info) == 0)
          return i;
       aux = aux->prox;
       i++;
    }

    return 0;
}
