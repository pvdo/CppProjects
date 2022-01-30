//==============================================
// Name:           Pedro Vitor do Carmo Saraiva Teixeira
// Student Number: 100036193
// Email:          pvdo-carmo-saraiva-t@myseneca.ca
// Section:        NEF
// Workshop:       5 (LAB)
//==============================================

#include <cstring>
#include <iostream>
#include "Ship.h"
#include "Engine.h"

using namespace std;
namespace sdds{
Ship::Ship(){
    setEmpty();
}
Ship::Ship(const char* typ, const Engine* eng, const int nOfEng){ //do I need to allocate memory?
    setEmpty();
        if( typ[0] != '\0' && nOfEng <= 10){
        
        strcpy(type, typ);
        numberOfEngines = nOfEng;
        for(int i = 0; i < nOfEng; i++)
        engine[i] = eng[i];
       
    }
}


Ship::~Ship(){
    
}

void Ship::setEmpty(){
   // engine[0] = '\0';
    type[0] = '\0';
    numberOfEngines = 0;
}



bool Ship::empty() const{
    bool flag = false;
    if(type[0] == '\0'){
        flag = true;
    }
    return flag;
}

float Ship::calculatePower() const{
    float sum = 0;
    for(int i = 0; i < this->numberOfEngines; i++ ){
        float sizeEng = this->engine[i].get();
        sum += sizeEng * 5;
    }
    return sum;
}

void Ship::display() const{
    if(numberOfEngines == 0){
        cout << "No available data" << endl;
    }else{
    
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << this->type << (numberOfEngines >= 4? "-" : "- ") << this->calculatePower() << endl;
        for(int i = 0; i < this->numberOfEngines; i++){
            this->engine[i].display();
        }
        cout.unsetf(ios::fixed);
    }
    
}

Ship& Ship::operator+=(Engine e){
    //int flag = false;
    if(this->type[0] == '\0'){
        cout << "The ship doesn't have a type! Engine cannot be added!" << endl;
    }
    else{
        if(numberOfEngines < MAX_ENGINE ){
       
           
           this->engine[numberOfEngines] = e;
//            for(int i = 0; i < numberOfEngines + 1; i++)
//            {
//                if(this->engine[i].get() <= 0){
//                    this->engine[i] = e;
//               }
//            }
            numberOfEngines ++;
        }
        //flag = true;
    }
    return *this;
}

bool operator ==(const Ship& shipA, const Ship& shipB){
    bool flag = false;
    if(shipA.calculatePower() == shipB.calculatePower()){
        flag = true;
    }
    return flag;
}
bool operator <(const Ship& ship, double provPow){
    bool flag = false;
    
    if(ship.calculatePower() < provPow){
        flag = true;
    }
    
    return flag;
}

}
