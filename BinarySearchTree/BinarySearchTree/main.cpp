#include <bits/stdc++.h>
#include "BinarySearchTree.h"
using namespace std;

int main() {

    cout << "Welcome to BinarySearchTree" << endl;

    cout << "To add ==> insert" << endl;
    cout << "To remove ==> pop" << endl;
    cout << "To check if empty ==> is_empty & is_bst_empty" << endl;
    cout << "To know size ==> get_size & bst_get_size" << endl;
    cout << "To know root ==> get_root & bst_get_root" << endl;
    cout << "To know min item ==> min_item" << endl;
    cout << "To know max item ==> max_item" << endl;
    cout << "To search  ==> search & bst_search_item" << endl;
    cout << "To display ==> pre_order & in_order & post_order" << endl;

    cout << "===========================================" << endl;

//  check empty BinarySearchTree

    BinarySearchTree bst1;

    bst1.pop(50);
    bst1.search(100);
    bst1.max_item();
    bst1.min_item();
    bst1.get_root();
    bst1.get_size();
    bst1.is_empty();
    bst1.pre_order();
    bst1.in_order();
    bst1.post_order();
    bst1.insert(20);
    cout << bst1.bst_get_root() << endl;
    cout << bst1.bst_get_size() << endl;
    cout << bst1.is_bst_empty() << endl;
    cout << bst1.bst_search_item(20) << endl;
    cout << bst1.bst_search_item(50) << endl;

//  check not empty BinarySearchTree

    BinarySearchTree bst2;

    bst2.insert(40);
    bst2.insert(45);
    bst2.insert(30);
    bst2.insert(35);
    bst2.insert(30);
    bst2.insert(22);
    bst2.insert(50);
    bst2.insert(43);
    bst2.get_root();
    bst2.is_empty();
    bst2.get_size();
    bst2.search(40);
    bst2.search(50);
    bst2.search(22);
    bst2.search(100);
    bst2.max_item();
    bst2.min_item();
    bst2.pre_order();
    cout << endl;
    bst2.in_order();
    cout << endl;
    bst2.post_order();
    cout << endl;
    bst2.pop(40);
    bst2.pop(50);
    bst2.pop(22);
    bst2.pop(100);
    bst2.get_size();
    bst2.max_item();
    bst2.min_item();
    bst2.pre_order();
    cout << endl;
    bst2.in_order();
    cout << endl;
    bst2.post_order();
    cout << endl;

    return 0;
}