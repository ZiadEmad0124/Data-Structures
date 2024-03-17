#include <bits/stdc++.h>
#include "node.h"
using namespace std;
template<class type>

class LinkedStack {

    node<type>* top = nullptr;
    int stack_size;

public:
    LinkedStack() {
        stack_size = 0;
    }

    void push(type item) {
        auto* new_node = new node<type>(item);
        if ( !is_stack_empty())
            new_node->set_next(top);
        top = new_node;
        stack_size++;
    }

    void pop() {
        if (is_stack_empty()) {
            cout << "Can't pop, because LinkedStack is empty" << endl;
        } else {
            node<type>* curr_ptr = top;
            top = top->get_next();
            delete curr_ptr;
            stack_size--;
        }
    }

    bool is_stack_empty() {
        return (top == nullptr);
    }

    void is_empty() {
        if (is_stack_empty())
            cout << "Yes, LinkedStack is empty" << endl;
        else
            cout << "No, LinkedStack isn't empty" << endl;
    }

    bool search_stack_item(type item) {
        bool is_item_found = false;
        if ( !is_stack_empty()) {
            node<type>* curr_ptr = top;
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
        if (is_stack_empty())
            cout << "Can't find " << item << ", because LinkedStack is empty" << endl;
        else if (search_stack_item(item))
            cout << "Yes, " << item << " is found" << endl;
        else
            cout << "No, " << item << " isn't found" << endl;
    }

    int get_stack_size() {
        return stack_size;
    }

    void get_size() {
        cout << "The size of stack is ===> " << stack_size << endl;
    }

    type get_stack_top() {
        return top->get_data();
    }

    void get_top() {
        if (is_stack_empty())
            cout << "Top not found, because LinkedStack is empty" << endl;
        else
            cout << "The Top is ==> " << top->get_data() << endl;
    }

    void join(LinkedStack new_linked_stack) {
        node<type>* curr_ptr = new_linked_stack.top;
        while (curr_ptr != nullptr) {
            push(curr_ptr->get_data());
            curr_ptr = curr_ptr->get_next();
        }
    }

    void reverse() {
        node<type>* pre_ptr = nullptr;
        node<type>* curr_ptr = top;
        node<type>* next_ptr;
        while (curr_ptr != nullptr) {
            next_ptr = curr_ptr->get_next();
            curr_ptr->set_next(pre_ptr);
            pre_ptr = curr_ptr;
            curr_ptr = next_ptr;
        }
        top = pre_ptr;
    }

    void clear() {
        if (is_stack_empty())
            cout << "Can't Clear LinkedStack, because it is empty" << endl;
        else
            while ( !is_stack_empty()) {
                pop();
            }
    }

    void display() {
        if (is_stack_empty()) {
            cout << "Can't display LinkedStack, because it is empty." << endl;
        } else {
            node<type>* curr_ptr = top;
            cout << "The LinkedStack is ==>  ";
            while (curr_ptr->get_next() != nullptr) {
                cout << curr_ptr->get_data() << " -->  ";
                curr_ptr = curr_ptr->get_next();
            }
            cout << curr_ptr->get_data() << endl;
        }
    }
};