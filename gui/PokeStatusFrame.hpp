#ifndef POKE_STATUS_FRAME_HPP
#define POKE_STATUS_FRAME_HPP

#include <gtkmm.h>
#include "gamecore/personagem.hpp"
#include "gtkmm/box.h"
#include "gtkmm/label.h"


class PokeStatusFrame : public Gtk::Frame
{
public:
    PokeStatusFrame(Personagem&);

    Personagem personagem;

    Gtk::Label l_vida;
    Gtk::Label l_forca;
    Gtk::Label l_armadura;
    Gtk::Label l_inteligencia;
    Gtk::Label l_destreza;
    Gtk::Box box;
};

#endif 
