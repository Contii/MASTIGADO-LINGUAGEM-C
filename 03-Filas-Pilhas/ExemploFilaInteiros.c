#include <stdio.h>

#include "UtilsForever.h"
#include "Fila/Fila.h"
#include "Pilha/Pilha.h"

int main(){
   pDFila fileira1 = criarFila();

   enfileirarInfo(fileira1, alocaInt(5));
   enfileirarInfo(fileira1, alocaInt(3));
   enfileirarInfo(fileira1, alocaInt(9));
   enfileirarInfo(fileira1, alocaInt(1));
   enfileirarInfo(fileira1, alocaInt(3));


/*
   void *info = desenfileirarInfo(fileira1);
   printf("\nRetirou o inteiro = %d \n", *((int*)info));

   while (filaVazia(fileira1)==0){
      info = desenfileirarInfo(fileira1);
      printf("\nRetirou o inteiro = %d \n", *((int*)info));
   }
*/

   printf("-------exercicio 1-------\n");
/// para o exercicio 1, tem a função NGE em fila.h (linha 49)
/// em utilsForever.h tem a struct nge e a função imprimeNge (linha 550)
//   pDLista lista1 = NGE(fileira1, comparaInt);
//   imprimirLista(lista1, imprimeNge);
   printf("\n");
   printf("-------exercicio 2-------\n");
/// exercicio 2
//   pDFila primos = fatoracaoPrima(630);
//   imprimirLista(primos->listinha,imprimeInt);
   printf("\n");
   printf("-------exercicio 3-------\n");
/// exercicio3, funcao esta na linha 50 de pilha.h, nao consegui resolver o problema..
//   pDPilha pilha1 = criarPilha();

//   empilharInfo(pilha1, alocaInt(5));
//   empilharInfo(pilha1, alocaInt(3));
//   empilharInfo(pilha1, alocaInt(9));
//   empilharInfo(pilha1, alocaInt(1));
//   empilharInfo(pilha1, alocaInt(3));

//   imprimirLista(pilha1->listinha, imprimeInt);
//   printf("\n");
//   troca(pilha1,2);
//   imprimirLista(pilha1->listinha, imprimeInt);


   printf("\n");
   printf("-------exercicio 4-------\n");
/// exercicio4, funcao esta na linha 682 de UtilsForever.h. Nao consegui entender porque sempre retorna S
   char pilha[4] = {'E','E','D','E','D'};
   char pilha2[4] = {'E','D','D','E','D'};
   printf("%c",bemFormada(pilha));
   printf("\n");
   printf("%c",bemFormada(pilha2));
   printf("\n");

   printf("\n");

}
