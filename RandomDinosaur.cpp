#include "RandomDinosaur.h"
#include <vector>
#include <random>

const std::vector<std::string> NAMES = {"Rex", "Spike", "Dino", "Trixie", "Thunder", "Rocky", "Titan", "Flash"};
const std::vector<std::string> SPECIES = {"Tyrannosaurus", "Velociraptor", "Triceratops", "Brachiosaurus", "Stegosaurus"};
const std::vector<std::string> COUNTRIES = {"USA", "France", "Italy", "Brazil", "Germany", "India", "China", "Mexico", "Russia", "Japan"};
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> nameDist(0, NAMES.size() - 1);
std::uniform_int_distribution<> speciesDist(0, SPECIES.size() - 1);
std::uniform_int_distribution<> countryDist(0, COUNTRIES.size() - 1);
std::uniform_int_distribution<> scalesDist(50, 300);
std::uniform_real_distribution<> sexChance(0.0, 1.0);

Dinosaur RandomDinosaurGenerator::generate() {
    return Dinosaur(NAMES[nameDist(gen)], SPECIES[speciesDist(gen)], (sexChance(gen) < 0.7) ? "M" : "F", COUNTRIES[countryDist(gen)], scalesDist(gen));
}