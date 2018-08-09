#include <iostream>
#include <vector>
using namespace std;

class QuickSort {
public:
    void sorted(vector<int>::iterator first, vector<int>::iterator last) {
        if (first == last || first + 1 == last) return;
        int pivot = *first;
        vector<int>::iterator pcur = first;
        int temp;
        for (vector<int>::iterator it = first+1; it != last; it ++) {
            if (*it<pivot) {
                temp = *it;
                *it = pivot;
                *pcur = temp;
                pcur ++;
            }
        }
        sorted(first, pcur);
        sorted(pcur, last);
    }
    void vector_display(vector<int>& v) {
        for (vector<int>:: iterator it = v.begin(); it != v.end(); it ++) {
            printf("%d ",*it);
        }printf("\n");
    }
};

int main () {
    vector<int> v;
    for (int i = 0 ; i < 10; i++) {
        v.push_back(100-i);
    }
    QuickSort s;
    s.sorted(v.begin(), v.end());
    s.vector_display(v);
}