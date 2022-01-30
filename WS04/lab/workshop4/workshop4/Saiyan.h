//
//  Saiyan.hpp
//  workshop4
//
//  Created by Pedro Do Carmo on 2020-02-06.
//  Copyright © 2020 Pedro Do Carmo. All rights reserved.
//

#ifndef SDDS_SAIYAN_H
#define SDDS_SAIYAN_H

namespace sdds{
    class Saiyan{
        char m_name[30];
        int m_dob;
        int m_power;
        bool m_super;
    public:
        Saiyan();
        ~Saiyan();
        Saiyan(const char*, int, int);
        bool isSuper() const;
        bool isValid() const;
        void setEmpty();
        void display() const;
        void set(const char*, int, int, bool super = false);
       // void set(const char*, int, int);
        bool hasLost(const Saiyan&) const;
    };

}


#endif /* SDDS_SAIYAN_H */
