//==============================================
// Name:           Pedro Vitor do Carmo Saraiva Teixeira
// Student Number: 100036193
// Email:          pvdo-carmo-saraiva-t@myseneca.ca
// Section:        NEF
// Workshop:       8 (LAB)
//==============================================
#include <iostream>
#include <cstring>
#include "Engineer.h"

using namespace std;
namespace sdds {

Engineer::Engineer(){
    m_esalary = 0;
    m_ewhours = 0;
    m_level = 0;
}

Engineer::Engineer(double salary, int whours, int level){
    if(salary > 0 && whours > 0){
        m_ewhours = whours;
        m_level = level;
        setSalary(salary);
    }else{
        m_esalary = 0;
        m_ewhours = 0;
        m_level = 0;
    }
}

Engineer::~Engineer(){
    
}

void Engineer::setSalary(double salary){
    if(m_level == MAX_LEVEL){
        m_esalary = salary + 3000;
    }else{
        m_esalary = salary;
    }
}

bool Engineer::workHours(){
    return m_ewhours == MIN_HOURS ? true : false;
}

void Engineer::bonus(){
    if(m_ewhours > MIN_HOURS && m_level == MAX_LEVEL){
        m_esalary += (m_esalary * 0.1);
    }else{
        m_esalary += (m_esalary * 0.05);
    }
}

ostream& Engineer::display(std::ostream &os) const{
    if(m_esalary > 0 && m_ewhours > 0){
        cout << "Engineer details" << endl;
        cout << "level: " << m_level << endl;
        cout << "Salary: " << m_esalary << endl;
        cout << "Working hours: "<< m_ewhours << endl;
    }else{
        cout << "Engineer is not initiated yet" << endl;
    }
    return os;
}
}
