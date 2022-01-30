//==============================================
// Name:           Pedro Vitor do Carmo Saraiva Teixeira
// Student Number: 100036193
// Email:          pvdo-carmo-saraiva-t@myseneca.ca
// Section:        NEF
// Workshop:       6 (LAB)
//==============================================

#ifndef SDDS_BASKET_HEADER
#define SDDS_BASKET_HEADER

#include <iostream>
namespace sdds{

class Basket{
    char *m_fruit;
    int m_qty; //not less than one
    double m_price; //not less than zero
    
public:
    Basket();
    Basket(const char*, int, double);
    Basket(const Basket& bsk);
    ~Basket();
    void init(const Basket&);
    void setName(const char*);
    void setQty(int);
    void setPrice(double);
    bool isEmpty() const;
    bool addPrice(double);
    std::ostream& display(std::ostream& os) const;
    Basket& operator=(const Basket&);
    bool operator==(const Basket&);
    bool operator!=(const Basket&);
    
};

std::ostream& operator<<(std::ostream& os, const Basket& bsk);

}



#endif /* Basket_hpp */
