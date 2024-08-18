#include "movimento.hpp"
#include "personagem.hpp"

// DEFINIÇÕES MOVIMENTOS ESPECÍFICOS
// ---------------------------------------------

void Movimento::iniciarMovimentos() {

    // Definição do ataque Tackle
    new Movimento("tackle", [] (Personagem &usuario, Personagem &alvo) {
        int dano = usuario.getForca();
        alvo.receberDano(dano);
    });


    // Definição do ataque Ember
    new Movimento("ember", [] (Personagem &usuario, Personagem &alvo) {
        int dano = usuario.getInteligencia();
        alvo.receberDano(dano);
    });


    // Definição do ataque Water Gun
    new Movimento("water gun", [] (Personagem &usuario, Personagem &alvo) {
        int dano = usuario.getInteligencia();
        alvo.receberDano(dano);
    });

    new Movimento("hadouken", [] (Personagem &usuario, Personagem &alvo) {
        int dano = usuario.getInteligencia() + 5;
        alvo.receberDano(dano);
    });

}

