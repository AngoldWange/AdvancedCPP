#include <vector>
#include <iostream>

using namespace::std;

int main() {
    vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter1 = ivec.begin();
    auto iter2 = ivec.end()-1;
    for (int i : ivec) cout << i << " " ;
    cout << endl;

    cout << *iter1 << endl; // 1
    cout << *iter2 << endl; // 9

    *iter2 += *iter1;
    iter1 = ivec.erase(iter1);
    for (int i : ivec) cout << i << " " ;
    cout << endl;

    cout << *iter1 << endl; // 2
    cout << *iter2 << endl; // 10

    *iter2 += *iter1;
    iter1 = ivec.erase(iter1);

    cout << *iter1 << endl; // 3
    cout << *iter2 << endl; // 12
    for (int i : ivec) cout << i << " " ;
    cout << endl;
}
