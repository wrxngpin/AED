#ifndef PILHA_H
#define PILHA_H

#include "ListaNaoOrdenada.h"

class Pilha {
private:
    ListaNaoOrdenada lista; // Composição (uso interno apenas)

public:
    // Métodos principais
    bool empilhar(Elemento* e);          // Retorna sucesso/falha
    bool desempilhar();                  // Retorna sucesso/falha
    const Elemento* consultarTopo() const; // Retorno const (segurança)
    bool pilhaVazia() const;
    bool pilhaCheia() const;
    Elemento* removerTopoSemDeletar();
};

#endif