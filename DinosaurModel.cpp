#include "DinosaurModel.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

void DinosaurModel::loadFromCSV(const std::string& filename) {
    dinosaurs.clear();
    std::ifstream file(filename);

    if (!file) {  // Check if file exists
        std::cerr << "⚠ Error: File '" << filename << "' not found.\n";
        return;
    }

    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, species, sex, country;
        int scales;

        std::getline(ss, name, ',');
        std::getline(ss, species, ',');
        std::getline(ss, sex, ',');
        std::getline(ss, country, ',');
        ss >> scales;

        // Automatically assign a unique UID when loading from CSV
        dinosaurs.emplace_back(Dinosaur(name, species, sex, country, scales));
    }
    file.close();
}

void DinosaurModel::addRandomDinosaur() {
    Dinosaur newDino = RandomDinosaurGenerator::generate();
    dinosaurs.push_back(newDino);
}

std::vector<Dinosaur> DinosaurModel::getAllDinosaurs() const {
    return dinosaurs;
}
// Step 1: Implement the following methods