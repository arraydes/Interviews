#include <iostream>
#include <unordered_set>

using namespace std;

// Create a hashset to store the sum of the squares of each of the number's digits
// If the sum is already in the set, the number is never going to reach 1, so stop the
// loop and return false
// If the sum is equal to 1, stop the loop and return true
// A helper function is needed to calculate the sum of the squares of each digit
int sumDigits(int n) {
    int res = 0;

    while (n > 0) {
        int digit = n % 10;
        res += (digit * digit);
        n /= 10;
    }

    return res;
}

bool isHappy(int n) {
    int sum = sumDigits(n);
    if (sum == 1) return true;

    unordered_set<int> sums;

    while(!sums.count(sum)) {
        sums.insert(sum);
        sum = sumDigits(sum);

        if (sum == 1) return true;
    }

    return false;
}

int main() {
    cout<<isHappy(19)<<endl;
    cout<<isHappy(2)<<endl;
    
    return 0;
}