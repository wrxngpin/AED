#include "Aluno.h"
#include <iostream>
#include <iomanip>

// Implementação do Construtor
Aluno::Aluno(long id, const std::string& nome, double nota)
    : Elemento(id), nome(nome), nota(nota) {}

// Implementação dos Getters
std::string Aluno::getNome() const { return nome; }
double Aluno::getNota() const { return nota; }

// Implementação do método polimórfico para imprimir
void Aluno::imprimirInfo() const {
    std::cout << "--- [ALUNO] --- ID: " << getID()
              << ", Nome: " << this->nome
              << ", Nota: " << std::fixed << std::setprecision(2) << this->nota << std::endl;
}

// Implementação do método de clonagem
Elemento* Aluno::clone() const {
    // Retorna um novo objeto Aluno que é uma cópia deste
    return new Aluno(*this);
}