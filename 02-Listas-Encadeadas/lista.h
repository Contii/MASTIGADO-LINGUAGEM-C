#ifndef LISTA_H
#define LISTA_H

#include "structs.h"
#include "TAD_ListaLinear.h"

/* ----------------------------------------------------------------------------------- */
/* ----------------------------------- FUNÇÕES BASE ---------------------------------- */
/* ----------------------------------------------------------------------------------- */
pDLista criarLista(){
/* Cria um ponteiro do tipo pDLista e aloca memoria para o mesmo.*/
    pDLista pd = malloc(sizeof(DLista));
/* Seta os campos com os valores default */
    pd->quantidade = 0;
    pd->primeiro   = NULL;
    pd->ultimo     = NULL;
    return pd;
}
void    resetarLista(pDLista pd){
/* Esta função reseta a lista pelo fato de o ponteiro descritor
    continuar declarado como contendo zero elementos.*/
   pNoh atual;
   atual = pd->primeiro;
   while(atual != NULL){
      pNoh aux = atual->prox;
      free(atual);
      atual = aux;
   }
   pd->primeiro   = NULL;
   pd->ultimo     = NULL;
   pd->quantidade = 0;
}
void    incluirInfo(pDLista pd, void *info1){
/* Verifica se a lista existe para depois trabalhar. pd = ponteiro descritor. */
   if (pd == NULL){
      printf("Lista nao existe ainda, nao eh possivel incluir!");
   return;
   }
   
/* Cria um ponteiro para NOH e aloca memoria para o mesmo. */
   pNoh pNovo = malloc(sizeof(Noh));
/* Atribui para o campo INFO de NOH, INFO1 fornecida pelo parâmetro da função. */
   pNovo->info = info1;
/* A inclusão ocorre para ser o ultimo noh da lista, portanto, o campo PROX = NULL. */
   pNovo->prox = NULL;
   
/* Cria um ponteiro AUXNOH para salvar o ULTIMO noh apontado por PD antes de
    atualizar a lista, não há alocação pois AUXNOH não será mais usado após o
     uso da função. */
   pNoh auxUltimo  = pd->ultimo;

/* Será atribuído ao ponteiro ULTIMO, o NOH. */
   pd->ultimo      = pNovo;
/* Atualiza a quantidade de nohs na lista.*/
   pd->quantidade++;

/* Se NOH for o único da lista, o descritor precisa ser atualizado também, no
    campo PRIMEIRO, com NOH. Portanto, se PRIMEIRO = NULL, a atribuição é feita. */
   if (pd->primeiro == NULL)
      pd->primeiro = pNovo;
   else{
/* Por fim, se não for o único da lista, colocá-o no final da mesma. */
      auxUltimo->prox = pNovo;
   }
}
void    incluirInfoNoInicio(pDLista pd, void *info1){
   if (pd == NULL)
   {
      printf("Lista nao existe ainda, nao eh possivel incluir!");
      return;
   }
   pNoh pNovo = malloc(sizeof(Noh));
   pNovo->info = info1;
   pNovo->prox = pd->primeiro;

   if(pd->ultimo == NULL){
    pd->ultimo = pNovo;
   }
   pd->primeiro = pNovo;
   pd->quantidade++;
}
int     excluirInfo(pDLista pd, void *info1, FuncaoComparacao pfc){
/* Cria dois NOH, atuel e anterior para trabalhar dentro da função.*/
   pNoh atual, anterior;
/* Atribui para atual, o primeiro elemento da lista, e para ANTERIOR, NULL. */
   atual      = pd->primeiro;
   anterior   = NULL;

/* Encontra INFO1 na lista e da break. */
   while(atual != NULL){
      if (pfc(atual->info, info1) == 0)
         break;
/* Caso ATUAL nao seja, ANTERIOR recebe ela e ATUAL o prox. */
   anterior   = atual;
   atual = atual->prox;
   }

   if (atual != NULL){
/* Se INFO1 existe na lista. */

/* Verifica se é o ULTIMO. Caso seja, PRIMEIRO recebe PROX.
    Pois atual deverá ser excluído. */
      if (atual == pd->primeiro){
            pd->primeiro = atual->prox;
      }
/* Verifica se é o ULTIMO. Caso seja, ULTIMO recebe ANTERIOR. e o campo
    PROX de ANTERIOR recebe NULL. Pois ATUAL deverá ser excluído. */
      else
      if (atual == pd->ultimo){
            pd->ultimo = anterior;
            anterior->prox  = NULL;
      }
/* Caso esteja no meio da lista... */
      else{
      anterior->prox = atual->prox;
      }
   pd->quantidade--;
   free(atual);
      return 1;
   }
   return 0;
}
void    imprimirLista(pDLista pd, FuncaoImpressao pfi){
/* Criação de um ponteiro AUXNOH que receberá o primeiro elemento da lista. */
    pNoh aux;
    aux = pd->primeiro;
/* Até que AUXNOH aponte para NULL, assim como o ULTIMO da lista, o comando
     WHILE ira chamar a FuncaoImpressao fornecida como parâmetro. */
    while(aux != NULL){
       //printf("%d", *(((int *)aux->info))); /* é preciso dizer qual o tipo de INFO. */
       pfi(aux->info); /* A FuncaoImpressao não imprime o NOH mas sim o campo INFO. */

       aux = aux->prox;
    }
}
int     contemInfo(pDLista pd, void *info1, FuncaoComparacao pfc){
/* Utilizando um AUXNOH, atribui a ele o campo primeiro para então, percorrer toda a
    lista em busca do INFO1, utilizando para isso a funcaocomparacao.  */
    pNoh aux;
    aux = pd->primeiro;
   int i=1;
   while(aux != NULL){
      if (pfc(aux->info, info1) == 0)
         return i;
   aux = aux->prox;
   i++;
   }
      return 0;
}
/* ----------------------------------------------------------------------------------- */
/* -------------------------------- FUNÇÕES RECURSIVAS ------------------------------- */
/* ----------------------------------------------------------------------------------- */
void    imprimirListaRecursivamente(pDLista pd, FuncaoImpressao pfi){
   imprimirListaRecursivo(pd->primeiro, pfi);
}
void    imprimirListaRecursivo(struct noh *atual, FuncaoImpressao pfi){
   if (atual == NULL)
      return;
   pfi(atual->info);
   imprimirListaRecursivo(atual->prox, pfi);
}

void    resetarListaRecursiva(pNoh atual){
   if (atual == NULL)
      return;
   resetarListaRecursiva(atual->prox);
   free(atual);
}
void    resetarListaRecursivamente(pDLista pd){
   resetarListaRecursiva(pd->primeiro);
   pd->primeiro   = NULL;
   pd->ultimo     = NULL;
   pd->quantidade = 0;
}
/* ----------------------------------------------------------------------------------- */
/* ---------------------------------- OUTRAS FUNÇÕES --------------------------------- */
/* ----------------------------------------------------------------------------------- */
int     quantosNoh(pDLista lista){
   pNoh atual = lista->primeiro;
   int quantidade = 0;
   while(atual != NULL){
      quantidade ++;
      atual =  atual->prox;
   }
   return quantidade;
}
pDLista duplicarLista(pDLista pd, FuncaoAlocacao pfa){
/* Crio uma nova lista para alocar os valores. */
   pDLista pNovaLista = criarLista();

/* Crio um noh ATUAL para perceorrer a lista. */
   pNoh atual = pd->primeiro;

/* Enquanto ATUAL não chegar ao final da lista.*/
   while (atual != NULL){

/* Cria um ponteiro VOID AUXINFO e atribui a ele a info de ATUAL,
    ao mesmo tempo que faz a chamada da FunçãoAlocação fornecica
     pelo parâmetro. */
     void *auxInfo = pfa(atual->info); /* A funcaoComparacao deve ser alocaInfoInt, pois recebe ponteiro void.
                                           alocaInt recebe INT portanto, receberia o endereço de memoria. */

/* Adiciona AUXINFO na nova lista, fazendo a chamada de incluirInfo.*/
     incluirInfo(pNovaLista, auxInfo);

/* Atual segue para copiar o proximo elemento da lista. */
     atual = atual->prox;
   }
   return pNovaLista; /* Um ponteiro pDLista deverá resgatar este return. */
}
pDLista split(pDLista lista, FuncaoPredicado pfp, FuncaoComparacao pfc){
/* Função que retorna nova lista de acordo com a FuncaoPredicado. */
   pDLista ListaNova = criarLista();
   pNoh atual = lista->primeiro;
   pNoh aux = NULL;

   while(atual != NULL){
      aux = atual->prox; /* Necessario para recuperar o encadeamento da lista, caso info seja excluida. */
      if(pfp(atual->info) == 1){

      incluirInfo(ListaNova,atual->info); /* Inclusão do predicado na lista nova. */
      excluirInfo(lista,atual->info,pfc); /* info sendo excluida. */
      }
      atual = aux; /* recuperando o encadeamento. */
   }
   return ListaNova;
}
int     contida (pDLista lista1, pDLista lista2, FuncaoComparacao pfc){
  /* Verifica se uma lsita esta dentro de outra lista. */
   pNoh atual1, atual2;
   int flag;
   atual1 = lista1->primeiro;
   atual2 = lista2->primeiro;
   
   if(lista1->quantidade > lista2->quantidade)
      return 0;
   while(atual1 != lista1->ultimo){
      flag = 0;
      atual2 = lista2->primeiro;
      while(atual2 != lista2->ultimo){
         if(pfc(atual1->info , atual2->info) == 0)
            flag = 1;
         atual2 = atual2->prox;
      }
      if(flag == 0)
         return 0;
      atual1 = atual1->prox;
   }
   return 1;
};
pDLista dividirLista(pDLista lista,void* info, FuncaoComparacao pfc){
/* Divide a lista a partir de info, o prox dele sera o primeiro da novaLista. */
   pDLista novaLista = criarLista();
   pNoh aux = NULL;
   pNoh atual = lista->primeiro; /* Atribui a ATUAL, o PRIMEIRO */

   while (atual != NULL){ /* Percorre a lista com ATUAL */
      if(pfc(info,atual->info) == 0){ /* Compara se a info fornecida para a divisão esta em ATUAL */
         novaLista->primeiro = atual->prox; /* Se verdadeiro, NOVALISTA receberá o ATUAL->PROX */
         novaLista->ultimo = lista->ultimo; /* Assim, NOVALISTA tem o PROX de INFO como PRIMEIRO e receberá como ULTIMO, o ULTIMO da LISTA original. */
         atual->prox = NULL; /* Atribui para o prox de ATUAL, (que agora deverá ser o ULTIMO da original) NULL */
         lista->ultimo = atual;
         novaLista->quantidade = quantosNoh(novaLista); /* Atualiza quantidade de NOVALISTA com a função QUANTOSNOH */
         lista->quantidade = quantosNoh(lista);
         return novaLista;
      }
   atual = atual->prox; /* caso ATUAL não seja a INFO, passa para o PROX noh */
   }
   return novaLista; /* Retorna a nova lista formada. */
}
pDLista dividirLista2(pDLista pListaOriginal, int pos){
/* Corta uma lista no meio e cria duas iguais 12345678 vira 1234 1234 (função nosense) */
/* Cria a nova lista para receber a nova que se formará. */
    pDLista pNovaLista = criarLista();

/* Percorre a lista original para encontrar a posicao onde deve ser dividida. */
    pNoh atual    = pListaOriginal->primeiro;
    int  contador = 1;

/* A condicao do loop preve o caso em que a posicao seja maior que a
       quantidade de nohs da lista. */
    while (contador < pos && atual != NULL){
       atual = atual->prox;
       contador++;
    }
/* Verifica se alcancou o final da lista. */
    if (atual != NULL){
       /* atualiza o descritor da nova lista */
       pNovaLista->primeiro   = atual->prox;
       pNovaLista->ultimo     = pListaOriginal->ultimo;
       pNovaLista->quantidade = pListaOriginal->quantidade - contador;
       /* atualiza o descritor da lista original */
       pListaOriginal->ultimo = atual;
       /* finaliza a lista original */
       atual->prox = NULL;
    }
    return pNovaLista;
}
pNoh    encontraMaior(pDLista lista, FuncaoComparacao pfc){
    pNoh atual      = lista->primeiro;
    pNoh aux        = NULL;
    pNoh maior      = atual;
    /* pNohd maior     = malloc(sizeof(Nohd)); */

    /* assume que o maior info eh o primeiro da lista
    maior->info = atual->info; */

    while(atual != NULL){
       /* compara o maior ateh agora com a info do noh atual */
       if(pfc(atual->info, maior->info) < 0){
          maior = atual;
          /*maior->info = atual->info;
          maior->prox = atual;
          maior->ant  = aux; */
       }
       aux   = atual;
       atual = atual->prox;
    }
   return maior;
}
pNoh    encontraMenorPessini(pDLista lista, FuncaoComparacao pfc){
    pNoh atual      = lista->primeiro;
    pNoh aux        = NULL;
    pNoh menor      = atual;
    /* pNohd menor     = malloc(sizeof(Nohd)); */

    /* assume que o menor info eh o primeiro da lista
    menor->info = atual->info; */

    while(atual != NULL){
       /* compara o menor ateh agora com a info do noh atual */
       if(pfc(atual->info, menor->info) > 0){
          menor = atual;
          /*menor->info = atual->info;
          menor->prox = atual;
          menor->ant  = aux; */
       }
       aux   = atual;
       atual = atual->prox;
    }
   return menor;
}
void    menorNoInicioPessini(pDLista lista, FuncaoComparacao pfc, FuncaoLocalizar pfl){
   pNoh atual  = lista->primeiro;
/*   pNoh aux    = lista->primeiro; */
   pNoh menor = pfl(lista,pfc); /* encontra o menor */

   if(pfc(atual->info,menor->info) == 0){ /*caso o valor de menor seja igual ao de primeiro para */
          return;
   }

   /* salva a info do atual antes de atribuir a info do menor */
   void *auxInfo = atual->info;
   atual->info   = menor->info; /* atribui o valor de menor para o primeiro da lista. */
   menor->info   = auxInfo;   /* atribui o valor do primeiro para o menor noh. */
}
pDLista uniao(pDLista lista1, pDLista lista2, FuncaoComparacao pfc){
   pDLista novaLista = criarLista();
   pNoh atual  = lista1->primeiro;
   pNoh atual2 = lista2->primeiro;

   while( (atual != NULL) || (atual2 != NULL) ){
      if(contemInfo(novaLista,atual->info,pfc) == 1){
         atual = atual->prox;
      }
   }
}
pDLista uniao2(pDLista lista1, pDLista lista2, FuncaoComparacao pfc){
    /* Escreve lista 1 e depois escreve os elementos de lita 2 que nao estavam em 1. */
    pDLista lista3;
    pNoh atual1, atual2;
    lista3 = criarLista();

    atual1 = lista1->primeiro;
    atual2 = lista2->primeiro;

    while (atual1 != NULL || atual2 != NULL){
        if(atual1 != NULL){
            if(contemInfo(lista3, atual1->info,pfc) == 0){
                incluirInfo(lista3, atual1->info);
            }
            atual1 = atual1->prox;
        }
        if(atual2 != NULL){
            if(contemInfo(lista3, atual2->info,pfc) == 0){
                incluirInfo(lista3, atual2->info);
            }
            atual2 = atual2->prox;
        }
    }
    return lista3;
}
pDLista intersecao(pDLista lista1, pDLista lista2, FuncaoComparacao pfc){ // nao funciona
    /* Imprime somente os elementos repetidos das listas.*/
    pDLista lista3;
    pNoh atual1, atual2;
    lista3 = criarLista();

    atual1 = lista1->primeiro;
    atual2 = lista2->primeiro;

    while (atual1 != NULL || atual2 != NULL){
        if(atual1 != NULL){
            if(contemInfo(lista3, atual1->info,pfc) == 0){
                if(contemInfo(lista2, atual1->info,pfc) != 0){
                    incluirInfo(lista3, atual1->info);
                }
            }
            atual1 = atual1->prox;
        }
        if(atual2 != NULL){
            if(contemInfo(lista3, atual2->info,pfc) == 0){
                if(contemInfo(lista1, atual2->info,pfc) == 0){
                    incluirInfo(lista3, atual2->info);
                }
            }
            atual2 = atual2->prox;
        }
    }
    return lista3;
}
int 	disjunta (pDLista lista1, pDLista lista2, FuncaoComparacao pfc){ // bugada
    pNoh atual1, atual2;
    atual1 = lista1->primeiro;
    atual2 = lista2->primeiro;

    while (atual1 != NULL || atual2 != NULL){
        if(atual1 != NULL){
            if(contemInfo(atual2->info, atual1->info,pfc) != 0){
                atual1 = atual1->prox;
                if(contemInfo(atual2->info, atual1->info,pfc) == 0){
                    return 0;

                }
            }
        }
        atual2 = atual2->prox;
    }
 return 1;
}
void 	ordenar (pDLista lista, void *novainfo){ // bugada
   pNoh atual, frente, aux;
   atual = lista->primeiro;
   frente = atual->prox;

   while((frente->prox != NULL) && (atual->info < novainfo)){
      atual = frente;
      frente = frente->prox;
   }
   if(lista->primeiro == NULL){
      lista->primeiro = novainfo;
      lista->primeiro->prox = atual;
   }
   else{
      frente->prox = novainfo;
      lista->primeiro = frente;
   }
}
/*17-Escreva uma funçao para incluir uma informaçao em uma lista encadeada em uma posiçao específica.
*/
/*18-Implemente uma funçao que receba como parametro um vetor e o tranforma em uma lista encadeada, conforme o prototipo a seguir:
pDLista constroiLista (void * vet[ ], int tam){} */
/*19-Implemente tambem a operaça o inversa:
void* constroiVetor (pDLista lista){} */
#endif