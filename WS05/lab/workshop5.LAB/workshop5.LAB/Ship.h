//==============================================
// Name:           Pedro Vitor do Carmo Saraiva Teixeira
// Student Number: 100036193
// Email:          pvdo-carmo-saraiva-t@myseneca.ca
// Section:        NEF
// Workshop:       5 (DIY)
//==============================================

#ifndef SDDS_SHIP_H
#define SDDS_SHIP_H
#include "Engine.h"

namespace sdds {
const int MAX_ENGINE = 10;
const int TYPE_RANGE = 6;

class Ship{
    Engine engine[MAX_ENGINE];
    char type[TYPE_RANGE + 1];
    int numberOfEngines;
public:
    Ship();
    Ship(const char*, const Engine*, const int);
    ~Ship();
    void setEmpty();
    bool empty() const;
    float calculatePower() const;
    void display() const;
    Ship& operator+=(Engine);
    friend bool operator==(const Ship&, const Ship&);
};


bool operator<(const Ship&, double);

}

#endif /* SDDS_SHIP_H */
