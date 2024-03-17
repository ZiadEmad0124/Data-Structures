#include <bits/stdc++.h>
using namespace std;
template<class type>

class node {

    type data;
    node* next_node = nullptr;
    node* prev_node = nullptr;

public:
    explicit node(type item) {
        set_data(item);
    }

    type get_data() {
        return data;
    }

    node* get_next() {
        return next_node;
    }

    node* get_prev() {
        return prev_node;
    }

    void set_data(type item) {
        data = item;
    }

    void set_next(node* node) {
        next_node = node;
    }

    void set_prev(node* node) {
        prev_node = node;
    }
};