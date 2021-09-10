#include<iostream>
#include<climits>
#include<queue>
using namespace std;

class MinHeap {
    private:
        int *data;
        int capacity;
        int curr_size;

        static int get_parent(int index) {
            return (index-1)/2; 
        }

        static int get_left_child(int index) {
            return 2*index + 1;
        }

        static int get_right_child(int index) {
            return 2*index + 2;
        }

        static void swap(int *x, int *y) {
            int temp = *x;
            *x = *y;
            *y = temp;
        }

        void reposition_modified_key(int index) {
            while(index != 0 && data[get_parent(index)] > data[index]) {
                swap(&data[index], &data[get_parent(index)]);
                index = get_parent(index);
            }
        }

    public:
        MinHeap(int _capacity) {
            capacity = _capacity;
            data = new int[_capacity];
            curr_size = 0;
        }

        int get_min() {
            return data[0];
        }

        bool insert_key(int key) {
            if(curr_size == capacity)
                return false;

            curr_size++;
            int index = curr_size-1;
            data[curr_size-1] = key;

            reposition_modified_key(index);

            return true;
        }

        void decrease(int index, int new_val) {
            cout << "\n" << data[index] << " replaced with " << new_val << endl;
            data[index] = new_val;
            reposition_modified_key(index);
        }

        bool extract_min() {
            if(curr_size <= 0)
                return false;

            if(curr_size == 1) {
                curr_size--;
                return true;
            }

            cout << "\n" << data[0] << " extracted" << endl;
            data[0] = data[curr_size-1];
            curr_size--;
            min_heapify(0);
            return true;
        }

        int delete_node(int index) {
            decrease(index, INT_MIN);
            int min = get_min();
            extract_min();
            return min;
        }

        void min_heapify(int index) {
            int left = get_left_child(index);
            int right = get_right_child(index);
            int smallest = index;
            if(left < curr_size && data[left] < data[index])
                smallest = left;
            if(right < curr_size && data[right] < data[smallest])
                smallest = right;
            if(smallest != index) {
                swap(&data[index], &data[smallest]);
                min_heapify(smallest);
            }
        }

        void resize_heap(int new_capacity) {
            capacity = new_capacity;
            delete(data);
            data = new int[new_capacity];
            curr_size = 0;
        }

        void print_heap() {
            if(curr_size <= 0)
                return;
            cout << endl;
            queue<int> heap_nodes;
            heap_nodes.push(0);
            int prev_level = 0;
            while(!heap_nodes.empty()) {
                int index = heap_nodes.front();
                if((index+1)/2 > prev_level)
                    cout << endl;
                cout << data[index] << " ";

                prev_level = (index + 1)/2;
                heap_nodes.pop();
                int left = get_left_child(index);
                int right = get_right_child(index);
                if(left < curr_size)
                    heap_nodes.push(left);
                if(right < curr_size)
                    heap_nodes.push(right);
            }

            cout << endl;
        }

        void print_heap_array() {
            for(int i=0; i<curr_size; i++) {
                cout << data[i] << " ";
            }

            cout << endl;
        }
};