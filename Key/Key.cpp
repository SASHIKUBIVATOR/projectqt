#include "Key.h"

Key::Key() = default;

Key::Key(Tree *tree) : _status(0), _tree(tree) {
}

Tree* Key::getTree() const {
    return _tree;
}

ushort Key::getStatus() const {
    return _status;
}

void Key::setStatus(const ushort status) {
    _status = status;
}
