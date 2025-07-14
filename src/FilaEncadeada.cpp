#include "FilaEncadeada.h"
#include <stdexcept>

// Complexidade: O(1) 
void FilaEncadeada::enfileirar(Elemento* elemento) {
    listaInterna.inserirNoFim(elemento);
}

// Complexidade: O(1)
void FilaEncadeada::desenfileirar() {
    if (estaVazia()) {
        throw std::runtime_error("Erro ao desenfileirar: a fila esta vazia.");
    }
    listaInterna.removerPrimeiro();
}

// Complexidade: O(1)
Elemento* FilaEncadeada::consultarInicio() const {
    if (estaVazia()) {
        return nullptr;
    }
    return listaInterna.getPrimeiroElemento();
}

// Complexidade: O(1)
bool FilaEncadeada::estaVazia() const {
    return listaInterna.estaVazia();
}