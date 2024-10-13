#include "../Fields/Passport.h"


Passport::Passport() = default;

Passport::Passport(const int seria, const int number) {
    _seria = seria;
    _number = number;
}

unsigned short Passport::getSeria() const {
    return _seria;
}

unsigned int Passport::getNumber() const {
    return _number;
}

void Passport::operator=(const Passport &passport) {
    this->_number = passport._number;
    this->_seria = passport._seria;
}

bool Passport::operator==(const Passport &passport) const {
    return this->_number == passport._number && this->_seria == _seria;
}

bool Passport::operator<(const Passport &passport) const {
    return this->_seria < passport._seria ||
        (this->_seria == passport._seria && this->_number < passport._number);
}

bool Passport::operator>(const Passport &passport) const {
    return this->_seria > passport._seria ||
        (this->_seria == passport._seria && this->_number > passport._number);
}

bool Passport::operator!=(const Passport &passport) const {
    return !(*this == passport);
}

QString Passport::getString() const {
    QString seriesStr = QString("%1").arg(_seria, 4, 10, QChar('0'));  // Серия из 4 цифр
    QString numberStr = QString("%1").arg(_number, 6, 10, QChar('0'));  // Номер из 6 циф
    return QString::number(_seria)+ " " + QString::number(_number);
}
