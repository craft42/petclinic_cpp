#include "DinosaurView.h"
#include <iostream>

void DinosaurView::displayDinosaur(const Dinosaur& dino) {
    std::cout << "ID: " << dino.uid << ", Name: " << dino.name << ", Species: " << dino.species 
              << ", Sex: " << dino.sex << ", Country: " << dino.country 
              << ", Scales: " << dino.scales << std::endl;
}

void DinosaurView::displayAllDinosaurs(const std::vector<Dinosaur>& dinos) {
    if (dinos.empty()) {
        std::cout << "No dinosaurs found." << std::endl;
        return;
    }
    for (const auto& dino : dinos) {
        displayDinosaur(dino);
    }
}

void DinosaurView::showMenu() {
    short unsigned int choice = 1;
    std::cout << choice++ << ". Show all Dinosaurs (for help)\n";
    std::cout << choice++ << ". Retrieve a Dinosaur (step 1.1)\n";
    std::cout << choice++ << ". Update a Dinosaur (step 1.1)\n";
    std::cout << choice++ << ". Delete a Dinosaur (step 1.1)\n";
    std::cout << choice++ << ". Load from CSV (step 1.2)\n";
    std::cout << choice++ << ". Add a Random Dinosaur (for help)\n";
    std::cout << choice++ << ". Run Simple Unit Tests (step 2.1)\n";
    std::cout << choice++ << ". Run Unit Tests from CSV (step 2.2)\n";

    std::cout << "99. Quit\n";
}