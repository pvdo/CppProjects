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
#include "Car.h"
using namespace std;
namespace sdds {


Car::Car(){
    carwash = false;
    setEmpty();
}

Car::Car(const char* licensePlate, const char* makeModel):Vehicle(licensePlate, makeModel){
    if(licensePlate == nullptr  || makeModel == nullptr || licensePlate[0] == '\0' ||  makeModel[0] == '\0' || strlen(makeModel) < 2 || strlen(licensePlate) > 8){
        carwash = false;
    }
}

std::istream& Car::read(std::istream& istr){
    if(ReadWritable::isCsv()){
        Vehicle::read(istr);
        istr >> carwash;
        istr.ignore(1000, '\n');
    }else{
        char yesNo[10] = {'\0'};
        cout << endl;
        cout << "Car information entry" << endl;
        Vehicle::read(istr);
        cout << "Carwash while parked? (Y)es/(N)o: ";
        do{
            
            istr >> yesNo;
            if((yesNo[0] != 'y' && yesNo[0] != 'Y' && yesNo[0] != 'n' && yesNo[0] != 'N')|| yesNo[1] != '\0'){
                cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                for(int i = 0; i < 10; i++){
                    yesNo[i] = '\0';
                }
                istr.ignore(10, '\n');
                istr.clear();
            }
        }while((yesNo[0] != 'y' && yesNo[0] != 'Y' && yesNo[0] != 'n' && yesNo[0] != 'N')|| yesNo[1] != '\0');
        if(yesNo[0] == 'y' || yesNo[0] == 'Y'){
            carwash = true;
        }
//        if(YesNo == 'n' || YesNo == 'N'){
//            carwash = false;
//        }
        
    }
    
    return istr;
}
std::ostream& Car::write(std::ostream& ostr) const{
    if(isEmpty()){
        ostr << "Invalid Car Object" << endl;;
    }else{
        if(ReadWritable::isCsv()){
            ostr << "C,";
        }else{
            ostr << "Vehicle type: Car" << endl;
        }
        
        Vehicle::write(ostr);
        
        if(ReadWritable::isCsv()){
            ostr << carwash << endl;
        }else{
            if(carwash == true)
                cout << "With Carwash" << endl;
            else
                cout << "Without Carwash" << endl;
        }
    }
    
    return ostr;
}


}

