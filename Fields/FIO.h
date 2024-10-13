//
// Created by nikita on 30.06.24.
//

#ifndef FIO_H
#define FIO_H

#include <QString>

using namespace std;

class FIO
{
public:
    FIO() = default;
    FIO(QString _lastName, QString _firstName, QString _patronymic);

    [[nodiscard]] QString getFIO() const;
    void setFIO(QString _lastName, QString _firstName, QString _patronymic);

    [[nodiscard]] QString getLastname() const;
    [[nodiscard]] QString getFirstname() const;
    [[nodiscard]] QString getPatronymic() const;

    bool operator<(const FIO &fio) const;
    bool operator==(const FIO &fio) const;
    bool operator>(const FIO &fio) const;
    bool operator!=(const FIO &fio) const;
    void operator = (const FIO &fio);

private:
    QString lastName;
    QString firstname                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       ;
    QString patronymic;
};

#endif //FIO_H
