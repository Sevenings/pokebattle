#include "movimento.hpp"
#include "pokemon.hpp"
#include <functional>
#include <stdexcept>
#include <string>
#include <iostream>

// MOVIMENTO class
//----------------------------------------------
//
//  +----------------------+--+
// / Tabela de movimentos /   |
// +-------------\-------+----+
// | "ember"     \ 0xf3423d30 |
// +-------------\------------+
// | "water gun" \ 0x20e2ff98 |
// +-------------\------------+
// | "tackle"    \ 0xba13bf0c |
// +-------------\------------+
// |     ...     \     ...    |
//

// Instanciação da Tabela de Movimentos
std::map<std::string, Movimento*> Movimento::tabelaMovimentos;


// Construtor. Instancia um novo Movimento e o Registra na Tabela de Movimentos
Movimento::Movimento(const std::string &nome, std::function<void (Pokemon &u, Pokemon &a)> atacar_impl) : 
    nome(nome), atacar_impl(atacar_impl)  // Inicializa as variáveis
{
    // Verifica se esse movimento já foi registrado
    if (tabelaMovimentos.find(nome) != tabelaMovimentos.end()) {
        std::cout << "Movimento " + nome + " já está na tabela de movimentos" << std::endl;
        return;
    }

    // Se não, registra o valor na tabela
    tabelaMovimentos.insert( { nome, this } );
}


// Retorna a instância do movimento com o nome referido
Movimento* Movimento::get(const std::string &nome) {

    // Procura o movimento na tabela
    auto it = tabelaMovimentos.find(nome);

    // Se não está: erro
    if (it == tabelaMovimentos.end()) {
        throw std::runtime_error("Movimento " + nome + " não encontrado na tabela de movimentos");
    }
    
    // Do contrário, o retorna
    return it->second;
}


void Movimento::atacar(Pokemon &usuario, Pokemon &alvo) {
    atacar_impl(usuario, alvo);
}


// Getters
// ---------

std::string Movimento::getNome() const { return nome; }


