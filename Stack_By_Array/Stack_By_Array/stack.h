#include <bits/stdc++.h>
using namespace std;
template<class type>

class Stack {

    int stack_size = 0;
    int stack_length = -1;
    type* stack;

public:
    explicit Stack(int size) {
        stack_size = size;
        stack = new type[stack_size];
    }

    void push(type item) {
        if (is_stack_full()) {
            cout << "Can't push, because Stack is full" << endl;
        } else {
            stack_length++;
            stack[stack_length] = item;
        }
    }

    void pop() {
        if (is_stack_empty())
            cout << "Can't pop, because Stack is empty" << endl;
        else
            stack_length--;
    }

    bool is_stack_empty() {
        return (stack_length == -1);
    }

    void is_empty() {
        string is_empty = is_stack_empty() ? "Yes, Stack is empty" : "No, Stack isn't empty";
        cout << is_empty << endl;
    }

    bool is_stack_full() {
        return (stack_length == stack_size - 1);
    }

    void is_full() {
        string is_full = is_stack_full() ? "Yes, Stack is full" : "No, Stack isn't full";
        cout << is_full << endl;
    }

    bool search_stack_item(type item) {
        bool is_item_found = false;
        if ( ! is_stack_empty()) {
            for (int i = 0; i <= stack_length; ++i) {
                if (stack[i] == item) {
                    is_item_found = true;
                    break;
                }
            }
        }
        return is_item_found;
    }

    void search(type item) {
        if (is_stack_empty())
            cout << "Can't find " << item << ", because Stack is empty" << endl;
        else if (search_stack_item(item))
            cout << "Yes, " << item << " is found" << endl;
        else
            cout << "No, " << item << " isn't found" << endl;
    }

    int get_stack_size() {
        return stack_size;
    }

    void get_size() {
        cout << "The stack_size of stack is ==> " << stack_size << endl;
    }

    int get_stack_length() {
        return stack_length;
    }

    void get_length() {
        cout << "The stack_length is ==> " << stack_length + 1 << endl;
    }

    type get_stack_top() {
        return stack[stack_length];
    }

    void get_top() {
        if (is_stack_empty())
            cout << "Top not found , because Stack is empty" << endl;
        else
            cout << "The Top is ==> " << stack[stack_length] << endl;
    }

    void enlargement(int num) {
        if (num > stack_size) {
            type* old_stack = stack;
            stack_size = num;
            stack = new type[num];
            for (int i = 0; i <= stack_length; ++i) {
                stack[i] = old_stack[i];
            }
            delete[] old_stack;
        } else {
            cout << "Can't enlargement, because " << num << " smaller or equal than stack_size of Stack" << endl;
        }
    }

    void join(Stack new_stack) {
        enlargement(stack_size + new_stack.stack_size);
        int num = new_stack.stack_length;
        while (num >= 0) {
            push(new_stack.stack[num]);
            num--;
        }
    }

    void reverse() {
        type* old_stack = stack;
        stack = new type[stack_size];
        for (int i = stack_length, j = 0; i >= 0 && j <= stack_length; --i, ++j) {
            stack[j] = old_stack[i];
        }
        delete[] old_stack;
    }

    void clear() {
        if (is_stack_empty())
            cout << "Can't clear Stack, because it is empty" << endl;
        else
            while ( ! is_stack_empty())
                pop();
    }

    void display() {
        if (is_stack_empty()) {
            cout << "Can't display Stack, because it is empty" << endl;
        } else {
            cout << "The Stack is ==> [ ";
            for (int i = stack_length; i > 0; --i) {
                cout << stack[i] << ", ";
            }
            cout << stack[0] << " ]" << endl;
        }
    }
};