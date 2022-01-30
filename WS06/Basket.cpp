//==============================================
// Name:           Pedro Vitor do Carmo Saraiva Teixeira
// Student Number: 100036193
// Email:          pvdo-carmo-saraiva-t@myseneca.ca
// Section:        NEF
// Workshop:       6 (LAB)
//==============================================

#include <iostream>
#include <cstring>
#include "Basket.h"

using namespace std;
namespace sdds{

Basket::Basket(){
    m_fruit = nullptr;
    m_qty = 0;
    m_price = 0;
}

Basket::Basket(const char* fruit, int qty, double price){
    if(fruit != nullptr && fruit[0] != '\0' && qty > 0 && price >= 0){
        int size = strlen(fruit);
        m_fruit = new char[size + 1];
        strcpy(m_fruit, fruit);
        m_fruit[size] = '\0';
        
        m_qty = qty;
        m_price = price;
    }else{
        m_fruit = nullptr;
        m_qty = qty;
        m_price = price;
    }
}

Basket::Basket(const Basket& bsk){
    init(bsk);

}
Basket::~Basket(){
    delete [] m_fruit;
}

void Basket::init(const Basket& bsk){
    //Shallow Copies
    m_qty = bsk.m_qty;
    m_price = bsk.m_price;
    
    //Allocate memory for name
    if(bsk.m_fruit != nullptr){
        int size = strlen(bsk.m_fruit);
        m_fruit = new char[size + 1];
        strcpy(m_fruit, bsk.m_fruit);
        m_fruit[size] = '\0';
    }else{
        m_fruit = nullptr;
    }
}

void Basket::setName(const char *fruit){
    if(fruit != nullptr && fruit[0] != '\0'){
        delete [] m_fruit;
        int size = strlen(fruit);
        m_fruit = nullptr;
        m_fruit = new char[size + 1];
        strcpy(m_fruit, fruit);
        m_fruit[size] = '\0';
    }
}

void Basket::setQty(int qty){
    if(qty >= 0)
        m_qty = qty;
}

void Basket::setPrice(double price){
    if(price > 0)
        m_price = price;
}

bool Basket::isEmpty() const{
    bool flag = m_fruit == nullptr? true : false;
    return flag;
}

bool Basket::addPrice(double price){
    bool flag = false;
    if(price > 0){
        m_price += price;
        flag = true;
    }
    return flag;
}

ostream& Basket::display(std::ostream &os) const{
    if(isEmpty()){
        os << "This Basket has not yet been filled" << endl;
    }else{
        os << "Basket Details" << '\n';
        os << "Name: " << m_fruit << '\n';
        os << "Quantity: " << m_qty << '\n';
        os.setf(ios::fixed);
        os.precision(2);
        os << "Price: " << m_price << endl;
        os.unsetf(ios::fixed);
    }
    return os;
}

Basket& Basket::operator=(const Basket &bsk){
    //check for self-assignment
    if(this != &bsk){
        delete [] m_fruit;
        init(bsk);
    }
    return *this;
}
//0x0000000100704e00

bool Basket::operator==(const Basket& bsk){
    bool flag = false;
    int compare = strcmp(this->m_fruit, bsk.m_fruit);
    if(compare == 0 && this->m_qty == bsk.m_qty && this->m_price == bsk.m_price){
        flag = true;
    }
    
    return flag;
}

bool Basket::operator!=(const Basket& bsk){
    bool flag = false;
    if(this->m_fruit != bsk.m_fruit || this->m_qty == bsk.m_qty || this->m_price != bsk.m_price)
        flag = true;
    
    return flag;
}

ostream& operator<<(std::ostream& os, const Basket& bsk){
    bsk.display(os);
    return os;
}
}

