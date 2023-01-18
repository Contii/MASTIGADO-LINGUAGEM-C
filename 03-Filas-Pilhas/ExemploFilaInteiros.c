#include <stdio.h>

#include "UtilsForever.h"
#include "Fila/Fila.h"

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
}
