//==============================================
// Name:           Pedro Vitor do Carmo Saraiva Teixeira
// Student Number: 100036193
// Email:          pvdo-carmo-saraiva-t@myseneca.ca
// Section:        NEF
// Workshop:       3 (DIY)
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "Train.h"

using namespace std;
namespace sdds{

Cargo::Cargo(){
    this->description[0] = '\0';
    this->weight = 0;
}
Cargo::Cargo(const char* desc, double wght){
    desc = this->description;
    wght = this->weight;
}


void Train::setTrain(const char* nam, int ident){
    
    if(nam != nullptr && nam[0] != '\0' && ident >= 1){
       
        strcpy(name, nam);
        id = ident;
        
    }else{
        name[0] = '\0';
        id = 0;
    }
    cargo = nullptr;
}

bool Train::isEmpty() const{
    
    return  id == 0;
}

void Train::display() const{
    
    cout << "***Train Summary***" << endl;
    if(isEmpty()){
        cout << "This is an empty train." << endl;
    }
    else{
        cout << "Name: " << name << " ID: " << id << endl;
        if(cargo != nullptr)
        {
            
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << "Cargo: " << cargo->getDesc() << " Weight: " << cargo->getWeight() << endl;
            cout.unsetf(ios::fixed);
        }
        else{
            cout << "No cargo on this train." << endl;
        }
    }
    
}

void Train::loadCargo(Cargo cg){
    cargo = new Cargo();
    cargo->init(cg.getDesc(), cg.getWeight());
}

void Train::unloadCargo(){
    delete cargo;
    cargo = nullptr;
}

void Cargo::init(const char* desc, double wght){
    if(strlen(desc) < MAX_DESC){
        strcpy(description, desc);
    }
    weight = wght <= MAX_WEIGHT || wght >= MIN_WEIGHT ? wght : MIN_WEIGHT;
}

bool Train::swapCargo(Train& tr){
    bool suceed = false;
    
    if(cargo != nullptr || tr.cargo != nullptr){
        Cargo* temp;
        temp = cargo;
        cargo = tr.cargo;
        tr.cargo = temp;
        suceed = true;
    }
    return suceed;
}

bool Train::increaseCargo(double addWght){
    bool suceed = false;
    
    if(cargo != nullptr){
        double newWeight = cargo->getWeight() + addWght;
        if(newWeight <= MAX_WEIGHT){
            cargo->setWeight(newWeight);
            suceed = true;
        }
    }
    return suceed;
}

bool Train::decreaseCargo(double wght){
    bool suceed = false;
    
    if(cargo != nullptr){
        double newWeight = cargo->getWeight() - wght;
        if(newWeight >= MIN_WEIGHT){
            cargo->setWeight(newWeight);
            suceed = true;
        }
    }
    return suceed;
}

const char* Cargo::getDesc()const{
    //char *pDesc;
    //strcpy(description, pDesc);
    return description;
}

double Cargo::getWeight(){
    return weight;
}

void Cargo::setWeight(double newWeight){
    weight = newWeight;
}
}
