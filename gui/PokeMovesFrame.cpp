#include "gui/PokeMovesFrame.hpp"
#include "gamecore/movimento.hpp"
#include "gtkmm/button.h"

PokeMovesFrame::PokeMovesFrame(Personagem &personagem) :
    personagem(personagem)
{
    // Inicialização do Frame
    set_label("Moves");
    set_label_align(Gtk::Align::CENTER);
    set_margin(20);


    // Cria os botões para cada um dos movimentos
    int k = 0;
    for (Movimento* movimento : personagem.getMovimentos()) {
        Gtk::Button btn;
        btn.set_label(movimento->getNome());
        grid.attach(btn, k%2, k/2);
        k++;
    }

    // Inicia o grid e o frame
    grid.set_row_homogeneous();
    set_child(grid);
}
