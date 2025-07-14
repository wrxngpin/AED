#pragma once
#include "ListaSimplesmenteEncadeada.h"
#include "elemento.h"

class PilhaEncadeada {
private:
    ListaSimplesmenteEncadeada listaInterna;

public:
    void empilhar(Elemento* elemento);
    void desempilhar();
    Elemento* consultarTopo() const;
    bool estaVazia() const;
};