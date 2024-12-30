#ifndef POKE_LIFE_BAR_HPP
#define POKE_LIFE_BAR_HPP

#include <gtkmm.h>
#include "gamecore/personagem.hpp"
#include "gtkmm/levelbar.h"


class PokeLifeBar : public Gtk::Frame
{
public:
    PokeLifeBar(Personagem&);

    Personagem personagem;
    Gtk::LevelBar lifebar;

    void updateValue();
};

#endif 
