#ifndef TEST_DINOSAUR_3_FUNCTIONS_H
#define TEST_DINOSAUR_3_FUNCTIONS_H

#include <cassert>
#include <iostream>
#include "DinosaurModel.h"

void testDinosaurCreation() {
    Dinosaur dino("T-Rex", "Tyrannosaurus", "M", "USA", 200);
    assert(dino.name == "T-Rex");
    assert(dino.species == "Tyrannosaurus");
    assert(dino.sex == "M");
    assert(dino.country == "USA");
    assert(dino.scales == 200);
    std::cout << "✔ testDinosaurCreation PASSED\n";
}

void runSimpleTests() {
    std::cout << "\nRunning tests...\n";
    testDinosaurCreation();
    // step 2 - Add more tests here
    std::cout << "✅✔ All tests passed!\n";
}

#endif // TEST_DINOSAUR_3_FUNCTIONS_H