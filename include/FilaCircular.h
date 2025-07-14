// FilaCircular.h
#ifndef FILACIRCULAR_H
#define FILACIRCULAR_H

#include "Elemento.h"

class FilaCircular {
private:
    Elemento* elementos[100];
    int inicio;
    int fim;
    int tamanho;

public:
    FilaCircular();
    ~FilaCircular();

    bool enfileirar(Elemento* e);     // Retorna false se falhar
    bool desenfileirar();             // Retorna false se falhar
    const Elemento* frente() const;   // Retorno const
    bool vazia() const;
    bool cheia() const;
    void imprimirTodos() const;
};

#endif
