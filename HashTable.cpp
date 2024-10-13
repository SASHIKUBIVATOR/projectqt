#include "HashTable.h"
#include "Tree/Tree.h"
using namespace std;

HashTable::HashTable(const unsigned size) {
    _table = vector<Key>(size);
    _size = size;
    for(int i=0; i < size; i++)
        _table[i] = Key(new Tree());
}

bool HashTable::insert(const Element &element) {
    const auto hash = hashFunction(element);
    if (_table[hash].getStatus() != 1) {
        if(_table[hash].getTree()->add(element)) {
            _table[hash].setStatus(1);
            return true;
        }
        return false;
    } else{
        return _table[hash].getTree()->add(element);
    }
}

bool HashTable::remove(const Element &element) {
    const auto hash = hashFunction(element);
    if(_table[hash].getStatus() == 1) {
        const bool res = _table[hash].getTree()->del(element);
        if(_table[hash].getTree()->isEmpty()) {
            _table[hash].setStatus(2);
        }
        return res;
    }
    return false;
}

int HashTable::find(const Element &element) const {
    const auto hash = hashFunction(element);
    if(_table[hash].getStatus() == 1) {
        const auto cnt = _table[hash].getTree()->search(element);
        if(cnt == -1)
            return -1;
        return cnt + 1;
    }
    return -1;
}

vector<Element> HashTable::print() const {
    vector<Element> v;
    for(const auto i : _table)
        i.getTree()->print(v);
    return v;
}

void HashTable::print(QPlainTextEdit *textEdit) const {
    for(size_t i=0; i < _table.size(); i++) {
        if(_table[i].getStatus() == 1) {
            textEdit->insertPlainText(QString::number(i) + ": ");
            _table[i].getTree()->print(textEdit);
            textEdit->insertPlainText("\n-----------------------------------------------------------\n");
        }
        else
            textEdit->insertPlainText(QString::number(i) + ": Null\n-----------------------------------------------------------\n");
    }
}

size_t HashTable::getSize() const {
    return _table.size();
}

void HashTable::outputFile(std::ofstream &file) const {
    for(const auto i : _table)
        if(i.getStatus() == 1)
            i.getTree()->outputFile(file);
}

unsigned HashTable::hashFunction(const Element &element) const {
    unsigned hash = 0;
    for(const auto i : element.getFIO().getFIO().toStdString())
        hash += i;

    hash += element.getPassport().getSeria();
    hash += element.getPassport().getNumber();
    return hash % _size;
}
