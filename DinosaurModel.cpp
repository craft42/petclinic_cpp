#include "DinosaurModel.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>


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

bool DinosaurModel::retrieveDinosaur(unsigned short int uid, Dinosaur& outDino) const {
    for (const auto& dino : dinosaurs) {
        if (dino.uid == uid) {
            outDino = dino;
            return true;
        }
    }
    return false;
}

bool DinosaurModel::updateDinosaur(unsigned short int uid, const Dinosaur& newDino) {
    for (auto& dino : dinosaurs) {
        if (dino.uid == uid) {
            dino = newDino;
            return true;
        }
    }
    return false;
}

bool DinosaurModel::deleteDinosaur(unsigned short int uid) {
    auto it = std::remove_if(dinosaurs.begin(), dinosaurs.end(),
        [&](const Dinosaur& d) { return d.uid == uid; });

    if (it != dinosaurs.end()) {
        dinosaurs.erase(it, dinosaurs.end());
        return true;
    }
    return false;
}

std::vector<Dinosaur> DinosaurModel::getAllDinosaurs() const {
    return dinosaurs;
}

bool DinosaurModel::predict(unsigned short int uid, int years) const {
    srand(time(0));
    Dinosaur dino("", "", "", "", 0);

    if (!retrieveDinosaur(uid, dino)) {
        std::cout << "Dinosaur not found.\n";
        return false;
    }

    int p = rand() % 500 + 50, x = dino.scales / 10, f = 0;
    std::cout << "Starting value: " << p << "\n";

    for (int i = 0; i < years; i++) {
        double m = ((std::sin(i) * (rand() % 20)) - 10) + x;
        p += static_cast<int>(m);
        if (p < 10) {
            std::cout << "❌ Event triggered at step " << i + 1 << "!\n";
            return true;
        }
        std::cout << "Step " << i + 1 << ": Value = " << p << "\n";
    }

    std::cout << "✅ Process completed successfully.\n";
    return false;
}