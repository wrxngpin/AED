#ifndef DEQUE_H
#define DEQUE_H

#include "Elemento.h" // Inclui a classe base para os elementos
#include "ListaNaoOrdenada.h" 

class Deque {
private:
    ListaNaoOrdenada listaInterna; // A instância de ListaNaoOrdenada que o Deque gerencia

public:
    // Construtor e Destrutor
    Deque();
    ~Deque();

    // Operações do Deque
    bool enfileirarInicio(Elemento* e); // Enfileira o deque, adicionando um elemento em seu início 
    bool enfileirarFim(Elemento* e);    // Enfileira o deque, adicionando um elemento em seu final 
    bool desenfileirarInicio();         // Desenfileira o deque, removendo um elemento em seu início 
    bool desenfileirarFim();            // Desenfileira o deque, removendo um elemento em seu final 
    const Elemento* consultarInicio() const; // Retorna o elemento do início do deque mas sem removê-lo
    const Elemento* consultarFim() const;    // Retorna o elemento do final do deque mas sem removê-lo
    bool dequeVazio() const;             // Verifica se o deque está vazio
    void imprimirTodos() const;         // Imprime todos os elementos do deque
};

#endif 