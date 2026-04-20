#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int carFleet(int target, vector<int> &position, vector<int> &speed) {
    // Create a vector of pairs to store each car's initial position and speed
    // Then sort it in decreasing order, to get the smallest time it takes
    // for a car to arrive at target, given by the formula (target - position)/speed
    // Then create a stack to maintain a monotonic decreasing order of the times to arrive
    // and only push times that maintain said structure, so only cars that
    // take more time that the top are different car fleets
    vector<pair<int, int>> cars; // To store values of position - speed
    stack<double> times; // Has to be double, as integer division rounds up to 0

    for (int i = 0; i < position.size(); i++) {
        cars.push_back({position[i], speed[i]});
    }

    sort(rbegin(cars), rend(cars));

    for (pair <int, int> car: cars) {
        double time = double((target - car.first) / car.second);
        if (!times.empty() && time <= times.top()) {
        } else {
            times.push(time);
        }
    }

    // The amount of elements in the stack 
    return times.size();
}

int main() {
    vector<int> inputPosition = {4, 1, 0, 7};
    vector<int> inputSpeed = {2, 2, 1, 1};

    cout<<"The number of car fleets is: "<<carFleet(10, inputPosition, inputSpeed)<<endl;
    return 0;
}