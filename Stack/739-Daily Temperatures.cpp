#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    // Create the result list
    // Store the day (index) and the temperature in that day into a monotonic decreasing stack
    // Iterating through the array comparing the current temperature to the top of the stack
    // if the one at the top is colder, pop it from the stack and save the difference between the current
    // day and the day of that colder temperature
    // If it is not colder, save the day and temperature into the stack
    int n = temperatures.size();
    vector<int> result(n); // Automatically initialized to 0
    stack<pair<int, int>> s;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top().second < temperatures[i]) {
            int colderDay = s.top().first;
            result[colderDay] = i - colderDay;
            s.pop();
        }

        s.push({i, temperatures[i]});
    }

    return result;
}

int main() {
    vector<int> input = {73,74,75,71,69,72,76,73};
    vector<int> output = dailyTemperatures(input);

    for (int n: output) {
        cout<<n<<" "<<endl;
    }
    
    return 0;
}