#ifndef SDDS_CAR_H
#define SDDS_CAR_H

namespace sdds{

const int MAX_CHAR = 20;
const int MIN_YEAR = 2000;
class Car : public Vehicle{
    char m_carType[MAX_CHAR + 1];
    int m_regYear;
    
public:
    Car();
    Car(const char*, int, int, int);
    
    void finetune();
    std::ostream& display(std::ostream& os) const;
    std::istream& input(std::istream& in);
    
};

std::ostream& operator<<(std::ostream& os, const Car& c);
std::istream& operator>>(std::istream& in, Car& c);
}
#endif
