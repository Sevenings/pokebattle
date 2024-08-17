#include <iostream>
#include <string>
#include <vector>
#include "pokemon.hpp"
#include "movimento.hpp"
using namespace std;


void printUI(const Pokemon &p1, const Pokemon &p2) {
    cout << p1.getNome() << " " << p1.getVida() << "/" << p1.getVidaMax() << " | " << p2.getNome() << " " << p2.getVida() << "/" << p2.getVidaMax() << endl;
    cout << "Atq: " << p1.getAtaque() << " | " << "Atq: "<< p2.getAtaque() << endl;
    cout << "Def: " << p1.getDefesa() << " | " << "Def: "<< p2.getDefesa() << endl;
    cout << "AtS: " << p1.getAtaqueEsp() << " | " << "AtS: "<< p2.getAtaqueEsp() << endl;
    cout << "DfS: " << p1.getDefesaEsp() << " | " << "DfS: "<< p2.getDefesaEsp() << endl;
    cout << "Vel: " << p1.getVelocidade() << " | " << "Vel: "<< p2.getVelocidade() << endl;
    
    // Printar os Movimentos
    vector<Movimento*> movimentosP1 = p1.getMovimentos();
    vector<Movimento*> movimentosP2 = p2.getMovimentos();

    int num_max_movimentos = max(movimentosP1.size(), movimentosP2.size());


    for (int i=0; i < num_max_movimentos; i++) {
        if (i < movimentosP1.size())
            cout << "Mov: " << p1.getMovimentos()[i]->getNome();
        else
            cout << "              ";

        cout << " | ";

        if (i < movimentosP2.size())
            cout << "Mov: " << p2.getMovimentos()[i]->getNome();
        cout << endl;
    }
    cout << endl;
}

int main() {
    Movimento::iniciarMovimentos();

    Pokemon charmander("pokemons/charmander.json");
    Pokemon squirtle("pokemons/squirtle.json");
    printUI(charmander, squirtle);

    charmander.ataca(squirtle, 0);

    printUI(charmander, squirtle);

    return 0;
}

