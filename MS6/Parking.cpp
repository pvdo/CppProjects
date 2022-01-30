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
#include <fstream>
#include <fstream>
#include "Parking.h"

using namespace std;
namespace sdds{



Parking::Parking(){
    m_filename = nullptr;
    m_numberSpots = 0;
    m_numberVehicle = 0;
    for(int i = 0; i < MAX_SPOTS; i ++){
        m_parkingSpots[i] = nullptr;
    }
}

Parking::Parking(const char* filename, int numberSpots){
    m_filename = nullptr;
    m_numberVehicle = 0;
    m_numberSpots = 0;
    for (int i = 0; i < MAX_SPOTS; i++)
    {
        m_parkingSpots[i] = nullptr;
    }
    if( filename == nullptr || filename[0] =='\0'){
        m_filename = nullptr;
    }else{
        m_filename = new char[strlen(filename) + 1];
        strcpy(m_filename, filename);
    }
    if(numberSpots < 10 || numberSpots > MAX_SPOTS)
    {
        m_numberSpots = 0;
        m_numberVehicle = 0;
    }else{
        m_numberSpots = numberSpots;
        m_numberVehicle = 0;
    }
        if(loadDataFile()){
            m_parkingMenu = Menu("Parking Menu, select an action:", 0);
            m_vehicleMenu = Menu("Select type of the vehicle:", 1);

            m_parkingMenu.add("Park Vehicle");
            m_parkingMenu.add("Return Vehicle");
            m_parkingMenu.add("List Parked Vehicles");
            m_parkingMenu.add("Close Parking (End of day)");
            m_parkingMenu.add("Exit Program");

            m_vehicleMenu.add("Car");
            m_vehicleMenu.add("Motorcycle");
            m_vehicleMenu.add("Cancel");

//            m_parkingMenu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Close Parking (End of day)" << "Exit Program";
//
//            m_vehicleMenu << "Car" << "Motorcycle" << "Cancel";
        }else{
            cout << "Error in data file" << endl;
            if(m_filename != nullptr){
                delete[] m_filename;
                m_filename = nullptr;
            }
            m_numberSpots = 0;
            m_numberVehicle = 0;
    }

}
Parking::~Parking(){
    saveDataFile();

    delete [] m_filename;
    m_filename = nullptr;

    for (int i = 0; i < MAX_SPOTS; i++)
    {
        if (m_parkingSpots[i] != nullptr)
        {
            delete m_parkingSpots[i];
            m_parkingSpots[i] = nullptr;
        }
    }
}

bool Parking::isEmpty() const{
    return m_filename == nullptr || m_filename[0] == '\0'? true : false;
}
void Parking::parkingStatus() const{
    cout << "****** Seneca Valet Parking ******" << endl;
    cout << "*****  Available spots: ";
    cout.width(4);
    cout.setf(ios::left);
    cout << m_numberSpots - m_numberVehicle << " *****" << endl;
    cout.unsetf(ios::left);
}


void Parking::parkingVehicle(){
   if (m_numberVehicle == m_numberSpots)
    {
        cout << "Parking is full" << endl;
    }
    else
    {
        int num = m_vehicleMenu.run();
        if (num == 1)
        {
            
            for (int i = 0; i < m_numberSpots; i++)
            {
                if (m_parkingSpots[i] == nullptr)
                {
                    m_parkingSpots[i] = new Car();
                    m_parkingSpots[i]->setCsv(false);
                    m_parkingSpots[i]->read(std::cin);

                    //write parking ticket
                    m_parkingSpots[i]->setParkingSpot(i + 1);
                    cout << endl;
                    cout << "Parking Ticket" << endl;
                    m_parkingSpots[i]->write(std::cout);
                    cout << endl;
                    //end loop
                    i = 100;
                    
                    //add to counter
                    m_numberVehicle++;
                }
            }
            

        }
        else if (num == 2)
        {
            for (int i = 0; i < m_numberSpots; i++)
            {
                if (m_parkingSpots[i] == nullptr)
                {
                    m_parkingSpots[i] = new Motorcycle();
                    m_parkingSpots[i]->setCsv(false);
                    m_parkingSpots[i]->read(std::cin);
                
                    //write out parking ticket
                    m_parkingSpots[i]->setParkingSpot(i + 1);
                    cout << endl;
                    cout << "Parking Ticket" << endl;
                    m_parkingSpots[i]->write(std::cout);
                    cout << endl;
                    //end loop
                    i = 100;
                    
                    //add to counter
                    m_numberVehicle++;
                }
            }
                    
            
        }
        else if (num == 3)
        {
            cout << "Parking cancelled" << endl;
        }
    }
}


void Parking::returnVehicle(){
    char licensePlate[9];
    bool match = false;
    int length = 0;
    cout << "Return Vehicle" << endl;
    cout << "Enter Licence Plate Number: ";

    do{
        cin.get(licensePlate, 9);
        cin.clear();
        cin.ignore(1000, '\n');

        if(strlen(licensePlate) > 8 || cin.fail()){
            cout << "Invalid Licence Plate, try again: ";
        }
    }while(strlen(licensePlate) > 8 || strlen(licensePlate) < 1 || cin.fail());

    length = strlen(licensePlate);
    for (int i = 0; i < length; i++)
    {
        licensePlate[i] = toupper(licensePlate[i]);
    }

    for(int i = 0; i < m_numberSpots; i++){
        if(m_parkingSpots[i] != nullptr && *m_parkingSpots[i] == licensePlate){
            match = true;
            cout << endl;
            cout << "Returning: " << endl;
            m_parkingSpots[i]->setCsv(false);
            m_parkingSpots[i]->write(cout);
            delete m_parkingSpots[i];
            m_parkingSpots[i] = nullptr;
            m_numberVehicle--;
        }
    }
    if(match == false){
        cout << "License plate " << licensePlate << "Not Found" << endl;
    }
    cout << endl;
}



void Parking::listParkedVehicle() const{

    cout << "*** List of parked vehicles ***" << endl;
    for(int i = 0; i <= m_numberVehicle; i++){
           if(m_parkingSpots[i] != nullptr){
               m_parkingSpots[i]->setCsv(false);
               cout << *m_parkingSpots[i];
               cout << "-------------------------------" << endl;
           }
    }

}
bool Parking::closeParking(){
    bool flag = false;
        char yesNo[4] = { 0 };
        if (m_numberVehicle == 0)
        {
            cout << "Closing Parking" << endl;
            flag = true;
        }
        else
        {
            cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
            cout << "Are you sure? (Y)es/(N)o: ";

            //yes no
            bool check = false;
            do
            {
                cin >> yesNo;

                if (strlen(yesNo) == 1)
                {
                    if (yesNo[0] == 'Y' || yesNo[0] == 'y')
                    {
                        check = true;
                    }
                    else if (yesNo[0] == 'N' || yesNo[0] == 'n')
                    {
                        check = true;
                    }
                    else
                    {
                        cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                    }
                }
                else
                {
                    cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
                }

            } while (!check);


            if (yesNo[0] == 'Y' || yesNo[0] == 'y')
            {
                flag = true;
                cout << "Closing Parking" << endl;
                for (int i = 0; i < m_numberSpots; i++)
                {
                    if (m_parkingSpots[i] != nullptr)

                    {    cout << endl;
                        cout << "Towing request" << endl;
                        cout << "*********************" << endl;
                        m_parkingSpots[i]->write(std::cout);
                        delete m_parkingSpots[i];
                        m_parkingSpots[i] = nullptr;
                        m_numberVehicle--;
                        
                    }
                }
                saveDataFile();
            }
            else if (yesNo[0] == 'N' || yesNo[0] == 'n')
            {
                cout << "Aborted!" << endl;
                flag = false;
                
            }

        }
    return flag;
}

bool Parking::exitParking() const{
    char yesNo[4];
    bool flag = false;
    bool flagYesNo = false;
    cout << "This will terminate the program!" << endl;
    cout << "Are you sure? (Y)es/(N)o: ";
    do{
        cin >> yesNo;
        if(strlen(yesNo) == 1){
            if(yesNo[0] == 'Y' || yesNo[0] == 'y'){
                flagYesNo = true;
            }
            else if(yesNo[0] == 'N' || yesNo[0] == 'n'){
                flagYesNo = true;
            }else{
                cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            }
        }else{
            cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
        }
    }while(flagYesNo == false);

    if(yesNo[0] == 'y' || yesNo[0] == 'Y'){
        saveDataFile();
        flag = true;
    }else{
        flag = false;
    }
    return flag;

}
bool Parking::loadDataFile(){
           bool state = true;
            ifstream fin;
       if (!isEmpty())
       {
           fin.open(m_filename);
       }

       char type;
       Vehicle* vp;
       m_numberVehicle = 0;

       while (m_numberVehicle < m_numberSpots && state && fin)
       {
           type = 'x';
           vp = nullptr;
           fin >> type;
           fin.ignore();
           if (type == 'C')
           {
               vp = new Car();
           }
           else if (type == 'M')
           {
               vp = new Motorcycle();
           }

           if (vp)
           {
               vp->setCsv(true);
               fin >> *vp;
               if (fin)
               {
                   m_parkingSpots[vp->getParkingSpot() - 1] = vp;
                   m_numberVehicle++;
               }
               else
               {
                   delete vp;
                   vp = nullptr;
                   state = false;
               }
           }
       }

       return state;
}


void Parking::saveDataFile() const{
    ofstream fout;

        if (!isEmpty())
        {
            fout.open(m_filename);

            if (fout)
            {
                for (int i = 0; i < m_numberSpots; i++)
                {
                    if (m_parkingSpots[i] != nullptr)
                    {
                        m_parkingSpots[i]->setCsv(true);
                        fout << *m_parkingSpots[i];
                    }
                }
            }
        }
}
int Parking::run(){
    {
            int num;
            if (!isEmpty())
            {
                
                do
                {
                     parkingStatus();
                     num = m_parkingMenu.run();
                    
                    if (num == 1)
                    {
                        parkingVehicle();
                    }
                    else if (num == 2)
                    {
                        returnVehicle();
                    }
                    else if (num == 3)
                    {
                        listParkedVehicle();
                    }
                    else if (num == 4)
                    {
                        if (!closeParking())
                        {
                            num = 0;
                        }
                        else
                        {
                            num = 4;
                            cin.ignore(1000, '\n');
                        }
                    }
                    else if (num == 5)
                    {
                        if (!exitParking())
                        {
                            num = 0;
                        }
                        else
                        {
                            num = 5;
                            cout << "Exiting program!" << endl;
                            cin.ignore(1000, '\n');
                        }
                        
        
                    }
                } while (num < 4);
    
                num = 0;
            }
            else
            {
                num = 1;
            }
            
            return num;
        }

    return m_parkingMenu.run();
}
}
