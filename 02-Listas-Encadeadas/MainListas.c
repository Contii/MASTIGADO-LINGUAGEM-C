#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"
#include "UtilsListas.h"

/* ----------------------------------------------------------------------------------- */
/* Perceba o uso dos includes, ao trabalhar com listas, utilizarei algumas bibliotecas:

    utilsListas.h 	- Adaptada do ultimo programa para poder usar algumas fun��es.
	lista.h 		- Para todas fun��es que envolvem manipula��o de listas.
	 
	perceba que dentro destas bibliotecas incluo:
	
	TAD_ListaLinear.h 	- Contem os tipos abstratos de dados para as structs e fun��es.
	structs.h 			- Contem as defini��es das structs.
	
    Para que n�o ocorra uma sobreposi��o de codigos struct, o #ifndef(if not defined)
     e o #define s�o utilizados nas bibliotecas. Desta forma, ao chamar a structs.h
	  em uma biblioteca pela segunda vez, a mesma sera desconsiderada, por ja
	   estar escrita no codigo anteriormente.

	Assim, posso incluir diversas bibliotecas que fazem o include das mesmas bibliotecas
     sem ter problemas com inclus�es repetidas. */

int main(){
	
/* ----------------------------------------------------------------------------------- */
/* Dando continuidade a nossa implementa��o de uma biblioteca gen�rica, estaremos
    agora adentrando no conte�do de Listas Encadeadas, para agrupar informa��es e ter
     acesso a elas, utilizando fun��es de organiza��o, altera��o, inclus�o, e qualquer
      outro tipo de fun��o genericamente implementada para trabalhar com esses dados
       a maneira que seja necess�rio. */

/* Perceba que para o desenvolvimento deste MAIN, foi necessario a inclus�o de uma nova
    biblioteca, lista.h, nela implementarei todas as fun��es para trabalhar com listas. */

/* Outra biblioteca importante, mas n�o estritamente necess�ria, ser� TAD_ListaLinear.h
    nela, toda a defini��o de dados e fun��es ser� definida, como typedefs por exemplo.
     desta forma nosso codigo ficar� mais limpo, e possibilitar� uma consulta mais
      r�pida na hora de conferir quais os tipos de dados e como devem ser tratados
       ao implementar uma nova fun��o. */

/* A biblioteca utilsListas.h que utilizarei � a mesma do programa de ponteiros mas com
    algumas modifica��es, pois anteriormente fiz as declara��es de typedefs e structs
	 enquanto dava a explica��o sobre os mesmos. Agora com as bibliotecas novas, estas
	  defini��es se encontram em TAD_ListaLinear.h e Structs.h. O que mudou agora em
	   utilsListas.h foi que comentei as linhas onde fazia estas defini��es. */

/* ------------------------------------- ATEN��O ------------------------------------- */
/* LEIA O COMENTARIO A SEGUIR QUANTAS VEZES FOR NECESSARIO PARA ENTENDER A LOGICA POR
    TR�S DA LISTA, EXISTE UMA IMAGEM QUE REPRESENTA A CRIA��O DA LISTA PARA
     PODER ABSORVER MELHOR ESTE RACIOC�NIO NO README.MD DO REPOSIT�RIO.


   Uma lista � composta por dois tipos de dados, um deles � o dLista(descritor da lista).
    Este tem como objetivo apontar para o in�cio(primeira struct) e para o fim(ultima struct)
     da lista, assim como contar quantas informa��es a lista possui(quantidade).
	  Portanto, ser� atribuido a ele 3 dados.

     struct dLista{
     struct noh* primeiro;
     struct noh* ultimo;
     int         quantidade;
     }

   Desta forma, ao criar uma nova lista, possuiremos uma scruct dLista vazia, sem info
    no primeiro, no ultimo e com quantidade definida em zero. Perceba que PRIMEIRO e
     ULTIMO s�o ponteiros para o tipo STRUCT NOH, o nosso segundo tipo de dado necess�rio
	  para a cria��o de uma lista.

    struct noh{
    void       *info;
    struct noh *prox;
    }

   Composto por um ponteiro VOID chamado INFO, o noh armazenar� a informa��o que foi
    inclu�da na lista. O campo PROX ser� um ponteiro para um outro noh, dando sequ�ncia
     para a acessibilidade de nossa lista.

   Desta forma, saberemos somente quem � o primeiro e o ultimo noh de nossa lista, assim
    como de quantos nohs a lista � composta. Para percorrer ela, precisaremos acessar os
     nohs um por um, ate que encontremos a informa��o que queremos trabalhar. */

/* ----------------------------------------------------------------------------------- */

/* Leia a defini��o do descritor de listas struct dLista em structs.h e em seguida,
    observe a nomenclatura atribuida a essa struct em TAD_ListaLinear.h*/

/* Na seguinte linha, chamo a fun��o criarLista para construir um descritor chamado
    Lista1. Veja tamb�m como essa fun��o trabalha em lista.h. */

   pDLista Lista1 = criarLista();

/* Voce pode estar em d�vida sobre como isso ocorre.
	pDLista � o apelido que dei a DLista*		, um ponteiro para um tipo de dado DLista.
	DLista  � o apelido que dei a struct dLista	, a estrutura criada em structs.h.
	
	a fun��o criarLista(); quando chamada, cria uma lista nova(vazia) e retorna o valor
	 pDLista, um ponteiro para esta lista recem criada. para poder receber este valor, 
	  � necess�ria a cria��o de uma vari�vel do mesmo tipo dele, Lista1.
	  
	caso fosse criar essa lista sem o TAD, seria:
	struct dLista* Lista1 = criarLista();			*/

/* Temos ent�o uma lista vazia, agora podemos come�ar a incluir informa��es na mesma,
    Uso ent�o a fun��o incluirInfo que recebe um ponteiro pDLista e um ponteiro para
     fun��o. Perceba o uso de tudo o que estudamos at� agora come�ar a tomar forma. */


   incluirInfo(Lista1, alocaInt(5)); alocaInt recebe um valor int.
   incluirInfo(Lista1, alocaInt(8)); alocaInt retorna um ponteiro int.
   incluirInfo(Lista1, alocaInt(7)); incluirInfo recebe um ponteiro VOID,
   incluirInfo(Lista1, alocaInt(2)); ou seja, qualquer ponteiro.
   incluirInfo(Lista1, alocaInt(1));
   incluirInfo(Lista1, alocaInt(22));

   printf("\n\nResultado da inclusao: \n");
   imprimirLista(Lista1, imprimeInt); /* uso novamente do rol� gen�rico. */

/* Vamos ver agora se a lista possui um numero, para isso, vamos aloc�-lo tamb�m, pois
    a fun��o contemInfo nao recebe INT e sim ponteiro VOID. Poder�amos usar toda a aloca��o
	 de PX que fizemos no programa anterior, mas assim estar�amos deixando de lado
      nossa implementa��o alocaInt gen�rica que simplifica nosso main. */
	  
   int r;
   r = contemInfo(Lista1, alocaInt(8), comparaInt);

/* De acordo com o retorno booleano de contemInfo, saberemos se a info est�
    ou n�o presente na lista. */
	
   if (r==0)
      printf("\nInformacao  Nao esta na lista!");
   else
      printf("\nInformacao esta na lista!");

/* Vamos agora excluir uma info da lista e ver como ela fica. */

   printf("\n\nResultado da exclusao: ");

/* Para a fun��o excluir, precisamos passar como parametros: lista, um valor, no caso
    chamo a fun��o alocaInt que me retornar� o ponteiro para INT, e a devida fun��o de
     compara��o do determinado tipo, comparaInt. Caso exista esta informa��o na lista
	  usando comparaInt a fun��o excluirInfo remover� ela da lista.*/
	  
   excluirInfo(Lista1, alocaInt(7), comparaInt);
   imprimirLista(Lista1, imprimeInt);
   printf("\n");

/* Vamos agora destruir nossa lista. */

   resetarLista(Lista1);

/* Vamos agora fazer uma inclus�o e imprimi-la novamente. */

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

/* A seguir, chamarei uma fun��o que duplica a lista em uma copia identica,
    Um novo pDLista � declarado aqui, para que possa resgatar o return de
     duplicar lista. Perceba tamb�m que preciso passar uma funcao de alocacao,
	  para que o algoritmo saiba qual o tipo de dado minha lista vai possuir.*/

   pDLista Lista2 = duplicarLista(Lista1, alocaInfoInt);
   printf("\nLista 1: ");
   imprimirLista(Lista1, imprimeInt);
   printf("\nLista 2: ");
   imprimirLista(Lista2, imprimeInt);

printf("\n");
}
