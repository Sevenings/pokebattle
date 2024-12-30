#include "gui/PokeLifeBar.hpp"
#include "gamecore/movimento.hpp"
#include "gtkmm/enums.h"
#include "gtkmm/label.h"
#include <string>

PokeLifeBar::PokeLifeBar(Personagem &personagem) :
    personagem(personagem)
{
    // Inicialização 
    set_margin(20);
    updateValue();

    Gtk::Label l_nome;
    std::string nome = personagem.getNome();
    l_nome.set_label(nome);

    Gtk::Label l_vida;
    std::string vida = std::to_string(personagem.getVida());
    std::string vidaMax = std::to_string(personagem.getVidaMax());
    l_vida.set_label(vida + "/" + vidaMax);

    Gtk::Box b_nome_vida(Gtk::Orientation::HORIZONTAL);
    b_nome_vida.set_spacing(200);
    b_nome_vida.set_expand(true);
    b_nome_vida.append(l_nome);
    b_nome_vida.append(l_vida);

    Gtk::Box m_box;
    m_box.set_orientation(Gtk::Orientation::VERTICAL);
    m_box.append(b_nome_vida);
    m_box.append(lifebar);

    // Composição dos widgets
    set_child(m_box);

}

void PokeLifeBar::updateValue() {
    double vida = (double) personagem.getVida();
    double vidaMax = (double) personagem.getVidaMax();
    double value =  vida / vidaMax;
    lifebar.set_value(value);
}
