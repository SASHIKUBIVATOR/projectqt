//
// Created by nikita on 30.06.24.

#include "../Fields/StateNumber.h"
#include <utility>

StateNumber::StateNumber() = default;

StateNumber::StateNumber(QString symbols, const ushort numbers) : m_numbers(numbers), m_symbols(std::move(symbols)){

}

void StateNumber::setNumber(QString symbols, const ushort numbers) {
    m_symbols = std::move(symbols);
    m_numbers = numbers;
}

bool StateNumber::operator==(const StateNumber &stateNumber) const {
    return this->m_numbers == stateNumber.m_numbers && this->m_symbols == stateNumber.m_symbols;
}

bool StateNumber::operator!=(const StateNumber &stateNumber) const {
    return !(*this == stateNumber);
}

QString StateNumber::getString() const {
    auto strNum = QString::number(m_numbers);
    if(strNum.length() == 3)
        return m_symbols[0] + strNum + m_symbols[1] + m_symbols[2];
    if(strNum.length() == 2){
        strNum = "0" + strNum;
        return m_symbols[0] + strNum + m_symbols[1] + m_symbols[2];
    }
    if(strNum.length() == 1) {
        strNum = "00" + strNum;
        return m_symbols[0] + strNum + m_symbols[1] + m_symbols[2];
    }
    else {
        strNum = "000" + strNum;
        return m_symbols[0] + strNum + m_symbols[1] + m_symbols[2];
    }
}
