#include <queue>
#include <iostream>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> MaxHeap;
    priority_queue<int, vector<int>, greater<int>> MinHeap;

public:
    MedianFinder() {

    }

    void addNum(int num) {
        if (MaxHeap.empty() || num < MaxHeap.top()) {
            MaxHeap.push(num);
        } else {
            MinHeap.push(num);
        }

        // Rebalance the heaps
        if (MaxHeap.size() > MinHeap.size() + 1) {
            MinHeap.push(MaxHeap.top());
            MaxHeap.pop();
        } else if (MinHeap.size() > MaxHeap.size() + 1) {
            MaxHeap.push(MinHeap.top());
            MinHeap.pop();
        }
    }

    double findMedian() {
        if (MaxHeap.size() == MinHeap.size()) {
            return (MaxHeap.top() + MinHeap.top()) / 2.0;
        } else if (MaxHeap.size() > MinHeap.size()) {
            return MaxHeap.top();
        } else {
            return MinHeap.top();
        }
    }
};
int main(){
    MedianFinder mf;
    //При необходимости вы можете добавить цифры при помощи mf.addNum(цифра)
    mf.addNum(2);
    mf.addNum(3);
    mf.addNum(4);
    mf.addNum(5);
    double median = mf.findMedian();
    cout << median;
    return 0;
}
