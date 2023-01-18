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
#endif
