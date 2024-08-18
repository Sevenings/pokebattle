#include "personagem.hpp"
#include "movimento.hpp"
#include <cstdlib>
#include <iostream>
using namespace std;


class ICombate {
    public:
        virtual Personagem* iniciar(Personagem &p1, Personagem &p2) = 0;
};




class CombateA1 : ICombate {
public:
    Personagem* iniciar(Personagem &p1, Personagem &p2) {
        
        // O combate acaba quando um dos jogadores morrerem
        while (p1.vivo() && p2.vivo()) {
            // Mostrar personagens na tela
            printUI(p1, p2);

            // Capturar a escolha do movimento p1
            int movimento_p1;
            cin >> movimento_p1; // Por favor não escolher um número fora do escopo

            // Decidir aleatoriamente o movimento do p2
            int num_movimentos = p2.getNumMovimentos();
            int movimento_p2 = rand() % num_movimentos;

            // Realizar o embate dos personagens (eles se batem)
            embate(p1, movimento_p1, p2, movimento_p2);
        }

        printUI(p1, p2);

        // Retorna o vencedor
        if (p1.vivo())
            return &p1;
        else if (p2.vivo())
            return &p2;
        else 
            return nullptr; // Não houve vencedor = empate
    }

private:

    void embate(Personagem &p1, int movimento_p1, Personagem &p2, int movimento_p2) {
        // Decide quem se move primeiro
        // Quem tiver maior iniciativa vai primeiro.
        Personagem *primeiro, *segundo;
        if (p1.getIniciativa() > p2.getIniciativa()) {
            primeiro = &p1;
            segundo = &p2;
        } else if (p1.getIniciativa() < p2.getIniciativa()) {
            primeiro = &p2;
            segundo = &p1;
        } else {
            // Em caso de empate, é por sorteio
            if (rand()%2 == 0) {
                primeiro = &p1;
                segundo = &p2;
            } else {
                primeiro = &p2;
                segundo = &p1;
            }
        }


        // O primeiro jogador aplica seu ataque sobre o segundo
        primeiro->ataca(*segundo, movimento_p1);
        
        // Print de confirmação
        string nome_movimento = primeiro->getMovimentos()[movimento_p1]->getNome();
        cout << primeiro->getNome() << " usa " << nome_movimento << " em " << segundo->getNome() << endl;

        // O segundo jogador aplica seu ataque sobre o primeiro
        segundo->ataca(*primeiro, movimento_p2);

        // Print de confirmação
        nome_movimento = segundo->getMovimentos()[movimento_p2]->getNome();
        cout << segundo->getNome() << " usa " << nome_movimento << " em " << primeiro->getNome() << endl;

    }

    // Printa os status do personagens no terminal
    void printUI(const Personagem &p1, const Personagem &p2) {
        cout << p1.getNome() << " " << p1.getVida() << "/" << p1.getVidaMax() << " | " << p2.getNome() << " " << p2.getVida() << "/" << p2.getVidaMax() << endl;
        cout << "For: " << p1.getForca() << " | " << "For: "<< p2.getForca() << endl;
        cout << "Arm: " << p1.getClasseDeArmadura() << " | " << "Arm"<< p2.getClasseDeArmadura() << endl;
        cout << "Int: " << p1.getInteligencia() << " | " << "Int: "<< p2.getInteligencia() << endl;
        cout << "Des: " << p1.getDestreza() << " | " << "Des: "<< p2.getDestreza() << endl;
        
        // Printar os Movimentos
        vector<Movimento*> movimentosP1 = p1.getMovimentos();
        vector<Movimento*> movimentosP2 = p2.getMovimentos();

        int num_max_movimentos = max(movimentosP1.size(), movimentosP2.size());


        for (int i=0; i < num_max_movimentos; i++) {
            if (i < movimentosP1.size())
                cout << "[" << i << "] " << p1.getMovimentos()[i]->getNome();
            else
                cout << "              ";

            cout << " | ";

            if (i < movimentosP2.size())
                cout << "[" << i << "] " << p2.getMovimentos()[i]->getNome();
            cout << endl;
        }
        cout << endl;
    }
};

