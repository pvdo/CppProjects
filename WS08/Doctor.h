//==============================================
// Name:           Pedro Vitor do Carmo Saraiva Teixeira
// Student Number: 100036193
// Email:          pvdo-carmo-saraiva-t@myseneca.ca
// Section:        NEF
// Workshop:       8 (LAB)
//==============================================

#ifndef SDDS_DOCTOR_H
#define SDDS_DOCTOR_H
#include <iostream>
#include "Employee.h"

namespace sdds{

const int MIN_W_HOURS = 6;
const int MAX_CHAR = 20;

class Doctor:public Employee{
    char m_type[MAX_CHAR + 1];
    double m_salary;
    int m_whours;
    bool m_specialist;
    
public:
    Doctor();
    Doctor(const char*, double, int, bool = false);
    ~Doctor();
    void setSalary(double);
    bool workHours();
    void bonus();
    std::ostream& display(std::ostream& os) const;
};
}

#endif
