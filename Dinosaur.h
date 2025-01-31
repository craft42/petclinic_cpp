#ifndef DINOSAUR_H
#define DINOSAUR_H

#include <string>

class Dinosaur {
private:
    static unsigned short int nextUID;

public:
    unsigned short int uid;
    std::string name;
    std::string species;
    std::string sex;
    std::string country;
    int scales;

    Dinosaur(std::string name, std::string species, std::string sex, std::string country, int scales);
    
    static unsigned short int generateUID();
};

#endif // DINOSAUR_H