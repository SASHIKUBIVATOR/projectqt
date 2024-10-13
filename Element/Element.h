#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>
#include "../Fields/Date.h"
#include "../Fields/FIO.h"
#include "../Fields/Passport.h"
#include "../Fields/StateNumber.h"

class Element
{
public:
    Element();
    Element(const Date &date, const FIO &fio, const Passport &passport, const StateNumber &stateNumber);

    FIO getFIO() const;
    Passport getPassport() const;
    StateNumber getStateNumber() const;
    Date getDate() const;
    string getDateString() const;

    void setFIO(const FIO &fio);
    void setPassport(const Passport &passport);

    // задаёт наим. продукта
    void setStateNumber(const StateNumber &stateNumber);

    // задаёт дату
    void setDate(const Date &date);

    bool operator ==(const Element &element) const;
    bool operator != (const Element &element) const;
    bool operator < (const Element &element) const;
    bool operator > (const Element &element) const;

    friend ostream& operator << (ostream& out, const Element &element);

private:
    Passport _passport;
    FIO _fio;
    StateNumber _stateNumber;
    Date _date;
};

#endif // ELEMENT_H
