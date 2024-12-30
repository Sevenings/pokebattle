#include "gui/PokeOutputDialog.hpp"
#include <string>

PokeOutputDialog::PokeOutputDialog()
{
    // Inicialização do Frame
    set_label("Output");
    set_margin(20);

    set_child(l_output);
}

void PokeOutputDialog::print(const std::string text) {
    l_output.set_label(text);
}
