void destruirListaRecursiva(pNoh atual){
    if (atual == NULL)
        return;
    destruirListaRecursiva(atual->prox);
    free(atual);
}

/* -------------------------------------*/
void destruirLista(pDLista pd){
   destruirListaRecursiva(pd->primeiro);
   pd->primeiro   = NULL;
   pd->ultimo     = NULL;
   pd->quantidade = 0;
}

