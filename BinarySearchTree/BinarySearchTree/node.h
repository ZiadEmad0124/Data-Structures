#include <bits/stdc++.h>
using namespace std;

class node {

    int data = 0;
    node* right = nullptr;
    node* left = nullptr;

public:
    explicit node(int item) {
        set_data(item);
    }

    int get_data() {
        return data;
    }

    node* get_right() {
        return right;
    }

    node* get_left() {
        return left;
    }

    void set_data(int item) {
        data = item;
    }

    void set_right(node* node) {
        right = node;
    }

    void set_left(node* node) {
        left = node;
    }
};