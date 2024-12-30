#include <gtkmm.h>
#include "gui/PokeViewerWindow.hpp"
#include "gamecore/movimento.hpp"


int main(int argc, char* argv[])
{
    Movimento::iniciarMovimentos();
    auto app = Gtk::Application::create("sevenings.pokebattle");

    return app->make_window_and_run<PokeViewerWindow>(argc, argv);
}
