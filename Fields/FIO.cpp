//
// Created by nikita on 30.06.24.
//

#include "FIO.h"
#include <utility>

FIO::FIO(QString _lastName, QString _firstName, QString _patronymic) : lastName(std::move(_lastName)),
                                                                    firstname(std::move(_firstName)), patronymic(std::move(_patronymic)) {}

QString FIO::getFIO() const {
    return lastName + " " + firstname + " " + patronymic;
}

void FIO::setFIO(QString _lastName, QString _firstName, QString _patronymic) {
    lastName = std::move(_lastName);
    firstname = std::move(_firstName);
    patronymic = std::move(_patronymic);
}

QString FIO::getLastname() const {
    return lastName;
}

QString FIO::getFirstname() const {
    return firstname;
}

QString FIO::getPatronymic() const {
    return patronymic;
}

bool FIO::operator<(const FIO &fio) const {
    if (lastName < fio.lastName)
        return true;
    if (lastName == fio.lastName)
    {
        if (firstname < fio.firstname)
            return true;
        if (firstname == fio.firstname)
        {
            if (patronymic < fio.patronymic)
                return true;
        }
    }
    return false;
}

bool FIO::operator==(const FIO &fio) const {
    return (lastName == fio.lastName) && (firstname == fio.firstname) && (patronymic == fio.patronymic);
}

bool FIO::operator>(const FIO &fio) const {
    if (*this < fio || *this == fio)
        return false;
    return true;
}

bool FIO::operator!=(const FIO &fio) const {
    return !(*this == fio);
}

void FIO::operator=(const FIO &fio) {
    lastName = fio.lastName;
    firstname = fio.firstname;
    patronymic = fio.patronymic;
}