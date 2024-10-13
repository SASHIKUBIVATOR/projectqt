#ifndef TREE_H
#define TREE_H
#include <fstream>
#include <vector>
#include <QPlainTextEdit>
#include "../Element/Element.h"
#include "Node/Node.h"

class Tree
{
public:
    Tree();

    bool add(const Element &el);
    int search(const Element &element) const;
    bool del(const Element &element);
    void outputFile(std::ofstream& file) const;
    void print(std::vector<Element>& v) const;
    void print(QPlainTextEdit *textEdit) const;
    bool isEmpty() const;

private:
    static bool addRec(Node *&node, const Element &el);

    static int searchRec(const Node *node, const Element &element);

    static void delMinRight(Node *&node, Node *&root);
    static bool delRec(Node *&node, const Element &element);

    static void out(const Node *node, ofstream& file);

    static void printRec(const Node *node, vector<Element>& v);
    static void printRec(const Node *node, QPlainTextEdit *textEdit, unsigned short k);

private:
    Node* root{};
};

#endif // TREE_H
