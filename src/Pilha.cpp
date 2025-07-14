#include "Pilha.h"

bool Pilha::empilhar(Elemento* e) {
    if (e == nullptr || pilhaCheia()) {
        return false; // Elemento inválido ou pilha cheia
    }
    return lista.inserirNoFinal(e); // O(1)
}

bool Pilha::desempilhar() {
    if (pilhaVazia()) {
        return false; // Pilha vazia
    }
    lista.removerUltimo(); // O(1)
    return true;
}

const Elemento* Pilha::consultarTopo() const {
    return lista.getUltimo(); // Retorna nullptr se vazia
}

bool Pilha::pilhaVazia() const {
    return lista.estaVazia();
}

bool Pilha::pilhaCheia() const {
    return lista.estaCheia();
}

// ✅ Novo método para impressão sem apagar elementos
Elemento* Pilha::removerTopoSemDeletar() {
    return lista.removerUltimoSemDeletar();
}
