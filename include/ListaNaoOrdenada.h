#ifndef LISTANAOORDENADA_H
#define LISTANAOORDENADA_H

#include "Elemento.h"

class ListaNaoOrdenada {
private:
    Elemento* elementos[100];  // Array estático (capacidade 100)
    int tamanho = 0;           // Tamanho atual

public:
    ~ListaNaoOrdenada();

    // Métodos de inserção/remoção
    bool inserirNoInicio(Elemento* e);            // O(n)
    bool inserirNoFinal(Elemento* e);             // O(1)
    bool removerPrimeiro();                       // O(n)
    bool removerUltimo();                         // O(1)
    bool removerPeloId(int id);                   // O(n)
    const Elemento* buscarPeloId(int id) const;   // O(n) - Retorno const
    bool alterarPeloId(int id, Elemento* novo);   // O(n)

    // Métodos auxiliares
    void imprimirTodos() const;                   // O(n)
    int getTamanho() const { return tamanho; }    // O(1)
    const Elemento* getPrimeiro() const;          // O(1) - Retorno const
    const Elemento* getUltimo() const;            // O(1) - Retorno const
    bool estaCheia() const { return tamanho >= 100; } // O(1)
    bool estaVazia() const { return tamanho == 0; }   // O(1)
    Elemento* removerUltimoSemDeletar();
};

#endif