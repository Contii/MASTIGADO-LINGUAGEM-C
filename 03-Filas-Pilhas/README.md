# Programa de Filas e Pilhas.
Filas e Pilhas são estruturas que possuem a mesma arquitetura de Listas, mas com outras regras de acesso.
<br> </br>

Uma `Fila` segue a mesma regra de acesso aos dados que uma lista encadeada, partindo do primeiro inserido até o ultimo, mas deve seguir uma regra de manipulação nas informações chamada de FIFO (First In, First Out).

Teoricamente, um indivíduo teria como desistir de estar em uma fila de espera, mas na estrutura de dados isso não deve ser possível, a remoção de informações só deve acontecer partindo do `Noh` mais antigo adicionado a fila.
<br> </br>
Em `Pilhas` podemos usar como exemplo uma pilha de livros, para remover o primeiro livro colocado sobre uma mesa devemos remover todos os que estão em cima dele primeiro, LIFO (Last In, First Out).

Uma característica importante das estruturas de pilha é que para remover um `Noh` que não esteja em cima da pilha, devemos criar uma segunda pilha para armazenar todos os que estão acima do mesmo, para em seguida recolocá-los na pilha original.
<br> </br>
Aqui, mais do que nunca, o TAD será necessário. Ele nos permite dar um nome diferente  para cada descritor de `Lista`, `Fila` ou `Pilha`, de maneira a não permitir por exemplo, que uma `Pilha` possa ser utilizada em uma função de `Fila`, por possuir a mesma estrutura. Isso desobedeceria a regra de acesso conceitual que uma `Pilha` deve obedecer.

## Arquivos
 
### Pasta Fila

Pasta com a biblioteca contendo funções de manipulação de filas.

### Pasta ListaLinear

Pasta com a biblioteca contendo funções de manipulação de listas.

### Pasta Pilha

Pasta com a biblioteca contendo funções de manipulação de pilhas.

### MainFilaPilha.c

Front-End do programa.

### structs.h

Biblioteca para armazenar as structs que poderão ser utilizadas no programa.

### utilsFilaPilha.h

Bilioteca com o Back-End do programa, contendo as funções e comentários.