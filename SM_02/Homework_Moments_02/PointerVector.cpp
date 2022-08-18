#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void SortPointers(vector<T*>& v) {
    sort(v.begin(), v.end(), [](auto it1, auto it2) { return (*it1 < *it2); });
}

int main() {
    const int Size = 10;
    int arr[Size];
    for (int i = 0; i < Size; i++) {
        arr[i] = rand();
    }
    vector<int*> vktr;
    int* ptr = nullptr;
    for (int i = 0; i < Size; i++) {
        ptr = &arr[i];
        vktr.push_back(ptr);
    }
    for (auto it : vktr) {
        cout << it << " -> " << *it << endl;
    }
    cout << "\n...Using sort pointers...\n\n";
    SortPointers(vktr);

    for (auto it : vktr)
        cout << it << " -> " << *it << endl;

    return 0;
}