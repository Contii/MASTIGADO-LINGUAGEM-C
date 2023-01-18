#include <stdio.h>

#include "utilsFilaPilha.h"
#include "Fila/fila.h"
#include "pilha/PilHa.h"

int main(){
   pDFila fileira1 = criarFila();

   enfileirarInfo(fileira1, alocaInt(5));
   enfileirarInfo(fileira1, alocaInt(3));
   enfileirarInfo(fileira1, alocaInt(9));
   enfileirarInfo(fileira1, alocaInt(1));
   enfileirarInfo(fileira1, alocaInt(3));

   void *info = desenfileirarInfo(fileira1);
   printf("\nRetirou o inteiro = %d \n", *((int*)info));

   while (filaVazia(fileira1)==0){
      info = desenfileirarInfo(fileira1);
      printf("\nRetirou o inteiro = %d \n", *((int*)info));
   }
   
   pDPilha pPilhaInt = criarPilha();

   empilharInfo(pPilhaInt, alocaInt(5));
   empilharInfo(pPilhaInt, alocaInt(3));
   empilharInfo(pPilhaInt, alocaInt(9));
   empilharInfo(pPilhaInt, alocaInt(1));
   empilharInfo(pPilhaInt, alocaInt(2));


   void *info = desempilharInfo(pPilhaInt);
   printf("\nDesempilhou o inteiro = %d \n", *((int*)info));

   while (pilhaVazia(pPilhaInt)==0){
      info = desempilharInfo(pPilhaInt);
      printf("\nDesempilhou o inteiro = %d \n", *((int*)info));
   }
	
}
