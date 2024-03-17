#include <bits/stdc++.h>
#include "node.h"
using namespace std;
template<class type>

class LinkedList {

    node<type>* head = nullptr;
    int linkedlist_size;

public:
    explicit LinkedList() {
        linkedlist_size = 0;
    }

    void push_front(type item) {
        auto* new_node = new node<type>(item);
        if ( ! is_linked_list_empty())
            new_node->set_next(head);
        head = new_node;
        linkedlist_size++;
    }

    void push_back(type item) {
        if (is_linked_list_empty()) {
            push_front(item);
        } else {
            auto* new_node = new node<type>(item);
            node<type>* curr_ptr = head;
            while (curr_ptr->get_next() != nullptr)
                curr_ptr = curr_ptr->get_next();
            curr_ptr->set_next(new_node);
            linkedlist_size++;
        }
    }

    void push_after(type item, type new_item) {
        if (is_linked_list_empty()) {
            cout << "Can't add " << new_item << " after " << item << ",  because LinkedList is empty" << endl;
        } else {
            bool is_item_found = false;
            node<type>* curr_ptr = head;
            while (curr_ptr != nullptr) {
                if (curr_ptr->get_data() == item) {
                    auto* new_node = new node<type>(new_item);
                    new_node->set_next(curr_ptr->get_next());
                    curr_ptr->set_next(new_node);
                    is_item_found = true;
                    linkedlist_size++;
                    break;
                }
                curr_ptr = curr_ptr->get_next();
            }
            if ( ! is_item_found)
                cout << "Can't add " << new_item << ", because " << item << " isn't found" << endl;
        }
    }

    void pop_front() {
        if (is_linked_list_empty()) {
            cout << "Can't remove first item, because LinkedList is empty" << endl;
        } else {
            node<type>* curr_ptr = head;
            head = head->get_next();
            delete curr_ptr;
            linkedlist_size--;
        }
    }

    void pop_back() {
        if (is_linked_list_empty()) {
            cout << "Can't remove last item, because LinkedList is empty" << endl;
        } else {
            if (linkedlist_size == 1) {
                pop_front();
            } else {
                node<type>* curr_ptr = head;
                while (curr_ptr->get_next()->get_next() != nullptr)
                    curr_ptr = curr_ptr->get_next();
                delete curr_ptr->get_next();
                curr_ptr->set_next(nullptr);
                linkedlist_size--;
            }
        }
    }

    void pop(type item) {
        if (is_linked_list_empty()) {
            cout << "Can't remove " << item << ", because LinkedList is empty" << endl;
        } else if (head->get_data() == item) {
            pop_front();
        } else {
            node<type>* pre_ptr = nullptr;
            node<type>* curr_ptr = head;
            bool is_item_found = false;
            while (curr_ptr != nullptr) {
                if (curr_ptr->get_data() == item) {
                    pre_ptr->set_next(curr_ptr->get_next());
                    delete curr_ptr;
                    linkedlist_size--;
                    is_item_found = true;
                    break;
                }
                pre_ptr = curr_ptr;
                curr_ptr = curr_ptr->get_next();
            }
            if ( ! is_item_found)
                cout << "Can't remove " << item << ", because it isn't found" << endl;
        }
    }

    type get_linked_list_head() {
        return head->get_data();
    }

    void get_head() {
        if (is_linked_list_empty())
            cout << "Head not found, because LinkedList is empty" << endl;
        else
            cout << "The Head is ===> " << head->get_data() << endl;
    }

    bool search_linked_list_item(type item) {
        bool is_item_found = false;
        if ( ! is_linked_list_empty()) {
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
        if (is_linked_list_empty())
            cout << "Can't find " << item << ", because LinkedList is empty" << endl;
        else if (search_linked_list_item(item))
            cout << "Yes, " << item << " is found" << endl;
        else
            cout << "No, " << item << " isn't found" << endl;
    }

    void replace(type curr_item, type new_item) {
        if (is_linked_list_empty()) {
            cout << "Can't replace " << curr_item << ", because LinkedList is empty" << endl;
        } else {
            bool is_item_found = false;
            node<type>* curr_ptr = head;
            while (curr_ptr != nullptr) {
                if (curr_ptr->get_data() == curr_item) {
                    curr_ptr->set_data(new_item);
                    is_item_found = true;
                    break;
                }
                curr_ptr = curr_ptr->get_next();
            }
            if ( ! is_item_found)
                cout << "Can't replace " << curr_item << ", because it isn't found" << endl;
        }
    }

    int get_linked_list_size() {
        return linkedlist_size;
    }

    void get_size() {
        cout << "The size of the LinkedList is ==> " << linkedlist_size << endl;
    }

    bool is_linked_list_empty() {
        return (head == nullptr);
    }

    void is_empty() {
        string is_empty = (is_linked_list_empty()) ? "Yes, LinkedList is empty" : "No, LinkedList isn't empty";
        cout << is_empty << endl;
    }

    void join(LinkedList new_linked_list) {
        node<type>* curr_ptr = new_linked_list.head;
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
            pre_ptr = curr_ptr;
            curr_ptr = next_ptr;
        }
        head = pre_ptr;
    }

    void clear() {
        if (is_linked_list_empty())
            cout << "Can't clear LinkedList, because it is empty" << endl;
        else
            while ( ! is_linked_list_empty())
                pop_front();
    }

    void display() {
        if (is_linked_list_empty()) {
            cout << "Can't display LinkedList, because it is empty" << endl;
        } else {
            node<type>* curr_ptr = head;
            cout << "The LinkedList is ===>  ";
            while (curr_ptr->get_next() != nullptr) {
                cout << curr_ptr->get_data() << " --> ";
                curr_ptr = curr_ptr->get_next();
            }
            cout << curr_ptr->get_data() << endl;
        }
    }
};