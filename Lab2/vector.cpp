#include <iostream>
#include <vector>
using namespace std;

void printMemVec(vector<int>* v, int size) {
    printf("Vector - Each int is worth %lu bytes\n", sizeof((*v)[0]));
    for(int i = 0; i < size; i++) {
        printf("Value :%i at memory location: %p\n", (*v)[i], &v[i]);
    }
}

void incVecBy10(vector<int>* v, int size) {
    for(int i = 0; i < size; i++) {
        (*v)[i] += 10;
    }
}

int main() {
    const int SIZE = 5;
    vector<int> v;
    for(int i = 0; i < SIZE; i++) {
        v.push_back(100 + i);
    }
    
    printf("Before Increment-------\n");
    printMemVec(&v, v.size());
    incVecBy10(&v, v.size());
    printf("\nAfter Increment--------\n");
    printMemVec(&v, v.size());

    //remove last element of v
    printf("\nAfter Pop--------\n");
    v.pop_back();
    printMemVec(&v, v.size());

    //add two elements
    printf("\nAfter Push--------\n");
    v.push_back(101);
    v.push_back(102);
    printMemVec(&v, v.size());

    
    return 0;
}