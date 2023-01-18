
<p align="center"> <img src="https://github.com/Contii/MASTIGADO-LINGUAGEM-C/blob/master/02-Listas-Encadeadas/Imagens/Imagem-Lista-Encadeada.png" width="100%"> </p>

# Programa de Listas Encadeadas.

Listas encadeadas são compostas por `Structs` chamadas de Nós, formadas por dois valores:

### um valor. (info)

### um ponteiro para uma struct. (prox)

O campo ponteiro para `struct` é responsável por indicar onde está o próximo valor da lista, por isso deve receber uma `struct`, pois o Noh que contém o próximo valor
será outra `Struct Noh`.

Uma lista encadeada deve ser acessada pela primeira `Struct Noh`, como ja deve ter imaginado. Para acessar o ultimo valor, deverá ser acessado todos os Nohs da lista. Mas isso não acontecerá em nossa lista pois será declarado
um campo para o ultimo Noh na propria definição da lista, neste caso, para acessar do segundo ao penúltimo noh, deverá se passar pelos anteriores.

> Existem listas duplamente encadeadas, estas possuem 3 campos, `anterior`(ponteiro struct), `info` e `prox`(ponteiro struct). Desta forma, é possivel ir e vir na lista, tanto começando pelo primeiro valor ou ultimo valor.

O campo info poderá ser `INT` para uma lista de numeros inteiros, mas neste programa trabalhamos com ponteiros `VOID`.
desta forma, qualquer valor poderá ser armazenado na `struct Noh`, até mesmo outra `struct`. Aqui começa a se ver a importância de saber trabalhar
com ponteiros `VOID` e alocação dinâmica de memória.

#### Segue uma imagem de como uma lista de ponteiros VOID pode ser construida:

<p align="center"> <img src="https://github.com/Contii/MASTIGADO-LINGUAGEM-C/blob/master/02-Listas-Encadeadas/Imagens/Imagem-Lista-Encadeada-VOID.png" width="100%"> </p>

## Arquivos
 
### MainListas.c

Front-End do programa.

### structs.h

Biblioteca para armazenar as structs que poderão ser utilizadas no programa.

### lista.h

Biblioteca com o Back-End do programa, contendo funções de manipulação de listas.

### utilsListas.h

Bilioteca com o Back-End do programa, contendo as funções e comentários. Uma versão adaptada da biblioteca `utilsPonteiros.h`, vista no programa anterior.

### TAD_ListaLinear.h

Bilioteca com os tipos abstratos de dados.