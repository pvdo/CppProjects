#include <iostream>
#include <cstring>
#include "Vehicle.h"

using namespace std;
namespace sdds {
Vehicle::Vehicle(){
    m_speed = 0;
    m_numberOfSeats = 0;
}
Vehicle::Vehicle(int speed, int noOfSeats){
    if(speed >= MIN_SPEED && noOfSeats > 0){
        m_speed = speed;
        m_numberOfSeats = noOfSeats;
    }else{
        m_speed = 0;
        m_numberOfSeats = 0;
    }
}
bool Vehicle::finetune(){
    bool flag;
    if(m_speed > MAX_SPEED){
        m_speed = MIN_SPEED;
        flag = true;
    }else{
        cout << "The car cannot be tuned" << endl;
        flag = false;
    }
    return flag;
}
ostream& Vehicle::display(std::ostream& os) const{
    if(m_speed >= MIN_SPEED && m_numberOfSeats > 0){
        os << "|" << m_speed << "|" << m_numberOfSeats << endl;
    }
    if(m_speed > MAX_SPEED){
        os << "Car has to be fine tuned for speed limit" << endl;
    }
    if(m_speed == 0){
        os << "This Car is not initiated" << endl;
    }
    
    return os;
}
istream& Vehicle::input(std::istream& in){
    int tempSpeed;
    int tempSeats;
    cout << "Enter the Vehicle`s speed: ";
    in >> tempSpeed;
    cout << "Enter no of seats: ";
    in >> tempSeats;
    
    *this = Vehicle(tempSpeed, tempSeats);
    
    return in;
    
}
    
ostream& operator<<(std::ostream& os, const Vehicle& v){
    v.display(os);
    return os;
}
istream& operator>>(std::istream& in, Vehicle& v){
    v.input(in);
    return in;
}
}

