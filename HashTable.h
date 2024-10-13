#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <QPlainTextEdit>
#include <fstream>
#include "Key/Key.h"

class HashTable
{
public:
    HashTable(unsigned size);

    // метод вставки элемента в таблицу
    bool insert(const Element &element);

    // метод удаления элемента
    bool remove(const Element &element);

    // метод поиска элемента
    int find(const Element &element) const;

    // метод вывода ХТ-БДП на основное окно в виде таблицы
    std::vector<Element> print() const;

    // метод вывода ХТ-БДП как альтернативное отображение в виде дерева положенного на бок
    void print(QPlainTextEdit *textEdit) const;

    // возвращает размер ХТ
    size_t getSize() const;

    // метод вывода ХТ-БДП в файл
    void outputFile(std::ofstream &file) const;

private:
    // метод для подсчёта хэша в хэш таблице
    unsigned hashFunction(const Element &element) const;

private:
    std::vector<Key> _table;
    unsigned _size{};
};

#endif // HASHTABLE_H
