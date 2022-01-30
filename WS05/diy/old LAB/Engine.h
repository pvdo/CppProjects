//==============================================
// Name:           Pedro Vitor do Carmo Saraiva Teixeira
// Student Number: 100036193
// Email:          pvdo-carmo-saraiva-t@myseneca.ca
// Section:        NEF
// Workshop:       5 (DIY)
//==============================================

#ifndef SDDS_ENGINE_H
#define SDDS_ENGINE_H

namespace sdds{
const int MAX_TYPE = 30;

    class Engine{
        double size;
        char typeEn[MAX_TYPE + 1];

    public:
        Engine();
        Engine(const char*, double);
        ~Engine();
        double get() const;
        void display() const;
        void setEmpty();
        void set(const char*, double);
    };
}

#endif /* SDDS_ENGINE_H */
