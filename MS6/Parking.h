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

#ifndef SDDS_PARKING_H
#define SDDS_PARKING_H
#include "Menu.h"
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"

namespace sdds {
const int MAX_SPOTS = 100;

class Parking{
    char *m_filename;
    Menu m_parkingMenu;
    Menu m_vehicleMenu;
    int m_numberSpots;
    int m_numberVehicle;
    Vehicle *m_parkingSpots[MAX_SPOTS];


    bool isEmpty() const;
    void parkingStatus() const;
    void parkingVehicle();
    void returnVehicle();
    void listParkedVehicle() const;
    bool closeParking();
    bool exitParking() const;
    bool loadDataFile();
    void saveDataFile()const;

public:
    Parking();
    Parking(const char*, int);
    Parking(const Parking& parking) = delete;
    Parking& operator=(const Parking& parking) = delete;
    ~Parking();
    int run();

};

}



#endif
