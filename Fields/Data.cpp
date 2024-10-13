//
// Created by nikita on 30.06.24.
//

#include <QString>

#include "Date.h"
#include <regex>
#include <iostream>
#include <tuple>

Date::Date(): m_year(0), m_month(0), m_day(0) {
}

Date::Date(ushort _year, ushort _month, ushort _day) : m_year(_year), m_month(_month), m_day(_day) {}

Date::Date(const string &date)
{
    if (const regex reg("^[0-3][0-9].[0-1][0-9].[0-9]+$"); regex_match(date, reg))
    {
        short cntPoint = 0;
        string current;
        for (const char i : date)
        {
            if (cntPoint == 0 && i == '.')
            {
                m_day = stoul(current);
                current = "";
                cntPoint++;
            }
            else if (cntPoint == 1 && i == '.')
            {
                m_month = stoul(current);
                current = "";
                cntPoint++;
            }
            else
                current += i;
        }
        m_year = stoul(current);
    }
    else
    {
        cout << "Error: not corrected date\n";
    }
}

bool Date::correctDate() const {
    if (m_month < 1 || m_month > 12 || m_day <= 0 || m_day > 31 || m_year == 0)
        return false;

    const unsigned short m_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    unsigned short cntm_days = m_days[m_month];

    if (m_month == 2 && ((m_year % 4 == 0 && m_year % 100 != 0) || m_year % 400 == 0))
    {
        cntm_days++;
    }

    return cntm_days >= m_day;
}

bool Date::operator==(const Date &date) const {
    return tie(m_year, m_month, m_day) == tie(date.m_year, date.m_month, date.m_day);
}

bool Date::operator!=(const Date &date) const {
    return !(*this == date);
}

bool Date::operator>(const Date &date) const {
    return tie(m_year, m_month, m_day) > tie(date.m_year, date.m_month, date.m_day);
}

bool Date::operator<(const Date &date) const {
    if (*this > date || *this == date)
        return false;
    return true;
}

bool Date::operator<=(const Date &date) const {
    return *this < date || *this == date;
}

bool Date::operator>=(const Date &date) const {
    return *this > date || *this == date;
}

void Date::operator=(const Date &date)
{
    m_year = date.m_year;
    m_month = date.m_month;
    m_day = date.m_day;
}

QString Date::getString() const {
    QString res;
    if(m_day < 10)
        res += "0" + QString::number(m_day)+".";
    else
        res += QString::number(m_day) + ".";

    if(m_month < 10)
        res += "0" + QString::number(m_month)+ ".";
    else
        res += QString::number(m_month) + ".";

    if(m_year < 10)
        res += "0" + QString::number(m_year);
    else
        res += QString::number(m_year);

    return res;
}

ushort Date::getYear() const {
    return m_year;
}

ushort Date::getMonth() const {
    return m_month;
}

ushort Date::getDay() const {
    return m_day;
}
