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
#include "Motorcycle.h"
using namespace std;
namespace sdds {

Motorcycle::Motorcycle() : Vehicle(){
    sidecar = false;
}
Motorcycle::Motorcycle(const char* licensePlate, const char* makeModel) : Vehicle(licensePlate, makeModel){
        sidecar = false;
    
}


std::istream& Motorcycle::read(std::istream& istr){
    if(ReadWritable::isCsv()){
        Vehicle::read(istr);
        istr >> sidecar;
        istr.ignore(1000, '\n');
    }else{
        cout << endl;
        cout << "Motorcycle information entry" << endl;
        Vehicle::read(istr);
        cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
        char yesNo[10];
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
            sidecar = true;
        }
        //        if(YesNo == 'n' || YesNo == 'N'){
        //            carwash = false;
        //        }
                
    }
    return istr;
}
std::ostream& Motorcycle::write(std::ostream& ostr) const{
    if(isEmpty()){
        ostr << "Invalid Motorcycle Object" << endl;;
    }else{
        if(ReadWritable::isCsv()){
            ostr << "M,";
        }else{
            ostr << "Vehicle type: Motorcycle" << endl;
        }
        
        Vehicle::write(ostr);
        
        if(isCsv()){
            ostr << sidecar << endl;
        }else{
            if(sidecar == true)
                cout << "With Sidecar" << endl;

        }
    }
    
    return ostr;
}

}


