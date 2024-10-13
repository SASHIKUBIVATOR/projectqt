#ifndef KEY_H
#define KEY_H

#include "../Tree/Tree.h"

class Key {
public:
    Key();
    Key(Tree* tree);

    Tree* getTree() const;
    unsigned short getStatus() const;
    void setStatus(unsigned short status);

private:
    unsigned short _status{};
    Tree *_tree{};
};

#endif // KEY_H
