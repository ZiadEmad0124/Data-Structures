#include <bits/stdc++.h>
#include "LinkedList.h"
using namespace std;

int main() {

    cout << "Welcome to LinkedList" << endl;

    cout << "To add ==> push_front & push_back & push_after" <<endl;
    cout << "To remove ==> pop_front & pop_back & pop" <<endl;
    cout << "To get head ==> get_head & get_linked_list_head" <<endl;
    cout << "To search  ==> search & search_linked_list_item" << endl;
    cout << "To replace ==> replace" << endl;
    cout << "To know size ==> get_size & get_linked_list_size" << endl;
    cout << "To check if empty ==> is_empty & is_linked_list_empty" << endl;
    cout << "To add LinkedList to another  ==> join" << endl;
    cout << "To reverse ==> reverse" << endl;
    cout << "To clear ==> clear" << endl;
    cout << "To display ==> display" <<endl;

    cout << "==========================================" << endl;

//  check empty LinkedList

    LinkedList <string> ll1;

    ll1.get_head();
    ll1.get_size();
    ll1.search("Ibrahim");
    ll1.replace("Ibrahim", "Abdalla");
    ll1.is_empty();
    ll1.pop_back();
    ll1.pop_front();
    ll1.pop("Osama");
    ll1.clear();
    ll1.display();
    ll1.push_back("Ahmed");
    ll1.push_back("Mohammed");
    ll1.push_back("Ziad");
    ll1.push_back("Mostafa");
    ll1.push_after("Ahmed", "Abdalla");
    ll1.display();
    cout << ll1.get_linked_list_size() << endl;
    cout << ll1.is_linked_list_empty() << endl;
    cout << ll1.get_linked_list_head() << endl;
    cout << ll1.search_linked_list_item("Ziad") << endl;
    cout << ll1.search_linked_list_item("Osama") << endl;

//  check not empty LinkedList

    LinkedList <string> ll2;

    ll2.push_back("Ahmed");
    ll2.push_back("Mohammed");
    ll2.push_back("Mostafa");
    ll2.push_back("Ibrahim");
    ll2.push_front("Abdalla");
    ll2.push_after("Mohammed", "Ziad");
    ll2.push_after("Kareem", "John");
    ll2.display();
    ll2.get_size();
    ll2.search("Abdalla");
    ll2.search("Ziad");
    ll2.search("Ibrahim");
    ll2.search("Osama");
    ll2.is_empty();
    ll2.get_head();
    ll2.pop_front();
    ll2.pop_back();
    ll2.pop("Ziad");
    ll2.display();
    ll2.replace("Ahmed", "Emad");
    ll2.replace("Mostafa", "Ezz");
    ll2.replace("Mohammed", "Marwan");
    ll2.replace("Ismail", "Mohammed");
    ll2.display();
    ll2.join(ll1);
    ll2.display();
    ll2.get_size();
    ll2.reverse();
    ll1.reverse();
    ll2.display();
    ll1.display();
    ll1.clear();
    ll2.clear();
    ll2.display();
    ll1.display();

    return 0;
}