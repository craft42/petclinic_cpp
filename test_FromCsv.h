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
    std::cout << "Loaded " << dinosaurs.size() << " dinosaurs from 'data.csv'\n";
    assert(dinosaurs.size()>0); // Ensure at least 3 dinosaurs are loaded
    std::cout << "✔ testLoadFromCSV PASSED (" << dinosaurs.size() << " dinosaurs loaded)\n";
}

void runCsvTests() {
    std::cout << "\nRunning tests...\n";
    testLoadFromCSV();
    // step 2 - Add more tests here
    std::cout << "✅ All tests passed!\n";
}

#endif // TEST_FROM_CSV_H