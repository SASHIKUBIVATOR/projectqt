#include "Tree.h"

Tree::Tree() {}

bool Tree::add(const Element &el) {
    return addRec(root, el);
}

bool Tree::addRec(Node *&node, const Element &el){
    if (!node)
    {
        node = new Node();
        node->setElement(el);

        node->_left = nullptr;
        node->_right = nullptr;
        node->_list = new List();
        return node->addInList(el);
    }

    if (node->_element.getDate() == el.getDate())
        return node->addInList(el);

    if (node->_element.getDate() < el.getDate())
        return addRec(node->_right, el);

    return addRec(node->_left, el);
}

int Tree::search(const Element &element) const {
    return searchRec(root, element);
}

int Tree::searchRec(const Node *node, const Element &element) {
    int cnt = 1;
    if (node != nullptr)
    {
        if (node->_element.getDate() == element.getDate())
        {
            auto countStepInList = node->_list->find(element);
            if(countStepInList < 0)
                return -1;
            return cnt + countStepInList;
        }
        if (node->_element.getDate() > element.getDate())
            return searchRec(node->_left, element);
        if (node->_element.getDate() < element.getDate())
            return searchRec(node->_right, element);
        cnt++;
    }

    return -1;
}

void Tree::delMinRight(Node *&node, Node *&root)
{
    if (node->_left != nullptr)
        delMinRight(node->_left, root);
    else
    {
        root->_element = node->_element;
        root->_list = node->_list;
        node = node->_right;
    }
}

bool Tree::del(const Element &element){
    return delRec(root, element);
}

bool Tree::delRec(Node *&node, const Element &element)
{
    if (node == nullptr)
        return false;

    if (element.getDate() < node->_element.getDate())
        return delRec(node->_left, element);
    else if (element.getDate() > node->_element.getDate())
        delRec(node->_right, element);
    else
    {
        if(node->removeInList(element)){
            if(node->listEmpty()){
                if (node->_left == nullptr)
                    node = node->_right;
                else if (node->_right == nullptr)
                    node = node->_left;
                else
                    delMinRight(node->_right, node);
            }
            return true;
        }
        return false;
    }
    return false;
}

void Tree::outputFile(std::ofstream& file) const {
    out(root, file);
}

void Tree::out(const Node *node, ofstream& file) {
    if (node != nullptr)
    {
        out(node->_left, file);
        node->_list->out(file);
        out(node->_right, file);
    }
}


void Tree::print(std::vector<Element>& v) const {
    printRec(root, v);
}

void Tree::printRec(const Node *node, vector<Element>& v) {
    if(node == nullptr)
        return;

    if(node->_right)
        printRec(node->_right, v);

    node->_list->print(v);

    if(node->_left)
        printRec(node->_left, v);
}

void Tree::print(QPlainTextEdit *textEdit) const {
    printRec(root, textEdit, 0);
}

void Tree::printRec(const Node *node, QPlainTextEdit *textEdit, unsigned short k) {
    if(node == nullptr)
        return;

    printRec(node->_right, textEdit, k+7);

    for(int i=0; i <= k; i++)
        textEdit->insertPlainText(" ");

    node->_list->print(textEdit);
    textEdit->insertPlainText("\n");

    printRec(node->_left, textEdit, k+11);
}


bool Tree::isEmpty() const {
    return root == nullptr;
}
