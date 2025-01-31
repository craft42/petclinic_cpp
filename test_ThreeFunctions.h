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

// Test retrieving a dinosaur
void testAddRetrieveDinosaur() {
    DinosaurModel model;
    model.addRandomDinosaur(); // Adds a dinosaur

    auto dinosaurs = model.getAllDinosaurs();
    assert(!dinosaurs.empty());

    Dinosaur retrievedDino = dinosaurs[0]; // Get first dino
    assert(retrievedDino.uid > 0);
    std::cout << "✔ testAddRetrieveDinosaur PASSED\n";
}

// Test updating a dinosaur
void testUpdateDinosaur() {
    DinosaurModel model;
    model.addRandomDinosaur();

    auto dinosaurs = model.getAllDinosaurs();
    unsigned short int uid = dinosaurs[0].uid;

    Dinosaur updatedDino("Spike", "Velociraptor", "F", "China", 150);
    bool updated = model.updateDinosaur(uid, updatedDino);
    assert(updated);

    Dinosaur retrievedDino("", "", "", "", 0);
    model.retrieveDinosaur(uid, retrievedDino);
    assert(retrievedDino.name == "Spike");
    assert(retrievedDino.species == "Velociraptor");
    assert(retrievedDino.country == "China");
    assert(retrievedDino.scales == 150);
    std::cout << "✔ testUpdateDinosaur PASSED\n";
}

// Test deleting a dinosaur
void testDeleteDinosaur() {
    DinosaurModel model;
    model.addRandomDinosaur();

    auto dinosaurs = model.getAllDinosaurs();
    unsigned short int uid = dinosaurs[0].uid;

    bool deleted = model.deleteDinosaur(uid);
    assert(deleted);
    // Retrieve the dinosaur needs to fail
    Dinosaur dino("", "", "", "", 0);
    assert(!model.retrieveDinosaur(uid, dino));
    std::cout << "✔ testDeleteDinosaur PASSED\n";
}

void runSimpleTests() {
    std::cout << "\nRunning tests...\n";
    testDinosaurCreation();
    testAddRetrieveDinosaur();
    testDeleteDinosaur();
    std::cout << "✅✔ All tests passed!\n";
}

#endif // TEST_DINOSAUR_3_FUNCTIONS_H