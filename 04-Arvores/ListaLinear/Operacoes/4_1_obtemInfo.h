void* obtemInfo(pDLista pd, int pos){

    pNoh aux = pd->primeiro;
    int i=1;

    while(aux != NULL){
       if (i == pos)
          return aux->info;
       aux = aux->prox;
       i++;
    }

    return NULL;
}
