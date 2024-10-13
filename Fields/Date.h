//
// Created by nikita on 30.06.24.
//

#ifndef DATE_H
#define DATE_H
#include <QString>

using namespace std;

class Date {
public:
    Date();
    Date(unsigned short _year, unsigned short _month, unsigned short _day);
    explicit Date(const string &date);

    bool operator==(const Date &date) const;
    bool operator!=(const Date &date) const;
    bool operator>(const Date &date) const;
    bool operator<(const Date &date) const;
    bool operator <= (const Date &date) const;
    bool operator >= (const Date &date) const;
    void operator=(const Date &date);
    [[nodiscard]] QString getString() const;
    unsigned short getYear() const;
    unsigned short getMonth() const;
    unsigned short getDay() const;
    [[nodiscard]] bool correctDate() const;

private:
    ushort m_year;
    ushort m_month;
    ushort m_day;
};

#endif //DATE_H
