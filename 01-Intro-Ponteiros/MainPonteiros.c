#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "utilsPonteiros.h"

int main(){
/* ----------------------------------------------------------------------------------- */
/* Todo endereco de memoria [0000] possui 4 bytes. um ponteiro é um endereço que aponta
    para outro endereço. Ao utilizar ponteiros VOID, podemos implementar funções genéricas
     que recebem dados de qualquer tipo e retornem dados de qualquer tipo, contanto que
      sejam feitas implementações de variáveis utilizando ponteiros para VOID, funções
       que recebam ponteiros VOID e que retornem ponteiros VOID.*/

   void *P; /* <-Declaração de um ponteiro VOID.(Apontando para qualquer tipo)
                  Desta forma, nosso ponteiro poderá apontar para INT, FLOAT,
                   STRUCT ou qualquer outro tipo de dado.*/

/* Lembre-se que ao escrever P, estaremos se referindo ao ponteiro, e nao ao valor
    para o qual ele aponta. Para se referir ao valor, utilizamos asterisco *. Perceba
     então que acima, apontamos para um valor sem tipo (VOID).
     *P <- valor apontado por P (atualmente sem tipo)
      P <- ponteiro P (por padrao possui tamanhao INT)*/

   P = malloc(sizeof(int)); /* <-P recebeu um espaço de memoria do tamanho INT, Desta
                                  forma, ele pode apontar para algum endereço. */

/* Um outro detalhe a ser observado, é que como P aponta para qualquer tipo, precisarei
    especificar qual o tipo do valor *P toda vez que for manipular o mesmo. */

   *((int*)P) = 5; /* <-O valor *P será do tipo (INT*) e a ele foi atribuido 5. */

   printf("%d", *((int*)P)); /* <-Impressão de *P (valor apontado por P). */

/* Para utilizar nosso ponteiro novamente com outro tipo de dado, precisaremos dar FREE
    em seu valor, para atribui-lo a outro tipo. */
   free((int*)P);

   P = malloc(sizeof(float)); /* <-Aloquei um espaço de memoria FLOAT para P */

   *((float*)P) = 3.14; /* <-O valor *P será do tipo (FLOAT*) atribuindo a ele 3.14  */
   printf("%d", *((float*)P)); /* <-Impressão da nova tipagem do nosso ponteiro.*/
   free((float*)P); /* Como não precisarei mais do valor, dou FREE na memoria. */

/* Agora o ponteiro não aponta para mais nada, Mas ainda poderia utiliza-lo caso
    atribuisse novamente uma memoria para ele.*/

   system("cls"); /* <-Vou limpar o console nao ficar mostrando estes printf */
/* ----------------------------------------------------------------------------------- */
/* --------------- lista 1 - Ponteiros e Alocação Dinamica de Memoria. --------------- */
/* ----------------------------------------------------------------------------------- */
   printf("-------------------------------------------------------------------\n");
   printf("--------Lista 1 - Ponteiros e Alocacao Dinamica de Memoria.--------\n");

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

   printf("PX-> %d \nPY-> %d", *((int*)px) , *((int*)py) );

/* O ponteiro pode continuar sendo VOID para sempre, mas ao apontar para algum valor,
    a alocação deve ser do tipo que o valor corresponde.
                        void *px;
                        px = malloc(sizeof(float));
                        *((float*)px) = 10,5;
                        printf("%f", *((float*)px)); */

   printf("\n");
   imprimeInt(px);
   imprimeInt(py);

/* Ao chamar uma função imprimeInt para fazer a impressão, note que não é preciso
    identificar o tipo de dado, somente informar o ponteiro, pois a própria função
     recebe esse valor como VOID e trabalha com o formato INT dentro dela. */

/* ----------------------------------------------------------------------------------- */
/* A função comparaInt recebe dois valores apontados por ponteiro VOID, internamente
    transforma esses ponteiros em INT, subtrai um pelo outro e retorna um valor INT.
     O codigo IF abaixo imprime uma frase para cada valor que a função comparaInt
      pode retornar, positivo, negativo ou 0. Observe que novamente, foi preciso
       indicar que o tipo de dado a ser impresso era do tipo INT. */

   if((comparaInt(px,py)) >0){
      printf("\n%d eh maior que %d", *((int*)px) , *((int*)py) );
   };
   if((comparaInt(px,py)) == 0){
      printf("\n%d eh igual a %d",   *((int*)px) , *((int*)py) );
   };
   if((comparaInt(px,py)) < 0){
      printf("\n%d eh menor que %d", *((int*)px) , *((int*)py) );
   };

/* A diferença para a impressão aqui comparado com a da função imprimeInt, é que
    aqui usamos um ponteiro VOID para armazenar o valor a ser impresso
     (precisa identificar que tipo de valor é). sendo que na imprimeInt, dentro da
      propria função está o printf, usando as variaveis locais INT da propria função. */

/* ----------------------------------------------------------------------------------- */
/* A seguir precisei imprimir a soma de dois valores INT. Para isso,
    existe a função somaInt. Mas ela somente serve para somar dois valores
     e não faz a impressão de nada.

   Para a impressão uso a função imprimeInt. Esta função recebe um ponteiro para VOID
    e faz a impressão dentro dela mesma, como vimos anteriormente. Veja também que
     foi feito o uso de uma função com o resultado de outra função.

   Para que isso ocorra, a função somaInt deve dar return em um ponteiro para VOID,
    instanciado dentro da propria função, que seria o resultado da soma entre os
     dois ponteiros VOID que ela recebeu primariamente. */

   printf("\nA soma entre %d e %d = ", *((int*)px) , *((int*)py) );
   imprimeInt(somaInt(px,py) );
   printf("\n");

/* ----------------------------------------------------------------------------------- */
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

   printf("A soma entre %.2f e %.2f = ", *((float*)px) , *((float*)py) );
   imprimeFloat((somaFloat(px,py)));
   printf("\n\n");

/* ----------------------------------------------------------------------------------- */
/* A seguir o uso dos ponteiros para VOID sendo usados na função para verificar se um
    numero  INT é perfeito. a função lida com variaveis locais para retornar um
     valor INT, afimarndo se o numero é ou não perfeito. */

   free((float*)px);
   px = malloc(sizeof(int));
   *((int*)px) = 28;

   if( (perfeitoInt(px) == 0)){
      printf("%d Nao eh perfeito", *((int*)px) );
   }
   if( (perfeitoInt(px) == 1)){
      printf("%d Eh perfeito", *((int*)px) );
   }

/* ----------------------------------------------------------------------------------- */
/* A seguinte implementação pedirá para o usuario dizer quantos numeros quer armazenar,
    informar cada um deles e em seguida, descobrir qual é o maior. */

/* Começo liberando os ponteiros VOID necessarios e
    peço para que o usuario informe quantos numeros quer utilizar*/

   free((int*)px);
   *((int*)px) = 0;

   printf("\n\n\nInforme quantos numeros inteiros devem ser alocados: ");
   scanf("%d", &*((int*)px));

/* A função a seguir esta detalhada em utils.h. */
/* O que ela faz é pedir para o usuario informar todos os numeros a serem alocados de
    acordo com o primeiro informado (PX), retornando um ponteiro que armazenará o
     primeiro deles. O ponteiro sera do tipo INT, por isso, para usa-lo em main,
      precisei alocar PY como INT, E atribuir o retorno da função para PY. */

   free((float*)py);
   py = malloc(sizeof(int));
   *((int*)py) = 0;

   py = (alocaNInteiros(px) );

/* Ao receber o resultado da função, o ponteiro PY esta pronto para ser usado na função
    maiorInteiroNoPonteiro(), Mas antes disso, um teste foi feito para saber se
     o mesmo resgatou todas os numeros alocados.*/

   printf("\nSegundo numero alocado: %d", *(((int*)py)+1) );

/* No printf acima, verifico o conteudo do segundo numero.
    Para imprimir todos eles, um comando FOR seria necessario. */

/* Dando continuidade a implementação, a função maiorInteiroNoPonteiro, ira trabalhar
    para vasculhar toda a memoria em busca do maior numero inserido nela. */

   printf("\nO maior numero da sua lista = ");
   maiorInteiroNoPonteiro(py,px);

/* ----------------------------------------------------------------------------------- */
/* A função a seguir esta detalhada em utils.h. */

   free((int*)px);
   *((int*)px) = 0;

   free((int*)py);
   *((int*)py) = 0;

   printf("\n\n\nQuantas pessoas serao cadastradas?  ");
   scanf("%d", &*((int*)px) );
   registraPessoas(px,alertaMenores);
   printf("-----------------------------\n");

/* Veja que aqui foi passado como parametro uma função. Quando qualquer função é criada,
    a mesma recebe um ponteiro que aponta para ela, assim como PX aponta para seu
     conteudo.(confira o parametro que registraPessoas recebe para esta função).*/

/* ----------------------------------------------------------------------------------- */
/* A seguinte implementação receberá um vetor para entao chamar uma função bubble sort.
    Para que a função seja generica, a implementação foi feita com ponteiros para VOID.
     Observe que a mesma função é utilizada para ordenar um vetor de FLOAT e outro
      vetor de STRUCT DATA. */

/* Perceba que agora, usarei diretamente um ponteiro para FLOAT na função bubbleSort,
    que recebe ponteiros VOID (qualquer ponteiro).*/
   float* vf[5];

   vf[0] = alocaFloat(2.5f); /* <-Chamada de alocaFloat pra alocar memoria aos valores*/
   vf[1] = alocaFloat(2.1f);
   vf[2] = alocaFloat(2.7f);
   vf[3] = alocaFloat(2.05f);
   vf[4] = alocaFloat(2.2f);

/* o seguinte laço FOR irá imprimir todos valores do vetor. */

   printf("\nVetor de floats desorganizados: ");
   int i;
   for (i=0; i<5; i++){
      printf("%.2f | ", *vf[i]);
   }

/* A função bubbleSort tem como objetivo ordenar os valores de um vetor, do menor para
    o maior. Para isso, ela vai precisar receber como parametros, o proprio vetor PX,
     quantos valores este vetor possui (5) e um ponteiro para uma função de comparação,
      que neste caso, é de numeros FLOAT. */

   bubbleSort(vf, 5, &comparaFloat); /* <-Uso do ponteiro FLOAT.*/

/* o seguinte laço FOR irá imprimir todos valores de acordo com suas novas posições. */

   printf("\nVetor de floats organizados:    ");
   for (i=0; i<5; i++){
      printf("%.2f | ", *vf[i]);
   }


/* Agora, o uso de um ponteiro STRUCT DATA(usando typedef), para a função bubbleSort. */
   pData vd[5];

   vd[0] = alocaData(01,03,2021);
   vd[1] = alocaData(01,02,2021);
   vd[2] = alocaData(05,01,2021);
   vd[3] = alocaData(07,02,2021);
   vd[4] = alocaData(28,02,2021);

   printf("\n\nVetor de datas desorganizadas: ");
   for (i=0; i<5; i++){
      printf("%d/%d/%d - ", vd[i]->dia, vd[i]->mes, vd[i]->ano);
   }

   bubbleSort(vd, 5, &comparaData); /* <-Ponteiro PDATA. */

   printf("\nVetor de datas organizadas:    ");
   for (i=0; i<5; i++){
      printf("%d/%d/%d | ", vd[i]->dia, vd[i]->mes, vd[i]->ano);
   }

/* ----------------------------------------------------------------------------------- */
/* ----------------------------- lista 2 - Recursividade. -----------------------------*/
/* ----------------------------------------------------------------------------------- */
   printf("\n\n\n-------------------------------------------------------------------\n");
   printf("--------------------- Lista 2 - Recursividade. --------------------\n");

   free((int*)px);
   *((int*)px) = 10;

   free((int*)py);
   *((int*)py) = 20;

   printf("\n%d  %d", *((int*)px), *((int*)py) );


/* Para esta lista, estarei resolvendo problemas com o uso de recursividade, Ao trabalhar
    com recursividade, não é aconselhado o uso de ponteiro, pois o mesmo pode ocasionar
     diversos erros e dificultar a absorção das implementações recursivas. Por este
     motivo, fiz somente a primeira função trabalhar com ponteiros, somaSucessoresInt. */

   printf("\nA soma recursiva entre %d e %d = ",*((int*)px), *((int*)py));
   imprimeInt(somaSucessoresInt(px,py) );

/* ----------------------------------------------------------------------------------- */
/* Perceba a seguir que o uso da função imprimeInt não sera mais possivel, por ela
    receber um ponteiro VOID */

/* A seguinte implementação tem como objetivo usar uma função recursiva que fará
    a multiplicação de dois numeros INT através das somas sucessivas.*/

   int x = 2;
   int y = -10;
   int z = 0;

   printf("\nA multiplicacao recursiva entre %d e %d = ", x, y);
   printf("%d", multIntSucessivo(x,y) );

/* ----------------------------------------------------------------------------------- */
/* A seguinte implementação usa uma função recursiva que retornará 1 caso o numero INT
    fornecido for primo, e 0 caso nao seja. Perceba que ela recebe 2 parametros... */

   printf("\n\nInforme um numero inteiro para verificar se eh primo: ");
   scanf("%d", &x);
   if(primoInt(x,x-1) == 0){
      printf("%d nao eh primo.", x);
   };
   if(primoInt(x,x-1) ==1){
      printf("%d eh primo.", x);
   };

/* Haveria outra forma de imprimir esta função, fazendo a chamada de PRINTF, dentro
    dela mesma, ao inves de retornar um valor e usar o comando IF no MAIN, mas desta
     forma, não seria possivel usar a mesma em outros algorítmos que não necessitem
      mostrar ao usuario se determinado numero é primo ou não. */

/* ----------------------------------------------------------------------------------- */
/* A seguinte implementação tem como objetivo informar um numero inteiro e chamar uma
    função que irá inprimir o mesmo em forma binaria. */


   x = 10;
   printf("\n\nO numero %d em binario = ", x);
   converteIntBin(x);

/* ----------------------------------------------------------------------------------- */
/* A seguinte implementação retornará quantos digitos um numero X possui. */

   x = 1233345666;
   printf("\n\n%d possui %d digitos",x, quantosDigitos(x) );

/* ----------------------------------------------------------------------------------- */
/* A seguinte implementação tem como objetivo retornar qual digito (Y ou Z) se repete
    mais vezes em dado numero X. */

   printf("\n\n\nInforme um numero inteiro para verificar ocorrencias: ");
   scanf("%d", &x);
   printf("Informe um digito presente no numero: ");
   scanf("%d", &y);
   printf("Informe outro digito presente no numero: ");
   scanf("%d", &z);

   if(ocorrenciaDigitoInt(x,y,z) > 0){
      printf("%d possui mais vezes o digito %d do que %d", x,y,z);
   }
   if(ocorrenciaDigitoInt(x,y,z) < 0){
      printf("%d possui mais vezes o digito %d do que %d", x,z,y);
   }
   if(ocorrenciaDigitoInt(x,y,z) == 0){
      printf("%d e %d ocorrem a mesma quantidade de vezes em %d", y,z,x);
   }
 /* a implementacao so funciona com numeros que vao até 10 digitos... */

/* ----------------------------------------------------------------------------------- */
/* A seguinte implementação tem como objetivo informar dois numeros inteiros e chamar
    uma função que irá calcular o Minimo Divisor Comum (MDC) entre estes numeros. */

   x = 6;
   y = 10;
   printf("\n\n\nO MDC entre %d e %d = %d",x,y, calculoMDC(x,y) );

/* ----------------------------------------------------------------------------------- */
/* A seguinte implementação tem como objetivo informar dois numeros inteiros e chamar
    uma função que irá calcular o Minimo Multiplo Comum (MMC) entre estes numeros. */

   x = 2;
   y = 5;
   printf("\nO MMC entre %d e %d = %d",x,y, calculoMMC(x,y) );

/* ----------------------------------------------------------------------------------- */
/* A seguinte implementação retornará a potencia de um valor X elevado a Y. */

   printf("\nA potencia de 2^5 = %d\n", potencia(x,y) );

/* ----------------------------------------------------------------------------------- */
/* A seguinte implementação retornará o fatorial de um valor X. */

   printf("O fatorial de %d! = %d\n", x, fatorial(x) );

/* ----------------------------------------------------------------------------------- */
/* A seguinte implementação retornará a raiz digital de um valor X. */

   x = 23;
   printf("A raiz digital de %d = %d\n", x, raizDigital(x) );

/* ----------------------------------------------------------------------------------- */
/* A seguinte implementação retornará a soma dos digitos de um valor X. */

   x = 125543;
   printf("A soma dos digitos de %d = %d\n", x, somaDigitos(x) );

/* ----------------------------------------------------------------------------------- */
/* A seguinte implementação retornará quantas vezes um digito X aparece em um numero Y.*/

   x = 5;
   y = 12551353;
   printf("O numero %d possui %d vezes o algarismo %d\n", y, quantosDigitosX(x,y) ,x);
   
/* ----------------------------------------------------------------------------------- */
}
