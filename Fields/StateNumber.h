//
// Created by nikita on 30.06.24.
//

#ifndef STATENUMBER_H
#define STATENUMBER_H
#include <QString>


class StateNumber {
public:
    StateNumber();
    StateNumber(QString symbols, ushort numbers);

    void setNumber(QString symbols, ushort numbers);

    bool operator == (const StateNumber &stateNumber) const;
    bool operator != (const StateNumber &stateNumber) const;
    [[nodiscard]] QString getString() const;
private:
    QString m_symbols;
    ushort m_numbers = 0;
};



#endif //STATENUMBER_H
