#include <string>
#include <vector>
#include <iostream>

class Pokemon;

class Movimento {
public:
    std::string nome;

    Movimento(std::string nome) : nome(nome) {}

    virtual void atacar(Pokemon &usuario, Pokemon &alvo) const = 0;
};


class Pokemon {
public:
    std::string nome;
    int vidaMax;
    int vida;
    int ataque;
    int defesa;
    int ataqueEsp;
    int defesaEsp;
    int velocidade;

    std::vector<Movimento*> movimentos;


    Pokemon(
        const std::string nome, 
        int vidaMax,
        int ataque,
        int defesa,
        int ataqueEsp,
        int defesaEsp,
        int velocidade
    ) : nome(nome),
        vidaMax(vidaMax),
        vida(vidaMax),
        ataque(ataque),
        defesa(defesa),
        ataqueEsp(ataqueEsp),
        defesaEsp(defesaEsp),
        velocidade(velocidade)
    {}

    void print() {
        std::cout << nome << " " << vida << "/" << vidaMax << std::endl;
        std::cout << "Ataque: " << ataque << std::endl;
        std::cout << "Defesa: " << defesa << std::endl;
        std::cout << "Atq Sp: " << ataqueEsp << std::endl;
        std::cout << "Def Sp: " << defesaEsp << std::endl;
        std::cout << "Veloci: " << velocidade << std::endl;
    }

    void receberDano(int dano) {
        int danoRecebido = dano - defesa;
        if (danoRecebido <= 0)
            return;
        vida -= danoRecebido;
        if (vida < 0)
            vida = 0;
    }

    void adicionarMovimento(Movimento *movimento) {
        movimentos.push_back(movimento);
    }

    void ataca(Pokemon &alvo, int numAtaque) {
        this->movimentos[numAtaque]->atacar(*this, alvo);
    }
};




class Tackle : public Movimento {
public:
    Tackle() : Movimento("Tackle") {}

    void atacar(Pokemon &usuario, Pokemon &alvo) const override {
        int dano = usuario.ataque;
        alvo.receberDano(dano);
    }
};
