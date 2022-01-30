//==============================================
// Name:           Pedro Vitor do Carmo Saraiva Teixeira
// Student Number: 100036193
// Email:          pvdo-carmo-saraiva-t@myseneca.ca
// Section:        NEF
// Workshop:       3 (DIY)
//==============================================
#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

namespace sdds{
    const int MAX_NAME = 30;
    const int MAX_DESC = 20;
    
    struct Cargo{
        char description[MAX_DESC];
        double weight;
    };

    class Train{
        char name[MAX_NAME];
        int id;
        Cargo* cargo;
        
    public:
        void setTrain(const char*, int);
        bool isEmpty() const;
        void display() const;
        void loadCargo(Cargo);
        void unloadCargo();
    };
    
}
#endif
