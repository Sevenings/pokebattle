#include <functional>
#include <map>
#include <string>
class Pokemon;

// MOVIMENTO class
// ---------------------------------------------

// Classe dos Movimentos
class Movimento {
private:
    std::string nome;
    static std::map<std::string, Movimento*> tabelaMovimentos;
    std::function<void (Pokemon &u, Pokemon &a)> atacar_impl;

public:

    // Construtor
    Movimento(const std::string &nome, std::function<void (Pokemon &u, Pokemon &a)> atacar);

    // Ataque
    void atacar(Pokemon &usuario, Pokemon &alvo);

    // Acessa a tabela de movimentos
    static Movimento* get(const std::string &nome);

    // Função que cria todos os movimentos e os salva na tabela de movimentos
    static void iniciarMovimentos();

    // Função que desaloca a memória de cada movimento criado
    /*static void desalocarMovimentos();*/

    // Getters
    // ---------
    std::string getNome() const;
};



