//
// Created by nikita on 30.06.24.
//

#ifndef PASSPORT_H
#define PASSPORT_H
#include <QString>

class Passport {
public:
    Passport();
    Passport(int seria, int number);

    unsigned short getSeria() const;
    unsigned getNumber() const;
    QString getString() const;

    void operator = (const Passport& passport);
    bool operator == (const Passport& passport) const;
    bool operator < (const Passport& passport) const;
    bool operator > (const Passport& passport) const;
    bool operator != (const Passport& passport) const;

private:
    unsigned short _seria{};
    unsigned _number{};
};

#endif //PASSPORT_H
