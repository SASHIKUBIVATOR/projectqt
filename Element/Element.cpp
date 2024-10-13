#include "Element.h"

Element::Element() {}

Element::Element(const Date &date, const FIO &fio, const Passport &passport, const StateNumber &stateNumber) : _date(date), _fio(fio), _passport(passport), _stateNumber(stateNumber)
{

}

FIO Element::getFIO() const {
    return _fio;
}

Passport Element::getPassport() const {
    return _passport;
}

StateNumber Element::getStateNumber() const {
    return _stateNumber;
}

Date Element::getDate() const {
    return _date;
}

string Element::getDateString() const{
    return to_string(_date.getDay()) + "." + to_string(_date.getMonth()) + "." + to_string(_date.getYear());
}

void Element::setFIO(const FIO &fio) {
    _fio = fio;
}

void Element::setPassport(const Passport &passport) {
    _passport = passport;
}

void Element::setStateNumber(const StateNumber &stateNumber) {
    _stateNumber = stateNumber;
}

void Element::setDate(const Date &date) {
    _date = date;
}

bool Element::operator ==(const Element &element) const {
    return _fio == element._fio && _date == element._date && _stateNumber == element._stateNumber && _passport == element._passport;
}

bool Element::operator != (const Element &element) const {
    return !(*this == element);
}

bool Element::operator < (const Element &element) const {
    if(_passport < element._passport)
        return true;
    if(_passport == element._passport && _fio < element._fio)
        return true;
    if(_passport == element._passport && _fio == element._fio && _date < element._date)
        return true;

    return false;
}

bool Element::operator > (const Element &element) const {
    return !(*this == element || *this < element);
}

ostream& operator << (ostream& out, const Element &element){
    auto passport = element.getPassport().getString().toStdString();
    auto fio = element.getFIO().getFIO().toStdString();
    auto stateNumber = element._stateNumber.getString().toStdString();
    auto date = element._date.getString().toStdString();
    out << passport + " " << fio + " " << stateNumber + " " << date;
    return out;
}
