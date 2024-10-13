#include "Node.h"

Node::Node() : _left(nullptr), _right(nullptr), _list(new List()) {}

Node::Node(Element element, Node *left, Node *right) : _left(left), _right(right), _element(element){
    _list = new List();
    _list->add(element);
}

Element Node::getElement() const {
    return _element;
}

bool Node::addInList(Element element) const {
    return _list->add(element);
}

bool Node::removeInList(Element element) {
    return _list->remove(element);
}

int Node::findInList(Element element) {
    return _list->find(element);
}

bool Node::listEmpty() const {
    return _list->head == nullptr;
}

void Node::setElement(const Element &element) {
    _element = element;
}
