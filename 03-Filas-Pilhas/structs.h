#ifndef STRUCTS_H
#define STRUCTS_H

/* ------------------------------- */
struct noh{
   void       *info;
   struct noh *prox;
};
/* ------------------------------- */
struct nohd{
   struct noh *ant;
   void       *info;
   struct noh *prox;
};
/* ------------------------------- */
struct formula{
   void       *coeficiente;
   void       *base;
   void       *expoente;
};
/* ------------------------------- */
struct dLista{
   int         quantidade;
   struct noh *primeiro;
   struct noh *ultimo;
};
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
struct dFila{
    pDLista pdLista;
};
/* ------------------------------- */
#endif