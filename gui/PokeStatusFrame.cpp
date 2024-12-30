#include "gui/PokeStatusFrame.hpp"
#include "gtkmm/enums.h"
#include "gtkmm/label.h"
#include <string>

PokeStatusFrame::PokeStatusFrame(Personagem &personagem) :
    personagem(personagem)
{
    // Inicialização do Frame
    set_label("Status: " + personagem.getNome());
    set_label_align(Gtk::Align::CENTER);
    set_margin(20);

    // Iniciar Label de Vida
    std::string vida = std::to_string(personagem.getVida());
    std::string vidaMax = std::to_string(personagem.getVidaMax());
    l_vida.set_text("Vida: " + vida + "/" + vidaMax);

    // Iniciar Label de Forca
    std::string forca = std::to_string(personagem.getForca());
    l_forca.set_text("Força: " + forca);
    
    // Iniciar Label de Armadura
    std::string ca = std::to_string(personagem.getClasseDeArmadura());
    l_armadura.set_text("CA: " + ca);
    
    // Iniciar Label de Inteligência
    std::string inteligencia = std::to_string(personagem.getInteligencia());
    l_inteligencia.set_text("Inteligencia: " + inteligencia);
    
    // Iniciar Label de Destreza
    std::string destreza = std::to_string(personagem.getDestreza());
    l_destreza.set_text("Destreza: " + destreza);
    

    // Composição dos Widgets
    box.set_orientation(Gtk::Orientation::VERTICAL);
    box.append(l_vida);
    box.append(l_forca);
    box.append(l_armadura);
    box.append(l_inteligencia);
    box.append(l_destreza);
    set_child(box);
}
