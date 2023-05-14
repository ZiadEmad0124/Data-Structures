#include <bits/stdc++.h>
#include "stack.h"
using namespace std;

int main() {

    cout << "Welcome to Stack" << endl;

    cout << "To add ==> push" <<endl;
    cout << "To remove ==> pop" <<endl;
    cout << "To check if empty ==> is_empty" << endl;
    cout << "To check if full ==> is_full" << endl;
    cout << "To search  ==> search" << endl;
    cout << "To know size ==> get_size" << endl;
    cout << "To know length ==> get_length" << endl;
    cout << "To get Top ==> get-top" <<endl;
    cout << "To large ==> enlargement" <<endl;
    cout << "To add stack to another ==> join" <<endl;
    cout << "To reverse ==> reverse" << endl;
    cout << "To display ==> display" <<endl;
    cout << "To end ==> clear" << endl;

    cout << "==============================" << endl;

//    check empty Stack

    Stack <string> s1(5);

    s1.display();
    s1.get_top();
    s1.get_size();
    s1.get_length();
    s1.is_empty();
    s1.is_full();
    s1.search("Ahmed");
    s1.pop();
    s1.clear();
    s1.push("Ziad");
    s1.push("Mohammed");
    s1.push("Ahmed");
    s1.push("Ibrahim");
    s1.display();


//    check not empty Stack

    Stack <string> s2(5);

    s2.push("Osama");
    s2.push("Abdalla");
    s2.push("Ihab");
    s2.push("Mahmoud");
    s2.display();
    s2.get_size();
    s2.get_top();
    s2.is_empty();
    s2.is_full();
    s2.push("Islam");
    s2.is_full();
    s2.get_length();
    s2.search("Osama");
    s2.search("Ihab");
    s2.search("Islam");
    s2.search("Mostafa");
    s2.join(s1);
    s2.display();
    s1.display();
    s2.get_size();
    s2.get_length();
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