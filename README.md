# 💻 Estruturas de Dados com Programação Orientada a Objetos em C++

Implementação de estruturas de dados fundamentais (Listas, Pilhas, Filas e Árvores) em C++, aplicando os quatro pilares da Programação Orientada a Objetos: Abstração, Encapsulamento, Herança e Polimorfismo.

Este projeto foi desenvolvido para a disciplina de **Algoritmos e Estruturas de Dados** na **Universidade do Estado do Rio de Janeiro (IPRJ)**.

---

### 📚 Índice

- [Autores e Contexto](#-autores-e-contexto)
- [Estrutura do Projeto](#-estrutura-do-projeto)
- [Tecnologias Utilizadas](#-tecnologias-utilizadas)
- [Como Compilar e Executar](#-como-compilar-e-executar)
- [Conceitos Gerais de Projeto](#-conceitos-gerais-de-projeto)
- [Decisões de Design](#-decisões-de-design)
- [Resumo das Implementações](#-resumo-das-implementações)
- [Tabela de Complexidade das Operações](#-tabela-de-complexidade-das-operações)
  
---

## 🧑‍🏫 Autores e Contexto

#### Alunos
- Ana Clara Bezerra
- Felipe Anderson Arcanjo Rodrigues
- João Henrique Madureira
- Luisa de Andrade Lacave
- Renan Thurler da Silva
- Victor Pinheiro Feitosa (GitHub: [@wrxngpin](https://github.com/wrxngpin))

#### Professor
- Rodrigo Mafort

---

## 📂 Estrutura do Projeto

O código-fonte está organizado da seguinte forma para garantir a separação de responsabilidades:

- `include/`: Contém os arquivos de cabeçalho (`.h`) com as declarações das classes e suas interfaces.
- `src/`: Contém os arquivos de implementação (`.cpp`) com a lógica dos métodos das classes.
- `main.cpp`: Programa principal utilizado para demonstrar e testar as funcionalidades das estruturas de dados.
- `README.md`: Esta documentação.

---

## 🛠️ Tecnologias Utilizadas

- **Linguagem:** C++ (utilizando o padrão C++11)
- **Compilador:** g++
- **Editor:** Visual Studio Code

---

## ▶️ Como Compilar e Executar

### Pré-requisitos

Para compilar e executar o projeto, você precisa ter um compilador C++ instalado, como o `g++`, que faz parte do GCC (GNU Compiler Collection).

### Instruções

1.  **Clone o repositório** (se estiver no GitHub):
    ```bash
    git clone [https://github.com/wrxngpin/SEU-REPOSITORIO.git](https://github.com/wrxngpin/SEU-REPOSITORIO.git)
    cd SEU-REPOSITORIO
    ```

2.  **Compile o projeto** usando o comando abaixo no terminal. Este comando compila todos os arquivos `.cpp` da pasta `src/` junto com o `main.cpp`, e utiliza os cabeçalhos da pasta `include/`.
    ```bash
    g++ -std=c++11 main.cpp src/*.cpp -Iinclude -o app.exe
    ```

3.  **Execute o programa** gerado:
    ```bash
    ./app.exe
    ```
    *(Em alguns sistemas, pode ser apenas `app.exe`)*

---

## 🧠 Conceitos Gerais de Projeto

O projeto foi guiado pelos quatro pilares da POO para criar um sistema coeso, flexível e reutilizável.

### 1. Abstração e Herança
Para permitir que nossas estruturas armazenassem diferentes tipos de dados (como `Aluno` e `Professor`), criamos uma hierarquia de classes a partir de uma base comum, a classe `Elemento`.

### 2. Polimorfismo
Graças à hierarquia e aos métodos virtuais, as estruturas de dados podem armazenar uma coleção de ponteiros para `Elemento*`. Ao chamar um método como `imprimirInfo()`, o C++ invoca a versão correta (de `Aluno` ou `Professor`), permitindo tratar objetos diferentes de forma uniforme.

### 3. Encapsulamento
O acesso aos atributos e às estruturas internas das classes é controlado. Detalhes de implementação, como a classe `No` nas listas encadeadas e na árvore, são privados, expondo apenas uma interface pública e segura.

---

## 🏛️ Decisões de Design

Aqui detalhamos o propósito de cada classe e as decisões de design que guiaram sua implementação.

### `Elemento` e `Aluno`
-   **Propósito:** `Elemento.h` define a interface para qualquer objeto que possa ser armazenado nas estruturas. É uma classe abstrata que representa o pilar da **Abstração**. `Aluno.h` é uma implementação concreta que herda de `Elemento`, demonstrando a **Herança**.
-   **Decisão de Design:** O uso de métodos virtuais puros (`imprimirInfo()` e `clone()`) em `Elemento` força todas as classes derivadas a fornecerem sua própria implementação. Isso garante que qualquer objeto em nossas estruturas saiba como se "apresentar" e se "clonar".

### `ListaNaoOrdenada`
-   **Propósito:** Uma implementação de lista com alocação sequencial (array estático). Serve como a base para a Parte I do trabalho e como componente para outras estruturas.
-   **Decisão de Design:** A escolha de um array estático foi intencional para demonstrar as características e limitações da alocação sequencial.

### `FilaBasica` vs. `FilaCircular`
-   **Propósito:** Ambas implementam o conceito de Fila (FIFO), mas com abordagens diferentes.
-   **Decisão de Design:**
    -   `FilaBasica` foi implementada usando **composição**, contendo uma `ListaNaoOrdenada`, promovendo o **reaproveitamento de código**, mas herdando a ineficiência da lista base (desenfileirar é `O(n)`).
    -   `FilaCircular` foi criada para resolver o problema de performance, alcançando complexidade `O(1)` para todas as operações.

### Listas com Alocação Encadeada (`ListaDuplamenteEncadeada`, `ListaDuplamenteEncadeadaCircular`)
-   **Propósito:** Implementar listas com alocação dinâmica, superando a limitação de tamanho fixo dos arrays.
-   **Decisão de Design:** A `ListaDuplamenteEncadeada` foi escolhida por sua flexibilidade, permitindo travessia em ambos os sentidos e remoções `O(1)` nas extremidades. A versão `Circular` é uma variação que conecta o fim ao início.

### `FilaEncadeada`
-   **Propósito:** Criar uma fila eficiente com alocação dinâmica.
-   **Decisão de Design:** Utiliza **composição** com uma lista encadeada, combinando a eficiência `O(1)` da `FilaCircular` com a flexibilidade da alocação dinâmica.

### `ArvoreBinariaBusca`
-   **Propósito:** Implementar uma estrutura de dados não linear otimizada para busca, inserção e remoção.
-   **Decisão de Design:** A principal decisão foi **encapsular** a classe `No` dentro da `ArvoreBinariaBusca` como uma classe privada, ocultando detalhes de implementação e expondo apenas operações de alto nível.

---

## 📝 Resumo das Implementações

### Classes da Hierarquia
- **`Elemento` (abstrata):** Base para todos os itens armazenáveis, com `id` comum e métodos virtuais.
- **`Aluno` e `Professor` (concretas):** Herdam de `Elemento` e implementam comportamento específico.

### Estruturas Implementadas
- **4 Estruturas Sequenciais:** `ListaNaoOrdenada`, `ListaOrdenada`, `Pilha` e `FilaCircular`.
- **4 Estruturas Encadeadas:** `ListaDuplamenteEncadeada`, `ListaDuplamenteEncadeadaCircular`, `FilaEncadeada` e `ArvoreBinariaBusca`.
- **3 Adaptadores por Composição:** `Pilha`, `FilaBasica` e `FilaEncadeada`, que reutilizam o código de listas subjacentes.
- **1 Estrutura Hierárquica:** `ArvoreBinariaBusca` para ordenação e busca eficiente.

### Recursos Especiais
- **Polimorfismo:** Permite que as estruturas armazenem `Aluno` e `Professor` de forma intercambiável.
- **Buffer Circular:** Implementado na `FilaCircular` para operações de enfileirar/desenfileirar em tempo constante `O(1)`.
- **Navegação Bidirecional:** Presente na `ListaDuplamenteEncadeada` para travessia em ambos os sentidos.
- **Encapsulamento de Nós:** Detalhes de implementação dos nós (`No`) são privados nas estruturas encadeadas e na árvore.
- **Gerenciamento Manual de Memória:** O programador tem controle total sobre a alocação (`new`) e desalocação (`delete`) dos elementos.

---

## ⏱️ Tabela de Complexidade das Operações

A tabela a seguir resume a complexidade de tempo (Big O) para as principais operações de cada estrutura de dados implementada.

| Estrutura | Operação | Complexidade (Pior Caso) | Observações |
| :--- | :--- | :---: | :--- |
| **Lista Não Ordenada** | Inserir no Início | `O(n)` | Requer deslocamento de todos os elementos. |
| | Inserir no Final | `O(1)` | Acesso direto à próxima posição livre. |
| | Remover do Início | `O(n)` | Requer deslocamento de todos os elementos. |
| | Remover do Final | `O(1)` | Acesso direto ao último elemento. |
| | Buscar / Alterar / Remover por ID | `O(n)` | Requer busca linear. |
| **Lista Ordenada** | Inserir | `O(n)` | Precisa encontrar a posição e deslocar. |
| | Buscar por ID | `O(log n)` | Utiliza busca binária. |
| | Remover | `O(n)` | Busca `O(log n)` + remoção `O(n)`. |
| **Pilha** | `empilhar` (push) | `O(1)` | Mapeia para `inserirNoFinal` da lista. |
| | `desempilhar` (pop) | `O(1)` | Mapeia para `removerUltimo` da lista. |
| **Fila Básica** | `enfileirar` | `O(1)` | Mapeia para `inserirNoFinal` da lista. |
| | `desenfileirar` | `O(n)` | Mapeia para `removerPrimeiro` da lista. |
| **Fila Circular** | `enfileirar` | `O(1)` | Acesso direto com aritmética modular. |
| | `desenfileirar` | `O(1)` | Acesso direto com aritmética modular. |
| **Lista Duplamente Enc.**| Inserir no Início / Final | `O(1)` | Manipulação direta de ponteiros `cabeca`/`cauda`. |
| | Remover do Início / Final | `O(1)` | Manipulação direta de ponteiros `cabeca`/`cauda`. |
| | Buscar / Remover por ID | `O(n)` | Requer busca linear. |
| **Árvore Binária Busca** | Inserir / Buscar / Remover | `O(n)` | Pior caso: árvore degenerada (como uma lista). |
| | Inserir / Buscar / Remover | `O(log n)` | **Caso Médio:** árvore balanceada. |
| | Percursos (em, pré, pós-ordem) | `O(n)` | Necessário visitar todos os nós. |

---

