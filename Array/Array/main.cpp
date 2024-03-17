#include <bits/stdc++.h>
#include "array.h"
using namespace std;

int main() {

    cout << "Welcome to Array" << endl;

    cout << "To add ==> push_front & push_back & push_after" << endl;
    cout << "To remove ==> pop_front & pop_back & pop" << endl;
    cout << "To check if empty ==> is_empty & is_arr_empty" << endl;
    cout << "To check if full ==> is_full & is_arr_full" << endl;
    cout << "To know size ==> get_size & arr_get_size" << endl;
    cout << "To know length ==> get_length & arr_get_length" << endl;
    cout << "To search  ==> search & arr_search_item" << endl;
    cout << "To replace ==> replace" << endl;
    cout << "To large ==> enlargement" << endl;
    cout << "To add Array to another ==> join" << endl;
    cout << "To reverse ==> reverse" << endl;
    cout << "To clear ==> clear" << endl;
    cout << "To display ==> display" << endl;

    cout << "===========================================" << endl;

//  check empty Array

    Array<int> a1(4);

    a1.is_empty();
    a1.get_size();
    a1.get_length();
    a1.clear();
    a1.search(99);
    a1.replace(99, 100);
    a1.enlargement(4);
    a1.display();
    a1.pop_front();
    a1.pop_back();
    a1.pop(99);
    a1.push_back(2);
    a1.push_back(4);
    a1.push_after(8, 3);
    a1.push_after(2, 3);
    a1.push_front(1);
    a1.is_full();
    a1.display();
    cout << a1.is_arr_empty() << endl;
    cout << a1.is_arr_full() << endl;
    cout << a1.arr_get_size() << endl;
    cout << a1.arr_get_length() << endl;
    cout << a1.arr_search_item(1) << endl;
    cout << a1.arr_search_item(50) << endl;

//  check not empty Array

    Array<int> a2(5);

    a2.push_back(1);
    a2.push_back(2);
    a2.push_after(2, 3);
    a2.push_front(0);
    a2.is_empty();
    a2.is_full();
    a2.get_size();
    a2.get_length();
    a2.search(0);
    a2.search(2);
    a2.search(3);
    a2.search(99);
    a2.replace(3, 100);
    a2.replace(1, 99);
    a2.replace(1000, 100);
    a2.display();
    a2.enlargement(7);
    a2.get_size();
    a2.join(a1);
    a2.display();
    a2.get_size();
    a2.get_length();
    a2.reverse();
    a1.reverse();
    a2.display();
    a1.display();
    a2.clear();
    a1.clear();
    a2.display();
    a1.display();

    return 0;
}