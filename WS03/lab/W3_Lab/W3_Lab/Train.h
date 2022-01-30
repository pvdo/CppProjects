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
    const double MAX_WEIGHT = 700.555;
    const double MIN_WEIGHT = 40.444;
    
    class Cargo{
        char description[MAX_DESC + 1];
        double weight;
        
       
    public:
        Cargo();
        Cargo(const char*, double);
        void init(const char*, double);
        const char* getDesc ()const;
        double getWeight ();
        void setWeight(double);
        void setDescription(const char*);
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
        bool swapCargo(Train&);
        bool increaseCargo(double);
        bool decreaseCargo(double);
    };
    
}
#endif
