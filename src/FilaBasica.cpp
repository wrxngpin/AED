#include "FilaBasica.h"
#include <iostream>

bool FilaBasica::enfileirar(Elemento* e) {
    if (cheia() || e == nullptr) return false;

    // Verifica se já existe elemento com o mesmo ID
    if (lista.buscarPeloId(e->getID()) != nullptr) {
        return false; // ID duplicado - não insere
    }

    return lista.inserirNoFinal(e); // O(1)
}

bool FilaBasica::desenfileirar() {
    if (vazia()) return false;
    lista.removerPrimeiro();
    return true;
}

const Elemento* FilaBasica::frente() const {
    return lista.getPrimeiro();
}

bool FilaBasica::vazia() const {
    return lista.estaVazia();
}

bool FilaBasica::cheia() const {
    return lista.estaCheia();
}

void FilaBasica::imprimirTodos() const {
    lista.imprimirTodos();
}
