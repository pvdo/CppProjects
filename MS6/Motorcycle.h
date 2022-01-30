/* Citation and Sources...
Final Project Milestone 6
Module: Menu
Filename: Menu.h
Version 1.0
Author Pedro Vitor do Carmo Saraiva Teixeira
Revision History
-----------------------------------------------------------
Date Reason
2020/04/05 Preliminary release
2020/04/05 Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_MOTORCYCLE_H
#define SDDS_MOTORCYCLE_H
#include <iostream>
#include "Vehicle.h"



namespace sdds {
class Motorcycle : public Vehicle{
    bool sidecar;
    
public:
    Motorcycle();
    Motorcycle(const char*, const char*);
    Motorcycle(const Motorcycle&) = delete;
    Motorcycle operator= (Motorcycle&) = delete;
    std::ostream& write(std::ostream& ostr) const;
    std::istream& read(std::istream& istr);
};

}
#endif


