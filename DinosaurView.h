#ifndef DINOSAUR_VIEW_H
#define DINOSAUR_VIEW_H

#include <vector>
#include "Dinosaur.h"

class DinosaurView {
public:
    static void displayDinosaur(const Dinosaur& dino);
    static void displayAllDinosaurs(const std::vector<Dinosaur>& dinos);
    static void showMenu();
};

#endif // DINOSAUR_VIEW_H