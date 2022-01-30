
#include "Saiyan.h"
#include <iostream>
#include <cstring>
#include "Utils.h"

using namespace std;
namespace sdds{
Saiyan::Saiyan(){
    setEmpty();
}

Saiyan::Saiyan(const char* nam, int birth, int pow){
    if( nam != nullptr && nam[0] != '\0' && birth < 2020 && pow > 0){
        set(nam, birth, pow);
    }else{
        setEmpty();
    }
}
Saiyan::~Saiyan(){
    delete [] m_name;
    m_name = nullptr;
}

bool Saiyan::isSuper() const{
    return m_super ? true : false;
}
bool Saiyan::isValid() const{
    bool flag = false;
    if(m_name[0] != '\0' && m_dob < 2020 && m_power > 0){
        flag = true;
    }
    return flag;
}
void Saiyan::setEmpty(){
    m_name[0] = '\0';
    m_dob = 0;
    m_power = 0;
    m_super = false;
}
void Saiyan::display() const{
    if(this->isValid()){
        
        cout << m_name << endl;
        cout << "DOB: " << m_dob << " Power: " << m_power << endl;
        cout << "Super Saiyan Ability:" << (isSuper() ? "Super Saiyan. ":"Not super Saiyan.") << endl;
        cout << endl;
    }
    else{
        cout << "Invalid Saiyan!" << endl;

    }
}
void Saiyan::set(const char* name, int dob, int power, bool super){
    if(this->m_name == nullptr && name[0] != '\0' && dob < 2020 && power > 0){
        strcpy(m_name, name);
        m_dob = dob;
        m_power = power;
        m_super = super;
    }else{
        setEmpty();
    }
}
//void Saiyan::set(const char* name, int dob, int power){
//    if(name[0] != '\0' || dob < 2020 || power > 0){
//        strcpy(m_name, name);
//        m_dob = dob;
//        m_power = power;
//        m_super = false;
//    }else{
//        setEmpty();
//    }
//}

bool Saiyan::hasLost(const Saiyan& other) const{
    bool flag;
    flag = this->m_power > other.m_power ? false : true;
    if(!this->isValid() || !other.isValid()){
        flag = false;
    }
    return flag;
}
}
