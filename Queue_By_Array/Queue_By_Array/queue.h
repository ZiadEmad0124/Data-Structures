#include <bits/stdc++.h>
using namespace std;
template <class type>

class Queue{

    int size = 0;
    int front = 0;
    int rear = -1;
    type* queue;

    bool is_queue_empty(){
        return (rear == -1);
    }

    bool is_queue_full(){
        return (rear == size-1);
    }

    bool find_item(type item){
        bool is_item_found = false;
        if ( ! is_queue_empty()){
            for (int i = front; i <= rear; ++i) {
                if (queue[i] == item){
                    is_item_found = true;
                    break;
                }
            }
        }
        return is_item_found;
    }

public:

    Queue(int queue_size){
        size = queue_size;
        queue = new type[size];
    }

    void enqueue(type item){
        if (is_queue_full()) {
            cout << "Can't enqueue, cause Queue is full";
        }else{
            rear++;
            queue[rear] = item;
        }
    }

    void dequeue(){
        if(is_queue_empty()){
            cout << "Can't dequeue, cause Queue is empty." << endl;
        }else{
            for (int i = 0; i < rear; ++i)
                queue[i] = queue[i+1];
            rear--;
        }
    }

    void get_size(){
        cout << "The size of queue is ==> " << size << endl;
    }

    void get_length(){
        cout << "The length of queue is ==> " << rear << endl;
    }

    void get_front(){
        if(is_queue_empty())
            cout << "Front not found, cause Queue is empty." << endl;
        else
            cout << "The front is ==> " << queue[0] << endl;
    }

    void get_rear(){
        if(is_queue_empty())
            cout << "Rear not found, cause Queue is empty." << endl;
        else
            cout << "The rear is ==> " << queue[rear] << endl;
    }

    void search(type item) {
        if (is_queue_empty())
            cout << "Can't find " << item << ", cause Queue is empty" << endl;
        else if(find_item(item))
            cout << "Yes, " << item << " is found" << endl;
        else
            cout << "No, " << item << " isn't found" << endl;
    }

    void is_empty(){
        string is_empty = is_queue_empty() ? "Yes, Queue is empty" : "No, Queue isn't empty";
        cout << is_empty << endl;
    }

    void is_full(){
        string is_full = is_queue_full() ? "Yes, Queue is full" : "No, Queue isn't full";
        cout << is_full << endl;
    }

    void enlargement(int num){
        if (num > size){
            type* old_queue = queue;
            queue = new type[num];
            size = num;
            for (int i = front; i <= rear; ++i)
                queue[i] = old_queue[i];
            delete[] old_queue;
        }else{
            cout << "Can't enlargement, cause " << num << " smaller or equal than size of Queue" << endl;
        }
    }

    void join(Queue new_queue){
        enlargement(size + new_queue.size);
        for (int i = 0; i <= new_queue.rear; ++i)
            enqueue(new_queue.queue[i]);
    }

    void reverse(){
        type* old_queue = queue;
        queue = new type[size];
        for (int i = rear, j = 0; i >= 0 && j <= rear; --i, ++j)
            queue[i] = old_queue[j];
        delete[] old_queue;
    }

    void clear(){
        if (is_queue_empty())
            cout << "Can't clear Queue, cause it is empty" << endl;
        else
            while ( ! is_queue_empty())
                dequeue();
    }

    void display(){
        if(is_queue_empty()){
            cout << "Can't display Queue, cause it is empty" << endl;
        }else{
            cout << "The Queue is ==> [ ";
            for (int i = 0; i < rear; ++i)
                cout << queue[i] << ", ";
            cout << queue[rear] << " ]" << endl;
        }
    }
};