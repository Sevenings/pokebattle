#include "personagem.hpp"
#include "movimento.hpp"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
using json = nlohmann::json;



// POKEMON class ---------------------------------------------

// Construtor Bruto
Personagem::Personagem(
    const std::string nome, 
    int vidaMax,
    int forca,
    int classe_de_armadura,
    int inteligencia,
    int destreza
) : nome(nome),
    vidaMax(vidaMax),
    vida(vidaMax), forca(forca),
    classe_de_armadura(classe_de_armadura),
    inteligencia(inteligencia),
    destreza(destreza)
{}



// Construtor via Json
Personagem::Personagem(const std::string filename) {
    // Lê o arquivo json
    std::ifstream f(filename);
    json data = json::parse(f);

    // Captura as informações
    nome = data["nome"];
    vidaMax = data["vidaMax"];
    vida = vidaMax;
    forca = data["forca"];
    classe_de_armadura = data["classe_de_armadura"];
    inteligencia = data["inteligencia"];
    destreza = data["destreza"];

    std::vector<std::string> nomes_movimentos = data["movimentos"];
    for (std::string nome_movimento : nomes_movimentos) {
        aprender(nome_movimento);
    }
}


// Imprime nome e status de um pokemon no console
void Personagem::print() const {
    std::cout << nome << " " << vida << "/" << vidaMax << std::endl;
    std::cout << "Ataque: " << forca << std::endl;
    std::cout << "Defesa: " << classe_de_armadura << std::endl;
    std::cout << "Atq Sp: " << inteligencia << std::endl;
    std::cout << "Veloci: " << destreza << std::endl;
}

// Recebe um dano. Pode ser amortecido pela defesa.
void Personagem::receberDano(int dano) {
    int danoRecebido = dano - classe_de_armadura;
    if (danoRecebido <= 0)
        return;
    vida -= danoRecebido;
    if (vida < 0)
        vida = 0;
}


// Adiciona um movimento à lista de movimentos do pokemon
void Personagem::aprender(Movimento *movimento) {
    movimentos.push_back(movimento);
}

void Personagem::aprender(std::string nome_movimento) {
    Movimento* movimento = Movimento::get(nome_movimento);
    if (movimento != nullptr)
        aprender(movimento);
}



// Executa um ataque a um alvo
void Personagem::ataca(Personagem &alvo, int numAtaque) {
    this->movimentos[numAtaque]->atacar(*this, alvo);
}


// Getters
//------------

std::string Personagem::getNome() const { return nome; }

int Personagem::getVida() const { return vida; }

int Personagem::getVidaMax() const { return vidaMax; }

bool Personagem::vivo() const { return vida > 0; }

int Personagem::getForca() const { return forca; }

int Personagem::getClasseDeArmadura() const { return classe_de_armadura; }

int Personagem::getInteligencia() const { return inteligencia; }

int Personagem::getDestreza() const { return destreza; }

std::vector<Movimento*> Personagem::getMovimentos() const { return movimentos; }

int Personagem::getNumMovimentos() const { return movimentos.size(); }

int Personagem::getIniciativa() const { return destreza; }
