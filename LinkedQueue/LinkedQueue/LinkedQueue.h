#include <bits/stdc++.h>
#include "node.h"
using namespace std;
template<class type>

class LinkedQueue {

    node<type>* front = nullptr;
    node<type>* rear = nullptr;
    int queue_size;

public:
    LinkedQueue() {
        queue_size = 0;
    }

    void enqueue(type item) {
        auto* new_node = new node<type>(item);
        if ( ! is_queue_empty())
            rear->set_next(new_node);
        else
            front = new_node;
        rear = new_node;
        queue_size++;
    }

    void dequeue() {
        if (is_queue_empty()) {
            cout << "Can't dequeue, because LinkedQueue is empty" << endl;
        } else {
            node<type>* curr_ptr = front;
            front = front->get_next();
            delete curr_ptr;
            queue_size--;
        }
    }

    int get_queue_size() {
        return queue_size;
    }

    void get_size() {
        cout << "The size of queue is ==> " << queue_size << endl;
    }

    bool is_queue_empty() {
        return (front == nullptr);
    }

    void is_empty() {
        string s = is_queue_empty() ? "Yes, LinkedQueue is empty" : "No, LinkedQueue isn't empty";
        cout << s << endl;
    }

    type get_queue_front() {
        return front->get_data();
    }

    void get_front() {
        if (is_queue_empty())
            cout << "Front not found, because LinkedQueue is empty" << endl;
        else
            cout << "The front is ==> " << front->get_data() << endl;
    }

    type get_queue_rear() {
        return rear->get_data();
    }

    void get_rear() {
        if (is_queue_empty())
            cout << "Rear not found, because LinkedQueue is empty" << endl;
        else
            cout << "The rear is ==> " << rear->get_data() << endl;
    }

       bool search_queue_item(type item) {
        bool is_item_found = false;
        if ( ! is_queue_empty()) {
            node<type>* curr_ptr = front;
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
        if (is_queue_empty())
            cout << "Can't find " << item << ", because LinkedQueue is empty" << endl;
        else if (search_queue_item(item))
            cout << "Yes, " << item << ", is found" << endl;
        else
            cout << "No, " << item << " isn't found" << endl;
    }

    void join(LinkedQueue new_linked_queue) {
        node<type>* curr_ptr = new_linked_queue.front;
        while (curr_ptr != nullptr) {
            enqueue(curr_ptr->get_data());
            curr_ptr = curr_ptr->get_next();
        }
    }

    void reverse() {
        node<type>* pre_ptr = nullptr;
        node<type>* curr_ptr = front;
        node<type>* next_ptr;
        rear = front;
        while (curr_ptr != nullptr) {
            next_ptr = curr_ptr->get_next();
            curr_ptr->set_next(pre_ptr);
            pre_ptr = curr_ptr;
            curr_ptr = next_ptr;
        }
        front = pre_ptr;
    }

    void clear() {
        if (is_queue_empty()) {
            cout << "Can't clear LinkedQueue, because it is empty" << endl;
        } else {
            while ( ! is_queue_empty()) {
                dequeue();
            }
        }
    }

    void display() {
        if (is_queue_empty()) {
            cout << "Can't display LinkedQueue, because it is empty" << endl;
        } else {
            cout << "The LinkedQueue is ==>  ";
            node<type>* curr_ptr = front;
            while (curr_ptr != rear) {
                cout << curr_ptr->get_data() << " --> ";
                curr_ptr = curr_ptr->get_next();
            }
            cout << curr_ptr->get_data() << endl;
        }
    }
};