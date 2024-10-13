#ifndef NODE_H
#define NODE_H

#include "ListNode/Listnode.h"

class Node {
    friend class Tree;
public:
    Node();
    Node(Element element, Node *left=nullptr, Node *right=nullptr);

    Element getElement() const;

    bool addInList(Element element) const;
    bool removeInList(Element element);
    int findInList(Element element);
    bool listEmpty() const;
    void setElement(const Element &element);

private:
    Node *_left;
    Node *_right;
    Element _element;
    List* _list;
};

#endif // NODE_H
