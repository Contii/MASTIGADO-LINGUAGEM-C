#include <stdio.h>
#include <stdlib.h>
#include "Structs.h"
#include "UtilsPonteiros.h"

int main(){
/*---------------------- lista 1 - ponteiros e alocação dinamica. ----------------------*/

/* Declarei um ponteiro px para VOID; aloquei memoria para ele. Ao definir o valor
    que ele apontava, especifiquei que o mesmo é do tipo INT.
     fiz o mesmo para o ponteiro py; */
   void *px;
   px = malloc(sizeof(int));
   *((int*)px) = 10;

   void *py;
   py = malloc(sizeof(int));
   *((int*)py) = 20;

/* imprimi os valores apontados pelos ponteiros VOID
    especificando que são valores do tipo INT. */

   printf("%d - %d", *((int*)px), *((int*)py));
   printf("\n");

/* O ponteiro pode continuar sendo VOID para sempre, mas ao apontar para algum valor,
    a alocação deve ser do tipo que o valor corresponde.
                        void *px;
                        px = malloc(sizeof(float));
                        *((float*)px) = 10,5;
                        printf("%f", *((float*)px)); */

   imprimeInt(px);
   imprimeInt(py);
   printf("\n");

/* Ao chamar uma função imprimeInt para fazer a impressão, note que não é preciso
    identificar o tipo de dado, somente informar o ponteiro, pois a própria função
     recebe esse valor como VOID e trabalha com o formato INT dentro dela. */

/* A função comparaInt recebe dois valores apontados por ponteiro VOID, internamente
    transforma esses ponteiros em INT, subtrai um pelo outro e retorna um valor INT.
     O codigo IF abaixo imprime uma frase para cada valor que a função comparaInt
      pode retornar, positivo, negativo ou 0. Observe que novamente, foi preciso
       indicar que o tipo de dado a ser impresso era do tipo INT. */

   if((comparaInt(px,py)) <0){
       printf("%d eh maior que %d", *((int*)px), *((int*)py));
   };
   if((comparaInt(px,py)) == 0){
       printf("%d eh igual a %d",   *((int*)px), *((int*)py));
   };
   if((comparaInt(px,py)) > 0){
       printf("%d eh menor que %d", *((int*)px), *((int*)py));
   };
   printf("\n");

/* A diferença para a impressão aqui comparado com a da função imprimeInt, é que
    aqui usamos um ponteiro VOID para armazenar o valor a ser impresso
     (precisa identificar que tipo de valor é). sendo que na imprimeInt, dentro da
      propria função está o printf, usando as variaveis locais INT da propria função. */


/* A seguir precisei imprimir a soma de dois valores INT. Para isso,
    existe a função somaInt. Mas ela somente serve para somar dois valores
     e não faz a impressão de nada.

   Para a impressão uso a função imprimeInt. Esta função recebe um ponteiro para VOID
    e faz a impressão dentro dela mesma, como vimos anteriormente. Veja também que
     foi feito o uso de uma função dentro de outra função.

   Para que isso ocorra, a função somaInt deve dar return em um ponteiro para VOID,
    instanciado dentro da propria função, que seria o resultado da soma entre os
     dois ponteiros VOID que ela recebeu primariamente. */

   printf("A soma entre %d e %d eh: ",*((int*)px), *((int*)py));
   imprimeInt((somaInt(px,py)));
   printf("\n");

/* Em seguida o exemplo mostra o uso para a função somaFloat e imprimeFloat. Note que
    para isso, foi necessario liberar a memoria dos ponteiros e alocar os valores
     com o tipo FLOAT. %.2f significa que somente duas casas apos a virgula
      serao impressas, pois float tem muitas casas decimais. */

   free((int*)px);
   px = malloc(sizeof(float));
   *((float*)px) = 10.5;

   free((int*)py);
   py = malloc(sizeof(float));
   *((float*)py) = 20.5;

   printf("A soma entre %.2f e %.2f eh: ",*((float*)px), *((float*)py));
   imprimeFloat((somaFloat(px,py)));
   printf("\n");

/* A seguir o uso dos ponteiros para VOID sendo usados na função para verificar se um
    numero  INT é perfeito. a função lida com variaveis locais para retornar um
     valor INT, afimarndo se o numero é ou não perfeito. */

   free((float*)px);
   px = malloc(sizeof(int));
   *((int*)px) = 28;

   if( (perfeitoInt(px) == 0)){
       printf("Nao eh perfeito");
   }
   if( (perfeitoInt(px) == 1)){
       printf("Eh perfeito");
   }


/* A seguinte implementação tem como objetivo, pedir par ao usuario dizer quantos numeros
    quer armazenar, informar cada um deles e em seguida, descobrir qual é o maior. */

/* Começo liberando os ponteiros VOID necessarios e
    peço para que o usuario informe quantos numeros quer utilizar*/
   free((int*)px);
   *((int*)px) = 0;

   printf("\n\nInforme quantos numeros inteiros devem ser alocados: ");
   scanf("%d", &*((int*)px));


/* A função a seguir esta detalhada em utils.h.
    O que ela faz é pedir para o usuario informar todos os numeros a serem alocados
     de acordo com o primeiro informado (PX), retornando um ponteiro que armazenará
      o primeiro deles. O ponteiro sera do tipo INT, por isso, para usa-lo em main,
       precisei alocar PY como INT, E atribuir o retorno da função para PY. */

   free((float*)py);
   py = malloc(sizeof(int));
   *((int*)py) = 0;

   py = (alocaNInteiros(px));

/* Ao receber o resultado da função, o ponteiro PY esta pronto para ser usado na função
    maiorInteiroNoPonteiro(), Mas antes disso, um teste foi feito para saber se
     o mesmo resgatou todas os numeros alocados.*/

   printf("%d", *(((int*)py)+1));

/* Verifico o conteudo do segundo numero.
    Para imprimir todos eles, um comando FOR seria necessario. */

/* Dando continuidade a implementação, a função maiorInteiroNoPonteiro, ira trabalhar
    para vasculhar toda a memoria em busca do maior numero inserido nela. */

   printf("\n\nO maior numero da sua lista eh: ");
   maiorInteiroNoPonteiro(py,px);

   free((int*)px);
   *((int*)px) = 0;

   free((int*)py);
   *((int*)py) = 0;

   printf("\n\nQuantas pessoas serao cadastradas?  ");
   scanf("%d", &*((int*)px));
   registraPessoas(px,alertaMenores);
/* Veja que aqui foi passado como parametro, uma função, quando qualquer função é criada,
    a mesma recebe um ponteiro, que aponta para ela, assim como PX aponta para seu
     conteudo.(confira o parametro que a função registraPessoas recebe para esta função.*/
}
