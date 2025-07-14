#pragma once
#include "ListaSimplesmenteEncadeada.h"
#include "elemento.h"

class FilaEncadeada {
private:
    ListaSimplesmenteEncadeada listaInterna;

public:
    void enfileirar(Elemento* elemento);
    void desenfileirar();
    Elemento* consultarInicio() const;
    bool estaVazia() const;
};