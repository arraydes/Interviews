#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> l;

    int n; cin>>n;

    while (n--) {
        l.push_back(n);
    }

    for (auto x: l)
        cout<<x<<endl;
}