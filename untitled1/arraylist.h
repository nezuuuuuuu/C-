#include <iostream>
#include "list.h"
using namespace std;

class ArrayList : public List {
//	int array[5];
    char* array;
    int count = 0;
    int capacity;

    char removeOne(char num) {
        for (int i = 0; i < count; i++) {
            if (array[i] == num) {
                for (int j = i; j < count-1; j++) {
                    array[j] = array[j+1];
                }
                array[count-1] = 0;
                count--;
                return i+1;
            }
        }
        return -1;
    }

public:

    ArrayList() {
        capacity = 5;
        array = (char*) calloc( capacity , sizeof(char) );

        cout << "Address of our array is " << &array << endl;

    }

    void insertLast(char num) {
        add(num);
    }

    void add(char num) {
        if (count >= capacity) {
            capacity *= 1.5;
            array = (char*) realloc(array, capacity * sizeof(char) );
        }
        array[count] = num;
        count++;
    }

    // when the number of elements reach 2/3 of the capacity,
    // you are to reallocate the array by reducing its size by 25%,
    // Add the functionality to maintain a minimum capacity of 5.
    // Determine after which line AFTER you want to insert your code
    int remove(char num){
        for (int i = 0; i < count; i++) {
            if (array[i] == num) {
                for (int j = i; j < count-1; j++) {
                    array[j] = array[j+1];
                }
                array[count-1] = 0;
                count--;
                if (capacity > 5 && count <= (2.0/3) * capacity) {
                    capacity *= 0.75;
                    if (capacity < 5) {
                        capacity = 5;
                    }
                    array = (char*) realloc(array, capacity * sizeof(char) );
                }
                return i+1;
            }
        }
        return -1;
    }

    char removeLast() {
        int tmp = array[count-1];
        array[count-1] = 0;
        count--;
        if (capacity > 5 && count <= (2.0/3) * capacity) {
            capacity *= 0.75;
            if (capacity < 5) {
                capacity = 5;
            }
            array = (char*) realloc(array, capacity * sizeof(char) );
        }
        return tmp;
    }

    int removeAll(char num) {
        int ctr = 0;
        while (removeOne(num) != -1) {
            ctr++;
        }

        if (capacity > 5 && count <= 0.6 * capacity) {
            capacity *= 0.8;
            if (capacity < 5) {
                capacity = 5;
            }
            array = (char*) realloc(array, capacity * sizeof(char) );
        }
        return ctr;
    }

    char get(int pos){
        return array[pos-1];
    }

    int size() {
        return count;
    }

    // TIME REMAINING: 00:00 minute
    void print() {
        cout << "Size: " << count << endl;
        for (int i = 0; i < capacity; i++) {
            cout << array[i] << ", ";
        }
        cout << endl;
    }
};
