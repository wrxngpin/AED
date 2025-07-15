#include "../include/Deque.h"
#include <iostream>

// Construtor
Deque::Deque() {
    // A listaInterna será inicializada automaticamente 
    // com seu construtor padrão.
}

// Destrutor
Deque::~Deque() {
    // O destrutor será chamado automaticamente,
    // liberando a memória dos elementos 
}

// Adiciona um elemento no deque em início 

bool Deque::enfileirarInicio(Elemento* e) {
    return listaInterna.inserirNoInicio(e);
}

// Adiciona um elemento no deque em final 

bool Deque::enfileirarFim(Elemento* e) {
    return listaInterna.inserirNoFinal(e);
}

// Remove um elemento no deque em início 

bool Deque::desenfileirarInicio() {
    return listaInterna.removerPrimeiro();
}

// Remove um elemento no deque em final

bool Deque::desenfileirarFim() {
    return listaInterna.removerUltimo();
}

// Retorna o elemento do início do deque sem removê-lo


const Elemento* Deque::consultarInicio() const {
    
    return listaInterna.consultarPrimeiro(); 
}

// Retorna o elemento do final sem removê-lo

const Elemento* Deque::consultarFim() const {
    
    return listaInterna.consultarUltimo();
}

// Verifica se o deque está vazio

bool Deque::dequeVazio() const {
    return listaInterna.estaVazia(); 
}

// Imprime todos os elementos do deque

void Deque::imprimirTodos() const {
    listaInterna.imprimirTodos();
}