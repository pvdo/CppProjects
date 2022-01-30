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
Ship::Ship(const char *typ, Engine *en, int noOfEn){ //do I need to allocate memory?
   // setEmpty();
    if(typ != nullptr && typ[0] != '\0'  && strlen(typ) <= 6 && en != nullptr && noOfEn <= 10 && noOfEn >= 0){
//    delete [] this->type;
//    delete [] this->engine;
//    this->type = nullptr;
//    this->engine = nullptr;
    
    this->type = new char[strlen(typ) + 1];
    for(int i = 0; i < strlen(typ) + 1; i++){
        type[i] = typ[i];
    }
  //  strcpy(this->type, typ);
    this->type[strlen(typ)] = '\0';
    
    numberOfEngines = noOfEn;
    this->engine = new Engine[numberOfEngines];
    for(int i = 0; i < numberOfEngines; i++){
        this->engine[i] = en[i];
    }
    
   
    }
}


Ship::~Ship(){
    delete [] engine;
    delete [] type;
    engine = nullptr;
    type = nullptr;
    
}

void Ship::setEmpty(){
    engine = nullptr;
    type = nullptr;
    numberOfEngines = 0;
    distance = 0;
}

//void Ship::set(const char* typ, Engine * en, int noOfEn){
//
//    if(typ != nullptr && typ[0] != '\0'  && strlen(typ) <= 6 && en != nullptr && noOfEn <= 10 && noOfEn >= 0){
//        int size = strlen(typ);
//        delete [] type;
//        delete [] engine;
//        type = nullptr;
//        engine = nullptr;
//
//        type = new char(size + 1);
//        strcpy(type, typ);
//        type[size] = '\0';
//
//        engine = new Engine[numberOfEngines];
//        for(int i = 0; i < noOfEn; i++){
//            engine[i] = en[i];
//        }
//        numberOfEngines = noOfEn;
//
//    }
//
//}

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
        cout << this->type << (numberOfEngines > 3? "-" : "- ")  << this->calculatePower() << endl;
        for(int i = 0; i < this->numberOfEngines; i++){
            this->engine[i].display();
        }
        cout.unsetf(ios::fixed);
    }
    
}

Ship& Ship::operator+=(Engine e){
   
    if(this->type != nullptr){
        if(numberOfEngines < MAX_ENGINE ){
            Engine *temp;
            temp = nullptr;
            temp = new Engine[numberOfEngines + 1];
            for(int i = 0; i < numberOfEngines; i++){
                temp[i] = engine[i];
            }

            delete [] engine;
            engine = nullptr;
            engine = new Engine[numberOfEngines + 1];

            for(int i = 0; i < numberOfEngines; i++){
                engine[i] = temp[i];
            }

            delete [] temp;

            this->engine[numberOfEngines] = e;
            numberOfEngines ++;
       }
    }else{
        cout << "The ship doesn't have a type! Engine cannot be added!" << endl;
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
