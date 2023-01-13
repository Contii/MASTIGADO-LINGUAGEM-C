
void incluirInfo(pDLista pd, void *info){

    if (pd == NULL){
        printf("Lista nao existe ainda, nao eh possivel incluir!");
        return;
    }
    /* aloca memoria para guardar a nova info */
    pNoh pNovo = malloc(sizeof(Noh));

    /* guarda a informação no campo "info" do novo noh alocado */
    pNovo->info = info;
    /* como a nova info ficar na última posicao da lista,
       não terá próximo */
    pNovo->prox = NULL;

    /* salva a referencia ao ultimo noh da lista antes de atualizar o descritor */
    pNoh auxUltimo  = pd->ultimo;
    /* o novo noh será identificado como último da lista pelo descritor */
    pd->ultimo      = pNovo;
    /* a lista tem mais um noh */
    pd->quantidade++;

    /* Se o novo noh é o único da lista, o descritor
       precisa atualizar também o ponteiro para o primeiro noh da lista */
    if (pd->primeiro == NULL)
        pd->primeiro = pNovo;
    else{
        /* se não for o único da lista, colocá-o no final da lista */
        auxUltimo->prox = pNovo;
    }
}
