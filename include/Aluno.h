#pragma once
#include "Elemento.h"
#include <string>

class Aluno : public Elemento {
private:
    std::string nome;
    double nota; // Usando 'nota' como atributo específico do Aluno

public:
    // Construtor
    Aluno(long id, const std::string& nome, double nota);

    // Getters para os atributos específicos
    std::string getNome() const;
    double getNota() const;

    // --- Implementação dos Métodos Virtuais Obrigatórios ---
    void imprimirInfo() const override;
    Elemento* clone() const override; // A correção para o erro
};