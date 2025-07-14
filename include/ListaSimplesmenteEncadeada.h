#pragma once
#include "Elemento.h"
#include <stdexcept>

class ListaSimplesmenteEncadeada {
private:
    // O Nó é uma classe interna e privada, escondendo o detalhe de implementação.
    class No {
    public:
        Elemento* dado;
        No* proximo;
        No(Elemento* d) : dado(d), proximo(nullptr) {}
    };

    No* cabeca; // Ponteiro para o primeiro nó da lista
    No* cauda;  // Ponteiro para o último nó (essencial para inserir no fim em O(1))
    int tamanho;

public:
    ListaSimplesmenteEncadeada();
    ~ListaSimplesmenteEncadeada();

    bool estaVazia() const;
    int getTamanho() const;
    
    // Operações principais
    void inserirNoInicio(Elemento* elemento);
    void inserirNoFim(Elemento* elemento);
    void removerPrimeiro();
    Elemento* getPrimeiroElemento() const;

    // (Você e sua equipe podem adicionar outros métodos como removerDoFim, buscarPeloId, etc.)
};