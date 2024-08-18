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
    int ataque,
    int defesa,
    int ataqueEsp,
    int defesaEsp,
    int velocidade
) : nome(nome),
    vidaMax(vidaMax),
    vida(vidaMax), ataque(ataque),
    defesa(defesa),
    ataqueEsp(ataqueEsp),
    defesaEsp(defesaEsp),
    velocidade(velocidade)
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
    ataque = data["ataque"];
    defesa = data["defesa"];
    ataqueEsp = data["ataqueEsp"];
    defesaEsp = data["defesaEsp"];
    velocidade = data["velocidade"];

    std::vector<std::string> nomes_movimentos = data["movimentos"];
    for (std::string nome_movimento : nomes_movimentos) {
        aprender(nome_movimento);
    }
}


// Imprime nome e status de um pokemon no console
void Personagem::print() const {
    std::cout << nome << " " << vida << "/" << vidaMax << std::endl;
    std::cout << "Ataque: " << ataque << std::endl;
    std::cout << "Defesa: " << defesa << std::endl;
    std::cout << "Atq Sp: " << ataqueEsp << std::endl;
    std::cout << "Def Sp: " << defesaEsp << std::endl;
    std::cout << "Veloci: " << velocidade << std::endl;
}

// Recebe um dano. Pode ser amortecido pela defesa.
void Personagem::receberDano(int dano) {
    int danoRecebido = dano - defesa;
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

int Personagem::getAtaque() const { return ataque; }

int Personagem::getDefesa() const { return defesa; }

int Personagem::getAtaqueEsp() const { return ataqueEsp; }

int Personagem::getDefesaEsp() const { return defesaEsp; }

int Personagem::getVelocidade() const { return velocidade; }

std::vector<Movimento*> Personagem::getMovimentos() const { return movimentos; }

