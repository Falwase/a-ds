
#include "Heap.tpp" 
#include <queue>

int kth_largest(vector<int> values, int k) {

    priority_queue<int> pq;

    for(int i = 0; i < values.size(); i++) {
        pq.push(values[i]);
    }

    for(int i = 1; i < k; i++) {
        pq.pop();
    }

    return pq.top();
}