#include <bits/stdc++.h>
#include "LinkedStack.h"
using namespace std;

int main() {

    cout << "Welcome to LinkedStack" << endl;

    cout << "To add ==> push" <<endl;
    cout << "To remove ==> pop" <<endl;
    cout << "To check if empty ==> is_empty & is_stack_empty" << endl;
    cout << "To search  ==> search & search_stack_item" << endl;
    cout << "To know size ==> get_size & get_stack_size" << endl;
    cout << "To get Top ==> get_top & get_stack_top" <<endl;
    cout << "To add stack to another ==> join" <<endl;
    cout << "To reverse ==> reverse" << endl;
    cout << "To end ==> clear" << endl;
    cout << "To display ==> display" <<endl;

    cout << "==============================" << endl;

//    check empty LinkedStack

    LinkedStack <char> s1;

    s1.display();
    s1.get_top();
    s1.get_size();
    s1.is_empty();
    s1.search('S');
    s1.pop();
    s1.clear();
    s1.push('A');
    s1.push('B');
    s1.push('C');
    s1.push('D');
    s1.display();
    cout << s1.is_stack_empty() << endl;
    cout << s1.get_stack_size() << endl;
    cout << s1.get_stack_top() << endl;
    cout << s1.search_stack_item('A') << endl;
    cout << s1.search_stack_item('P') << endl;


//    check not empty LinkedStack

    LinkedStack <char> s2;

    s2.push('E');
    s2.push('F');
    s2.push('G');
    s2.push('H');
    s2.display();
    s2.search('F');
    s2.search('H');
    s2.search('J');
    s2.search('S');
    s2.get_size();
    s2.get_top();
    s2.is_empty();
    s2.join(s1);
    s2.display();
    s1.display();
    s2.get_size();
    s2.reverse();
    s1.reverse();
    s2.display();
    s1.display();
    s2.clear();
    s1.clear();
    s2.display();
    s1.display();

    return 0;
}