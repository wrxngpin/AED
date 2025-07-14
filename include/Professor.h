#pragma once
#include "Elemento.h"
#include <string>

class Professor : public Elemento {
private:
    std::string nome;
    std::string area; // Atributo específico do Professor

public:
    // Construtor
    Professor(long id, const std::string& nome, const std::string& area);

    // Getters
    std::string getNome() const;
    std::string getArea() const;

    // --- Implementação dos Métodos Virtuais Obrigatórios ---
    void imprimirInfo() const override;
    Elemento* clone() const override; // A correção para o erro
};