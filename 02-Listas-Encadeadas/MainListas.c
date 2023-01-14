#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"
#include "UtilsListas.h"

/* ----------------------------------------------------------------------------------- */
/* Perceba o uso dos includes, ao trabalhar com listas, utilizarei algumas bibliotecas:

    utilsListas.h 	- Adaptada do ultimo programa para poder usar algumas funções.
	lista.h 		- Para todas funções que envolvem manipulação de listas.
	 
	perceba que dentro destas bibliotecas incluo:
	
	TAD_ListaLinear.h 	- Contem os tipos abstratos de dados para as structs e funções.
	structs.h 			- Contem as definições das structs.
	
    Para que não ocorra uma sobreposição de codigos struct, o #ifndef(if not defined)
     e o #define são utilizados nas bibliotecas. Desta forma, ao chamar a structs.h
	  em uma biblioteca pela segunda vez, a mesma sera desconsiderada, por ja
	   estar escrita no codigo anteriormente.

	Assim, posso incluir diversas bibliotecas que fazem o include das mesmas bibliotecas
     sem ter problemas com inclusões repetidas. */

int main(){
	
/* ----------------------------------------------------------------------------------- */
/* Dando continuidade a nossa implementação de uma biblioteca genérica, estaremos
    agora adentrando no conteúdo de Listas Encadeadas, para agrupar informações e ter
     acesso a elas, utilizando funções de organização, alteração, inclusão, e qualquer
      outro tipo de função genericamente implementada para trabalhar com esses dados
       a maneira que seja necessário. */

/* Perceba que para o desenvolvimento deste MAIN, foi necessario a inclusão de uma nova
    biblioteca, lista.h, nela implementarei todas as funções para trabalhar com listas. */

/* Outra biblioteca importante, mas não estritamente necessária, será TAD_ListaLinear.h
    nela, toda a definição de dados e funções será definida, como typedefs por exemplo.
     desta forma nosso codigo ficará mais limpo, e possibilitará uma consulta mais
      rápida na hora de conferir quais os tipos de dados e como devem ser tratados
       ao implementar uma nova função. */

/* A biblioteca utilsListas.h que utilizarei é a mesma do programa de ponteiros mas com
    algumas modificações, pois anteriormente fiz as declarações de typedefs e structs
	 enquanto dava a explicação sobre os mesmos. Agora com as bibliotecas novas, estas
	  definições se encontram em TAD_ListaLinear.h e Structs.h. O que mudou agora em
	   utilsListas.h foi que comentei as linhas onde fazia estas definições. */

/* ------------------------------------- ATENÇÃO ------------------------------------- */
/* LEIA O COMENTARIO A SEGUIR QUANTAS VEZES FOR NECESSARIO PARA ENTENDER A LOGICA POR
    TRÁS DA LISTA, EXISTE UMA IMAGEM QUE REPRESENTA A CRIAÇÃO DA LISTA PARA
     PODER ABSORVER MELHOR ESTE RACIOCÍNIO NO README.MD DO REPOSITÓRIO.


   Uma lista é composta por dois tipos de dados, um deles é o dLista(descritor da lista).
    Este tem como objetivo apontar para o início(primeira struct) e para o fim(ultima struct)
     da lista, assim como contar quantas informações a lista possui(quantidade).
	  Portanto, será atribuido a ele 3 dados.

     struct dLista{
     struct noh* primeiro;
     struct noh* ultimo;
     int         quantidade;
     }

   Desta forma, ao criar uma nova lista, possuiremos uma scruct dLista vazia, sem info
    no primeiro, no ultimo e com quantidade definida em zero. Perceba que PRIMEIRO e
     ULTIMO são ponteiros para o tipo STRUCT NOH, o nosso segundo tipo de dado necessário
	  para a criação de uma lista.

    struct noh{
    void       *info;
    struct noh *prox;
    }

   Composto por um ponteiro VOID chamado INFO, o noh armazenará a informação que foi
    incluída na lista. O campo PROX será um ponteiro para um outro noh, dando sequência
     para a acessibilidade de nossa lista.

   Desta forma, saberemos somente quem é o primeiro e o ultimo noh de nossa lista, assim
    como de quantos nohs a lista é composta. Para percorrer ela, precisaremos acessar os
     nohs um por um, ate que encontremos a informação que queremos trabalhar. */

/* ----------------------------------------------------------------------------------- */

/* Leia a definição do descritor de listas struct dLista em structs.h e em seguida,
    observe a nomenclatura atribuida a essa struct em TAD_ListaLinear.h*/

/* Na seguinte linha, chamo a função criarLista para construir um descritor chamado
    Lista1. Veja também como essa função trabalha em lista.h. */

   pDLista Lista1 = criarLista();

/* Voce pode estar em dúvida sobre como isso ocorre.
	pDLista é o apelido que dei a DLista*		, um ponteiro para um tipo de dado DLista.
	DLista  é o apelido que dei a struct dLista	, a estrutura criada em structs.h.
	
	a função criarLista(); quando chamada, cria uma lista nova(vazia) e retorna o valor
	 pDLista, um ponteiro para esta lista recem criada. para poder receber este valor, 
	  é necessária a criação de uma variável do mesmo tipo dele, Lista1.
	  
	caso fosse criar essa lista sem o TAD, seria:
	struct dLista* Lista1 = criarLista();			*/

/* Temos então uma lista vazia, agora podemos começar a incluir informações na mesma,
    Uso então a função incluirInfo que recebe um ponteiro pDLista e um ponteiro para
     função. Perceba o uso de tudo o que estudamos até agora começar a tomar forma. */


   incluirInfo(Lista1, alocaInt(5)); alocaInt recebe um valor int.
   incluirInfo(Lista1, alocaInt(8)); alocaInt retorna um ponteiro int.
   incluirInfo(Lista1, alocaInt(7)); incluirInfo recebe um ponteiro VOID,
   incluirInfo(Lista1, alocaInt(2)); ou seja, qualquer ponteiro.
   incluirInfo(Lista1, alocaInt(1));
   incluirInfo(Lista1, alocaInt(22));

   printf("\n\nResultado da inclusao: \n");
   imprimirLista(Lista1, imprimeInt); /* uso novamente do rolê genérico. */

/* Vamos ver agora se a lista possui um numero, para isso, vamos alocá-lo também, pois
    a função contemInfo nao recebe INT e sim ponteiro VOID. Poderíamos usar toda a alocação
	 de PX que fizemos no programa anterior, mas assim estaríamos deixando de lado
      nossa implementação alocaInt genérica que simplifica nosso main. */
	  
   int r;
   r = contemInfo(Lista1, alocaInt(8), comparaInt);

/* De acordo com o retorno booleano de contemInfo, saberemos se a info está
    ou não presente na lista. */
	
   if (r==0)
      printf("\nInformacao  Nao esta na lista!");
   else
      printf("\nInformacao esta na lista!");

/* Vamos agora excluir uma info da lista e ver como ela fica. */

   printf("\n\nResultado da exclusao: ");

/* Para a função excluir, precisamos passar como parametros: lista, um valor, no caso
    chamo a função alocaInt que me retornará o ponteiro para INT, e a devida função de
     comparação do determinado tipo, comparaInt. Caso exista esta informação na lista
	  usando comparaInt a função excluirInfo removerá ela da lista.*/
	  
   excluirInfo(Lista1, alocaInt(7), comparaInt);
   imprimirLista(Lista1, imprimeInt);
   printf("\n");

/* Vamos agora destruir nossa lista. */

   resetarLista(Lista1);

/* Vamos agora fazer uma inclusão e imprimi-la novamente. */

   printf("\nLista nova: ");
   incluirInfo(Lista1, alocaInt(1));
   incluirInfo(Lista1, alocaInt(4));
   incluirInfo(Lista1, alocaInt(3));
   incluirInfo(Lista1, alocaInt(6));
   incluirInfo(Lista1, alocaInt(5));
   incluirInfo(Lista1, alocaInt(11));
   incluirInfo(Lista1, alocaInt(7));
   incluirInfo(Lista1, alocaInt(8));

   imprimirLista(Lista1, imprimeInt);

/* A seguir, chamarei uma função que duplica a lista em uma copia identica,
    Um novo pDLista é declarado aqui, para que possa resgatar o return de
     duplicar lista. Perceba também que preciso passar uma funcao de alocacao,
	  para que o algoritmo saiba qual o tipo de dado minha lista vai possuir.*/

   pDLista Lista2 = duplicarLista(Lista1, alocaInfoInt);
   printf("\nLista 1: ");
   imprimirLista(Lista1, imprimeInt);
   printf("\nLista 2: ");
   imprimirLista(Lista2, imprimeInt);

printf("\n");
}
