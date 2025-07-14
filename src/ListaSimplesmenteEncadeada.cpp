#include "ListaSimplesmenteEncadeada.h"

// Construtor: cria uma lista vazia
ListaSimplesmenteEncadeada::ListaSimplesmenteEncadeada() : cabeca(nullptr), cauda(nullptr), tamanho(0) {}

// Destrutor: importantíssimo para liberar toda a memória alocada
ListaSimplesmenteEncadeada::~ListaSimplesmenteEncadeada() {
    while (!estaVazia()) {
        removerPrimeiro();
    }
}

bool ListaSimplesmenteEncadeada::estaVazia() const {
    return tamanho == 0;
}

int ListaSimplesmenteEncadeada::getTamanho() const {
    return tamanho;
}

void ListaSimplesmenteEncadeada::inserirNoInicio(Elemento* elemento) {
    No* novoNo = new No(elemento);
    if (estaVazia()) {
        cabeca = cauda = novoNo;
    } else {
        novoNo->proximo = cabeca;
        cabeca = novoNo;
    }
    tamanho++;
}

void ListaSimplesmenteEncadeada::inserirNoFim(Elemento* elemento) {
    No* novoNo = new No(elemento);
    if (estaVazia()) {
        cabeca = cauda = novoNo;
    } else {
        cauda->proximo = novoNo;
        cauda = novoNo;
    }
    tamanho++;
}

void ListaSimplesmenteEncadeada::removerPrimeiro() {
    if (estaVazia()) {
        throw std::runtime_error("Erro: A lista esta vazia.");
    }
    No* noParaRemover = cabeca;
    cabeca = cabeca->proximo;
    if (cabeca == nullptr) {
        cauda = nullptr;
    }
    delete noParaRemover->dado;
    delete noParaRemover;
    tamanho--;
}

Elemento* ListaSimplesmenteEncadeada::getPrimeiroElemento() const {
    if (estaVazia()) {
        return nullptr;
    }
    return cabeca->dado;
}