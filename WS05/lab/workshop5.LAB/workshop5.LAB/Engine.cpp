//==============================================
// Name:           Pedro Vitor do Carmo Saraiva Teixeira
// Student Number: 100036193
// Email:          pvdo-carmo-saraiva-t@myseneca.ca
// Section:        NEF
// Workshop:       5 (LAB)
//==============================================


#include <iostream>
#include <cstring>
#include "Engine.h"

using namespace std;
namespace sdds{

Engine::Engine(){
    setEmpty();
}
Engine::Engine(const char *typ, double siz){
    setEmpty();
    set(typ, siz);
}
Engine::~Engine(){
        
}
    
void Engine::setEmpty(){
    this->size = 0;
    this->type[0] = '\0';
}

void Engine::set(const char *typ, double siz){
    if(typ[0] != '\0' && siz > 0 ){
        
        strcpy(this->type, typ);
        this->size = siz;
    }
}
double Engine::get() const{
    return this->size;
}

void Engine::display() const{
    cout << size << " liters - " << type << endl;
    }
}

