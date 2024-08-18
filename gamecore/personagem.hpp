#include <string>
#include <vector>

class Movimento;


// POKEMON class
// ---------------------------------------------

// Classe Personagem
class Personagem {
    // Atributos
    std::string nome;
    int vidaMax;
    int vida;
    int ataque;
    int defesa;
    int ataqueEsp;
    int defesaEsp;
    int velocidade;
    std::vector<Movimento*> movimentos;

public:
    // Construtor Bruto
    Personagem( const std::string nome, int vidaMax, int ataque, int defesa, int ataqueEsp, int defesaEsp, int velocidade);

    // Construtor via Json
    Personagem(const std::string filename);


    // Imprime nome e status de um pokemon no console
    void print() const;

    // Adiciona um movimento à lista de movimentos do pokemon
    void aprender(Movimento *movimento);
    void aprender(std::string nome_movimento);

    // Recebe um dano. Pode ser amortecido pela defesa.
    void receberDano(int dano);

    // Executa um ataque a um alvo
    void ataca(Personagem &alvo, int numAtaque);


    // Getters
    //------------
    std::string getNome() const;

    int getVida() const;

    int getVidaMax() const;

    int getAtaque() const;

    int getDefesa() const;

    int getAtaqueEsp() const;

    int getDefesaEsp() const;

    int getVelocidade() const;

    std::vector<Movimento*> getMovimentos() const;
};




