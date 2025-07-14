#include "ListaDuplamenteEncadeadaCircular.h"
#include <iostream>

ListaDuplamenteEncadeadaCircular::ListaDuplamenteEncadeadaCircular() : cabeca(nullptr), tamanho(0) {}

ListaDuplamenteEncadeadaCircular::~ListaDuplamenteEncadeadaCircular() {
    while (!estaVazia()) {
        removerPrimeiro();
    }
}

bool ListaDuplamenteEncadeadaCircular::estaVazia() const { return tamanho == 0; }
int ListaDuplamenteEncadeadaCircular::getTamanho() const { return tamanho; }

void ListaDuplamenteEncadeadaCircular::inserirNoInicio(Elemento* elemento) {
    No* novoNo = new No(elemento);
    if (estaVazia()) {
        cabeca = novoNo;
        novoNo->proximo = cabeca;
        novoNo->anterior = cabeca;
    } else {
        No* cauda = cabeca->anterior;
        novoNo->proximo = cabeca;
        novoNo->anterior = cauda;
        cabeca->anterior = novoNo;
        cauda->proximo = novoNo;
        cabeca = novoNo;
    }
    tamanho++;
}

void ListaDuplamenteEncadeadaCircular::inserirNoFim(Elemento* elemento) {
    if (estaVazia()) {
        inserirNoInicio(elemento);
    } else {
        No* novoNo = new No(elemento);
        No* cauda = cabeca->anterior;
        novoNo->proximo = cabeca;
        novoNo->anterior = cauda;
        cabeca->anterior = novoNo;
        cauda->proximo = novoNo;
        tamanho++;
    }
}

void ListaDuplamenteEncadeadaCircular::removerPrimeiro() {
    if (estaVazia()) return;
    No* noParaRemover = cabeca;
    if (tamanho == 1) {
        cabeca = nullptr;
    } else {
        No* cauda = cabeca->anterior;
        cabeca = cabeca->proximo;
        cabeca->anterior = cauda;
        cauda->proximo = cabeca;
    }
    delete noParaRemover->dado;
    delete noParaRemover;
    tamanho--;
}

void ListaDuplamenteEncadeadaCircular::removerUltimo() {
    if (estaVazia()) return;
    No* noParaRemover = cabeca->anterior;
    if (tamanho == 1) {
        cabeca = nullptr;
    } else {
        No* novaCauda = noParaRemover->anterior;
        novaCauda->proximo = cabeca;
        cabeca->anterior = novaCauda;
    }
    delete noParaRemover->dado;
    delete noParaRemover;
    tamanho--;
}

bool ListaDuplamenteEncadeadaCircular::removerPeloId(long id) {
    if (estaVazia()) return false;
    No* atual = cabeca;
    for (int i = 0; i < tamanho; ++i) {
        if (atual->dado->getID() == id) {
            if (atual == cabeca) {
                removerPrimeiro();
            } else {
                atual->anterior->proximo = atual->proximo;
                atual->proximo->anterior = atual->anterior;
                delete atual->dado;
                delete atual;
                tamanho--;
            }
            return true;
        }
        atual = atual->proximo;
    }
    return false;
}

Elemento* ListaDuplamenteEncadeadaCircular::buscarPeloId(long id) const {
    if (estaVazia()) return nullptr;
    No* atual = cabeca;
    for (int i = 0; i < tamanho; ++i) {
        if (atual->dado->getID() == id) {
            return atual->dado;
        }
        atual = atual->proximo;
    }
    return nullptr;
}

void ListaDuplamenteEncadeadaCircular::imprimirTodos() const {
    if (estaVazia()) {
        std::cout << "A lista circular esta vazia." << std::endl;
        return;
    }
    No* atual = cabeca;
    do {
        atual->dado->imprimirInfo();
        atual = atual->proximo;
    } while (atual != cabeca);
}