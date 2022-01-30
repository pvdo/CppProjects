//==============================================
// Name:           Pedro Vitor do Carmo Saraiva Teixeira
// Student Number: 100036193
// Email:          pvdo-carmo-saraiva-t@myseneca.ca
// Section:        NEF
// Workshop:       4 (DIY)
//==============================================

#ifndef SDDS_SAIYAN_H
#define SDDS_SAIYAN_H

namespace sdds{
    class Saiyan{
        char *m_name;
        int m_dob;
        int m_power;
        bool m_super;
        int m_level;
    public:
        Saiyan();
        ~Saiyan();
        Saiyan(const char*, int = 0, int = 0);
        bool isSuper() const;
        bool isValid() const;
        void setEmpty();
        void display() const;
        void set(const char*, int, int, int level = 0, bool super = false);
        bool hasLost(Saiyan&);
        void powerup();
    };

}


#endif /* SDDS_SAIYAN_H */
