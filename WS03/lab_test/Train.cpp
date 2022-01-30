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
#include <string.h>
#include "Train.h"

using namespace std;
namespace sdds{

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
            cout << "Cargo: " << cargo->description << " Weight: " << cargo->weight << endl;
        }
        else{
            cout << "No cargo on this train." << endl;
        }
    }
    
}

void Train::loadCargo(Cargo cg){
    cargo = new Cargo;
    strcpy(cargo->description, cg.description);
    cargo->weight = cg.weight;
    
}

void Train::unloadCargo(){
    delete cargo;
    cargo = nullptr;
}
}
