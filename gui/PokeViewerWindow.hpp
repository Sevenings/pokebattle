#ifndef POKEVIEWERWINDOW_HPP
#define POKEVIEWERWINDOW_HPP

#include <gtkmm.h>
#include "gamecore/personagem.hpp"
#include "gui/PokeLifeBar.hpp"
#include "gui/PokeMovesFrame.hpp"
#include "gui/PokeOutputDialog.hpp"
#include "gui/PokeStatusFrame.hpp"


class PokeViewerWindow : public Gtk::Window
{
public:
    PokeViewerWindow();

    Personagem personagem = Personagem("./personagens/charmander.json");

    PokeStatusFrame poke_status_frame;
    PokeMovesFrame poke_moves_frame;
    PokeOutputDialog output_dialog;
    PokeLifeBar poke_lifebar;
};

#endif
