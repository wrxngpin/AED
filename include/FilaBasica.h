#ifndef FILABASICA_H
#define FILABASICA_H

#include "ListaNaoOrdenada.h"

class FilaBasica {
private:
    ListaNaoOrdenada lista;

public:
    bool enfileirar(Elemento* e);      // Retorna false se falhar
    bool desenfileirar();              // Retorna false se falhar
    const Elemento* frente() const;    // Retorno const
    bool vazia() const;
    bool cheia() const;
    void imprimirTodos() const;
};

#endif
