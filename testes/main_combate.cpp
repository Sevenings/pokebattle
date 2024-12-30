#include <iostream>
#include "gamecore/personagem.hpp"
#include "gamecore/movimento.hpp"
#include "gamecore/combate.hpp"
using namespace std;


int main() {
    Movimento::iniciarMovimentos();

    Personagem charmander("personagens/charmander.json");
    Personagem squirtle("personagens/squirtle.json");

    CombateA1 combate;
    
    Personagem *vencedor = combate.iniciar(charmander, squirtle);

    if (vencedor == nullptr) {
        cout << "RESULTADO: Empate!" << endl;
        return 0;
    }
    cout << "RESULTADO: " << vencedor->getNome() << " venceu!" << endl;
    return 0;
}

