#include <bits/stdc++.h>
#include "DoublyLinkedList.h"
using namespace std;

int main() {

    cout << "Welcome to DoublyLinkedList" << endl;

    cout << "To add ==> push_front & push_back & push_after" <<endl;
    cout << "To remove ==> pop_front & pop_back & pop" <<endl;
    cout << "To get head ==> get_head & get_doubly_linked_list_head" <<endl;
    cout << "To search  ==> search & search_doubly_linked_list_item" << endl;
    cout << "To replace ==> replace" << endl;
    cout << "To know size ==> get_size & get_doubly_linked_list_size" << endl;
    cout << "To check if empty ==> is_empty & is_doubly_linked_list_empty" << endl;
    cout << "To add DoublyLinkedList to another  ==> join" << endl;
    cout << "To reverse ==> reverse" << endl;
    cout << "To clear ==> clear" << endl;
    cout << "To display ==> display" <<endl;

    cout << "==========================================" << endl;

//  check empty DoublyLinkedList

    DoublyLinkedList <float> dll1;

    dll1.get_head();
    dll1.get_size();
    dll1.search(5.5);
    dll1.replace(5.5, 7.5);
    dll1.is_empty();
    dll1.pop_back();
    dll1.pop_front();
    dll1.pop(80.5);
    dll1.clear();
    dll1.display();
    dll1.push_back(1.5);
    dll1.push_back(3.5);
    dll1.push_back(4.5);
    dll1.push_back(5.5);
    dll1.push_after(1.5, 2.5);
    dll1.display();
    cout << dll1.get_doubly_linked_list_head() << endl;
    cout << dll1.is_doubly_linked_list_empty() << endl;
    cout << dll1.get_doubly_linked_list_size() << endl;
    cout << dll1.search_doubly_linked_list_item(1.5) << endl;
    cout << dll1.search_doubly_linked_list_item(10.5) << endl;

//  check not empty DoublyLinkedList

    DoublyLinkedList <float> dll2;

    dll2.push_back(1.5);
    dll2.push_back(2.5);
    dll2.push_back(4.5);
    dll2.push_back(5.5);
    dll2.push_front(0.5);
    dll2.push_after(2.5, 3.5);
    dll2.display();
    dll2.get_size();
    dll2.search(0.5);
    dll2.search(3.5);
    dll2.search(5.5);
    dll2.search(99.5);
    dll2.is_empty();
    dll2.get_head();
    dll2.pop_front();
    dll2.pop_back();
    dll2.pop(3.5);
    dll2.display();
    dll2.replace(1.5, 99.5);
    dll2.replace(4.5, 100.5);
    dll2.replace(2.5, 50.5);
    dll2.replace(80.5, 1000.5);
    dll2.display();
    dll2.join(dll1);
    dll2.display();
    dll2.get_size();
    dll2.reverse();
    dll1.reverse();
    dll2.display();
    dll1.display();
    dll1.clear();
    dll2.clear();
    dll2.display();
    dll1.display();

    return 0;
}