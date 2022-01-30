//==============================================
// Name:           Pedro Vitor do Carmo Saraiva Teixeira
// Student Number: 100036193
// Email:          pvdo-carmo-saraiva-t@myseneca.ca
// Section:        NEF
// Workshop:       9 (LAB)
//==============================================
#ifndef SDDS_NUMBERSBOX_H
#define SDDS_NUMBERSBOX_H

#include <iostream>
#include <cstring>

const int MAX_NAME = 15;

namespace sdds{

template <typename T>

class NumbersBox{
    char name[MAX_NAME + 1];
    int size;
    T* items;

public:
    NumbersBox(){
        name[0] = {'\0'};
        size = 0;
        items = nullptr;
    }
    
    NumbersBox(int siz, const char* nam){
        
        if(siz > 0 && nam != nullptr && nam[0] != '\0'){
            size = siz;
            strcpy(name, nam);
            items = new T[size];

        }else{
            name[0] = {'\0'};
            size = 0;
            items = nullptr;
        }
    }
    ~NumbersBox() {
         delete[] items;
         items = nullptr;
     }
    
    T& operator [](int i){
        return items[i];
    }

    NumbersBox<T>& operator*=(const NumbersBox<T>& other){

        if(size == other.size && items != nullptr && other.items != nullptr){
            for(int i = 0; i < size; i++){
                items[i] *= other.items[i];
            }
        }
        return *this;
    }
    
    NumbersBox<T>& operator+=(T num){
       if (size != 0) {
           if (items != nullptr){
               T* temp;
               temp = new T[size];
               for(int i = 0; i < size; i++){
                    temp[i] = items[i];
               }
            
               delete [] items;
               items = nullptr;
               items = new T[size + 1];
               
               for(int i = 0; i < size; i++){
                    items[i] = temp[i];
                }
               
               delete [] temp;
               temp = nullptr;
               
               items[size] = num;
                
               size ++;
           }
       }
         return *this;
    }
    
    std::ostream& display(std::ostream& os) const{
        if(name[0] == '\0' || size == 0 || items == nullptr){
            os << "Empty Box" << std::endl;
        }else{
            os << "Box name: " << name << std::endl;
            for(int i = 0; i < size; i++){
                if(i == size - 1 ){
                    os << items[i];
                }else{
                    os << items[i] << ", ";
                }
            }
            os << std::endl;
        }
        return os;
    }
    

};
template<typename T>
std::ostream& operator<<(std::ostream& os, NumbersBox<T>& box){
    box.display(os);
    return os;
}
}




#endif
