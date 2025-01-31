#ifndef DINOSAUR_MODEL_H
#define DINOSAUR_MODEL_H

#include <vector>
#include <optional>
#include "Dinosaur.h"
#include "RandomDinosaur.h"

class DinosaurModel {
private:
    std::vector<Dinosaur> dinosaurs;

public:
    void loadFromCSV(const std::string& filename);
    bool predict(unsigned short int uid, int y) const;

    bool retrieveDinosaur(unsigned short int uid, Dinosaur& dino) const;
    bool updateDinosaur(unsigned short int uid, const Dinosaur& newDino);
    bool deleteDinosaur(unsigned short int uid);
    std::vector<Dinosaur> getAllDinosaurs() const;
    void addRandomDinosaur();
};

#endif // DINOSAUR_MODEL_H