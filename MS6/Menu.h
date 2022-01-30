/* Citation and Sources...
Final Project Milestone 6
Module: Menu
Filename: Menu.h
Version 1.0
Author Pedro Vitor do Carmo Saraiva Teixeira
Revision History
-----------------------------------------------------------
Date Reason
2020/04/05 Preliminary release
2020/04/05 Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>

namespace sdds{
const int MAX_NO_OF_ITEMS = 10;

class MenuItem{
    char *m_item;
    MenuItem();
    MenuItem(const char*);
    std::ostream& display(std::ostream& os) const;
    MenuItem(const MenuItem& menuItem) = delete;
    MenuItem& operator=(const MenuItem& menuItem) = delete;
    ~MenuItem();
    
    friend class Menu;
};


class Menu{
    char *m_title;
    MenuItem *m_menuItems[MAX_NO_OF_ITEMS];
    int m_indentation;
    int noOfItems;
    
public:
    Menu();
    Menu(const char*, int = 0);
    Menu(const Menu& menu);
    Menu& operator=(const Menu& menu);
    operator bool() const;
    bool isEmpty() const;
    std::ostream& display(std::ostream& os = std::cout) const;
    Menu& operator=(const char*);
    void add(const char*);
    int run() const;
    operator int() const;
    Menu& operator <<(const char*);
   // Menu(int);
    ~Menu();
    
    //-----Other function----//
    void init(const Menu& menu);
    void setEmpty();
    
};

//std::ostream& operator<<(Menu&, const char*);
}



#endif


