#include "PilhaEncadeada.h"
#include <stdexcept>

// Complexidade: O(1)
void PilhaEncadeada::empilhar(Elemento* elemento) {
    
    listaInterna.inserirNoInicio(elemento);
}

// Complexidade: O(1)
void PilhaEncadeada::desempilhar() {
    if (estaVazia()) {
        throw std::runtime_error("Erro ao desempilhar: a pilha esta vazia.");
    }
    
    listaInterna.removerPrimeiro();
}

// Complexidade: O(1)
Elemento* PilhaEncadeada::consultarTopo() const {
    if (estaVazia()) {
        return nullptr;
    }
    return listaInterna.getPrimeiroElemento();
}

// Complexidade: O(1)
bool PilhaEncadeada::estaVazia() const {
    return listaInterna.estaVazia();
}