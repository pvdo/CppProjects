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
#include <iostream>
#include <cstring>
#include "Menu.h"

using namespace std;

namespace sdds{

//-----------------------MENU ITEM-------------------//
MenuItem::MenuItem(){
    m_item = nullptr;
}

MenuItem::MenuItem(const char* item){
    if(item != nullptr && item[0] != '\0'){
        m_item = new char[strlen(item) + 1];
        strcpy(m_item, item);
        m_item[strlen(item)] = '\0';
    }else{
        m_item = nullptr;
    }
}

ostream& MenuItem::display(std::ostream &os) const{
    if(m_item != nullptr && m_item[0] != '\0'){
        os << m_item << endl;
    }
    return os;
}

MenuItem::~MenuItem(){
    delete [] m_item;
    m_item = nullptr;
}

//------------------------MENU--------------------//
    
Menu::Menu(){
    m_title = nullptr;
    noOfItems = 0;
    m_indentation = 0;
    for(int i = 0; i < MAX_NO_OF_ITEMS; i ++){
        m_menuItems[i] = nullptr;
    }
    
}

Menu::Menu(const char* title, int indent){
    if(title != nullptr && title[0] != '\0'){
        m_title = new char[strlen(title) + 1];
        strcpy(m_title, title);
        m_title[strlen(title)] = '\0';
        for(int i = 0; i < MAX_NO_OF_ITEMS; i ++){
            m_menuItems[i] = nullptr;
            //m_menuItems[i]->m_item = nullptr;
        }
         m_indentation = indent;
    }else{
        setEmpty();
    }

   
    noOfItems = 0;
    
}
    
void Menu::setEmpty(){
    delete [] m_title;
    m_title = nullptr;
  
    for(int i = 0; i < noOfItems; i ++){
       // delete m_menuItems[i]->m_item;
       // m_menuItems[i]->m_item = nullptr;
        delete m_menuItems[i];
        m_menuItems[i] = nullptr;
    }
    m_indentation = 0;
    noOfItems = 0;
}
void Menu::init(const Menu& menu){
    //Shallow Copy
    m_indentation = menu.m_indentation;
    noOfItems = menu.noOfItems;
    
    //Allocate Memory
    if(menu.m_title != nullptr){
        m_title = new char[strlen(menu.m_title) + 1];
        strcpy(m_title, menu.m_title);
        m_title[strlen(menu.m_title)] = '\0';
    
        for(int i = 0; i < noOfItems; i++){
            m_menuItems[i] = new MenuItem (menu.m_menuItems[i]->m_item);
            //m_menuItems[i]->m_item = menu.m_menuItems[i]->m_item;
        }
    }
}

Menu::Menu(const Menu& menu){
    if(menu.m_title == nullptr || menu.m_title[0] == '\0')
        setEmpty();
    else
        init(menu);
}

Menu& Menu::operator=(const Menu& menu){
    //Check self-assignment
    if(this != &menu){
        setEmpty();
        init(menu);
    }
    return *this;
}

Menu::operator bool() const{
   bool choice = true;
    if(isEmpty())
        choice = false;
    return choice;
}

bool Menu::isEmpty() const{
    bool flag = false;
    if(m_title == nullptr || m_title[0] == '\0')
        flag = true;
    
    return flag;
}

Menu& Menu::operator=(const char* title){
    if(title != nullptr && title[0] != '\0'){
        delete [] m_title;
        m_title = nullptr;
        m_title = new char[strlen(title) + 1];
        strcpy(m_title, title);
        m_title[strlen(title)] = '\0';
    }else{
        setEmpty();
        
    }
    return *this;
}

void Menu::add(const char* item){
    if(item == nullptr || item[0] == '\0'){
        setEmpty();
    }else{
        if(noOfItems < MAX_NO_OF_ITEMS){
            delete m_menuItems[noOfItems];
            m_menuItems[noOfItems] = nullptr;
            m_menuItems[noOfItems] = new MenuItem(item);
            noOfItems ++;
        }
    }
    
}

std::ostream& Menu::display(std::ostream& os) const{
    if(isEmpty()){
        cout << "Invalid Menu!" << endl;
    }
    else if(m_menuItems[0] == nullptr){
        cout.width((4 * m_indentation) + strlen(m_title));
        cout << m_title << '\n';
        cout << "No Items to display!" << endl;
    }else{
        if(m_indentation > 0){
            cout.width((4 * m_indentation) + strlen(m_title));
        }
        cout << m_title << '\n';
        
            char ind[50] = {'\0'};
            for(int i = 0; i < m_indentation; i++){
                strcat(ind, "    ");
            }
        for(int i = 0; i < noOfItems; i++){
            cout << ind << i + 1 << "- " << m_menuItems[i]->m_item << '\n';
        }
        cout << ind << "> ";
    }
    return os;
}

int Menu::run() const{
    display();
    int select = 0;
    if(m_menuItems[0] != nullptr){
        cin >> select;
        
        while (cin.fail() || (select <= 0 || select > noOfItems)) {
            if(cin.fail()){
                cout << "Invalid Integer, try again: ";
            }
            if((select <= 0 || select > noOfItems) && !cin.fail()){
            cout << "Invalid selection, try again: ";
            }
            cin.clear();
            cin.ignore(2000, '\n');

            cin >> select;


        }
        cin.ignore(9999, '\n');
    }
    return select;
}

Menu::operator int() const{
    return run();
}

Menu& Menu::operator<<(const char* addItem){
    if(addItem != nullptr && m_title != nullptr){
        this->add(addItem);
    }else{
        setEmpty();
        
    }
    return *this;
}
Menu::~Menu(){
    delete [] m_title;
    m_title = nullptr;
    for(int i = 0; i < noOfItems; i++){
        delete m_menuItems[i];
        m_menuItems[i] = nullptr;
    }
}
    
} //namespace close brackets


