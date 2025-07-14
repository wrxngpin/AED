#pragma once
#include "Elemento.h"

class ArvoreBinariaBusca {
private:
    // Nó da árvore, definido de forma privada e encapsulada
    class No {
    public:
        Elemento* dado;
        No* esquerda;
        No* direita;

        No(Elemento* d) : dado(d), esquerda(nullptr), direita(nullptr) {}
    };

    No* raiz;

    // --- Funções Auxiliares Recursivas (privadas) ---
    // A implementação pública chama estas funções recursivas.
    No* inserirRecursivo(No* no, Elemento* elemento);
    No* removerRecursivo(No* no, long id);
    Elemento* buscarRecursivo(No* no, long id) const;
    void emOrdemRecursivo(No* no) const;
    void preOrdemRecursivo(No* no) const;
    void posOrdemRecursivo(No* no) const;
    void destruirRecursivo(No* no);
    No* encontrarMinimo(No* no); // Função auxiliar para a remoção

public:
    ArvoreBinariaBusca();
    ~ArvoreBinariaBusca();
    bool estaVazia() const;

    // --- Métodos Públicos ---
    void Inserir(Elemento* elemento);
    void RemoverPeloId(long id);
    Elemento* BuscarPeloId(long id) const;

    // Percursos
    void emOrdem() const;
    void preOrdem() const;
    void posOrdem() const;
};