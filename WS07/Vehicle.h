#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H

namespace sdds{

const int MIN_SPEED = 100;
const int MAX_SPEED = 140;
class Vehicle{
    int m_speed;
    int m_numberOfSeats;

public:
    Vehicle();
    Vehicle(int, int);
    bool finetune();
    std::ostream& display(std::ostream& os) const;
    std::istream& input(std::istream& in);
    
};
std::ostream& operator<<(std::ostream& os, const Vehicle& v);
std::istream& operator>>(std::istream& in, Vehicle& v);
}


#endif
