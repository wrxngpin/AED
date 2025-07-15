#include "include/Aluno.h"
#include "include/Professor.h"
#include "include/ListaNaoOrdenada.h"
#include "include/ListaOrdenada.h"
#include "include/Pilha.h"
#include "include/Deque.h"
#include "include/FilaBasica.h"
#include "include/FilaCircular.h"
#include "include/PilhaEncadeada.h"           
#include "include/FilaEncadeada.h"            
#include "include/ListaSimplesmenteEncadeada.h" 
#include "include/ListaDuplamenteEncadeada.h"        
#include "include/ListaDuplamenteEncadeadaCircular.h" 
#include "include/ArvoreBinariaBusca.h"
#include <iostream>
#include <limits>
#include <string>
#include <stdlib.h>

using namespace std;

// Variáveis globais
ListaNaoOrdenada lnao;
ListaOrdenada lord;
Pilha pilha;
Deque deque;
FilaBasica filaB;
FilaCircular filaC;

PilhaEncadeada pilhaEnc;
FilaEncadeada filaEnc;
ListaSimplesmenteEncadeada listaSenc;
ListaDuplamenteEncadeada listaDupEnc;             
ListaDuplamenteEncadeadaCircular listaDupEncCirc;

ArvoreBinariaBusca arvore;



// Protótipos
void limparBuffer();
void menuPrincipal();
void menuListaNaoOrdenada();
void menuListaOrdenada();
void menuDeque();
void menuPilha();
void menuFila();
bool idExiste(int id);
void menuArvoreBinaria();
Elemento* criarElementoComIdValido(int tipo);

void menuEncadeadas();
void menuPilhaEncadeada();
void menuFilaEncadeada();
void menuListaSimplesmenteEncadeada();
void menuListaDuplamenteEncadeada();        
void menuListaDuplamenteEncadeadaCircular(); 

// Implementações

void limparBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Verifica se ID já existe em listas (pode estender para pilha/fila)
bool idExiste(int id) {
    if (lnao.buscarPeloId(id) != nullptr) return true;
    if (lord.buscarPeloId(id) != nullptr) return true;
    // Se quiser, implemente buscarPeloId na pilha e filas e cheque aqui também
    return false;
}

// Cria elemento pedindo ID válido (único)
Elemento* criarElementoComIdValido(int tipo) {
    int id;
    while (true) {
        cout << "ID (único): ";
        cin >> id;
        limparBuffer();
        if (idExiste(id)) {
            cout << "ID já existe! Tente outro.\n";
        } else {
            break;
        }
    }

    string nome;
    cout << "Nome: ";
    getline(cin, nome);

    if (tipo == 1) {
        int matricula;
        cout << "Matrícula: ";
        cin >> matricula;
        limparBuffer();
        return new Aluno(id, nome, matricula);
    } else {
        string area;
        cout << "Área: ";
        getline(cin, area);
        return new Professor(id, nome, area);
    }
}

Elemento* criarElemento(int tipo) {
    // Se precisar de uma versão simples sem checagem, mantenha esta
    // Senão, sempre use criarElementoComIdValido no menu
    int id;
    cout << "ID: ";
    cin >> id;
    limparBuffer();

    string nome;
    cout << "Nome: ";
    getline(cin, nome);

    if (tipo == 1) {
        int matricula;
        cout << "Matrícula: ";
        cin >> matricula;
        limparBuffer();
        return new Aluno(id, nome, matricula);
    } else {
        string area;
        cout << "Área: ";
        getline(cin, area);
        return new Professor(id, nome, area);
    }
}

void menuPrincipal() {
    int opcao;
    do {
        system("cls || clear");
        cout << "========== MENU PRINCIPAL ==========\n";
        cout << "1. Lista Não Ordenada\n";
        cout << "2. Lista Ordenada\n";
        cout << "3. Pilha\n";
        cout << "4. Fila\n";
        cout << "5. Estruturas Encadeadas (Parte II)\n"; 
        cout << "6. Sair\n";                            
        cout << "Escolha uma opção: ";
        cin >> opcao;
        limparBuffer();

        switch(opcao) {
            case 1: menuListaNaoOrdenada(); break;
            case 2: menuListaOrdenada(); break;
            case 3: menuPilha(); break;
            case 4: menuFila(); break;
            case 5: menuEncadeadas(); break;
            case 6: cout << "Saindo...\n"; break;
            default: cout << "Opção inválida!\n";
        }
    } while(opcao != 6);
}

void menuListaNaoOrdenada() {
    int opcao;
    do {
        system("cls || clear");
        cout << "========== LISTA NÃO ORDENADA ==========\n";
        cout << "1. Inserir no início\n";
        cout << "2. Inserir no final\n";
        cout << "3. Remover primeiro\n";
        cout << "4. Remover último\n";
        cout << "5. Remover por ID\n";
        cout << "6. Buscar por ID\n";
        cout << "7. Alterar por ID\n";
        cout << "8. Imprimir todos\n";
        cout << "9. Voltar\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        limparBuffer();

        switch(opcao) {
            case 1: {
                int tipo;
                cout << "1. Aluno\n2. Professor\nEscolha: ";
                cin >> tipo;
                limparBuffer();

                Elemento* e = criarElementoComIdValido(tipo);
                if(lnao.inserirNoInicio(e)) {
                    cout << "Inserido com sucesso!\n";
                } else {
                    cout << "Falha ao inserir!\n";
                    delete e;
                }
                break;
            }
            case 2: {
                int tipo;
                cout << "1. Aluno\n2. Professor\nEscolha: ";
                cin >> tipo;
                limparBuffer();

                Elemento* e = criarElementoComIdValido(tipo);
                if(lnao.inserirNoFinal(e)) {
                    cout << "Inserido com sucesso!\n";
                } else {
                    cout << "Falha ao inserir!\n";
                    delete e;
                }
                break;
            }
            case 3:
                if(lnao.removerPrimeiro()) {
                    cout << "Primeiro elemento removido!\n";
                } else {
                    cout << "Lista vazia!\n";
                }
                break;
            case 4:
                if(lnao.removerUltimo()) {
                    cout << "Último elemento removido!\n";
                } else {
                    cout << "Lista vazia!\n";
                }
                break;
            case 5: {
                int id;
                cout << "ID para remover: ";
                cin >> id;
                limparBuffer();

                if(lnao.removerPeloId(id)) {
                    cout << "Removido com sucesso!\n";
                } else {
                    cout << "ID não encontrado!\n";
                }
                break;
            }
            case 6: {
                int id;
                cout << "ID para buscar: ";
                cin >> id;
                limparBuffer();

                if(const Elemento* elem = lnao.buscarPeloId(id)) {
                    elem->imprimirInfo();
                } else {
                    cout << "Elemento não encontrado!\n";
                }
                break;
            }
            case 7: {
                int id;
                cout << "ID para alterar: ";
                cin >> id;
                limparBuffer();

                if (!lnao.buscarPeloId(id)) {
                    cout << "ID não encontrado!\n";
                    break;
                }

                int tipo;
                cout << "Novo tipo (1-Aluno 2-Professor): ";
                cin >> tipo;
                limparBuffer();

                Elemento* novo = nullptr;

                if (tipo == 1) {
                    string nome;
                    int matricula;

                    cout << "Nome: ";
                    getline(cin, nome);
                    cout << "Matrícula: ";
                    cin >> matricula;
                    limparBuffer();

                    novo = new Aluno(id, nome, matricula);

                } else if (tipo == 2) {
                    string nome, area;

                    cout << "Nome: ";
                    getline(cin, nome);
                    cout << "Área: ";
                    getline(cin, area);

                    novo = new Professor(id, nome, area);

                } else {
                    cout << "Tipo inválido!\n";
                    break;
                }

                if (lnao.alterarPeloId(id, novo)) {
                    cout << "Alterado com sucesso!\n";
                } else {
                    cout << "Falha ao alterar!\n";
                    delete novo;
                }
                break;
            }
            case 8:
                cout << "====== ELEMENTOS NA LISTA ======\n";
                lnao.imprimirTodos();
                break;
            case 9: break;
            default: cout << "Opção inválida!\n";
        }

        if(opcao != 9) {
            cout << "\nPressione Enter para continuar...";
            cin.get();
        }
    } while(opcao != 9);
}

void menuListaOrdenada() {
    int opcao;
    do {
        system("cls || clear");
        cout << "========== LISTA ORDENADA ==========\n";
        cout << "1. Inserir\n";
        cout << "2. Remover por ID\n";
        cout << "3. Buscar por ID\n";
        cout << "4. Alterar por ID\n";
        cout << "5. Imprimir todos\n";
        cout << "6. Voltar\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        limparBuffer();

        switch(opcao) {
            case 1: {
                int tipo;
                cout << "1. Aluno\n2. Professor\nEscolha: ";
                cin >> tipo;
                limparBuffer();

                Elemento* e = criarElementoComIdValido(tipo);
                if(lord.inserir(e)) {
                    cout << "Inserido com sucesso!\n";
                } else {
                    cout << "Falha ao inserir (ID duplicado ou lista cheia)!\n";
                    delete e;
                }
                break;
            }
            case 2: {
                int id;
                cout << "ID para remover: ";
                cin >> id;
                limparBuffer();

                if(lord.removerPeloId(id)) {
                    cout << "Removido com sucesso!\n";
                } else {
                    cout << "ID não encontrado!\n";
                }
                break;
            }
            case 3: {
                int id;
                cout << "ID para buscar: ";
                cin >> id;
                limparBuffer();

                if (const Elemento* elem = lord.buscarPeloId(id)) {
                    elem->imprimirInfo();
                } else {
                    cout << "Elemento não encontrado!\n";
                }
                break;
            }
            case 4: {
                int id;
                cout << "ID para alterar: ";
                cin >> id;
                limparBuffer();

                if (!lord.buscarPeloId(id)) {
                    cout << "ID não encontrado!\n";
                    break;
                }

                int tipo;
                cout << "Novo tipo (1-Aluno 2-Professor): ";
                cin >> tipo;
                limparBuffer();

                Elemento* novo = nullptr;

                if (tipo == 1) {
                    string nome;
                    int matricula;

                    cout << "Nome: ";
                    getline(cin, nome);
                    cout << "Matrícula: ";
                    cin >> matricula;
                    limparBuffer();

                    novo = new Aluno(id, nome, matricula);

                } else if (tipo == 2) {
                    string nome, area;

                    cout << "Nome: ";
                    getline(cin, nome);
                    cout << "Área: ";
                    getline(cin, area);

                    novo = new Professor(id, nome, area);

                } else {
                    cout << "Tipo inválido!\n";
                    break;
                }

                if (lord.alterarPeloId(id, novo)) {
                    cout << "Alterado com sucesso!\n";
                } else {
                    cout << "Falha ao alterar!\n";
                    delete novo;
                }
                break;
            }
            case 5:
                cout << "====== ELEMENTOS NA LISTA ======\n";
                lord.imprimirTodos();
                break;
            case 6: break;
            default: cout << "Opção inválida!\n";
        }
        if(opcao != 6) {
            cout << "\nPressione Enter para continuar...";
            cin.get();
        }
    } while(opcao != 6);
}

void menuPilha() {
    int opcao;
    do {
        system("cls || clear");
        cout << "========== PILHA ==========\n";
        cout << "1. Empilhar\n";
        cout << "2. Desempilhar\n";
        cout << "3. Consultar topo\n";
        cout << "4. Imprimir todos\n";
        cout << "5. Voltar\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        limparBuffer();

        switch(opcao) {
            case 1: {
                int tipo;
                cout << "1. Aluno\n2. Professor\nEscolha: ";
                cin >> tipo;
                limparBuffer();

                Elemento* e = criarElementoComIdValido(tipo);
                if(pilha.empilhar(e)) {
                    cout << "Empilhado com sucesso!\n";
                } else {
                    cout << "Falha ao empilhar (pilha cheia)!\n";
                    delete e;
                }
                break;
            }
            case 2:
                if(pilha.desempilhar()) {
                    cout << "Desempilhado com sucesso!\n";
                } else {
                    cout << "Pilha vazia!\n";
                }
                break;
            case 3:
                if(const Elemento* topo = pilha.consultarTopo()) {
                    cout << "Elemento no topo:\n";
                    topo->imprimirInfo();
                } else {
                    cout << "Pilha vazia!\n";
                }
                break;
            case 4: {
                cout << "====== ELEMENTOS NA PILHA (TOPO → BASE) ======\n";
                
                Pilha temp;
                while (!pilha.pilhaVazia()) {
                    const Elemento* topo = pilha.consultarTopo();
                    topo->imprimirInfo();
                    temp.empilhar(const_cast<Elemento*>(topo));
                    pilha.removerTopoSemDeletar();  // NÃO deleta
                }

                // Restaurar a pilha original
                while (!temp.pilhaVazia()) {
                    pilha.empilhar(const_cast<Elemento*>(temp.consultarTopo()));
                    temp.removerTopoSemDeletar();
                }
                break;
            }
            case 5:
                cout << "Voltando ao menu principal...\n";
                break;
            default:
                cout << "Opção inválida!\n";
        }
        if(opcao != 5) {
            cout << "\nPressione Enter para continuar...";
            cin.get();
        }
    } while(opcao != 5);
}

void menuFila() {
    int opcao;
    do {
        system("cls || clear");
        cout << "========== FILA ==========\n";
        cout << "1. Fila Básica\n";
        cout << "2. Fila Circular\n";
        cout << "3. Voltar\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        limparBuffer();

        if(opcao == 1) {
            int op;
            do {
                system("cls || clear");
                cout << "========== FILA BÁSICA ==========\n";
                cout << "1. Enfileirar\n";
                cout << "2. Desenfileirar\n";
                cout << "3. Consultar frente\n";
                cout << "4. Imprimir todos\n";
                cout << "5. Voltar\n";
                cout << "Escolha uma opção: ";
                cin >> op;
                limparBuffer();

                switch(op) {
                    case 1: {
                        int tipo;
                        cout << "1. Aluno\n2. Professor\nEscolha: ";
                        cin >> tipo;
                        limparBuffer();

                        Elemento* e = criarElementoComIdValido(tipo);
                        if(filaB.enfileirar(e)) {
                            cout << "Enfileirado com sucesso!\n";
                        } else {
                            cout << "Falha ao enfileirar (fila cheia)!\n";
                            delete e;
                        }
                        break;
                    }
                    case 2:
                        if(filaB.desenfileirar()) {
                            cout << "Desenfileirado com sucesso!\n";
                        } else {
                            cout << "Fila vazia!\n";
                        }
                        break;
                    case 3:
                        if(const Elemento* frente = filaB.frente()) {
                            cout << "Elemento na frente:\n";
                            frente->imprimirInfo();
                        } else {
                            cout << "Fila vazia!\n";
                        }
                        break;
                    case 4:
                        cout << "====== ELEMENTOS NA FILA ======\n";
                        filaB.imprimirTodos();
                        break;
                    case 5: break;
                    default: cout << "Opção inválida!\n";
                }
                if(op != 5) {
                    cout << "\nPressione Enter para continuar...";
                    cin.get();
                }
            } while(op != 5);
        }

        else if(opcao == 2) {
            int op;
            do {
                system("cls || clear");
                cout << "========== FILA CIRCULAR ==========\n";
                cout << "1. Enfileirar\n";
                cout << "2. Desenfileirar\n";
                cout << "3. Consultar frente\n";
                cout << "4. Imprimir todos\n";
                cout << "5. Voltar\n";
                cout << "Escolha uma opção: ";
                cin >> op;
                limparBuffer();

                switch(op) {
                    case 1: {
                        int tipo;
                        cout << "1. Aluno\n2. Professor\nEscolha: ";
                        cin >> tipo;
                        limparBuffer();

                        Elemento* e = criarElementoComIdValido(tipo);
                        if(filaC.enfileirar(e)) {
                            cout << "Enfileirado com sucesso!\n";
                        } else {
                            cout << "Falha ao enfileirar (fila cheia)!\n";
                            delete e;
                        }
                        break;
                    }
                    case 2:
                        if(filaC.desenfileirar()) {
                            cout << "Desenfileirado com sucesso!\n";
                        } else {
                            cout << "Fila vazia!\n";
                        }
                        break;
                    case 3:
                        if(const Elemento* frente = filaC.frente()) {
                            cout << "Elemento na frente:\n";
                            frente->imprimirInfo();
                        } else {
                            cout << "Fila vazia!\n";
                        }
                        break;
                    case 4:
                        cout << "====== ELEMENTOS NA FILA CIRCULAR ======\n";
                        filaC.imprimirTodos();
                        break;
                    case 5: break;
                    default: cout << "Opção inválida!\n";
                }
                if(op != 5) {
                    cout << "\nPressione Enter para continuar...";
                    cin.get();
                }
            } while(op != 5);
        }
        else if(opcao != 3) {
            cout << "Opção inválida!\n";
            cout << "\nPressione Enter para continuar...";
            cin.get();
        }
    } while(opcao != 3);
}

void menuEncadeadas() {
    int opcao;
    do {
        system("cls || clear");
        cout << "========== ESTRUTURAS ENCADEADAS (PARTE II) ==========\n";
        cout << "1. Pilha Encadeada\n";
        cout << "2. Fila Encadeada\n";
        cout << "3. Lista Simplesmente Encadeada\n";
        cout << "4. Lista Duplamente Encadeada\n";        
        cout << "5. Lista Duplamente Encadeada Circular\n"; 
        cout << "6. Arvore Binaria de Busca\n";
        cout << "7. Deque\n";
        cout << "8. Voltar\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        limparBuffer();

        switch(opcao) {
            case 1: menuPilhaEncadeada(); break;
            case 2: menuFilaEncadeada(); break;
            case 3: menuListaSimplesmenteEncadeada(); break; 
            case 4: menuListaDuplamenteEncadeada(); break;        
            case 5: menuListaDuplamenteEncadeadaCircular(); break; 
            case 6: menuArvoreBinaria(); break;
            case 7: menuDeque();
            case 8: break;
            default: cout << "Opcao invalida!\n";
        }
    } while(opcao != 8);
}


void menuPilhaEncadeada() {
    int opcao;
    do {
        system("cls || clear");
        cout << "========== PILHA ENCADEADA ==========\n";
        cout << "1. Empilhar (Push)\n";
        cout << "2. Desempilhar (Pop)\n";
        cout << "3. Consultar Topo\n";
        cout << "4. Voltar\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        limparBuffer();

        switch(opcao) {
            case 1: {
                int tipo;
                cout << "1. Aluno\n2. Professor\nEscolha: ";
                cin >> tipo;
                limparBuffer();
                Elemento* e = criarElementoComIdValido(tipo);
                pilhaEnc.empilhar(e); // Usa o objeto pilhaEnc
                cout << "Empilhado com sucesso!\n";
                break;
            }
            case 2: {
                try {
                    pilhaEnc.desempilhar(); // Usa o objeto pilhaEnc
                    cout << "Desempilhado com sucesso!\n";
                } catch (const std::runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 3: {
                Elemento* topo = pilhaEnc.consultarTopo(); // Usa o objeto pilhaEnc
                if (topo) {
                    cout << "Elemento no topo:\n";
                    topo->imprimirInfo();
                } else {
                    cout << "Pilha vazia!\n";
                }
                break;
            }
            case 4: break;
            default: cout << "Opcao invalida!\n";
        }
        if (opcao != 4) {
            cout << "\nPressione Enter para continuar...";
            cin.get();
        }
    } while (opcao != 4);
}


void menuFilaEncadeada() {
    int opcao;
    do {
        system("cls || clear");
        cout << "========== FILA ENCADEADA ==========\n";
        cout << "1. Enfileirar (Enqueue)\n";
        cout << "2. Desenfileirar (Dequeue)\n";
        cout << "3. Consultar Frente\n";
        cout << "4. Voltar\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        limparBuffer();

        switch(opcao) {
            case 1: {
                int tipo;
                cout << "1. Aluno\n2. Professor\nEscolha: ";
                cin >> tipo;
                limparBuffer();
                Elemento* e = criarElementoComIdValido(tipo);
                filaEnc.enfileirar(e); // Usa o objeto filaEnc
                cout << "Enfileirado com sucesso!\n";
                break;
            }
            case 2: {
                try {
                    filaEnc.desenfileirar(); // Usa o objeto filaEnc
                    cout << "Desenfileirado com sucesso!\n";
                } catch (const std::runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 3: {
                Elemento* frente = filaEnc.consultarInicio(); // Usa o objeto filaEnc
                if (frente) {
                    cout << "Elemento na frente da fila:\n";
                    frente->imprimirInfo();
                } else {
                    cout << "Fila vazia!\n";
                }
                break;
            }
            case 4: break;
            default: cout << "Opcao invalida!\n";
        }
        if (opcao != 4) {
            cout << "\nPressione Enter para continuar...";
            cin.get();
        }
    } while (opcao != 4);
}

void menuListaSimplesmenteEncadeada() {
    int opcao;
    do {
        system("cls || clear");
        cout << "========== LISTA SIMPLESMENTE ENCADEADA ==========\n";
        cout << "1. Inserir no Inicio\n";
        cout << "2. Inserir no Fim\n";
        cout << "3. Remover Primeiro\n";
        // Para implementar "imprimirTodos", a sua classe de lista precisa ter esse método.
        // Assumindo que você adicionará: void imprimirTodos() const;
        // cout << "4. Imprimir Todos\n";
        cout << "5. Voltar\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        limparBuffer();

        switch(opcao) {
            case 1: {
                int tipo;
                cout << "1. Aluno\n2. Professor\nEscolha o tipo: ";
                cin >> tipo;
                limparBuffer();
                Elemento* e = criarElementoComIdValido(tipo);
                listaSenc.inserirNoInicio(e);
                cout << "Inserido no inicio com sucesso!\n";
                break;
            }
            case 2: {
                int tipo;
                cout << "1. Aluno\n2. Professor\nEscolha o tipo: ";
                cin >> tipo;
                limparBuffer();
                Elemento* e = criarElementoComIdValido(tipo);
                listaSenc.inserirNoFim(e);
                cout << "Inserido no fim com sucesso!\n";
                break;
            }
            case 3: {
                try {
                    listaSenc.removerPrimeiro();
                    cout << "Primeiro elemento removido com sucesso!\n";
                } catch (const std::runtime_error& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            /* case 4:
                cout << "--- Elementos na Lista ---\n";
                listaSenc.imprimirTodos();
                break;
            */
            case 5: break;
            default: cout << "Opcao invalida!\n";
        }
        if (opcao != 5) {
            cout << "\nPressione Enter para continuar...";
            cin.get();
        }
    } while (opcao != 5);
}


void menuListaDuplamenteEncadeada() {
    int opcao;
    do {
        system("cls || clear");
        cout << "========== LISTA DUPLAMENTE ENCADEADA ==========\n";
        cout << "1. Inserir no Inicio\n";
        cout << "2. Inserir no Fim\n";
        cout << "3. Remover Primeiro\n";
        cout << "4. Remover Ultimo\n";
        cout << "5. Remover por ID\n";
        cout << "6. Buscar por ID\n";
        cout << "7. Imprimir Todos\n";
        cout << "8. Voltar\n";
        cout << "Escolha: ";
        cin >> opcao;
        limparBuffer();

        switch (opcao) {
            case 1: {
                int tipo; cout << "1. Aluno\n2. Professor\nEscolha: "; cin >> tipo; limparBuffer();
                Elemento* e = criarElementoComIdValido(tipo);
                listaDupEnc.inserirNoInicio(e);
                cout << "Inserido com sucesso!\n";
                break;
            }
            case 2: {
                int tipo; cout << "1. Aluno\n2. Professor\nEscolha: "; cin >> tipo; limparBuffer();
                Elemento* e = criarElementoComIdValido(tipo);
                listaDupEnc.inserirNoFim(e);
                cout << "Inserido com sucesso!\n";
                break;
            }
            case 3:
                listaDupEnc.removerPrimeiro();
                cout << "Primeiro elemento removido (se existir).\n";
                break;
            case 4:
                listaDupEnc.removerUltimo();
                cout << "Ultimo elemento removido (se existir).\n";
                break;
            case 5: {
                long id; cout << "ID para remover: "; cin >> id; limparBuffer();
                if (listaDupEnc.removerPeloId(id)) cout << "Removido com sucesso!\n";
                else cout << "ID nao encontrado!\n";
                break;
            }
            case 6: {
                long id; cout << "ID para buscar: "; cin >> id; limparBuffer();
                Elemento* elem = listaDupEnc.buscarPeloId(id);
                if (elem) elem->imprimirInfo();
                else cout << "ID nao encontrado!\n";
                break;
            }
            case 7:
                cout << "--- Elementos na Lista ---\n";
                listaDupEnc.imprimirTodos();
                break;
            case 8: break;
            default: cout << "Opcao Invalida!\n";
        }
        if (opcao != 8) {
            cout << "\nPressione Enter para continuar...";
            cin.get();
        }
    } while (opcao != 8);
}

void menuListaDuplamenteEncadeadaCircular() {
    int opcao;
    do {
        system("cls || clear");
        cout << "========== LISTA DUPLAMENTE ENCADEADA CIRCULAR ==========\n";
        // As opções são as mesmas
        cout << "1. Inserir no Inicio\n";
        cout << "2. Inserir no Fim\n";
        cout << "3. Remover Primeiro\n";
        cout << "4. Remover Ultimo\n";
        cout << "5. Remover por ID\n";
        cout << "6. Buscar por ID\n";
        cout << "7. Imprimir Todos\n";
        cout << "8. Voltar\n";
        cout << "Escolha: ";
        cin >> opcao;
        limparBuffer();

        // A lógica é a mesma, mas chama os métodos do objeto 'listaDupEncCirc'
        switch (opcao) {
            case 1: {
                int tipo; cout << "1. Aluno\n2. Professor\nEscolha: "; cin >> tipo; limparBuffer();
                Elemento* e = criarElementoComIdValido(tipo);
                listaDupEncCirc.inserirNoInicio(e);
                cout << "Inserido com sucesso!\n";
                break;
            }
            case 2: {
                int tipo; cout << "1. Aluno\n2. Professor\nEscolha: "; cin >> tipo; limparBuffer();
                Elemento* e = criarElementoComIdValido(tipo);
                listaDupEncCirc.inserirNoFim(e);
                cout << "Inserido com sucesso!\n";
                break;
            }
            case 3:
                listaDupEncCirc.removerPrimeiro();
                cout << "Primeiro elemento removido (se existir).\n";
                break;
            case 4:
                listaDupEncCirc.removerUltimo();
                cout << "Ultimo elemento removido (se existir).\n";
                break;
            case 5: {
                long id; cout << "ID para remover: "; cin >> id; limparBuffer();
                if (listaDupEncCirc.removerPeloId(id)) cout << "Removido com sucesso!\n";
                else cout << "ID nao encontrado!\n";
                break;
            }
            case 6: {
                long id; cout << "ID para buscar: "; cin >> id; limparBuffer();
                Elemento* elem = listaDupEncCirc.buscarPeloId(id);
                if (elem) elem->imprimirInfo();
                else cout << "ID nao encontrado!\n";
                break;
            }
            case 7:
                cout << "--- Elementos na Lista Circular ---\n";
                listaDupEncCirc.imprimirTodos();
                break;
            case 8: break;
            default: cout << "Opcao Invalida!\n";
        }
        if (opcao != 8) {
            cout << "\nPressione Enter para continuar...";
            cin.get();
        }
    } while (opcao != 8);
}

// Esta função vai para o seu arquivo main.cpp

void menuArvoreBinaria() {
    int opcao;
    do {
        system("cls || clear");
        cout << "========== ÁRVORE BINÁRIA DE BUSCA ==========\n";
        cout << "1. Inserir\n";
        cout << "2. Remover por ID\n";
        cout << "3. Buscar por ID\n";
        cout << "4. Imprimir em Ordem (In-Order)\n";
        cout << "5. Imprimir em Pré-Ordem (Pre-Order)\n";
        cout << "6. Imprimir em Pós-Ordem (Post-Order)\n";
        cout << "7. Voltar\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        limparBuffer();

        switch(opcao) {
            case 1: {
                int tipo;
                cout << "1. Aluno\n2. Professor\nEscolha o tipo de elemento: ";
                cin >> tipo;
                limparBuffer();

                // MELHORIA: Corrigido o nome da função para o padrão do projeto.
                Elemento* e = criarElementoComIdValido(tipo); 
                arvore.Inserir(e);

                cout << "Elemento inserido com sucesso na árvore!\n";
                break;
            }
            case 2: {
                long id;
                cout << "ID para remover: ";
                cin >> id;
                limparBuffer();

                // A lógica de buscar primeiro para dar um feedback mais claro é boa.
                if (arvore.BuscarPeloId(id)) {
                    arvore.RemoverPeloId(id);
                    cout << "Elemento com ID " << id << " removido (ou sua substituição ocorreu).\n";
                } else {
                    cout << "ID não encontrado na árvore!\n";
                }
                break;
            }
            case 3: {
                long id;
                cout << "ID para buscar: ";
                cin >> id;
                limparBuffer();
                
                if (const Elemento* elem = arvore.BuscarPeloId(id)) {
                    cout << "Elemento encontrado:\n";
                    elem->imprimirInfo();
                } else {
                    cout << "Elemento não encontrado!\n";
                }
                break;
            }
            case 4: {
                // MELHORIA: Verifica se a árvore está vazia antes de imprimir.
                cout << "--- Percurso Em Ordem (In-Order) ---\n";
                if (arvore.estaVazia()) {
                    cout << "A árvore está vazia.\n";
                } else {
                    arvore.emOrdem();
                }
                break;
            }
            case 5: {
                // MELHORIA: Verifica se a árvore está vazia antes de imprimir.
                cout << "--- Percurso Pré-Ordem (Pre-Order) ---\n";
                if (arvore.estaVazia()) {
                    cout << "A árvore está vazia.\n";
                } else {
                    arvore.preOrdem();
                }
                break;
            }
            case 6: {
                // MELHORIA: Verifica se a árvore está vazia antes de imprimir.
                cout << "--- Percurso Pós-Ordem (Post-Order) ---\n";
                if (arvore.estaVazia()) {
                    cout << "A árvore está vazia.\n";
                } else {
                    arvore.posOrdem();
                }
                break;
            }
            case 7:
                break;
            default:
                cout << "Opção inválida!\n";
        }

        if(opcao != 7) {
            cout << "\nPressione Enter para continuar...";
            cin.get();
        }
    } while(opcao != 7);
}

void menuDeque() {
    int opcao;
    do {
        system("cls || clear");
        cout << "========== DEQUE ==========\n";
        cout << "1. Enfileirar no Início (addFront)\n";
        cout << "2. Enfileirar no Fim (addBack)\n";
        cout << "3. Desenfileirar do Início (removeFront)\n";
        cout << "4. Desenfileirar do Fim (removeBack)\n";
        cout << "5. Consultar Início (peekFront)\n";
        cout << "6. Consultar Fim (peekBack)\n";
        cout << "7. Imprimir todos\n";
        cout << "8. Voltar\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        limparBuffer();

        switch(opcao) {
            case 1: { // Enfileirar no Início
                int tipo;
                cout << "1. Aluno\n2. Professor\nEscolha: ";
                cin >> tipo;
                limparBuffer();
                Elemento* e = criarElementoComIdValido(tipo);
                if(deque.enfileirarInicio(e)) {
                    cout << "Enfileirado no início com sucesso!\n";
                } else {
                    cout << "Falha ao enfileirar no início (deque cheio ou erro)!\n";
                    delete e;
                }
                break;
            }
            case 2: { // Enfileirar no Fim
                int tipo;
                cout << "1. Aluno\n2. Professor\nEscolha: ";
                cin >> tipo;
                limparBuffer();
                Elemento* e = criarElementoComIdValido(tipo);
                if(deque.enfileirarFim(e)) {
                    cout << "Enfileirado no fim com sucesso!\n";
                } else {
                    cout << "Falha ao enfileirar no fim (deque cheio ou erro)!\n";
                    delete e;
                }
                break;
            }
            case 3: // Desenfileirar do Início
                if(deque.desenfileirarInicio()) {
                    cout << "Desenfileirado do início com sucesso!\n";
                } else {
                    cout << "Deque vazio!\n";
                }
                break;
            case 4: // Desenfileirar do Fim
                if(deque.desenfileirarFim()) {
                    cout << "Desenfileirado do fim com sucesso!\n";
                } else {
                    cout << "Deque vazio!\n";
                }
                break;
            case 5: { // Consultar Início
                if(const Elemento* frente = deque.consultarInicio()) {
                    cout << "Elemento no início:\n";
                    frente->imprimirInfo();
                } else {
                    cout << "Deque vazio!\n";
                }
                break;
            }
            case 6: { // Consultar Fim
                if(const Elemento* fim = deque.consultarFim()) {
                    cout << "Elemento no fim:\n";
                    fim->imprimirInfo();
                } else {
                    cout << "Deque vazio!\n";
                }
                break;
            }
            case 7: // Imprimir todos
                cout << "====== ELEMENTOS NO DEQUE ======\n";
                deque.imprimirTodos();
                break;
            case 8: // Voltar
                cout << "Voltando ao menu principal...\n";
                break;
            default:
                cout << "Opção inválida!\n";
        }
        if(opcao != 8) {
            cout << "\nPressione Enter para continuar...";
            cin.get();
        }
    } while(opcao != 8);
}

int main() {
    menuPrincipal();
    return 0;
}
