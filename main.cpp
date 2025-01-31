#include "DinosaurModel.h"
#include "DinosaurView.h"
#include <iostream>

int main() {
    DinosaurModel model;
    model.loadFromCSV("data.csv");

    int choice;
    do {
        DinosaurView::showMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: { // Show all Dinosaurs
                DinosaurView::displayAllDinosaurs(model.getAllDinosaurs());
                break;
            }
            case 2: { // Retrieve a Dinosaur
                unsigned short int uid;
                std::cout << "Enter Dinosaur ID: ";
                std::cin >> uid;
                Dinosaur dino( "", "", "", "", 0);
                if (model.retrieveDinosaur(uid, dino)) {
                    DinosaurView::displayDinosaur(dino);
                } else {
                    std::cout << "Dinosaur not found.\n";
                }
                break;
            }
            case 3: { // Update a Dinosaur
                unsigned short int uid;
                std::cout << "Enter Dinosaur ID to update: ";
                std::cin >> uid;
                Dinosaur dino("", "", "", "", 0);
                if (model.retrieveDinosaur(uid, dino)) {
                    std::string name, species, sex, country;
                    int scales;
                    std::cout << "New Name: ";
                    std::cin >> name;
                    std::cout << "New Species: ";
                    std::cin >> species;
                    std::cout << "New Sex (M/F): ";
                    std::cin >> sex;
                    std::cout << "New Country: ";
                    std::cin >> country;
                    std::cout << "New Number of Scales: ";
                    std::cin >> scales;

                    Dinosaur updatedDino(name, species, sex, country, scales);
                    if (model.updateDinosaur(uid, updatedDino)) {
                        std::cout << "Dinosaur updated successfully.\n";
                    } else {
                        std::cout << "Failed to update Dinosaur.\n";
                    }
                } else {
                    std::cout << "Dinosaur not found.\n";
                }
                break;
            }
            case 4: { // Delete a Dinosaur
                unsigned short int uid;
                std::cout << "Enter Dinosaur ID to delete: ";
                std::cin >> uid;
                if (model.deleteDinosaur(uid)) {
                    std::cout << "Dinosaur deleted successfully.\n";
                } else {
                    std::cout << "Dinosaur not found.\n";
                }
                break;
            }
            case 5: { // Load from CSV
                model.loadFromCSV("data.csv");
                std::cout << "Data loaded from CSV.\n";
                break;
            }
            case 6: { // Add a Random Dinosaur
                model.addRandomDinosaur();
                std::cout << "Random Dinosaur added.\n";
                break;
            }
            case 99: // Quit
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 99);

    return 0;
}