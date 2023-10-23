
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int kth_largest(vector<int> values, int k) {

    std::priority_queue<int> pq;

    for(int i = 0; i < values.size(); i++) {
        pq.push(values[i]);
    }

    for(int i = 1; i < k; i++) {
        pq.pop();
    }

    return pq.top();
}

int main() {


}