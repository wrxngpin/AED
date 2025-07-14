# Trabalho de Algoritmos e Estruturas de Dados - Programação Orientada a Objetos

Universidade do Estado do Rio de Janeiro - IPRJ

## Grupo

Alunos: Ana Clara Bezerra, Felipe Anderson Arcanjo Rodrigues, João Henrique, Luisa de Andrade Lacave, Renan Thurler da Silva e Victor Pinheiro Feitosa

GitHub: Luisa-Andrade

---

## Professor

Rodrigo Mafort

---

## Objetivo

Este trabalho visa a aplicação prática dos quatro pilares da Programação Orientada a Objetos (Abstração, Encapsulamento, Herança e Polimorfismo) na implementação de estruturas de dados em C++. O sistema implementado busca coesão, ser reutilizável e seguir as boas práticas da orientação a objetos.

---

## Estrutura Utilizada no Projeto

- `include/` — arquivos `.h` que contém as declarações das classes.
- `src/` — arquivos `.cpp` contendo as implementações.
- `main.cpp` — programa principal para testes e demonstração.
- `README.md` — documentação do projeto.

---

## 🛠️ Instruções de Compilação e Execução

Para o projeto, utilizamos do VsCode e para sua compilação utilizamos o compilador `g++`. 

O comando utilizado foi:

```bash
g++ -std=c++11 main.cpp src/*.cpp -Iinclude -o app.exe
```

Que cria o arquivo app.exe e executando ele:

```bash
app.exe
```

Temos a execução do trabalho e suas funcionalidades.

Com isso podemos seguir as aplicações do trabalho.

---

## Parte I — Implementações com Alocação Sequencial

### Classe Abstrata de nome `Elemento`

A classe `Elemento` foi criada para servir como a base abstrata para todos os tipos de dados que serão armazenados nas estruturas. Essa decisão segue o princípio da **abstração**, definindo assim um modelo em comum para os elementos que fazem parte de: listas, filas, pilhas e as outras estruturas presentes no projeto.

As classes que herdam de `Elemento`, que são as classes derivadas, nomeamos de `Aluno` e `Professor`, que representam tipos distintos de dados que as estruturas devem armazenar e manipular.

---

### Motivação e Objetivo

De acordo com a proposta do trabalho é necessário uma hierarquia de classes para representar os elementos armazenados e que essa hierarquia comece com uma classe abstrata, aquela que chamamos de `Elemento`. Essa classe deve conter:

- Um **atributo protegido `id`**, funcionando como chave primária para cada elemento;
- Um **método público `getID()`**, única forma de acesso externo ao identificador;
- Ao menos um **método virtual puro**, para garantir que as classes derivadas implementem seu próprio comportamento.

As classes derivadas (`Aluno` e `Professor`), implementam esse modelo, adicionando atributos e comportamentos específicos, como nome, matrícula e área de atuação, além de suas próprias versões do método `imprimirInfo()`.

---

### Decisões de Projeto

- A classe foi definida como **abstrata** por meio de um método virtual puro `imprimirInfo() const`, que força as subclasses a implementarem sua própria forma de exibir informações específicas do tipo de dado que representa;
- O atributo `id` foi declarado como `protected`, restringindo o acesso direto e promovendo o **encapsulamento**;
- O método `getID()` foi implementado como a única forma de obter o valor do ID, conforme pedido no enunciado;
- As classes `Aluno` e `Professor` estendem `Elemento`, cada uma com seus atributos próprios (como nome e matrícula para `Aluno`, nome e área para `Professor`), respeitando o princípio da **herança**.

---

### Relacionamento com Outros Componentes

A classe `Elemento` será herdada por todas as classes concretas que representam dados nas estruturas. Isso permite que listas, filas, pilhas e árvores possam armazenar diferentes tipos de objetos — como instâncias de `Aluno` e `Professor` —, mas tratá-los de forma genérica via ponteiros ou referências para `Elemento`, utilizando **polimorfismo** para acessar métodos como `imprimirInfo()`.

Essa abordagem utilizada fortalece a coesão do sistema e promove a **reutilização de código**, permitindo que as estruturas operem sobre qualquer classe derivada sem necessidade de conhecer sua implementação específica.

---

### Complexidade dos Métodos

| Método           | Complexidade | Observação                                              |
|------------------|--------------|----------------------------------------------------------|
| `getID()`        | O(1)         | Acesso direto ao valor armazenado em memória.            |
| `imprimirInfo()` | -            | Método virtual puro — sua complexidade depende da implementação em `Aluno` e `Professor`. |

---

### Conformidade com os Requisitos do Enunciado

- [x] Classe abstrata com método virtual puro;
- [x] Atributo `id` protegido, acessado apenas via método público;
- [x] Compatível com uso em estruturas genéricas baseadas em ponteiros para `Elemento`;
- [x] Garante polimorfismo em chamadas como `imprimirInfo()` em listas e outras estruturas, permitindo que objetos das classes `Aluno` e `Professor` sejam tratados individualmente.

---

## FAZER ALTERAÇÕES DAQUI PRA BAIXO!!!!


### Hierarquia Elemento

- **Elemento** (classe abstrata)
  - Atributo protegido `id` (tipo `int`);
  - Método público `getID() const`;
  - Método virtual puro `imprimirInfo() const = 0` para obrigar implementação em classes concretas.
- Classes concretas que herdam de Elemento:
  - **Aluno** — atributos: `nome`, `matricula`;
  - **Professor** — atributos: `nome`, `area`.

Essas classes servem para demonstrar o polimorfismo e armazenamento heterogêneo nas estruturas de dados.

---

### Lista Não Ordenada

- Métodos: 
  - `inserirNoInicio`, `inserirNoFinal`
  - `removerPrimeiro`, `removerUltimo`
  - `removerPeloId`, `buscarPeloId`, `alterarPeloId`
- Implementação: array estático de ponteiros para `Elemento`.
- Complexidades:
  - Inserir no início: O(n) (desloca elementos)
  - Inserir no final: O(1)
  - Remover primeiro: O(n)
  - Remover último: O(1)
  - Buscar/remover/alterar pelo ID: O(n)

---

### Lista Ordenada

- Mesmos métodos da lista não ordenada, mas mantendo a ordem crescente pelo `id`.
- Busca implementada via busca binária para otimizar para O(log n).
- Inserções mantêm a ordem deslocando elementos.
- Complexidades:
  - Inserir: O(n)
  - Buscar: O(log n)
  - Remover: O(n)

---

### Pilha (Stack)

- Implementada via composição usando a Lista Não Ordenada.
- Métodos expostos:
  - `empilhar` (push)
  - `desempilhar` (pop)
  - `consultarTopo` (top)
  - `pilhaCheia`, `pilhaVazia`
- Todas as operações mapeadas para métodos da lista subjacente.

---

### Fila (Queue)

#### Implementação básica (FilaBasica)

- Composição com Lista Não Ordenada.
- Operação `desenfileirar` faz remoção do primeiro elemento (O(n)).
- Operação `enfileirar` insere no final (O(1)).
- Ineficiência devido ao deslocamento na remoção.

#### Implementação otimizada (FilaCircular)

- Usa array circular fixo (tamanho 100).
- Ponteiros para Elemento gerenciados circularmente.
- Todas as operações: enfileirar, desenfileirar, consultar frente, pilhaCheia e pilhaVazia são O(1).
- Resolve problema da fila básica.

---

## Parte II — Implementações com Alocação Encadeada

## Arvore Binaria de Busca
A Arvore Binaria de Busca foi implementada para manter os elementos ordenados com base no ID, garantindo buscas, inserções e remoções eficientes com uma entrada de dados equeilibrados. Assim como requerido, a classe "No" da árvore é privada e inacessível ao usuário final.  As operações foram implementadas de forma recursiva.

Complexidade dos Metodos Utilizados:

| Método           | Complexidade | Observação                                              |
|------------------|--------------|----------------------------------------------------------|
| `Inserir,BuscarPeloId,RemoverPeloId`        | O(log n) Caso medio        | Pior caso seria O(n), em caso da arvore perder sua forma devido a uma possivel lista já ordenada.         |
| `emOrdem,preOrdem,pósOrdem` | O(n)            | Isso devido a necessidade de visitar todos os nós da arvore para tal. |
|

*(Ainda não implementado — pode ser estendido conforme requisitos futuros)*

---

## Decisões de Design

- Uso extensivo de polimorfismo para permitir armazenar objetos heterogêneos em uma mesma estrutura.
- Classes abstratas e virtuais puras para garantir implementação correta dos métodos essenciais.
- Gerenciamento manual de memória (`new` e `delete`) para cada elemento inserido/removido.
- Separação clara entre declarações (`.h`) e implementações (`.cpp`).
- Uso de composição para construir Pilha e Fila a partir das listas existentes, facilitando reaproveitamento de código.

---

## Complexidade das Estruturas e Operações

| Estrutura          | Operação           | Complexidade   |
|--------------------|--------------------|---------------|
| Lista Não Ordenada  | Inserir no início  | O(n)          |
|                    | Inserir no final   | O(1)          |
|                    | Remover primeiro   | O(n)          |
|                    | Remover último     | O(1)          |
|                    | Buscar/Alterar/Remover pelo ID | O(n)          |
| Lista Ordenada      | Inserir            | O(n)          |
|                    | Buscar             | O(log n)      |
|                    | Remover            | O(n)          |
| Pilha               | Empilhar           | O(1)          |
|                    | Desempilhar        | O(1)          |
|                    | Consultar topo     | O(1)          |
| Fila Básica         | Enfileirar         | O(1)          |
|                    | Desenfileirar      | O(n)          |
| Fila Circular       | Enfileirar         | O(1)          |
|                    | Desenfileirar      | O(1)          |
| Arvore Binaria     | Inserir            | O(log n)      |
| de Busca           | Buscar pelo ID     | O(log n)      |
|                    | Remover pelo ID    | O(log n)      |

---
