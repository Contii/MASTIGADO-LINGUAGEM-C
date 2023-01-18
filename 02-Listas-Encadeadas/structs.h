#ifndef STRUCTS_H
#define STRUCTS_H

/* ------------------------------- */
struct data{
   int         dia;
   int         mes;
   int         ano;
};
/* ------------------------------- */
struct pessoa{
   int         Idade;
   char        Nome[25];
};
/* ------------------------------- */
struct formula{
   void       *coeficiente;
   void       *base;
   void       *expoente;
};
/* ------------------------------- */
struct dLista{			// Struct Descritor de Listas
   int         quantidade;
   struct noh *primeiro;
   struct noh *ultimo;
};
/* ------------------------------- */
struct noh{				// Struct Noh de Listas
   void       *info;
   struct noh *prox;
};
/* ------------------------------- */
struct nohd{			// Struct Noh de Listas Duplas
   struct noh *ant;
   void       *info;
   struct noh *prox;
};
#endif
