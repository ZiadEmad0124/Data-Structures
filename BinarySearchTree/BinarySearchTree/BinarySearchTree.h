#include <bits/stdc++.h>
#include "node.h"
using namespace std;

class BinarySearchTree {

    node* root = nullptr;
    int bst_size;

    node* insert(node* curr_root, int item) {

        if (curr_root == nullptr) {
            node* new_node = new node(item);
            curr_root = new_node;
        } else if (item <= curr_root->get_data()) {
            curr_root->set_left(insert(curr_root->get_left(), item));
        } else {
            curr_root->set_right(insert(curr_root->get_right(), item));
        }

        return curr_root;
    }

    node* search(node* curr_root, int item) {

        if (curr_root == nullptr) {
            return nullptr;
        } else if (curr_root->get_data() == item) {
            return curr_root;
        } else if (item < curr_root->get_data()) {
            return search(curr_root->get_left(), item);
        } else {
            return search(curr_root->get_right(), item);
        }
    }

    node* min_node(node* curr_node) {
        if (curr_node == nullptr) {
            return nullptr;
        } else if (curr_node->get_left() == nullptr) {
            return curr_node;
        } else {
            return min_node(curr_node->get_left());
        }
    }

    node* max_node(node* curr_node) {
        if (curr_node == nullptr) {
            return nullptr;
        } else if (curr_node->get_right() == nullptr) {
            return curr_node;
        } else {
            return max_node(curr_node->get_right());
        }
    }

    node* pop(node* curr_root, int item) {
//        if tree is empty
        if (curr_root == nullptr) {
            return nullptr;
        }
//        if item < root of subtree
        if (item < curr_root->get_data()) {
            curr_root->set_left(pop(curr_root->get_left(), item));
//        if item > root of subtree
        } else if (item > curr_root->get_data()) {
            curr_root->set_right(pop(curr_root->get_right(), item));
        } else {
//            root I want to delete is leaf node
            if (curr_root->get_left() == nullptr && curr_root->get_right() == nullptr) {
                curr_root = nullptr;
//            root I want to delete has one child on left
            } else if (curr_root->get_left() != nullptr && curr_root->get_right() == nullptr) {
                curr_root->set_data(curr_root->get_left()->get_data());
                delete curr_root->get_left();
                curr_root->set_left(nullptr);
//            root I want to delete has one child on right
            } else if (curr_root->get_left() == nullptr && curr_root->get_right() != nullptr) {
                curr_root->set_data(curr_root->get_right()->get_data());
                delete curr_root->get_right();
                curr_root->set_right(nullptr);
//            root I want to delete has two child
            } else {
                node* predecessor = max_node(curr_root->get_left());
                curr_root->set_data(predecessor->get_data());
                curr_root->set_left(pop(curr_root->get_left(), predecessor->get_data()));
            }
        }

        return curr_root;
    }

    void pre_order(node* curr_root) {

        if (curr_root == nullptr) {
            return;
        }
        cout << curr_root->get_data() << "  ";
        pre_order(curr_root->get_left());
        pre_order(curr_root->get_right());
    }

    void in_order(node *curr_root) {

        if (curr_root == nullptr) {
            return;
        }
        in_order(curr_root->get_left());
        cout << curr_root->get_data() << "  ";
        in_order(curr_root->get_right());
    }

    void post_order(node *curr_root) {

        if (curr_root == nullptr) {
            return;
        }
        post_order(curr_root->get_left());
        post_order(curr_root->get_right());
        cout << curr_root->get_data() << "  ";
    }

public:
    explicit BinarySearchTree() {
        bst_size = 0;
    }

    void insert(int item) {
        root = insert(root, item);
        bst_size += 1;
    }

    bool bst_search_item(int item) {
        if (search(root, item) == nullptr) {
            return 0;
        } else {
            return 1;
        }
    }

    void search(int item) {
        if (is_bst_empty()) {
            cout << "Can't search item, because BST is empty" << endl;
        }else{
            if (search(root, item) == nullptr) {
            cout << "No, " << item << " isn't found" << endl;
            } else {
            cout << "Yes, " << item << " is found" << endl;
            }
        }
    }

    void min_item() {
        if (is_bst_empty()) {
            cout << "Can't get min item, because BST is empty" << endl;
        } else {
            node *min_item = min_node(root);
            cout << "Min item in tree is ==> " << min_item->get_data() << endl;
        }
    }

    void max_item() {
        if (is_bst_empty()) {
            cout << "Can't get max item, because BST is empty" << endl;
        } else {
            node* max_item = max_node(root);
            cout << "Max item in tree is ==> " << max_item->get_data() << endl;
        }
    }

    void pop(int item) {
        if (is_bst_empty())
            cout << "Can't pop, because BST is empty" << endl;
        else {
            if (bst_search_item(item) == 0) {
                cout << "Can't pop " << item << ", because it isn't found" << endl;
            } else {
                root = pop(root, item);
                bst_size--;
            }
        }
    }

    int bst_get_root(){
        return root->get_data();
    }

    void get_root() {
        if (is_bst_empty())
            cout << "Can't get root, because BST is empty" << endl;
        else
            cout << "The root is ==> " << root->get_data() << endl;
    }

    bool is_bst_empty() {
        return (root == nullptr);
    }

    void is_empty() {
        string is_empty = (is_bst_empty()) ? "Yes, is empty" : "No, isn't empty";
        cout << is_empty << endl;
    }

    int bst_get_size(){
        return bst_size;
    }

    void get_size() {
        cout << "The get_size is ==> " << bst_size << endl;
    }

    void pre_order() {
        if (is_bst_empty())
            cout << "Can't display in pre_order, because BST is empty" << endl;
        else
            pre_order(root);
    }

    void in_order() {
        if (is_bst_empty())
            cout << "Can't display in in_order, because BST is empty" << endl;
        else
            in_order(root);
    }

    void post_order() {
        if (is_bst_empty())
            cout << "Can't display in post_order, because BST is empty" << endl;
        else
            post_order(root);
    }
};