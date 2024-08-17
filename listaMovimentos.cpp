#include "movimento.hpp"
#include "pokemon.hpp"

// DEFINIÇÕES MOVIMENTOS ESPECÍFICOS
// ---------------------------------------------

void Movimento::iniciarMovimentos() {

    // Definição do ataque Tackle
    new Movimento("tackle", [] (Pokemon &usuario, Pokemon &alvo) {
        int dano = usuario.getAtaque();
        alvo.receberDano(dano);
    });


    // Definição do ataque Ember
    new Movimento("ember", [] (Pokemon &usuario, Pokemon &alvo) {
        int dano = usuario.getAtaqueEsp();
        alvo.receberDano(dano);
    });


    // Definição do ataque Water Gun
    new Movimento("water gun", [] (Pokemon &usuario, Pokemon &alvo) {
        int dano = usuario.getAtaqueEsp();
        alvo.receberDano(dano);
    });

}

