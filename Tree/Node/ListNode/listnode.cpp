#include "Listnode.h"

bool List::add(const Element &element){
    if(head == nullptr) {
        head = new ListNode(element);
        return true;
    }
    if(head->element == element)
        return false;

    auto curr = head;
    while (curr->next != nullptr) {
        if(curr->element == element)
            return false;
        curr = curr->next;
    }
    curr->next = new ListNode(element);
    curr->next->prev = curr;
    return true;
}

bool List::remove(const Element &element) {
    if(head == nullptr)
        return false;

    if(head->element == element) {
        auto del = head;
        head = head->next;
        delete del;
        if(head != nullptr)
            head->prev = nullptr;
        return true;
    }

    auto curr = head;
    while(curr != nullptr && curr->element != element){
        curr = curr->next;
    }

    if (curr == nullptr)
        return false;

    if(curr->next == nullptr){
        curr->prev->next = nullptr;
        delete curr;
        return true;
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
    return true;
}

int List::find(const Element &element) {
    auto curr = head;
    int cnt = 1;
    while (curr != nullptr && curr->element != element) {
        cnt++;
        curr=curr->next;
    }
    if(curr == nullptr)
        return -1;
    return cnt;
}

void List::print(QPlainTextEdit *textEdit) {
    auto curr = head;
    int cnt = 1;
    while (curr != nullptr) {
        textEdit->insertPlainText(curr->element.getPassport().getString()
                                  + " " + curr->element.getFIO().getFIO()
                                  + " " + curr->element.getStateNumber().getString()
                                  + " " + QString::fromStdString(curr->element.getDateString()) + " -> ");
        curr=curr->next;
    }
}

void List::print(vector<Element> &v) {
    auto curr = head;
    int cnt = 1;
    while (curr != nullptr) {
        v.push_back(curr->element);
        curr=curr->next;
    }
}

void List::out(ofstream &file) {
    auto curr = head;
    int cnt = 1;
    while (curr != nullptr) {
        file << curr->element << endl;
        curr=curr->next;
    }
}

ListNode::ListNode(Element element) {
    this->element = element;
    next = nullptr;
    prev = nullptr;
}
