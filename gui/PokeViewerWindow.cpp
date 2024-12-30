#include "gui/PokeViewerWindow.hpp"
#include "gtkmm/enums.h"
#include "gui/PokeLifeBar.hpp"

PokeViewerWindow::PokeViewerWindow() :
    poke_status_frame(personagem),
    poke_moves_frame(personagem),
    poke_lifebar(personagem)
{
    // Iniciar Window
    set_title("PokeViewerGUI");
    set_default_size(200, 50);

    // Define a sessão de baixo da UI
    Gtk::Box box_inferior;

    box_inferior.append(poke_status_frame);
    box_inferior.append(poke_moves_frame);

    // Define a sessão de cima da UI
    Gtk::Box box_superior;
    box_superior.append(poke_lifebar);
    box_superior.append(output_dialog);
    box_superior.append(box_inferior);
    box_superior.set_orientation(Gtk::Orientation::VERTICAL);

    // Inicialização final
    set_child(box_superior);

    output_dialog.print("Charmander se prepara para atacar");
}
