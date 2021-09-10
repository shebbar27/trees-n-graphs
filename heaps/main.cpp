#include<iostream>
#include"MinHeap.cpp"
using namespace std;

int main()
{
    MinHeap heap(20);
    cout << "Insert 3: Success? " <<  boolalpha << heap.insert_key(3) << endl;
    cout << "Insert 2: Success? " <<  boolalpha << heap.insert_key(2) << endl;
    heap.print_heap();
    cout << "Delete node at 1: Success? " << heap.delete_node(1) << endl;
    heap.print_heap();
    cout << "Insert 15: Success? " <<  boolalpha << heap.insert_key(15) << endl;
    heap.print_heap();
    cout << "Insert 5: Success? " <<  boolalpha << heap.insert_key(5) << endl;
    heap.print_heap();
    cout << "Insert 4: Success? " <<  boolalpha << heap.insert_key(4) << endl;
    heap.print_heap();
    cout << "Insert 45: Success? " <<  boolalpha << heap.insert_key(45) << endl;
    heap.print_heap();
    cout << "Extract min: Success? " << boolalpha << heap.extract_min() << endl;
    cout << "Get Min: " << heap.get_min() << endl;
    heap.print_heap();
    //heap.print_heap_array();
    heap.decrease(2, 1);
    cout << "Get Min: " << heap.get_min() << endl;
    heap.print_heap();
    //heap.print_heap_array();
    return 0;
}