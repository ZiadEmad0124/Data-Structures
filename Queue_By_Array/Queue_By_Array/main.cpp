#include <bits/stdc++.h>
#include "queue.h"
using namespace std;

int main() {

    cout << "Welcome to Queue" << endl;

    cout << "To add ==> enqueue" <<endl;
    cout << "To remove ==> dequeue" <<endl;
    cout << "To know queue_size ==> get_size & get_queue_size" << endl;
    cout << "To know length ==> get_length & get_queue_length" << endl;
    cout << "To get front ==> get_front & get_queue_front" <<endl;
    cout << "To get rear ==> get_rear & get_queue_rear" <<endl;
    cout << "To search  ==> search & search_queue_item" << endl;
    cout << "To check if empty ==> is_empty & is_queue_empty" << endl;
    cout << "To check if full ==> is_full & is_queue_full" << endl;
    cout << "To large ==> enlargement" <<endl;
    cout << "To add Queue to another ==> join" << endl;
    cout << "To reverse ==> reverse" << endl;
    cout << "To display ==> display" <<endl;
    cout << "To end ==> clear" << endl;

    cout << "==============================" << endl;

//    check empty Queue

    Queue <char> q1(5);

    q1.display();
    q1.get_front();
    q1.get_rear();
    q1.get_size();
    q1.is_empty();
    q1.search('a');
    q1.dequeue();
    q1.clear();
    q1.enqueue('b');
    q1.enqueue('c');
    q1.enqueue('d');
    q1.enqueue('e');
    q1.enqueue('f');
    q1.display();
    cout << q1.get_queue_size() << endl;
    cout << q1.get_queue_length() << endl;
    cout << q1.get_queue_front() << endl;
    cout << q1.get_queue_rear() << endl;
    cout << q1.is_queue_empty() << endl;
    cout << q1.is_queue_full() << endl;
    cout << q1.search_queue_item('f') << endl;
    cout << q1.search_queue_item('l') << endl;

//    check not empty Queue

    Queue <char> q2(5);

    q2.enqueue('j');
    q2.enqueue('h');
    q2.enqueue('i');
    q2.enqueue('j');
    q2.enqueue('k');
    q2.display();
    q2.search('j');
    q2.search('h');
    q2.search('i');
    q2.search('w');
    q2.get_size();
    q2.get_front();
    q2.get_rear();
    q2.is_empty();
    q2.is_full();
    q2.join(q1);
    q2.display();
    q1.display();
    q2.get_size();
    q2.get_length();
    q2.reverse();
    q1.reverse();
    q2.display();
    q1.display();
    q2.clear();
    q1.clear();
    q2.display();
    q1.display();

    return 0;
}