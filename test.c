#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    const int SIZE = 4;
    int a[SIZE];
    vector<int> s1(5);
    const int T = s1.size();
    int b[T];
    cout << sizeof(b)/sizeof(*b) << endl;

    char* p1;
    char const* const* p2 = &p1;

    return 0;
}
