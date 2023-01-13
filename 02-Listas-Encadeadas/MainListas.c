#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"
#include "UtilsForever.h"


/* ----------------------------------------------------------------------------------- */
/* Perceba o uso dos includes, ao trabalhar com listas, utilizarei minha biblioteca
    utils.h para poder usar algumas funções, e a biblioteca de listas.h para todas as que
     envolvem listas. perceba que dentro destas bibliotecas incluo a TAD.h e a Structs.h
      para poder trabalhar com as structs e com os typedefs que defini por padrão.

   Dentro de Utils.h incluo Strucs.h e dentro de Listas.h também faço esta inclusão.
    Para que não ocorra uma sobreposição de codigos struct, o #ifndef(if not defined)
     e o #define são utilizados nas mesmas. Desta forma, ao chamar a struct.h em uma
      biblioteca pela segunda vez, a mesma sera desconsiderada, por ja estar escrita
       no codigo anteriormente.

   Assim, posso incluir diversas bibliotecas que fazem o include das mesmas bibliotecas
    sem ter problemas com inclusões repetidas. */

int main(){

/* ----------------------------------------------------------------------------------- */
/* Dando continuidade a nossa implementação de uma biblioteca genérica, estaremos
    agora adentrando no conteúdo de Listas Encadeadas, para agrupar informações e ter
     acesso a elas, utilizando funções de organização, alteração, inclusão, e qualquer
      outro tipo de função genericamente implementada para trabalhar com esses dados
       a maneira que seja necessário. */

/* Perceba que para o uso deste MAIN, foi necessario a inclusão de uma nova biblioteca,
    Listas.h, nela implementarei todas as funções para trabalhar com listas. */

/* Outra biblioteca importante, mas não estritamente necessária, será TAD_ListaLinear.h
    nela, toda a definição de dados e funções será definida, como typedefs por exemplo.
     desta forma nosso codigo ficará mais limpo, e possibilitará uma consulta mais
      rápida, na hora de conferir quais os tipos de dados e como devem ser tratados
       ao implementar uma nova função. */

/* A biblioteca Utils.h que utilizarei é a mesma que do programa MASTIGADO anterior,
    Mas com algumas modificações, pois anteriormente fiz as declarações de typedefs e
     structs enquanto dava a explicação sobre os mesmos. Agora com as bibliotecas novas,
      estas definições se encontram em TAD.h e Structs.h. O que mudou no Utils.h foi
       que comentei as linhas onde fazia estas definições. */

/* ------------------------------------- ATENÇÃO ------------------------------------- */
/* LEIA O COMENTARIO A SEGUIR QUANTAS VEZES FOR NECESSARIO PARA ENTENDER A LOGICA POR
    TRÁS DA LISTA, IREI ADICIONAR UMA IMAGEM QUE REPRESENTA A CRIAÇÃO DA LISTA PARA
     PODER ABSORVER MELHOR ESTE RACIOCÍNIO.


   Uma lista é composta por dois tipos de dados. Um deles é o dLista (descitor da lista).
    O descritor tem como objetivo apontar para o início e para o fim da lista, assim como
     contar quantas informações a lista possui. Portanto, será atribuido a ele 3 dados.

     struct dLista{
     struct noh* primeiro;
     struct noh* ultimo;
     int         quantidade;
     }

   Desta forma, ao criar uma nova lista, possuiremos uma scruct dLista vazia, sem info
    no primeiro, no ultimo e com quantidade setada em zero. Perceba que PRIMEIRO e
     ULTIMO são ponteiros para o tipo STRUCT NOH, o nosso segundo tipo de dado
      necessário para a criação de uma lista.

    struct noh{
    void       *info;
    struct noh *prox;
    }

   Composto por um ponteiro VOID chamado INFO, o noh armazenará a informação que foi
    incluída na lista. O campo PROX será um ponteiro para um outro noh, dando sequência
     para a acessibilidade de nossa lista.

   Desta forma, saberemos somente quem é o primeiro e o ultimo noh de nossa lista, assim
    como de quantos noh a lista é composta. Para percorrer ela, precisaremos acessar os
     nohs um por um, ate que encontremos a informação que queremos trabalhar. */

/* ----------------------------------------------------------------------------------- */

/* Leia a definição do descritor de listas struct dLista em Structs.h e em seguida,
    observe a nomenclatura atribuida a essa struct em TAD.h*/

/* Na seguinte linha, chamo a função criarLista para construir um descritor chamado
    Lista1. Veja também como essa função trabalha em Lista.h. */

//   pDLista Lista1 = criarLista();

/* Temos então uma lista vazia, agora poderemos começar a incluir informações na mesma,
    Uso então a função incluirInfo que recebe um ponteiro PDLISTA e um ponteiro para
     FUNÇÃO. Perceba o uso de tudo o que estudamos até agora começar a tomar forma. */


//   incluirInfo(Lista1, alocaInt(5)); /* alocaInt é generico e recebe um parametro.*/
//   incluirInfo(Lista1, alocaInt(8));
//   incluirInfo(Lista1, alocaInt(7));
//   incluirInfo(Lista1, alocaInt(2));
//   incluirInfo(Lista1, alocaInt(1));
//   incluirInfo(Lista1, alocaInt(22));

//   printf("\n\nResultado da inclusao: \n");
//   imprimirLista(Lista1, imprimeInt); /* uso novamente do rolê genérico. */

/* Vamos ver agora se a lista possui um numero, para isso, vamos alocá-lo também, pois
    a função contemInfo nao recebe INT e sim ponteiro VOID. Poderíamos usar toda a aloca
     ção de PX que fizemos no programa anterior, mas assim estaríamos deixando de lado
      nossa implementação alocaInt genérica que simplifica nosso main. */
//   int r;
//   r = contemInfo(Lista1, alocaInt(8), comparaInt);

/* De acordo com o retorno booleano de contemInfo, saberemos se a info está
    ou não presente na lista. */
//   if (r==0)
//      printf("\nInformacao  Nao estah na lista!");
//   else
//      printf("\nInformacao estah na lista!");

/* Vamos agora excluir uma info da lista e ver como ela fica. */
//   printf("\n\nResultado da exclusao: ");

/* Para a função excluir, precisamos passar como parametros a lista, um valor, no caso
    chamo a função alocaInt que me retornará o ponteiro para INT, e a devida função de
     comparação do determinado tipo, comparaInt. */
//   excluirInfo(Lista1, alocaInt(7), comparaInt);
//   imprimirLista(Lista1, imprimeInt);
//   printf("\n");

/* Vamos agora destruir nossa lista. */

//   resetarLista(Lista1);

/* Vamos agora fazer uma inclusão e imprimi-la novamente. */
//   printf("\nLista nova: ");
//   incluirInfo(Lista1, alocaInt(1));
//   incluirInfo(Lista1, alocaInt(4));
//   incluirInfo(Lista1, alocaInt(3));
//   incluirInfo(Lista1, alocaInt(6));
//   incluirInfo(Lista1, alocaInt(5));
//   incluirInfo(Lista1, alocaInt(11));
//   incluirInfo(Lista1, alocaInt(7));
//   incluirInfo(Lista1, alocaInt(8));

//   imprimirLista(Lista1, imprimeInt);

/* A seguir, chamarei uma função que duplica a lista em uma copia identica,
    para isso, preciso alocar valores ponteiro INT dentro dos nohs. */

/* Um novo pDLista é declarado aqui, para que possa resgatar o return de
    duplicar lista. */

//   pDLista Lista2 = duplicarLista(Lista1, alocaInfoInt);

//   printf("\nLista 1: ");
//   imprimirLista(Lista1, imprimeInt);
//   printf("\nLista 2: ");
//   imprimirLista(Lista2, imprimeInt);

//   dividirLista(Lista1, 4);
//   pDLista Lista1Div = duplicarLista(Lista1, alocaInfoInt);
//   printf("\nNova lista 1: ");
//   imprimirLista(Lista1, imprimeInt);
//   printf("\nLista Dividida: ");
//   imprimirLista(Lista1Div, imprimeInt);

//   printf("\nLista 1 e 2 Unidas: ");
//   incluirInfo(Lista1, alocaInt(9));
//   pDLista Lista3 = uniao(Lista1, Lista2, comparaInt);
//   imprimirLista(Lista3, imprimeInt);

//   printf("\nIntersecao das listas 1 e 2: ");
//   incluirInfo(Lista2, alocaInt(22));
//   pDLista Lista4 = intersecao(Lista1, Lista2, comparaInt);
//   imprimirLista(Lista4, imprimeInt);

//   if (contida(Lista2, Lista3, comparaInt) ==1 )
//   printf("\nContida: ");
//   else
//   printf("\n Nao contida: ");

   pDLista Lista1 = criarLista();

   incluirInfo(Lista1, alocaInt(1));
   incluirInfo(Lista1, alocaInt(2));
   incluirInfo(Lista1, alocaInt(3));
   incluirInfo(Lista1, alocaInt(4));

   pDLista Lista2 = criarLista();

   incluirInfo(Lista2, alocaInt(5));
   incluirInfo(Lista2, alocaInt(6));
   incluirInfo(Lista2, alocaInt(7));
   incluirInfo(Lista2, alocaInt(8));

   pDLista Lista3 = criarLista();

   incluirInfo(Lista3, alocaInt(1));
   incluirInfo(Lista3, alocaInt(2));
   incluirInfo(Lista3, alocaInt(3));
   incluirInfo(Lista3, alocaInt(4));

   pDLista Lista4 = criarLista();

   incluirInfo(Lista4, alocaInt(5));
   incluirInfo(Lista4, alocaInt(6));
   incluirInfo(Lista4, alocaInt(3));
   incluirInfo(Lista4, alocaInt(300));

   printf("\n imprima uma lista: ");
   imprimirLista(Lista4, imprimeInt);
   printf("\n imprima esta lista somente com multiplos de 3: ");
   pDLista Lista5 = split(Lista4, predicadoMult3);
   imprimirLista(Lista5, imprimeInt);

   printf("\n Encontre o menor info da lista: ");
   pNoh noh = encontraMenorPessini(Lista4,comparaInt);
   imprimeInt(noh->info);

   printf("\n coloque o menor info no inicio: ");
   menorNoInicioPessini(Lista4,comparaInt,encontraMenorPessini);
   imprimirLista(Lista4, imprimeInt);

   pDLista Lista6 = criarLista();

   incluirInfo(Lista6, alocaInt(5));
   incluirInfo(Lista6, alocaInt(6));
   incluirInfo(Lista6, alocaInt(3));
   incluirInfo(Lista6, alocaInt(20));
   incluirInfo(Lista6, alocaInt(4));
   incluirInfo(Lista6, alocaInt(2));
   incluirInfo(Lista6, alocaInt(1));
   incluirInfo(Lista6, alocaInt(9));
   incluirInfo(Lista6, alocaInt(7));
   incluirInfo(Lista6, alocaInt(11));

   void* px = malloc (sizeof(int));
   *((int*)px) = 2;
   printf("\n divida a lista 6: \n");
   imprimirLista(Lista6, imprimeInt);
   pDLista Lista7 = criarLista();
   Lista7 = dividirLista(Lista6, alocaInfoInt(px), comparaInt);

   printf("\n lista 6: ");
   imprimirLista(Lista6, imprimeInt);
   printf("\n lista 7: ");
   imprimirLista(Lista7, imprimeInt);



   /* Implementação do exercicio 1. */

   printf("----Exercicio 1----\n");

   int x =10, y = 9;
   int z = mod(x,y);
   printf("Resto de 10 por 9 eh: %d", z);
/* ---------------------------------- */


/* Implementação do exercicio 2. */
   printf("\n----Exercicio 2---- ");
   pDLista Lista11 = criarLista();

   incluirInfo(Lista11, alocaInt(1));
   incluirInfo(Lista11, alocaInt(2));
   incluirInfo(Lista11, alocaInt(3));
   incluirInfo(Lista11, alocaInt(4));
   incluirInfo(Lista11, alocaInt(5));
   incluirInfo(Lista11, alocaInt(6));
   incluirInfo(Lista11, alocaInt(7));
   incluirInfo(Lista11, alocaInt(8));
   incluirInfo(Lista11, alocaInt(9));

   printf("\n Lista 1: ");
   imprimirLista(Lista11, imprimeInt);

   pDLista Lista22 = criarLista();
   Lista22 = split2(Lista11, predicadoMult3,comparaInt);

   printf("\n Lista 1 nova: ");
   imprimirLista(Lista11, imprimeInt);

   printf("\n lista split: ");
   imprimirLista(Lista22, imprimeInt);
/* ---------------------------------- */


/* Implementação do exercicio 3. */

   printf("\n----Exercicio 3---- ");

   pDLista ListaFormulas = criarLista();
   incluirFormula2(ListaFormulas,123);
   incluirFormula2(ListaFormulas,456);
   incluirFormula2(ListaFormulas,230);





/* ---------------------------------- */


/* Implementação do exercicio 4. */

   printf("\n----Exercicio 4---- ");

   pDLista Lista33 = criarLista();

   incluirInfo(Lista33, alocaInt(3));
   incluirInfo(Lista33, alocaInt(2));
   incluirInfo(Lista33, alocaInt(3));
   incluirInfo(Lista33, alocaInt(4));
   incluirInfo(Lista33, alocaInt(5));
   incluirInfo(Lista33, alocaInt(6));
   incluirInfo(Lista33, alocaInt(7));
   incluirInfo(Lista33, alocaInt(8));
   incluirInfo(Lista33, alocaInt(9));


   printf("\n maior elemento: ");

    void* pa;
    pa = malloc (sizeof(int*));
    pa = maiorElementoRecursivo(Lista33,comparaInt);
    printf("%d", *((int*)pa));
/* ---------------------------------- */

printf("\n");
}
