#pragma once
#include "Elemento.h"

class ListaDuplamenteEncadeada {
private:
    // Nó encapsulado, agora com ponteiro para o anterior
    class No {
    public:
        Elemento* dado;
        No* proximo;
        No* anterior;

        No(Elemento* d) : dado(d), proximo(nullptr), anterior(nullptr) {}
    };

    No* cabeca;
    No* cauda;
    int tamanho;

public:
    ListaDuplamenteEncadeada();
    ~ListaDuplamenteEncadeada();

    // Métodos de estado
    bool estaVazia() const;
    int getTamanho() const;

    // Métodos de inserção
    void inserirNoInicio(Elemento* elemento);
    void inserirNoFim(Elemento* elemento);

    // Métodos de remoção
    void removerPrimeiro();
    void removerUltimo();
    bool removerPeloId(long id);

    // Métodos de busca e visualização
    Elemento* buscarPeloId(long id) const;
    void imprimirTodos() const;
};