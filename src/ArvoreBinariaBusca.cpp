#include "ArvoreBinariaBusca.h"
#include <iostream>

// --- Construtor e Destrutor ---
ArvoreBinariaBusca::ArvoreBinariaBusca() : raiz(nullptr) {}

ArvoreBinariaBusca::~ArvoreBinariaBusca() {
    destruirRecursivo(raiz);
}



bool ArvoreBinariaBusca::estaVazia() const {
    return raiz == nullptr;
}

void ArvoreBinariaBusca::destruirRecursivo(No* no) {
    if (no != nullptr) {
        destruirRecursivo(no->esquerda);
        destruirRecursivo(no->direita);
        delete no->dado;
        delete no;
    }
}

// --- Métodos Públicos (Wrappers) ---
void ArvoreBinariaBusca::Inserir(Elemento* elemento) {
    raiz = inserirRecursivo(raiz, elemento);
}

void ArvoreBinariaBusca::RemoverPeloId(long id) {
    raiz = removerRecursivo(raiz, id);
}

Elemento* ArvoreBinariaBusca::BuscarPeloId(long id) const {
    return buscarRecursivo(raiz, id);
}

void ArvoreBinariaBusca::emOrdem() const {
    std::cout << "Em Ordem (In-Order): ";
    emOrdemRecursivo(raiz);
    std::cout << std::endl;
}

void ArvoreBinariaBusca::preOrdem() const {
    std::cout << "Pre-Ordem (Pre-Order): ";
    preOrdemRecursivo(raiz);
    std::cout << std::endl;
}

void ArvoreBinariaBusca::posOrdem() const {
    std::cout << "Pos-Ordem (Post-Order): ";
    posOrdemRecursivo(raiz);
    std::cout << std::endl;
}


// --- Funções Auxiliares Recursivas (Implementação) ---

ArvoreBinariaBusca::No* ArvoreBinariaBusca::inserirRecursivo(No* no, Elemento* elemento) {
    if (no == nullptr) {
        return new No(elemento);
    }
    if (elemento->getID() < no->dado->getID()) {
        no->esquerda = inserirRecursivo(no->esquerda, elemento);
    } else if (elemento->getID() > no->dado->getID()) {
        no->direita = inserirRecursivo(no->direita, elemento);
    }
    return no;
}

Elemento* ArvoreBinariaBusca::buscarRecursivo(No* no, long id) const {
    if (no == nullptr || no->dado->getID() == id) {
        return no ? no->dado : nullptr;
    }
    if (id < no->dado->getID()) {
        return buscarRecursivo(no->esquerda, id);
    } else {
        return buscarRecursivo(no->direita, id);
    }
}

ArvoreBinariaBusca::No* ArvoreBinariaBusca::encontrarMinimo(No* no) {
    while (no && no->esquerda != nullptr) {
        no = no->esquerda;
    }
    return no;
}

ArvoreBinariaBusca::No* ArvoreBinariaBusca::removerRecursivo(No* no, long id) {
    if (no == nullptr) return no;

    if (id < no->dado->getID()) {
        no->esquerda = removerRecursivo(no->esquerda, id);
    } else if (id > no->dado->getID()) {
        no->direita = removerRecursivo(no->direita, id);
    } else { // Nó a ser removido encontrado
        // Caso 1: Nó sem filhos ou com um filho
        if (no->esquerda == nullptr) {
            No* temp = no->direita;
            delete no->dado;
            delete no;
            return temp;
        } else if (no->direita == nullptr) {
            No* temp = no->esquerda;
            delete no->dado;
            delete no;
            return temp;
        }
        // Caso 2: Nó com dois filhos
        No* temp = encontrarMinimo(no->direita);
        delete no->dado; // Deleta o dado antigo
        no->dado = temp->dado->clone(); // Copia o dado do sucessor
        no->direita = removerRecursivo(no->direita, temp->dado->getID());
    }
    return no;
}

// --- Percursos ---

void ArvoreBinariaBusca::emOrdemRecursivo(No* no) const {
    if (no != nullptr) {
        emOrdemRecursivo(no->esquerda);
        std::cout << no->dado->getID() << " ";
        emOrdemRecursivo(no->direita);
    }
}

void ArvoreBinariaBusca::preOrdemRecursivo(No* no) const {
    if (no != nullptr) {
        std::cout << no->dado->getID() << " ";
        preOrdemRecursivo(no->esquerda);
        preOrdemRecursivo(no->direita);
    }
}

void ArvoreBinariaBusca::posOrdemRecursivo(No* no) const {
    if (no != nullptr) {
        posOrdemRecursivo(no->esquerda);
        posOrdemRecursivo(no->direita);
        std::cout << no->dado->getID() << " ";
    }
}