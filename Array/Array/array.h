#include <bits/stdc++.h>
using namespace std;
template <class type>

class Array{

    int size = 0;
    int length = -1;
    type* arr;

    bool is_arr_empty(){
        return (length == -1);
    }

    bool is_arr_full(){
        return (length == size-1);
    }

    bool find_item(type item){
        bool is_item_found = false;
        if( !is_arr_empty()){
            for (int i = 0 ; i < size; ++i) {
                if (arr[i] == item){
                    is_item_found = true;
                    break;
                }
            }
        }
        return is_item_found;
    }

public:
    Array(int arr_size){
        size = arr_size;
        arr = new type[size];
    }

    void push_front(type item){
        if (is_arr_full()){
            cout << "Can't add " << item << " in front of Array, cause it is full" << endl;
        } else if(is_arr_empty()){
            length++;
            arr[length] = item;
        } else{
            for(int i = length+1 ; i > 0 ; i--){
                arr[i] = arr[i-1];
            }
            arr[0] = item;
            length++;
        }
    }

    void push_back(type item){
        if(is_arr_full()){
            cout << "Can't add " << item << " at back of Array, cause it is full" << endl;
        }else{
            length++;
            arr[length] = item;
        }
    }

    void push_after(type item, type new_item){
        if (is_arr_full()){
            cout << "Can't add " << new_item << ", cause Array is full" << endl;
        }else if(is_arr_empty()) {
            push_front(new_item);
        }else if (find_item(item)){
            for (int i = length+1 ; i > 0 ; i--) {
                if (arr[i-1] == item){
                    arr[i] = new_item;
                    break;
                }
                arr[i] = arr[i-1];
            }
            length++;
        }else{
            cout << "Can't add " << new_item << ", cause " << item << " isn't found" << endl;
        }
    }

    void pop_back(){
        if (is_arr_empty())
            cout << "Can't remove last item, cause Array is empty" << endl;
        else
            length--;
    }

    void pop_front() {
        if (is_arr_empty()){
            cout << "Can't remove first item, cause Array is empty" << endl;
        }else {
            for (int i = 0; i < length; ++i)
                arr[i] = arr[i + 1];
            length--;
        }
    }

    void pop(type item){
        if (is_arr_empty()){
            cout << "Can't remove " << item << ", cause Array is empty" << endl;
        }else{
            if (arr[length] == item){
                pop_back();
            }else if (arr[0] == item){
                pop_front();
            }else {
                bool is_item_found = false;
                for (int i = 1; i < length; ++i) {
                    if (arr[i] == item) {
                        for (int j = i; j < length; ++j) {
                            arr[j] = arr[j + 1];
                        }
                        is_item_found = true;
                        length--;
                        break;
                    }
                }
                if (!is_item_found) {
                    cout << "Can't remove " << item << ", cause it isn't found" << endl;
                }
            }
        }
    }

    void is_empty(){
        string is_empty = is_arr_empty() ? "Yes, Array is empty" : "No, Array isn't empty";
        cout << is_empty << endl;
    }

    void is_full(){
        string is_full = is_arr_full() ? "Yes, Array is full" : "No, Array isn't full";
        cout << is_full << endl;
    }

    void get_size(){
        cout << "The size of the Array is ==> " << size << endl;
    }

    void get_length(){
        cout << "The length of the Array is ==> " << length + 1 << endl;
    }

    void search(type item) {
        if (is_arr_empty())
            cout << "Can't find " << item << ", cause Array is empty" << endl;
        else if(find_item(item))
            cout << "Yes, " << item << " is found" << endl;
        else
            cout << "No, " << item << " isn't found" << endl;
    }

    void replace(type curr_item, type new_item){
        if (is_arr_empty()){
            cout << "Can't replace " << curr_item << ", cause Array is empty" << endl;
        }else{
            bool is_curr_item_found = false;
            for (int i = 0 ; i <= length ; ++i) {
                if (arr[i] == curr_item){
                    arr[i] = new_item;
                    is_curr_item_found = true;
                    break;
                }
            }
            if ( ! is_curr_item_found)
                cout << "Can't replace " << curr_item << ", cause it isn't found" << endl;
        }
    }

    void enlargement(int num){
        if (num > size){
            type* old_array = arr;
            size = num;
            arr = new type[size];
            for (int i = 0; i <= length; ++i) {
                arr[i] = old_array[i];
            }
            delete[] old_array;
        }else{
            cout << "Can't enlargement, cause " << num << " smaller or equal than size of Array" << endl;
        }
    }

    void join(Array new_array){
        enlargement(size + new_array.size);
        for (int i = 0; i <= new_array.length; ++i)
            push_back(new_array.arr[i]);
    }

    void reverse(){
        type* old_arr = arr;
        arr = new type[size];
        for (int i = length, j = 0; i >= 0 && j <= length; --i, ++j)
            arr[j] = old_arr[i];
        delete[] old_arr;
    }

    void clear(){
        if (is_arr_empty())
            cout << "Can't clear Array, cause it is empty" << endl;
        else
            while ( ! is_arr_empty())
                pop_back();
    }

    void display() {
        if (is_arr_empty()) {
            cout << "Can't display Array, cause it is empty" << endl;
        }else {
            cout << "The Array is ==> [ ";
            for (int i = 0; i < length; ++i)
                cout << arr[i] << ", ";
            cout << arr[length] << " ]" << endl;
        }
    }
};