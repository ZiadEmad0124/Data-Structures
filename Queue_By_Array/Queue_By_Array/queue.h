#include <bits/stdc++.h>
using namespace std;
template<class type>

class Queue {

    int queue_size = 0;
    int front = 0;
    int rear = -1;
    type* queue;

public:
    explicit Queue(int size) {
        queue_size = size;
        queue = new type[queue_size];
    }

    void enqueue(type item) {
        if (is_queue_full()) {
            cout << "Can't enqueue, because Queue is full";
        } else {
            rear++;
            queue[rear] = item;
        }
    }

    void dequeue() {
        if (is_queue_empty()) {
            cout << "Can't dequeue, because Queue is empty." << endl;
        } else {
            for (int i = 0; i < rear; ++i)
                queue[i] = queue[i + 1];
            rear--;
        }
    }

    int get_queue_size() {
        return queue_size;
    }

    void get_size() {
        cout << "The queue_size of queue is ==> " << queue_size << endl;
    }

    int get_queue_length() {
        return rear;
    }

    void get_length() {
        cout << "The length of queue is ==> " << rear << endl;
    }

    type get_queue_front() {
        return queue[0];
    }

    void get_front() {
        if (is_queue_empty())
            cout << "Front not found, because Queue is empty." << endl;
        else
            cout << "The front is ==> " << queue[0] << endl;
    }

    type get_queue_rear() {
        return queue[rear];
    }

    void get_rear() {
        if (is_queue_empty())
            cout << "Rear not found, because Queue is empty." << endl;
        else
            cout << "The rear is ==> " << queue[rear] << endl;
    }

    bool search_queue_item(type item) {
        bool is_item_found = false;
        if ( ! is_queue_empty()) {
            for (int i = front; i <= rear; ++i) {
                if (queue[i] == item) {
                    is_item_found = true;
                    break;
                }
            }
        }
        return is_item_found;
    }

    void search(type item) {
        if (is_queue_empty())
            cout << "Can't find " << item << ", because Queue is empty" << endl;
        else if (search_queue_item(item))
            cout << "Yes, " << item << " is found" << endl;
        else
            cout << "No, " << item << " isn't found" << endl;
    }

        bool is_queue_empty() {
        return (rear == -1);
    }

    void is_empty() {
        string is_empty = is_queue_empty() ? "Yes, Queue is empty" : "No, Queue isn't empty";
        cout << is_empty << endl;
    }

    bool is_queue_full() {
        return (rear == queue_size - 1);
    }

    void is_full() {
        string is_full = is_queue_full() ? "Yes, Queue is full" : "No, Queue isn't full";
        cout << is_full << endl;
    }

    void enlargement(int num) {
        if (num > queue_size) {
            type* old_queue = queue;
            queue = new type[num];
            queue_size = num;
            for (int i = front; i <= rear; ++i)
                queue[i] = old_queue[i];
            delete[] old_queue;
        } else {
            cout << "Can't enlargement, because " << num << " smaller or equal than queue_size of Queue" << endl;
        }
    }

    void join(Queue new_queue) {
        enlargement(queue_size + new_queue.queue_size);
        for (int i = 0; i <= new_queue.rear; ++i)
            enqueue(new_queue.queue[i]);
    }

    void reverse() {
        type* old_queue = queue;
        queue = new type[queue_size];
        for (int i = rear, j = 0; i >= 0 && j <= rear; --i, ++j)
            queue[i] = old_queue[j];
        delete[] old_queue;
    }

    void clear() {
        if (is_queue_empty())
            cout << "Can't clear Queue, because it is empty" << endl;
        else
            while (!is_queue_empty())
                dequeue();
    }

    void display() {
        if (is_queue_empty()) {
            cout << "Can't display Queue, because it is empty" << endl;
        } else {
            cout << "The Queue is ==> [ ";
            for (int i = 0; i < rear; ++i)
                cout << queue[i] << ", ";
            cout << queue[rear] << " ]" << endl;
        }
    }
};