#include <iostream>
#include <set>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    set<int> ss;

    for (int x = 0; x <= b; ++x)
        for (int y = 0; a * x + y * b <= a * b; ++y) {
            ss.insert(ss.end(), a * x + y * b);
        }

    for (int i = a * b; i >= 0; i--)
        if (ss.find(i) == ss.end()) {
            cout << i;
            break;
        }
    return 0;
}
