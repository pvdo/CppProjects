#include <iostream>
#include <cstring>
#include <iomanip>
#include "Vehicle.h"
#include "Car.h"


using namespace std;
namespace sdds {
Car::Car(){
    m_carType[0] = '\0';
    m_regYear = 0;
}
Car::Car(const char* type, int year, int speed, int noOfSeats) : Vehicle (speed, noOfSeats){
    if(strlen(type) <= MAX_CHAR + 1 && year >= MIN_YEAR){
        strcpy(m_carType, type);
        m_regYear = year;
    }else{
        m_carType[0] = '\0';
        m_regYear = 0;
    }
}
    
void Car::finetune(){
    if(m_regYear < MIN_YEAR){
        cout << "Car cannot be tuned and has to be scraped" << endl;
    }else{
        Vehicle::finetune();
        cout << "This car is finely tuned to default speed" << endl;
    }
}
ostream& Car::display(std::ostream& os) const{
    if(m_carType[0] == '\0'){
        cout << "Car is not initiated yet" << endl;
    }else{
        cout.width(20);
        cout.setf(ios::left);
        cout << m_carType;
        cout.unsetf(ios::left);
        cout << m_regYear;
        Vehicle::display(os);
        
    }
    return os;
}
istream& Car::input(std::istream& in){
    char tempType[MAX_CHAR + 1];
    cout << "Enter the car type: ";
    in.getline(tempType, MAX_CHAR + 1);
    
    int tempYear;
    cout << "Enter the car registration year: ";
    in >> tempYear;
    
    if(tempYear >= MIN_YEAR){
        strcpy(m_carType, tempType);
        m_regYear = tempYear;
    }
     Vehicle::input(in);
    
    return in;
}
    
ostream& operator<<(std::ostream& os, const Car& c){
    c.display(os);
    return os;
    
}
istream& operator>>(std::istream& in, Car& c){
    c.input(in);
    return in;
}
}
