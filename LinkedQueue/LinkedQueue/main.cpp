#include <bits/stdc++.h>
#include "LinkedQueue.h"
using namespace std;

int main() {

    cout << "Welcome to LinkedQueue" << endl;

    cout << "To add ==> enqueue" <<endl;
    cout << "To remove ==> dequeue" <<endl;
    cout << "To check if empty ==> is_empty & is_queue_empty" << endl;
    cout << "To know size ==> get_size & get_queue_size" << endl;
    cout << "To get front ==> get_front & get_queue_front" <<endl;
    cout << "To get rear ==> get_rear & get_queue_rear" <<endl;
    cout << "To search  ==> search & search_queue_item" << endl;
    cout << "To add LinkedQueue to another ==> join" << endl;
    cout << "To reverse ==> reverse" << endl;
    cout << "To end ==> clear" << endl;
    cout << "To display ==> display" <<endl;

    cout << "==============================" << endl;

//    check empty LinkedQueue

    LinkedQueue <int> lq1;

    lq1.display();
    lq1.get_front();
    lq1.get_rear();
    lq1.get_size();
    lq1.is_empty();
    lq1.search(5);
    lq1.dequeue();
    lq1.clear();
    lq1.enqueue(1);
    lq1.enqueue(2);
    lq1.enqueue(3);
    lq1.enqueue(4);
    lq1.enqueue(5);
    lq1.display();
    cout << lq1.is_queue_empty() << endl;
    cout << lq1.get_queue_size() << endl;
    cout << lq1.get_queue_front() << endl;
    cout << lq1.get_queue_rear() << endl;
    cout << lq1.search_queue_item(2) << endl;
    cout << lq1.search_queue_item(20) << endl;

//    check not empty LinkedQueue

    LinkedQueue <int> lq2;

    lq2.enqueue(6);
    lq2.enqueue(7);
    lq2.enqueue(8);
    lq2.enqueue(9);
    lq2.enqueue(10);
    lq2.display();
    lq2.search(6);
    lq2.search(8);
    lq2.search(10);
    lq2.search(99);
    lq2.get_size();
    lq2.get_front();
    lq2.get_rear();
    lq2.is_empty();
    lq2.join(lq1);
    lq2.display();
    lq1.display();
    lq2.get_size();
    lq2.reverse();
    lq1.reverse();
    lq2.display();
    lq1.display();
    lq2.clear();
    lq1.clear();
    lq2.display();
    lq1.display();

    return 0;
}