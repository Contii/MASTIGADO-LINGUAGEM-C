#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>

/*---------------- COMO É DEFINIDA UMA FUNÇÃO COM PONTEIROS PARA VOID -----------------*/

/* void          nomeFunção  (void *info,void *info2,void *info3)                      */
/* retorna void  nomeFunção (valor apontado por ponteiro VOID, valor2, valor3)         */


/*------------ FUNÇÃO COM PONTEIROS PARA VOID E PONTEIRO PARA OUTRA FUNÇÃO ------------*/

/* void          nomeFunção  (void *info, void *(funcao)(void *))                      */
/* retorna void  nomeFunção (ponteiro VOID, função e seu parametro)                    */

/* void          nomeFunção  (void *info, void *(funcao)(void *)(void *))              */
/* retorna void  nomeFunção (ponteiro VOID, função e seus 2 parametros)                */


/* ----------------------------------------------------------------------------------- */
/* -------------------------------- TIPO DE DADO INT --------------------------------- */
/* ----------------------------------------------------------------------------------- */

void   imprimeInt(void *info){
   int *pi     = (int *) info;
   printf("%d   ", *pi);
}

int    comparaInt(void *info1, void *info2){
/* Função recebendo dois ponteiros VOID, trabalhando com eles em ponteiros INT,
    e retornando um valor INT. */
   int *p1     = (int *) info1;
   int *p2     = (int *) info2;
   return *p2 - *p1;/* <-retorna valor apontado por P2 menos valor apontado por P1 em uma função que retorna um valor INT. */
}

int*   somaInt(void *info1, void *info2){
/* Função recebendo dois ponteiros VOID, trabalhando com eles em ponteiros INT,
    e retornando SOMA em ponteiro INT. */
   int *soma   = malloc(sizeof(int));
   int *p1     = (int *) info1;
   int *p2     = (int *) info2;
   *soma = (*p1 + *p2); /* <- valor de P1 mais valor de P2 sera atribuido pelo ponteiro SOMA */
   return soma; /* <-retorna ponteiro INT que aponta para o valor atribuido em SOMA em uma função que retorna somente ponteiros tipo INT. */
}

int    perfeitoInt(void *info){
   int *p1     = (int *) info;
   int i = 0;
   void *soma  = malloc(sizeof(int)); /* <- este ponteiro VOID é desnecessario, foi feito para treinar.*/
   *((int*)soma) = 0; /* <- Lembre que para trabalhar com ponteiros VOID em memoria de outro tipo, é preciso indicar o tipo. */

   for(i=1; i <= (*p1/2) ;++i){
      if(*p1 % i == 0)
         *((int*)soma) += i;
      }
      if( *((int*)soma) == *p1)
       return 1; /* É perfeito */
      else
       return 0; /* Não é perfeito */
}

void*  alocaInfoInt(void *info){
/* Com esta função, podemos converter um ponteiro em INT,
    e alocar memoria para o mesmo. */
   int *pi     = (int *) malloc(sizeof(int));
   *pi = *((int*)info);
   return pi; /* <-retorna um ponteiro INT em uma função que retorna ponteiro VOID (qualquer coisa) */
}

int*   alocaInt(int n){
/* Com esta função, podemos converter uma variavel INT qualquer
    em um ponteiro INT e alocar memoria para o mesmo. */
   int *pi     = (int *) malloc(sizeof(int));
   *pi = n;
   return pi; /* <-retorna um ponteiro INT em uma função que retorna somente ponteiro INT. */
}

int*   alocaNInteiros(void *info){
   int *p1     = (int *) info;
/* declarando ponteiro P2 para armazenar um espaco de tamanho INFO para os numeros */
   int *p2    = malloc(*p1 * sizeof(int));/* <---(*p1) desta forma a função fica generica, pois nao importa o tamanho de INFO, a memoria sera alocada de acordo.*/

/* este FOR ira receber um valor pelo usuario e definira que a proxima memoria do endereco apontado por P2,
    receberá este valor (P2[|->10|32|31|00000000] onde [] é a memoria alocada pelo tamanho de P1(INFO)*/
   for(int i = 0; i < (*p1); i++){
       int x = 0;
       printf("\nDigite um numero inteiro para ser alocado:");
       scanf("%d", p2 + i); /* <- o usuario atribui ao endereço seguinte pelo apontado por P2. */
   }
   return p2; /* <- retornando o ponteiro INT cujo valor apontado por ele está em uma memoria cheia de valores P2[|->10|32|31|34|23|21|45]. */
}

void    maiorInteiroNoPonteiro(void* info1, void *info2){
   int *p1     = (int *) info1;
   int *p2     = (int *) info2;
   int *maior  = malloc(sizeof(int));
   *maior = 0;
/* Nesta função, um ponteiro MAIOR é criado para poder retornar ao final qual será o maior valor encontrado.
    Para que isso ocorra, o comando FOR a seguir, ira comparar o valor do primeiro endereço de INFO1 (ponteiro para uma memoria cheia de valores)
     com o proximo endereço (INFO1[|->VALOR|VALOR|VALOR|], ate que o tamanho INFO2 (quantidade de valores) seja satisfeito,
      atribuindo assim, um valor novo para MAIOR para cada vez que INFO1 for maior.*/
   for(int i = 0; i <= *p2; i++){
      if(comparaInt((p1 + i),maior) < 0){
      *maior = *(p1 + i); /* <- o valor do ponteiro MAIOR recebera o valor apontado por P1(INFO1) no campo I.*/
      }
   }
   printf("%d", *maior);
}

/* ----------------------------------------------------------------------------------- */
/* -------------------------------- TIPO DE DADO FLOAT ------------------------------- */
/* ----------------------------------------------------------------------------------- */

void    imprimeFloat(void *info){
   float *pf   = (float *) info;
   printf("%.2f   ", *pf);
}

float   comparaFloat(void *info1, void *info2){
   float *p1 = (float *) info1;
   float *p2 = (float *) info2;
   return *p2 - *p1;
}

float*  somaFloat(void *info1, void *info2){
   float *soma  = malloc(sizeof(float));
   float *p1    = (float *) info1;
   float *p2    = (float *) info2;
   *soma = (*p1 + *p2);
   return soma;
}

/* ----------------------------------------------------------------------------------- */
/* ------------------------------------ OPERAÇOES ------------------------------------ */
/* ----------------------------------------------------------------------------------- */

void    alertaMenores(void * info){
   struct pessoa *P = (struct pessoa*) info;

   if(P->Idade < 18){
       printf("--------ATENCAO---------\n-----MENOR DE IDADE----- ");
       printf("\nNome: %s \nIdade: %d \n\n", P->Nome, P->Idade);
       }
   }

void    registraPessoas(void *info, void *(funcao)(void *)){
/*  Observe que a função esta recebendo dois parametros, ponteiro void e ponteiro função.
     observe tambem que esse ponteiro void*(funcao), foi indicado juntamente com o seu parametro (void*),
      lembre que ao receber PX o mesmo é tratado como info na função, e aqui a função alertaMenores(de acordo com o MAIN),
       esta sendo apontada pela função, respeitando o parametro (*void) da mesma. (caso a função alertaMenores utilizasse (void *info1, void *info2),
        a nomenclatura que receberia o ponteiro para a função seria (void *(funcao)(void*)(void*))*/
   int *p1      = (int *) info;
   struct pessoa *P = malloc(sizeof (struct pessoa)*(*p1));
/* Aqui, estou alocando memoria para varias structs do tamanho PESSOA, e o ponteiro P que é tambem do tipo struct PESSOA,
    irá apontar para cada uma dessas memorias durante a implementação da função. (lembre que cada instancia foi sequenciada
     no proximo endereço de memoria de P (P[->PESSOA|PESSOA|PESSOA|PESSOA] onde [] corresponde a memoria total alocada))
                                          P[PESSOA|->PESSOA|PESSOA|PESSOA] representação de (P+1)*/
/*  Este FOR tem como objetivo criar um vetor para poder armazenar os nomes e idades.*/
   int i;
   printf("\n-----Cadastrando pessoas-----\n");
   for(i= 0; i < (*p1) ;i++){
      printf("Nome: ");
      scanf("%s", &(P+i)->Nome);  /* de acordo com a representação de (P+1), aqui o endereço de (P+I) recebe o valor pelo usuario.*/
      printf("Idade: ");
      scanf("%d", &(P+i)->Idade);
      printf("\n");
      funcao(P+i);
   }
}

#endif /* UTILS_H */
