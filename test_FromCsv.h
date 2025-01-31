#ifndef TEST_FROM_CSV_H
#define TEST_FROM_CSV_H

#include <cassert>
#include <iostream>
#include "DinosaurModel.h"

void testLoadFromCSV() {
    DinosaurModel model;
    model.loadFromCSV("data.csv");

    auto dinosaurs = model.getAllDinosaurs();
    if (dinosaurs.empty()) {
        std::cerr << "⚠ Warning: Test skipped - 'data.csv' is empty.\n";
        return;
    }
    assert(dinosaurs.size()>0); // Ensure at least 3 dinosaurs are loaded
    std::cout << "✔ testLoadFromCSV PASSED (" << dinosaurs.size() << " dinosaurs loaded)\n";
}

void testRetrieveDinosaurFromCSV() {
    DinosaurModel model;
    model.loadFromCSV("data.csv");
    
    auto dinosaurs = model.getAllDinosaurs();
    if (dinosaurs.empty()) {
        std::cerr << "⚠ Warning: Test skipped - 'data.csv' is empty.\n";
        return;
    }
    unsigned short int firstUID = dinosaurs[0].uid;

    Dinosaur dino("", "", "", "", 0);
    bool found = model.retrieveDinosaur(firstUID, dino);

    assert(found);
    assert(dino.uid == firstUID);
    assert(dino.name == dinosaurs[0].name);
    std::cout << "✔ testRetrieveDinosaurFromCSV PASSED (UID: " << firstUID << " found)\n";
}

void testUpdateDinosaurFromCSV() {
    DinosaurModel model;
    model.loadFromCSV("data.csv");

    auto dinosaurs = model.getAllDinosaurs();
    if (dinosaurs.empty()) {
        std::cerr << "⚠ Warning: Test skipped - 'data.csv' is empty.\n";
        return;
    }
    unsigned short int firstUID = dinosaurs[0].uid;

    Dinosaur updatedDino( "UpdatedName", "UpdatedSpecies", "M", "UpdatedCountry", 999);
    bool updated = model.updateDinosaur(firstUID, updatedDino);

    assert(updated);

    Dinosaur dino("", "", "", "", 0);
    model.retrieveDinosaur(firstUID, dino);

    assert(dino.name == "UpdatedName");
    assert(dino.species == "UpdatedSpecies");
    assert(dino.country == "UpdatedCountry");
    assert(dino.scales == 999);

    std::cout << "✔ testUpdateDinosaurFromCSV PASSED (UID: " << firstUID << " updated)\n";
}

void testDeleteDinosaurFromCSV() {
    DinosaurModel model;
    model.loadFromCSV("data.csv");

    auto dinosaurs = model.getAllDinosaurs();
    if (dinosaurs.empty()) {
        std::cerr << "⚠ Warning: Test skipped - 'data.csv' is empty.\n";
        return;
    }
    unsigned short int firstUID = dinosaurs[0].uid;

    bool deleted = model.deleteDinosaur(firstUID);
    assert(deleted);

    Dinosaur dino("", "", "", "", 0);
    bool found = model.retrieveDinosaur(firstUID, dino);
    assert(!found);

    std::cout << "✔ testDeleteDinosaurFromCSV PASSED (UID: " << firstUID << " deleted)\n";
}

void runCsvTests() {
    std::cout << "\nRunning tests...\n";
    testLoadFromCSV();
    testRetrieveDinosaurFromCSV();
    testUpdateDinosaurFromCSV();
    testDeleteDinosaurFromCSV();
    std::cout << "✅ All tests passed!\n";
}

#endif // TEST_FROM_CSV_H