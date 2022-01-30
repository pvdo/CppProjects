//==============================================
// Name:           Pedro Vitor do Carmo Saraiva Teixeira
// Student Number: 100036193
// Email:          pvdo-carmo-saraiva-t@myseneca.ca
// Section:        NEF
// Workshop:       4 (DIY)
//==============================================
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
    setEmpty();
    set(nam, birth, pow);
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
    if(  m_name != nullptr && m_name[0] != '\0' && m_dob < 2020 && m_power > 0 && m_level >= 0){
        flag = true;
    }
    return flag;
}
void Saiyan::setEmpty(){
    m_name = nullptr;
    m_dob = 0;
    m_power = 0;
    m_super = false;
    m_level = 0;
}
void Saiyan::display() const{
    if(this->isValid()){
        
        cout << m_name << endl;
        cout << "DOB: " << m_dob << " Power: " << m_power << endl;
        cout << "Super Saiyan Ability:" << (isSuper() ? " Super Saiyan.":" Not super Saiyan.") << endl;
        if(m_level <= 0 )
        {
            cout << endl;
        }
        
        if(m_level > 0){
        cout << "Super Saiyan level is: " << m_level << endl;
        }
        //cout << endl;
    }
    else{
        cout << "Invalid Saiyan!" << endl;

    }
}
void Saiyan::set(const char* name, int dob, int power, int level, bool super){

    if(name != nullptr && name[0] != '\0' && dob < 2020 && power > 0){
        
     //   if(m_name != nullptr){
            delete [] m_name;
       // }
        
        int size = strlen(name);
        m_name = new char[size + 1];
        strcpy(m_name, name);
        m_name[size] = '\0';
        
        
        m_dob = dob;
        m_power = power;
        m_super = super;
        if(isSuper())
            m_level = level;
                
    }else{
        setEmpty();
    }
}


bool Saiyan::hasLost(Saiyan& other){
    bool flag;
    this->powerup();
    other.powerup();
    flag = this->m_power > other.m_power ? false : true;
    if(!this->isValid() || !other.isValid()){
        flag = false;
    }
    return flag;
}

void Saiyan::powerup(){
    if(this->isSuper())
    {
        this->m_power = this->m_power * (this->m_level + 1);
    }
}
}
