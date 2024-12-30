project('Pokebattle', 'cpp')
gtkmm_dep = dependency('gtkmm-4.0', version: '>= 4.6.0')
inc = include_directories('include')
exe_file = executable('PokeViewerGUI', 
  'main.cpp', 
  'gui/PokeViewerWindow.cpp',
  'gui/PokeStatusFrame.cpp',
  'gui/PokeMovesFrame.cpp',
  'gui/PokeOutputDialog.cpp',
  'gui/PokeLifeBar.cpp',
  'gamecore/personagem.cpp',
  'gamecore/movimento.cpp',
  'gamecore/listaMovimentos.cpp',
  dependencies: gtkmm_dep,
  include_directories: inc,
  # win_subsystem: 'windows',
)

