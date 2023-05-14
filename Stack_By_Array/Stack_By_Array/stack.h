#include <bits/stdc++.h>
using namespace std;
template <class type>

class Stack{

    int size = 0;
    int length = -1;
    type* stack;

    bool is_stack_empty(){
        return (length == -1);
    }

    bool is_stack_full(){
        return (size == length+1);
    }

    bool find_item(type item){
        bool is_item_found = false;
        if( ! is_stack_empty()){
            for (int i = 0; i <= length; ++i) {
                if (stack[i] == item){
                    is_item_found = true;
                    break;
                }
            }
        }
        return is_item_found;
    }

public:

    Stack(int stack_size){
        size = stack_size;
        stack = new type[size];
    }

    void push(type item){
        if (is_stack_full()){
            cout << "Can't push, cause Stack is full" << endl;
        }else{
            length++;
            stack[length] = item;
        }
    }

    void pop(){
        if (is_stack_empty())
            cout << "Can't pop, cause Stack is empty" << endl;
        else
            length--;
    }

    void is_empty(){
        string is_empty = is_stack_empty() ? "Yes, Stack is empty" : "No, Stack isn't empty";
        cout << is_empty << endl;
    }

    void is_full(){
        string is_full = is_stack_full() ? "Yes, Stack is full" : "No, Stack isn't full";
        cout << is_full << endl;
    }

    void search(type item) {
        if (is_stack_empty())
            cout << "Can't find " << item << ", cause Stack is empty" << endl;
        else if(find_item(item))
            cout << "Yes, " << item << " is found" << endl;
        else
            cout << "No, " << item << " isn't found" << endl;
    }

    void get_size(){
            cout << "The size of stack is ==> " << size << endl;
    }

    void get_length(){
            cout << "The length is ==> " << length+1 << endl;
    }

    void get_top(){
        if (is_stack_empty())
            cout << "Top not found , cause Stack is empty" << endl;
        else
            cout << "The Top is ==> " << stack[length] << endl;
    }

    void enlargement(int num){
        if (num > size){
            type* old_stack = stack;
            size = num;
            stack = new type[num];
            for (int i = 0; i <= length; ++i) {
                stack[i] = old_stack[i];
            }
            delete[] old_stack;
        }else{
            cout << "Can't enlargement, cause " << num << " smaller or equal than size of Stack" << endl;
        }
    }

    void join(Stack new_stack){
        enlargement(size + new_stack.size);
        int num = new_stack.length;
        while (num >= 0) {
            push(new_stack.stack[num]);
            num--;
        }
    }

    void reverse(){
        type* old_stack = stack;
        stack = new type[size];
        for (int i = length, j = 0; i >= 0 && j <= length; --i, ++j) {
            stack[j] = old_stack[i];
        }
        delete[] old_stack;
    }

    void clear(){
        if(is_stack_empty())
            cout << "Can't clear Stack, cause it is empty" << endl;
        else
            while ( ! is_stack_empty())
                pop();
    }

    void display() {
        if (is_stack_empty()) {
            cout << "Can't display Stack, cause it is empty" << endl;
        } else {
            cout << "The Stack is ==> [ ";
            for (int i = length; i > 0; --i) {
                cout << stack[i] << ", ";
            }
            cout << stack[0] << " ]" << endl;
        }
    }
};