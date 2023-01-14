# Programa de Listas Encadeadas.

Listas encadeadas são compostas por `Structs` chamadas de Nós, formadas por dois valores:

### um valor. (info)

### um ponteiro para uma struct. (prox)

O campo ponteiro para `struct` é responsável por indicar onde está o próximo valor da lista, por isso deve receber uma `struct`, pois o Noh que contém o próximo valor
será outra `Struct Noh`.

Uma lista encadeada deve ser acessada pela primeira `Struct Noh`, como ja deve ter imaginado. Para acessar o ultimo valor, deverá ser acessado todos os Nohs da lista.

Existem listas duplamente encadeadas, estas possuem 3 campos, `anterior`(ponteiro struct), `info` e `prox`(ponteiro struct). Desta forma, é possivel ir e vir na lista, tanto começando pelo primeiro valor ou ultimo valor.

O campo valor poderá ser `INT` para uma lista de numeros inteiros, mas neste programa trabalhamos com ponteiros `VOID`.
desta forma, qualquer valor poderá ser armazenado na `struct Noh`, até mesmo outra `struct`. Aqui começa a se ver a importância de saber trabalhar
com ponteiros `VOID` e alocação dinâmica de memória.
 
 ## Arquivos
 
### mainListas.c

Front end do programa.

### structs.h

Biblioteca para armazenar as structs que poderão ser utilizadas no programa.

### lista.h

Biblioteca com o Back-end do programa, contendo funções de manipulação de listas.

### UtilsListas.h

Bilioteca com o Back-end do programa, contendo as funções e comentários. Uma versão adaptada da biblioteca `utilsPonteiros.h`, vista no programa anterior.