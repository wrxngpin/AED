#include "ListaNaoOrdenada.h"
#include <iostream>

// Destrutor: libera memória
ListaNaoOrdenada::~ListaNaoOrdenada() {
    for (int i = 0; i < tamanho; ++i) {
        delete elementos[i];
    }
}

// Insere no início (desloca elementos para a direita)
bool ListaNaoOrdenada::inserirNoInicio(Elemento* e) {
    if (estaCheia() || e == nullptr || buscarPeloId(e->getID()) != nullptr) {
        return false; // Lista cheia, elemento inválido ou ID repetido
    }
    for (int i = tamanho; i > 0; --i) {
        elementos[i] = elementos[i - 1];
    }
    elementos[0] = e;
    tamanho++;
    return true;
}

// Insere no final (O(1))
bool ListaNaoOrdenada::inserirNoFinal(Elemento* e) {
    if (estaCheia() || e == nullptr || buscarPeloId(e->getID()) != nullptr) {
        return false;
    }
    elementos[tamanho++] = e;
    return true;
}

// Remove o primeiro elemento (desloca elementos para a esquerda)
bool ListaNaoOrdenada::removerPrimeiro() {
    if (estaVazia()) return false;
    delete elementos[0];
    for (int i = 1; i < tamanho; ++i) {
        elementos[i - 1] = elementos[i];
    }
    tamanho--;
    return true;
}

// Remove o último elemento (O(1))
bool ListaNaoOrdenada::removerUltimo() {
    if (estaVazia()) return false;
    delete elementos[--tamanho];
    return true;
}

// Remove por ID (busca linear + deslocamento)
bool ListaNaoOrdenada::removerPeloId(int id) {
    for (int i = 0; i < tamanho; ++i) {
        if (elementos[i]->getID() == id) {
            delete elementos[i];
            for (int j = i; j < tamanho - 1; ++j) {
                elementos[j] = elementos[j + 1];
            }
            tamanho--;
            return true;
        }
    }
    return false;
}

// Busca por ID (retorna ponteiro const)
const Elemento* ListaNaoOrdenada::buscarPeloId(int id) const {
    for (int i = 0; i < tamanho; ++i) {
        if (elementos[i]->getID() == id) {
            return elementos[i];
        }
    }
    return nullptr;
}

// Altera elemento por ID (substitui diretamente)
bool ListaNaoOrdenada::alterarPeloId(int id, Elemento* novo) {
    if (novo == nullptr || novo->getID() != id) return false;
    for (int i = 0; i < tamanho; ++i) {
        if (elementos[i]->getID() == id) {
            delete elementos[i];
            elementos[i] = novo;
            return true;
        }
    }
    return false;
}

// Remove o último sem deletar (para uso em estruturas temporárias como pilha)
Elemento* ListaNaoOrdenada::removerUltimoSemDeletar() {
    if (estaVazia()) return nullptr;
    return elementos[--tamanho]; // Apenas remove da lista, sem delete
}

// Imprime todos os elementos (polimorfismo)
void ListaNaoOrdenada::imprimirTodos() const {
    for (int i = 0; i < tamanho; ++i) {
        elementos[i]->imprimirInfo();
    }
}

// Retorna primeiro/último elemento (const)
const Elemento* ListaNaoOrdenada::getPrimeiro() const {
    return estaVazia() ? nullptr : elementos[0];
}

const Elemento* ListaNaoOrdenada::getUltimo() const {
    return estaVazia() ? nullptr : elementos[tamanho - 1];



}