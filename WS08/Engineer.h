//==============================================
// Name:           Pedro Vitor do Carmo Saraiva Teixeira
// Student Number: 100036193
// Email:          pvdo-carmo-saraiva-t@myseneca.ca
// Section:        NEF
// Workshop:       8 (LAB)
//==============================================

#ifndef SDDS_ENGINEER_H
#define SDDS_ENGINEER_H
#include <iostream>
#include "Employee.h"

namespace sdds{

const int MIN_HOURS = 5;
const int MAX_LEVEL = 4;

class Engineer :public Employee{
    double m_esalary;
    int m_ewhours;
    int m_level;
public:
    Engineer();
    Engineer(double, int, int);
    ~Engineer();
    void setSalary(double);
    bool workHours();
    void bonus();
    std::ostream& display(std::ostream& os)const;
};
}

#endif
