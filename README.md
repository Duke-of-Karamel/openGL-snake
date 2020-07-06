# Prvni testovani open gl
Samozadanym ukolem je vytvorit jednoduchou 2D hru (Snake)

Pouzivam make, zadny cmake, snazim se to udelat tak, abych tomu rozumne rozumnel

## Instalace
apt install libglew-dev
 - dev umoznuje include
 - GLEW = GL Extension Wrangler
 - Multiplatformni zjednoduseni a zuniverzalovani funkci open GL

 apt install libglfw3-dev
  - dev umoznuje include
  - GLFW = Graphics Library FrameWork
  - multiplatformni sprava oken a sprava vstupnich zarizeni (klavevsnice, joystick)

## Programovani
Prvni krok byl vytvoreni okna a renderovani trojuhelniku
s jednoduchymy shadery, normalne bych mel pokracovat renderovanim
3D objektu, ale snake je jen 2D, proto se v dalsim kroku spis zamerim
na shadery a dynamicke body