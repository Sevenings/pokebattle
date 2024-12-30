#ifndef POKE_OUTPUT_DIALOG_HPP
#define POKE_OUTPUT_DIALOG_HPP

#include "gtkmm/label.h"
#include <gtkmm.h>
#include <string>


class PokeOutputDialog : public Gtk::Frame
{
public:
    PokeOutputDialog();

    void print(const std::string);

    Gtk::Label l_output;
};

#endif 
