#include "Professor.h"
#include <iostream>

// Implementação do Construtor
Professor::Professor(long id, const std::string& nome, const std::string& area)
    : Elemento(id), nome(nome), area(area) {}

// Implementação dos Getters
std::string Professor::getNome() const { return nome; }
std::string Professor::getArea() const { return area; }

// Implementação do método polimórfico para imprimir
void Professor::imprimirInfo() const {
    std::cout << "--- [PROFESSOR] --- ID: " << getID()
              << ", Nome: " << this->nome
              << ", Area: " << this->area << std::endl;
}

// Implementação do método de clonagem
Elemento* Professor::clone() const {
    // Retorna um novo objeto Professor que é uma cópia deste
    return new Professor(*this);
}