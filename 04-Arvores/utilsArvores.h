#ifndef UTILSARVORES_H
#define UTILSARVORES_H

#include <stdio.h>
#include "structs.h"
#include "TAD_Arvore.h"


/*---------------- COMO É DEFINIDA UMA FUNÇÃO COM PONTEIROS PARA VOID -----------------*/

/* void          nomeFunção (void *info               ,void *info2        ,void *info3)*/
/* retorna void  nomeFunção (valor apontado por       ,valor2             ,valor3     )*/
/*                            qualquer ponteiro   qualquer ponteiro   qualquer ponteiro*/

/*------------ FUNÇÃO COM PONTEIROS PARA VOID E PONTEIRO PARA OUTRA FUNÇÃO ------------*/

/* void          nomeFunção (void *info   , void     *(funcao) (void *))               */
/* retorna void  nomeFunção (ponteiro VOID, retorno  função    seu parametro)          */

/* void          nomeFunção (void *info   , void     *(funcao) (void *)(void *))       */
/* retorna void  nomeFunção (ponteiro VOID, retorno  função    seus 2 parametros)      */

/* Ao atribuir um "esboço" typedef para função, a nomenclatura do ponteiro para função
    passa a ser generica e mais simples.*/

//typedef int      (*FuncaoComparacao)      (void*, void*);
/*      retorno  (*nomeFunção)      (Parametros da função)*/

/* Desta forma, toda função que retorna INT e usa como parametros dois ponteiros VOID,
    poderá ser "evocada" por outra função com a tipagem FuncaoComparacao e variavel FC.
     exemplo:

void       bubbleSort(*void   info[]   , FuncaoComparacao  fc      )
retorno    função    ( tipo   variavel , tipo              variavel)*/

/* Outra função que retorne INT e use dois ponteiros VOID e que não sirva para comparar
    também poderia ser usada, mas não é o ideal pois isso geraria muita confusão na
     hora da implementação. Por isso, usarei este typedef(tipo) para todas as funções
      comparação(comparaInt, comparaFloat, comparaData, etc...). A seguir uso um novo
       typedef para funções de impressão (imprimeInt, imprimeFloat, etc..). */

//typedef int (*FuncaoImpressao)(void*);

/* Desta forma, sempre que precisar imprimir um valor em uma função, posso passar como
    um parametro o tipo FuncaoImpressao com a variavel FI (FuncaoImpressao fi).
     Lembre que estas funções (imprimeInt, imprimeFloat, imprimeData) so imprimem
      ponteiros VOID. */

/* ----------------------------------------------------------------------------------- */
/* -------------------------------- TIPO DE DADO INT --------------------------------- */
/* ----------------------------------------------------------------------------------- */
void    imprimeInt(void *info){
   int *pi     = (int *) info;
   printf("%d   ", *pi);
}
int converteInt(void *info){
   int *p1 = (int *) info;
   int p2 = 0;

   p2 = *p1

   return p2;
}
int     comparaInt(void *info1, void *info2){

/* Função recebendo dois ponteiros VOID, trabalhando com eles em ponteiros INT,
    e retornando um valor INT. */

    int* pf1 = (int*)info1;
    int* pf2 = (int*)info2;
    if (*pf1 > *pf2)
        return -1;
    if (*pf1 == *pf2)
        return 0;
    else
        return 1;
}
int     comparaIntValor(void *info1, void *info2){

/* Função igual a comparaInt mas que retorna a diferença entre os valores. */
   int *p1 = (int *)info1;
   int *p2 = (int *)info2;
      return *p2 - *p1;
}
int*    somaInt(void *info1, void *info2){

/* Função recebendo dois ponteiros VOID, trabalhando com eles em ponteiros INT,
    e retornando SOMA em ponteiro INT. */

   int *soma   = malloc(sizeof(int));
   int *p1     = (int *) info1;
   int *p2     = (int *) info2;

   *soma = (*p1 + *p2); /* <-Valor de P1 mais valor de P2 sera atribuido pelo ponteiro SOMA */

   return soma; /* <-Retorna ponteiro INT que aponta para o valor atribuido em SOMA
                    em uma função que retorna somente ponteiros tipo INT. */
}
int     perfeitoInt(void *info){

   int *p1     = (int *) info;
   int i = 0;
   void *soma  = malloc(sizeof(int)); /* <-Este ponteiro VOID é desnecessario, foi feito para treinar.*/

   *((int*)soma) = 0; /* <-Lembre-se, para usar ponteiros VOID em memoria de outro tipo, precisa indicar o tipo. */

   for(i=1; i <= (*p1/2) ;++i){
      if(*p1 % i == 0)
         *((int*)soma) += i;
      }

      if( *((int*)soma) == *p1)
       return 1; /* É perfeito */

      else
       return 0; /* Não é perfeito */
}
void*   alocaInfoInt(void *info){

/* Com esta função, podemos converter um ponteiro em INT,
    e alocar memoria para o mesmo. */

   int *pi     = (int *) malloc(sizeof(int));
   *pi = *((int*)info);

   return pi; /* <-Retorna um ponteiro INT em uma função que
                    retorna ponteiro VOID (ponteiro para qualquer coisa)*/
}
int*    alocaInt(int n){

/* Com esta função, podemos converter uma variavel INT qualquer
    em um ponteiro INT e alocar memoria para o mesmo. */

   int *pi     = (int *) malloc(sizeof(int));
   *pi = n;

   return pi; /* <-retorna um ponteiro INT em uma função que retorna somente ponteiro INT. */
}
int*    alocaNInteiros(void *info){

/* Declarando ponteiro P2 para armazenar um espaco de tamanho INFO para os numeros */
   int *p1     = (int *) info;
   int *p2    = malloc(*p1 * sizeof(int));/* <-(*P1) Desta forma a função fica generica, pois nao
                                             importa o tamanho de INFO, a memoria sera alocada de acordo.*/

/* Este FOR ira receber um valor pelo usuario e definira que a proxima memoria do endereco apontado por P2,
    receberá este valor (P2[|->10|32|31|00000000] onde [] é a memoria alocada pelo tamanho de P1(INFO)*/

   for(int i = 0; i < (*p1); i++){
       int x = 0;
       printf("Digite um numero inteiro para ser alocado: ");
       scanf("%d", p2 + i); /* <-O usuario atribui ao endereço seguinte pelo apontado por P2. */
   }
   return p2; /* <-Retorna ponteiro INT cujo valor apontado por ele
                  está em uma memoria cheia de valores P2[|->10|32|31|34|23|21|45]. */
}
void    maiorInteiroNoPonteiro(void* info1, void *info2){

   int *p1     = (int *) info1;
   int *p2     = (int *) info2;
   int *maior  = malloc(sizeof(int));
   *maior = 0;

/* Nesta função, um ponteiro MAIOR é criado para poder retornar ao final qual será o maior valor encontrado.
    Para que isso ocorra, o comando FOR a seguir, ira comparar o valor do primeiro endereço de
     INFO1 (ponteiro para uma memoria cheia de valores) com o proximo endereço (INFO1[|->VALOR|VALOR|VALOR|],
      ate que o tamanho INFO2 (quantidade de valores) seja satisfeito, atribuindo assim,
       um valor novo para MAIOR para cada vez que INFO1 for maior.*/

   for(int i = 0; i <= *p2; i++){
      if(comparaInt((p1 + i),maior) < 0){
      *maior = *(p1 + i); /* <-O valor do ponteiro MAIOR recebera o valor apontado por P1(INFO1) no campo I.*/
      }
   }
   printf("%d", *maior);
}
void*   numeroSucessorInt(void *info){
   (*((int*)info))++;
   return info;
}
void*   numeroAntecessorInt(void *info){
   (*((int*)info))--;
   return info;
}
void*   somaSucessoresInt(void *info1, void *info2){

/* Esta função utiliza ponteiros para VOID pra realizar a soma entre dois valores
    através da recursividade. O primeiro IF da função sera o retono do resultado (INFO1)
     caso o valor apontado por INFO2 seja 0. */

   if (*((int*)info2) == 0)
   return info1;

   else
/* O segundo IF faz o decremento de INFO2 e chama novamente a ela mesma, utilizando também
    duas funções que retornam os respectivos sucessores e antecessores de INFO1 e INFO2.  */

   if (*((int*)info2) > 0)
   return somaSucessoresInt(numeroSucessorInt(info1),numeroAntecessorInt(info2));
}
int     multIntSucessivo(int info1, int info2){

   int info3;

/* Esta função tem como objetivo multiplicar INFO1 e INFO2 de maneira recursiva.
    para isso, ela compara no primeiro IF se info 1 é maior do que 0, caso isso ocorra
     sera decrementado e o valor de INFO2 sera atribuido a variavel local INFO3. */
   if(info1>0){
      info1--;
      info3 = info2;
   }

   else
/* O seguinte IF faz a mesma coisa do primeiro, com a diferença de incrementar INFO1,
    e atribuir (-INFO2) a INFO3. Com isso, sera possivel fazer a multiplicação de numeros negativos.*/
   if (info1<0){
      info1++;
      info3 = -info2;
   }

/* Por fim, o ultimo IF compara INFO1 com 0 e caso seja verdade, retorna INFO3. Caso INFO1 ainda nao
    seja negativo, chama novamente a função acrescida do valor de INFO3 armazenado anteriormente. */
   if(info1==0)
      return info3;

   else
      return info3 + multIntSucessivo(info1,info2);
}
int     primoInt(int info1,int info2){

/* A seguinte função usa a recursividade para verificar se um dado valor INFO1 é primo.
    Perceba que um valor INFO2 esta sendo recebido por ela, mas o mesmo é (INFO1-1). */

/* Para este IF, caso INFO2 (numero anterior a INFO1) seja 1, retorne 1 (numero primo) */
   if(info2==1){
      return 1;
   }

   else
/* Para este IF, caso o resto da divisão de INFO1 por INFO2(valor anterior a INFO1) seja 0,
    retorne 0 (numero não primo)  */
   if(info1%info2==0){
      return 0;
   }

   else
/* caso nenhum dos IFs sejam satisfeitos, a função ira chamar a ela mesma novamente. até que
    se tente dividir todos os numeros anteriores a INFO1, por ele mesmo. quando INFO2 for 1,
     a função terá se certificado que o unico numero dividido por INFO1 é ele mesmo (numero primo).*/
      return primoInt(info1, info2-1);
}
int     quantosDigitos(int x){

   if (x < 10)
      return 1;
   else
      return 1 + quantosDigitos(x/10);
}
int     ocorrenciaDigitoInt(int info1, int info2, int info3){

/* Esta função tem como objetivo, retornar se o algarismo INFO2 esta presente mais vezes em INFO1
    do que INFO3. Para isso, a função verifica se INFO1 é zero, caso positivo, retorna 0.*/
   if(info1 == 0){
      return 0;
   }

/* No segundo IF, verifica se o restante da divisao de INFO1 é = a INFO2, caso positivo,
    soma 1 para X e retorna x + ela mesma com INFO1 sendo dividido por 10. */
   if(info1 % 10 == info2){
      return 1+ocorrenciaDigitoInt(info1/10,info2,info3);
   }

/*O mesmo acontece no terceiro IF, mas a comparação é feita então com INFO1 e INFO3. */
   if(info1 % 10 == info3){
      return -1+ocorrenciaDigitoInt(info1/10,info2,info3);
   }

   else
/* Caso nenhum IF seja verdadeiro, a função retorna ela mesma, sem somar ou subtrair o
    valor de return, com o numero INFO1 dividido por 10, para verificar na proxima
     chamada, se o proximo algarismo de INFO1 corresponde a INFO2 ou INFO3.  */

      return ocorrenciaDigitoInt(info1/10,info2,info3);
}
void    converteIntBin(int x){

/* Esta função converte numeros inteiros para binario usando recursividade. */

   if ( x == 0 )
   return;

   converteIntBin(x / 2);
   printf("%d", x % 2);

}
int     calculoMDC(int x, int y){

   if (y==0){
      return x;
   }

   else
      return calculoMDC(y, x%y);
}
int     calculoMMC(int x,int y){

   int z;

   if(y == 0)
      return x;

   else
      z = (x*y)/(calculoMMC(x,y));
      return (z);
}
int     potencia(int x, int y){

   if (y == 0)
      return 1;

   if (y > 0)
      return x * potencia(x, y-1);

   else
      return 0;
}
int     fatorial(int x){

   if (x == 0)
      return 1;

   if (x > 0)
      return x * fatorial(x-1);

   else
      return 0;
}
//............raizDigital.............
int     somaAlgarismo(int x){

   if(((x/10) + (x%10)) <=9){
      x= ((x/10) + (x%10));
      return x;
   }

   else
      x=((x/10) + (x%10));
      return raizDigital(x);
}
int     raizDigital(int x){

    if (x>9)
       return somaAlgarismo(x);

    if (x<=9)
       return x;
}
//....................................
int     somaDigitos(int x){
   if (x<10)
      return x;

   return x%10 + somaDigitos(x/10);
}
int     quantosDigitosX(int k, int n){

   if (n<10 && n!=k)
      return 0;

   if (n<10 && n==k)
      return 1;

   if (n>=10 && n%10==k)
      return 1 + quantosDigitosX(k,n/10);

   return 0 + quantosDigitosX(k,n/10);
}
int     calculoMaxDC(int a, int b){

   if(a%b == 0)
      return b;
   else
      return calculoMaxDC(b, a%b);
}
int     mod(int x, int y){
/* Calcula quantas quantas vezes Y cabe em X, Esta função não retorna resto de divisão. */

   if(y == 1){ /* Caso Y seja 1, nao tem resto. */
      return 0;
   }
   else
   if(x<y){
      return x; /* Caso X seja menor que Y, X será o resto. */
   }
   else
      return mod(x-y,y); /* remove 1 vez Y de X e chama recursivamente a função. */
}
/* ----------------------------------------------------------------------------------- */
/* -------------------------------- TIPO DE DADO FLOAT ------------------------------- */
/* ----------------------------------------------------------------------------------- */
void    imprimeFloat(void *info){

   float *pf   = (float *) info;
   printf("%.2f   ", *pf);
}
int     comparaFloat(void *info1, void *info2){

    float* pf1 = (float*)info1;
    float* pf2 = (float*)info2;
    if (*pf1 > *pf2)
        return -1;
    if (*pf1 == *pf2)
        return 0;
    else
        return 1;
}
float*  somaFloat(void *info1, void *info2){

   float *soma  = malloc(sizeof(float));
   float *p1    = (float *) info1;
   float *p2    = (float *) info2;
   *soma = (*p1 + *p2);
      return soma;
}
float*  alocaFloat(float valor){

   float *pf = (float*) malloc(sizeof(float));
   *pf       = valor;
      return pf;
}
/* ----------------------------------------------------------------------------------- */
/* --------------------------------- TIPO DE DADO DATA ------------------------------- */
/* ----------------------------------------------------------------------------------- */

/* Outro uso de typedef, nele defino que quando eu escrever (Data), significa
    que estou definindo uma variavel do tipo STRUCT DATA (definida em structs.h). */
//typedef struct data  Data;

/* Neste typedef, defino que quando escrever pData estou me referindo a um ponteiro
    para STRUCT DATA. Assim, fica muito menos trabalhoso lidar com estas variáveis. */
//typedef Data*        pData;

pData   alocaData(int dia, int mes, int ano){

/* esta função usa o typedef definido acima para indicar que o retorno será um ponteiro
    para um valor tipo STRUCT DATA. */

   pData pdata = malloc(sizeof(Data));
   pdata->dia = dia;
   pdata->mes = mes;
   pdata->ano = ano;
   return pdata;
}
void    imprimeData (void *info){

   pData pdata = (pData) info;
   printf("teste %d /%d /%d \n", pdata->dia,pdata->mes,pdata->ano);
}
int     comparaData(void* info1, void* info2){

/* Observe como a implementação do typedef afetou a definição STRUCT DATA e ponteiro
    para STRUCT DATA. */
	
/* Para o valor PDATA1, temos um tipo (pData) ponteiro para (Data) sendo que (Data)
    é um tipo STRUCT DATA. (assim como INT é um tipo de dado, (Data) agora também é um
     tipo de dado, e pData também é um tipo de dado (do tipo, ponteiro para (Data))). */
	 
    pData  data1 = (pData) info1;
    pData  data2 = (pData) info2;

    if (((data1->ano - data2->ano)*365) +
        ((data1->mes - data2->mes)* 30) +
         (data1->dia - data2->dia) > 0)
        return -1; /* <-PDATA2 é mais antiga (menor) que PDATA1 */

    if (((data1->ano - data2->ano)*365) +
        ((data1->mes - data2->mes)* 30) +
         (data1->dia - data2->dia) == 0)
        return 0; /* <-Mesmo dia */
    else
        return 1; /* <-PDATAi é mais antiga (menor) que PDATA2 */
}
int     comparaDataDias  (void *info1, void *info2){
    pData p1 = (pData) info1;
    pData p2 = (pData) info2;
    return ((p2->ano - p1->ano)*365) +
           ((p2->mes - p1->mes)*30)  +
            (p2->dia - p1->dia)  ;
}
void*   alocaInfoData(void *info){
   pData pd = (pData) malloc(sizeof(Data));
   pd->dia = ((pData)info)->dia;
   pd->mes = ((pData)info)->mes;
   pd->ano = ((pData)info)->ano;
   return pd;
}
/* ----------------------------------------------------------------------------------- */
/* ------------------------------------ OPERAÇOES ------------------------------------ */
/* ----------------------------------------------------------------------------------- */
void    bubbleSort(void* dados[], int tam, FuncaoComparacao fc){
   int i, j;
   void* temp;

/* Veja nesta função, um parametro TYPEDEF definido no inicio da biblioteca. O comando
    FOR abaixo será responsável por contar até o numero de endereços do vetor (lembre
     que um vetor DADOS[5] possui 01234 endereços, por isso (n-1) foi usado. */
   for (i=0; i<tam-1; i++){

/* A primeira contagem do proximo FOR, contará até que J tenha percorrido todo o vetor
    fazendo comparações, Atribuindo então I++ e começando a contagem J novamente. */

/* Na primeira contagem, Caso DADOS[5], a partir do momento em que J =  4,
    A contagem finaliza e I++. Um detalhe chave para este algoritmo, é que na proxima
     contagem de J, não será necessario contar o ultimo endereço de memoria, pois o
      maior numero com certeza estará no ultimo endereço de DADOS[] */
      for (j=0; j<tam-(i+1); j++){
/* Caso a comparação FC do valor do primeiro endereço de DADOS[] seja maior que o valor
   Do próximo endereço de DADOS[] utilizo a varável TEMP para fazer a troca dos
    valores. */
        if (fc(dados[j], dados[j+1]) < 0){
           temp       = dados[j];
           dados[j]   = dados[j+1];
           dados[j+1] = temp;
        }
      }
   }
/* Esse algoritmo é complexo, provavelmente você também terá essa dificuldade,
    por isso representei ele para que você possa absorver esta idéia.

COMEÇANDO I = 0 ATE QUE J < 4
J = 0       43521
resultado = |34|521 J = 1
resultado = 3|45|21 J = 2
resultado = 34|25|1 J = 3
resultado = 342|15| J = 4
PARA TUDO I = 1 ATE QUE J < 3
J = 0       34215
resultado = |34|215 J = 1
resultado = 3|24|15 J = 2
resultado = 32|14|5 J = 3
PARA TUDO I = 2 ATE QUE J < 2
J = 0       32145
resultado = |23|145 J = 1
resultado = 2|13|45 J = 2
PARA TUDO I = 3 ATE QUE J < 1
J = 0       21345
resultado = |12|345 J = 1
PARA TUDO I = 3 ATE QUE J = 0
J = 0 */
}
void    alertaMenores(void * info){

   struct pessoa *P = (struct pessoa*) info;

   if(P->Idade < 18){
       printf("--------ATENCAO---------\n-----MENOR DE IDADE----- ");
       printf("\nNome: %s \nIdade: %d \n------------------------\n\n", P->Nome, P->Idade);
       }
}
void    registraPessoas(void *info, void *(funcao)(void *)){
/* ----------------------------------------------------------------------------------- */
/* Esta função recebe dois parametros, ponteiro VOID e ponteiro para FUNÇAO. */

/*Oberseve que FUNÇÃO não esta utilizando o typedef como na função bubbleSort, pois a
    função registraPessoas foi escrita para somente receber a função alertaMenores.
     Portanto, não foi necessario criar um typedef para esta função. Perceba que a
      definição obedece o roteiro descrito na linha 13 deste arquivo.h.
   Lembre que ao receber PX o conteudo do mesmo é {tratado como INFO} na função, e aqui,
    o conteudo da função(alertaMenores) passada no MAIN.c, sera {tratada como FUNCAO}.
     FUNCAO está respeitando o parametro (*void) de alertaMenores.

   (caso a função alertaMenores utilizasse (void *info1, void *info2),
    a nomenclatura de registrapessoas seria:
     void    registraPessoas(void *info, void *(funcao)(void *)(void *))*/

   int *p1      = (int *) info;
   struct pessoa *P = malloc(sizeof (struct pessoa)*(*p1));

/* Aqui, estou alocando memoria para varias structs do tamanho PESSOA, e o ponteiro P que é tambem do tipo struct PESSOA,
    irá apontar para cada uma dessas memorias durante a implementação da função. (lembre que cada instancia foi sequenciada
     no proximo endereço de memoria de P (P[->PESSOA|PESSOA|PESSOA|PESSOA] onde [] corresponde a memoria total alocada))
                                          P[PESSOA|->PESSOA|PESSOA|PESSOA] representação de (P+1)*/

/*  Este FOR tem como objetivo criar um vetor para poder armazenar os nomes e idades.*/
   int i;

   printf("\n-----Cadastrando pessoas-----\n\n");
   for(i= 0; i < (*p1) ;i++){
      printf("Nome: ");
      scanf("%s", &(P+i)->Nome);  /* de acordo com a representação de (P+1), aqui o endereço de (P+I) recebe o valor pelo usuario.*/
      printf("Idade: ");
      scanf("%d", &(P+i)->Idade);
      printf("\n");
      funcao(P+i);
   }
}
int     predicadoMult2(void *info){
/* Retorna 1 caso o numero informado seja divisível por 2. */
   int *pi     = (int *) info;
   if ((*pi % 2) == 0){
      return 1;
   }
   if ((*pi % 2) != 0){
      return 0;
   }
}
int     predicadoMult3(void *info){
/* Retorna 1 caso o numero informado seja divisível por 3. */
   int *pi     = (int *) info;
   if ((*pi % 3) == 0){
      return 1;
   }
   if ((*pi % 3) != 0){
      return 0;
   }
}
#endif