#pragma once
#include "Elemento.h"

class ListaDuplamenteEncadeadaCircular {
private:
    // A definição do Nó é a mesma, encapsulada e privada.
    class No {
    public:
        Elemento* dado;
        No* proximo;
        No* anterior;

        No(Elemento* d) : dado(d), proximo(nullptr), anterior(nullptr) {}
    };

    No* cabeca; // Continua sendo o ponto de entrada da lista
    int tamanho;

public:
    ListaDuplamenteEncadeadaCircular();
    ~ListaDuplamenteEncadeadaCircular();

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