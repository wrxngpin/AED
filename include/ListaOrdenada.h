#ifndef LISTAORDENADA_H
#define LISTAORDENADA_H

#include "Elemento.h"

class ListaOrdenada {
private:
    Elemento* elementos[100];  // Array de ponteiros (capacidade fixa)
    int tamanho = 0;           // Tamanho atual da lista

    // Método auxiliar para busca binária
    int buscaBinaria(int id) const;

public:
    ~ListaOrdenada();

    // Métodos principais (completa conforme enunciado)
    bool inserir(Elemento* e);                    // O(n) - Insere mantendo ordem
    bool removerPeloId(int id);                   // O(n) - Remove e desloca elementos
    const Elemento* buscarPeloId(int id) const;   // O(log n) - Busca binária
    bool alterarPeloId(int id, Elemento* novo);   // O(n) - Remove e insere novo
    void imprimirTodos() const;                   // O(n) - Chama imprimirInfo() de cada elemento

    // Métodos extras (exigidos pelo enunciado)
    bool inserirNoInicio(Elemento* e) { return false; } // Não aplicável em lista ordenada
    bool inserirNoFinal(Elemento* e) { return inserir(e); } // Equivalente a inserir
};

#endif