#include <bits/stdc++.h>
using namespace std;
template<class type>

class Array {

    int arr_size = 0;
    int arr_length = -1;
    type* arr;

public:
    explicit Array(int size) {
        arr_size = size;
        arr = new type[arr_size];
    }

    void push_front(type item) {
        if (is_arr_full()) {
            cout << "Can't add " << item << " in front of Array, because it is full" << endl;
        } else if (is_arr_empty()) {
            arr_length++;
            arr[arr_length] = item;
        } else {
            for (int i = arr_length + 1; i > 0; i--) {
                arr[i] = arr[i - 1];
            }
            arr[0] = item;
            arr_length++;
        }
    }

    void push_back(type item) {
        if (is_arr_full()) {
            cout << "Can't add " << item << " at back of Array, because it is full" << endl;
        } else {
            arr_length++;
            arr[arr_length] = item;
        }
    }

    void push_after(type item, type new_item) {
        if (is_arr_full()) {
            cout << "Can't add " << new_item << ", because Array is full" << endl;
        } else if (is_arr_empty()) {
            cout << "Can't add " << new_item << ", because " << item << " isn't found , Array is empty" << endl;
        } else if (arr_search_item(item)) {
            for (int i = arr_length + 1; i > 0; i--) {
                if (arr[i - 1] == item) {
                    arr[i] = new_item;
                    break;
                }
                arr[i] = arr[i - 1];
            }
            arr_length++;
        } else {
            cout << "Can't add " << new_item << ", because " << item << " isn't found" << endl;
        }
    }

    void pop_back() {
        if (is_arr_empty())
            cout << "Can't remove last item, because Array is empty" << endl;
        else
            arr_length--;
    }

    void pop_front() {
        if (is_arr_empty()) {
            cout << "Can't remove first item, because Array is empty" << endl;
        } else {
            for (int i = 0; i < arr_length; ++i)
                arr[i] = arr[i + 1];
            arr_length--;
        }
    }

    void pop(type item) {
        if (is_arr_empty()) {
            cout << "Can't remove " << item << ", because Array is empty" << endl;
        } else {
            if (arr[arr_length] == item) {
                pop_back();
            } else {
                bool is_item_found = false;
                for (int i = 0; i < arr_length; ++i) {
                    if (arr[i] == item) {
                        for (int j = i; j < arr_length; ++j) {
                            arr[j] = arr[j + 1];
                        }
                        is_item_found = true;
                        arr_length--;
                        break;
                    }
                }
                if ( ! is_item_found) {
                    cout << "Can't remove " << item << ", because it isn't found" << endl;
                }
            }
        }
    }

    bool is_arr_empty() {
        return (arr_length == -1);
    }

    void is_empty() {
        string is_empty = is_arr_empty() ? "Yes, Array is empty" : "No, Array isn't empty";
        cout << is_empty << endl;
    }

    bool is_arr_full() {
        return (arr_length == arr_size - 1);
    }

    void is_full() {
        string is_full = is_arr_full() ? "Yes, Array is full" : "No, Array isn't full";
        cout << is_full << endl;
    }

    int arr_get_size(){
        return arr_size;
    }

    void get_size() {
        cout << "The arr_size of the Array is ==> " << arr_size << endl;
    }

    int arr_get_length(){
        return arr_length;
    }

    void get_length() {
        cout << "The arr_length of the Array is ==> " << arr_length + 1 << endl;
    }

    bool arr_search_item(type item) {
        bool is_item_found = false;
        if ( ! is_arr_empty()) {
            for (int i = 0; i < arr_size; ++i) {
                if (arr[i] == item) {
                    is_item_found = true;
                    break;
                }
            }
        }
        return is_item_found;
    }

    void search(type item) {
        if (is_arr_empty())
            cout << "Can't find " << item << ", because Array is empty" << endl;
        else if (arr_search_item(item))
            cout << "Yes, " << item << " is found" << endl;
        else
            cout << "No, " << item << " isn't found" << endl;
    }

    void replace(type curr_item, type new_item) {
        if (is_arr_empty()) {
            cout << "Can't replace " << curr_item << ", because Array is empty" << endl;
        } else {
            bool is_curr_item_found = false;
            for (int i = 0; i <= arr_length; ++i) {
                if (arr[i] == curr_item) {
                    arr[i] = new_item;
                    is_curr_item_found = true;
                    break;
                }
            }
            if (!is_curr_item_found)
                cout << "Can't replace " << curr_item << ", because it isn't found" << endl;
        }
    }

    void enlargement(int new_size) {
        if (new_size > arr_size) {
            type* old_array = arr;
            arr_size = new_size;
            arr = new type[arr_size];
            for (int i = 0; i <= arr_length; ++i) {
                arr[i] = old_array[i];
            }
            delete[] old_array;
        } else {
            cout << "Can't enlargement, because " << new_size << " smaller or equal than arr_size of Array" << endl;
        }
    }

    void join(Array new_array) {
        enlargement(arr_size + new_array.arr_size);
        for (int i = 0; i <= new_array.arr_length; ++i)
            push_back(new_array.arr[i]);
    }

    void reverse() {
        type* old_arr = arr;
        arr = new type[arr_size];
        for (int i = arr_length, j = 0; i >= 0 && j <= arr_length; --i, ++j)
            arr[j] = old_arr[i];
        delete[] old_arr;
    }

    void clear() {
        if (is_arr_empty())
            cout << "Can't clear Array, because it is empty" << endl;
        else
            while ( ! is_arr_empty())
                pop_back();
    }

    void display() {
        if (is_arr_empty()) {
            cout << "Can't display Array, because it is empty" << endl;
        } else {
            cout << "The Array is ==> [ ";
            for (int i = 0; i < arr_length; ++i)
                cout << arr[i] << ", ";
            cout << arr[arr_length] << " ]" << endl;
        }
    }
};