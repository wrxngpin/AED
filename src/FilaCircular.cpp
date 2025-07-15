#include "FilaCircular.h"
#include <iostream>

FilaCircular::FilaCircular() : inicio(0), fim(0), tamanho(0) {}

FilaCircular::~FilaCircular() {
    // Libera memória dos elementos restantes
    while (!vazia()) {
        desenfileirar();
    }
}

bool FilaCircular::enfileirar(Elemento* e) {
    if (cheia() || e == nullptr) return false;

    // Verifica se já existe elemento com mesmo ID
    for (int i = 0; i < tamanho; ++i) {
        int index = (inicio + i) % 100;
        if (elementos[index]->getID() == e->getID()) {
            return false; // ID duplicado, falha na inserção
        }
    }

    elementos[fim] = e;
    fim = (fim + 1) % 100;
    tamanho++;
    return true;
}

bool FilaCircular::desenfileirar() {
    if (vazia()) return false;

    delete elementos[inicio];
    inicio = (inicio + 1) % 100;
    tamanho--;
    return true;
}

const Elemento* FilaCircular::frente() const {
    if (vazia()) return nullptr;
    return elementos[inicio];
}

bool FilaCircular::vazia() const {
    return tamanho == 0;
}

bool FilaCircular::cheia() const {
    return tamanho == 100;
}

void FilaCircular::imprimirTodos() const {
    if (vazia()) {
        std::cout << "Fila vazia!\n";
        return;
    }
    std::cout << "====== ELEMENTOS NA FILA CIRCULAR ======\n";
    for (int i = 0; i < tamanho; ++i) {
        int index = (inicio + i) % 100;
        elementos[index]->imprimirInfo();
    }
}
