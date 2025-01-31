#include "Dinosaur.h"

unsigned short int Dinosaur::nextUID = 1; // Start UID at 1

Dinosaur::Dinosaur(std::string name, std::string species, std::string sex, std::string country, int scales)
    : uid(generateUID()), name(name), species(species), sex(sex), country(country), scales(scales) {}

unsigned short int Dinosaur::generateUID() {
    return nextUID++;
}