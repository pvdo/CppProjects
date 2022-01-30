//==============================================
// Name:           Pedro Vitor do Carmo Saraiva Teixeira
// Student Number: 100036193
// Email:          pvdo-carmo-saraiva-t@myseneca.ca
// Section:        NEF
// Workshop:       8 (LAB)
//==============================================

#ifndef SDDS_EMPLOYEE_H
#define SDDS_EMPLOYEE_H
#include <iostream>

namespace sdds{

class Employee{
public:
    virtual ~Employee(){};
    virtual void setSalary(double) = 0;
    virtual void bonus() = 0;
    virtual bool workHours() = 0;
    virtual std::ostream& display(std::ostream& os)const = 0;
};
}

#endif
