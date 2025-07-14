#include "ListaOrdenada.h"
#include <iostream>

// Destrutor: libera memória dos elementos
ListaOrdenada::~ListaOrdenada() {
    for (int i = 0; i < tamanho; ++i) {
        delete elementos[i];
    }
}

// Busca binária (retorna posição ou -1 se não encontrado)
int ListaOrdenada::buscaBinaria(int id) const {
    int ini = 0, fim = tamanho - 1;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        if (elementos[meio]->getID() == id) {
            return meio;
        } else if (elementos[meio]->getID() < id) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

// Insere elemento mantendo a ordenação por ID
bool ListaOrdenada::inserir(Elemento* e) {
    if (tamanho >= 100 || e == nullptr || buscarPeloId(e->getID()) != nullptr) {
        return false; // Lista cheia, elemento inválido ou ID repetido
    }

    int i = tamanho - 1;
    while (i >= 0 && elementos[i]->getID() > e->getID()) {
        elementos[i + 1] = elementos[i]; // Desloca elementos para a direita
        i--;
    }
    elementos[i + 1] = e;
    tamanho++;
    return true;
}

// Remove elemento por ID
bool ListaOrdenada::removerPeloId(int id) {
    int pos = buscaBinaria(id);
    if (pos == -1) return false;

    delete elementos[pos]; // Libera memória
    for (int i = pos; i < tamanho - 1; ++i) {
        elementos[i] = elementos[i + 1]; // Desloca elementos para a esquerda
    }
    tamanho--;
    return true;
}

// Busca elemento por ID (retorna ponteiro const para evitar modificações externas)
const Elemento* ListaOrdenada::buscarPeloId(int id) const {
    int pos = buscaBinaria(id);
    return pos != -1 ? elementos[pos] : nullptr;
}

// Altera elemento por ID (substitui diretamente para manter ordem)
bool ListaOrdenada::alterarPeloId(int id, Elemento* novo) {
    if (novo == nullptr || tamanho >= 100 || novo->getID() != id) {
        return false; // Novo elemento inválido ou ID incompatível
    }

    int pos = buscaBinaria(id);
    if (pos == -1) return false;

    delete elementos[pos]; // Remove antigo
    elementos[pos] = novo; // Insere novo (mantém ordem se ID não mudar)
    return true;
}

// Imprime todos os elementos (demonstra polimorfismo)
void ListaOrdenada::imprimirTodos() const {
    for (int i = 0; i < tamanho; ++i) {
        elementos[i]->imprimirInfo();
    }
}