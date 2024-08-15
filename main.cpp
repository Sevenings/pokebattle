#include <iostream>
#include <string>
#include <vector>
#include <json.hpp>
#include "pokemon.hpp"
using namespace std;






Pokemon charmander("Charmander", 10, 15, 12, 13, 14, 15);
Pokemon squirtle("Squirtle", 15, 14, 13, 12, 11, 10);



void printUI(const Pokemon &p1, const Pokemon &p2) {
    cout << p1.nome << " " << p1.vida << "/" << p1.vidaMax << " | " << p2.nome << " " << p2.vida << "/" << p2.vidaMax << endl;
    cout << "Atq: " << p1.ataque << " | " << "Atq: "<< p2.ataque << endl;
    cout << "Def: " << p1.defesa << " | " << "Def: "<< p2.defesa << endl;
    cout << "AtS: " << p1.ataqueEsp << " | " << "AtS: "<< p2.ataqueEsp << endl;
    cout << "DfS: " << p1.defesaEsp << " | " << "DfS: "<< p2.defesaEsp << endl;
    cout << "Vel: " << p1.velocidade << " | " << "Vel: "<< p2.velocidade << endl;
    cout << "Mov: " << p1.movimentos[0]->nome << " | " << "Mov: " << p2.movimentos[0]->nome << endl;
    cout << endl;
}

int main() {
    Tackle tackle;

    charmander.adicionarMovimento(&tackle);
    squirtle.adicionarMovimento(&tackle);

    printUI(charmander, squirtle);

    charmander.ataca(squirtle, 0);

    printUI(charmander, squirtle);

    return 0;
}

