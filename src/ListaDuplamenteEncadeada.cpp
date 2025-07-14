#include "ListaDuplamenteEncadeada.h"
#include <iostream>

ListaDuplamenteEncadeada::ListaDuplamenteEncadeada() : cabeca(nullptr), cauda(nullptr), tamanho(0) {}

ListaDuplamenteEncadeada::~ListaDuplamenteEncadeada() {
    while (!estaVazia()) {
        removerPrimeiro();
    }
}

bool ListaDuplamenteEncadeada::estaVazia() const { return tamanho == 0; }
int ListaDuplamenteEncadeada::getTamanho() const { return tamanho; }

void ListaDuplamenteEncadeada::inserirNoInicio(Elemento* elemento) {
    No* novoNo = new No(elemento);
    if (estaVazia()) {
        cabeca = cauda = novoNo;
    } else {
        novoNo->proximo = cabeca;
        cabeca->anterior = novoNo;
        cabeca = novoNo;
    }
    tamanho++;
}

void ListaDuplamenteEncadeada::inserirNoFim(Elemento* elemento) {
    No* novoNo = new No(elemento);
    if (estaVazia()) {
        cabeca = cauda = novoNo;
    } else {
        novoNo->anterior = cauda;
        cauda->proximo = novoNo;
        cauda = novoNo;
    }
    tamanho++;
}

void ListaDuplamenteEncadeada::removerPrimeiro() {
    if (estaVazia()) return;
    No* noParaRemover = cabeca;
    cabeca = cabeca->proximo;
    if (cabeca != nullptr) {
        cabeca->anterior = nullptr;
    } else {
        cauda = nullptr;
    }
    delete noParaRemover->dado;
    delete noParaRemover;
    tamanho--;
}

void ListaDuplamenteEncadeada::removerUltimo() {
    if (estaVazia()) return;
    No* noParaRemover = cauda;
    cauda = cauda->anterior;
    if (cauda != nullptr) {
        cauda->proximo = nullptr;
    } else {
        cabeca = nullptr;
    }
    delete noParaRemover->dado;
    delete noParaRemover;
    tamanho--;
}

bool ListaDuplamenteEncadeada::removerPeloId(long id) {
    if (estaVazia()) return false;
    if (cabeca->dado->getID() == id) {
        removerPrimeiro();
        return true;
    }
    if (cauda->dado->getID() == id) {
        removerUltimo();
        return true;
    }
    No* atual = cabeca->proximo;
    while (atual != nullptr && atual != cauda) {
        if (atual->dado->getID() == id) {
            atual->anterior->proximo = atual->proximo;
            atual->proximo->anterior = atual->anterior;
            delete atual->dado;
            delete atual;
            tamanho--;
            return true;
        }
        atual = atual->proximo;
    }
    return false;
}

Elemento* ListaDuplamenteEncadeada::buscarPeloId(long id) const {
    No* atual = cabeca;
    while (atual != nullptr) {
        if (atual->dado->getID() == id) {
            return atual->dado;
        }
        atual = atual->proximo;
    }
    return nullptr;
}

void ListaDuplamenteEncadeada::imprimirTodos() const {
    if (estaVazia()) {
        std::cout << "A lista esta vazia." << std::endl;
        return;
    }
    No* atual = cabeca;
    while (atual != nullptr) {
        atual->dado->imprimirInfo();
        atual = atual->proximo;
    }
}