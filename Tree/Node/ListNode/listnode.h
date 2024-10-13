#ifndef LISTNODE_H
#define LISTNODE_H

#include <fstream>
#include <QPlainTextEdit>
#include "../../../Element/Element.h"

struct ListNode {
    ListNode(Element element);

    ListNode* next{};
    ListNode* prev{};
    Element element;
};

struct List {
    List() = default;
    bool add(const Element &element);

    bool remove(const Element &element);

    int find(const Element &element);

    void print(QPlainTextEdit* textEdit);

    void print(vector<Element>& v);

    void out(ofstream &file);

    ListNode* head{};
};
#endif // LISTNODE_H
