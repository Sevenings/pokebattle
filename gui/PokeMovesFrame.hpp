#ifndef POKE_MOVES_FRAME_HPP
#define POKE_MOVES_FRAME_HPP

#include <gtkmm.h>
#include "gamecore/personagem.hpp"
#include "gtkmm/grid.h"


class PokeMovesFrame : public Gtk::Frame
{
public:
    PokeMovesFrame(Personagem&);

    Personagem personagem;

    Gtk::Grid grid;
};

#endif 
