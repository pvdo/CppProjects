//==============================================
// Name:           Pedro Vitor do Carmo Saraiva Teixeira
// Student Number: 100036193
// Email:          pvdo-carmo-saraiva-t@myseneca.ca
// Section:        NEF
// Workshop:       8 (LAB)
//==============================================
#include <iostream>
#include <cstring>
#include "Doctor.h"

using namespace std;
namespace sdds {
Doctor::Doctor(){
    m_type[0] = '\0';
    m_salary = 0;
    m_whours = 0;
    m_specialist = false;
}

Doctor::Doctor(const char* type, double salary, int whours, bool specialist){
    if(salary > 0 && whours > 0){
        strcpy(m_type, type);
        m_whours = whours;
        m_specialist = specialist;
        setSalary(salary);
    }else{
        m_type[0] = '\0';
        m_salary = 0;
        m_whours = 0;
        m_specialist = false;
    }
}
Doctor::~Doctor(){
    
}
void Doctor::setSalary(double salary){
    if(m_specialist == true){
        m_salary = salary + 2000;
    }else{
        m_salary = salary;
    }
}

bool Doctor::workHours(){
    return m_whours == MIN_W_HOURS? true : false;
}

void Doctor::bonus(){
    if(m_whours > MIN_W_HOURS){
        m_salary += (m_salary*0.1);
    }else{
        m_salary += (m_salary*0.05);
    }
}
ostream& Doctor::display(ostream& os) const{
    if(m_salary > 0 && m_whours > 0){
        cout << "Doctor details" << endl;
        cout << "Doctor Type: " << m_type << endl;
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << "Salary: " << m_salary << endl;
        cout << "Working Hours: " << m_whours << endl;
    }else{
        cout << "Doctor is not initiated yet" << endl;
    }
    
    return os;
}
}

