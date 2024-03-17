#include <bits/stdc++.h>
#include "node.h"
using namespace std;
template<class type>

class DoublyLinkedList {

    node<type>* head = nullptr;
    int doubly_linked_list_size;

public:
    explicit DoublyLinkedList() {
        doubly_linked_list_size = 0;
    }

    void push_front(type item) {
        auto* new_node = new node<type>(item);
        if ( ! is_doubly_linked_list_empty()) {
            new_node->set_next(head);
            head->set_prev(new_node);
        }
        head = new_node;
        doubly_linked_list_size++;
    }

    void push_back(type item) {
        if (is_doubly_linked_list_empty()) {
            push_front(item);
        } else {
            auto* new_node = new node<type>(item);
            node<type>* curr_ptr = head;
            while (curr_ptr->get_next() != nullptr)
                curr_ptr = curr_ptr->get_next();
            curr_ptr->set_next(new_node);
            new_node->set_prev(curr_ptr);
            doubly_linked_list_size++;
        }
    }

    void push_after(type item, type new_item) {
        if (is_doubly_linked_list_empty()) {
            cout << "Can't add " << new_item << " ,because DoublyLinkedList is empty" << endl;
        } else {
            auto* new_node = new node<type>(new_item);
            node<type>* curr_ptr = head;
            bool is_item_found = false;
            while (curr_ptr != nullptr) {
                if (curr_ptr->get_data() == item) {
                    new_node->set_next(curr_ptr->get_next());
                    new_node->set_prev(curr_ptr);
                    curr_ptr->set_next(new_node);
                    new_node->get_next()->set_prev(curr_ptr);
                    is_item_found = true;
                    doubly_linked_list_size++;
                    break;
                }
                curr_ptr = curr_ptr->get_next();
            }
            if ( ! is_item_found)
                cout << "Can't add " << new_item << " because " << item << ", isn't found" << endl;
        }
    }

    void pop_front() {
        if (is_doubly_linked_list_empty()) {
            cout << "Can't remove first item, because DoublyLinkedList is empty" << endl;
        } else {
            node<type>* curr_ptr = head;
            head = head->get_next();
            delete curr_ptr;
            doubly_linked_list_size--;
        }
    }

    void pop_back() {
        if (is_doubly_linked_list_empty()) {
            cout << "Can't remove last item, because DoublyLinkedList is empty" << endl;
        } else {
            if (doubly_linked_list_size == 1) {
                pop_front();
            } else {
                node<type>* curr_ptr = head;
                while (curr_ptr->get_next()->get_next() != nullptr)
                    curr_ptr = curr_ptr->get_next();
                delete curr_ptr->get_next();
                curr_ptr->set_next(nullptr);
            }
            doubly_linked_list_size--;
        }
    }

    void pop(type item) {
        if (is_doubly_linked_list_empty()) {
            cout << "Can't remove " << item << ", because DoublyLinkedList is empty" << endl;
        } else if (item == head->get_data()) {
            pop_front();
        } else {
            node<type>* curr_ptr = head;
            node<type>* pre_ptr = nullptr;
            bool is_item_found = false;
            while (curr_ptr != nullptr) {
                if (curr_ptr->get_data() == item) {
                    pre_ptr->set_next(curr_ptr->get_next());
                    curr_ptr->get_next()->set_prev(pre_ptr);
                    is_item_found = true;
                    doubly_linked_list_size--;
                    delete curr_ptr;
                    break;
                }
                pre_ptr = curr_ptr;
                curr_ptr = curr_ptr->get_next();
            }
            if ( ! is_item_found)
                cout << "Can't remove " << item << ", because it isn't found" << endl;
        }
    }

    type get_doubly_linked_list_head() {
        return head->get_data();
    }

    void get_head() {
        if (is_doubly_linked_list_empty())
            cout << "Head not found, because DoublyLinkedList is empty" << endl;
        else
            cout << "The Head is ===> " << head->get_data() << endl;
    }

    bool search_doubly_linked_list_item(type item) {
        bool is_item_found = false;
        if (!is_doubly_linked_list_empty()) {
            node<type>* curr_ptr = head;
            while (curr_ptr != nullptr) {
                if (curr_ptr->get_data() == item) {
                    is_item_found = true;
                    break;
                }
                curr_ptr = curr_ptr->get_next();
            }
        }
        return is_item_found;
    }

    void search(type item) {
        if (is_doubly_linked_list_empty()) {
            cout << "Can't find " << item << ", because DoublyLinkedList is empty" << endl;
        } else if (search_doubly_linked_list_item(item)) {
            cout << "Yes, " << item << " is found" << endl;
        } else {
            cout << "No, " << item << " isn't found" << endl;
        }
    }

    void replace(type curr_item, type new_item) {
        if (is_doubly_linked_list_empty()) {
            cout << "Can't replace " << curr_item << ", because DoublyLinkedList is empty" << endl;
        } else {
            bool is_curr_item_found = false;
            node<type>* curr_ptr = head;
            while (curr_ptr != nullptr) {
                if (curr_ptr->get_data() == curr_item) {
                    curr_ptr->set_data(new_item);
                    is_curr_item_found = true;
                    break;
                }
                curr_ptr = curr_ptr->get_next();
            }
            if ( ! is_curr_item_found)
                cout << "Can't replace " << curr_item << ", because it isn't found" << endl;
        }
    }

    int get_doubly_linked_list_size() {
        return doubly_linked_list_size;
    }

    void get_size() {
        cout << "The size of DoublyLinkedList is ===> " << doubly_linked_list_size << endl;
    }

    bool is_doubly_linked_list_empty() {
        return (head == nullptr);
    }

    void is_empty() {
        if (is_doubly_linked_list_empty())
            cout << "Yes, DoublyLinkedList is empty" << endl;
        else
            cout << "No, DoublyLinkedList isn't empty" << endl;
    }

    void join(DoublyLinkedList new_doubly_linked_list) {
        node<type>* curr_ptr = new_doubly_linked_list.head;
        while (curr_ptr != nullptr) {
            push_back(curr_ptr->get_data());
            curr_ptr = curr_ptr->get_next();
        }
    }

    void reverse() {
        node<type>* pre_ptr = nullptr;
        node<type>* curr_ptr = head;
        node<type>* next_ptr;
        while (curr_ptr != nullptr) {
            next_ptr = curr_ptr->get_next();
            curr_ptr->set_next(pre_ptr);
            curr_ptr->set_prev(next_ptr);
            pre_ptr = curr_ptr;
            curr_ptr = next_ptr;
        }
        head = pre_ptr;
    }

    void clear() {
        if (is_doubly_linked_list_empty())
            cout << "Can't clear DoublyLinkedList, because it is empty" << endl;
        else
            while ( ! is_doubly_linked_list_empty())
                pop_front();
    }

    void display() {
        if (is_doubly_linked_list_empty()) {
            cout << "Can't display DoublyLinkedList, because it is empty" << endl;
        } else {
            node<type>* curr_ptr = head;
            cout << "The LinkedList is ===>  ";
            while (curr_ptr->get_next() != nullptr) {
                cout << curr_ptr->get_data() << " <--> ";
                curr_ptr = curr_ptr->get_next();
            }
            cout << curr_ptr->get_data() << endl;
        }
    }
};