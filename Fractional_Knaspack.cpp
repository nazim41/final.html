#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Item {
    int value, weight;
    Item(int value, int weight) : value(value), weight(weight) {}
};


bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}


double fractionalKnapsack(int W, vector<Item> &arr, int n) {

    sort(arr.begin(), arr.end(), compare);

    double maxValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {

        if (currentWeight + arr[i].weight <= W) {
            currentWeight += arr[i].weight;
            maxValue += arr[i].value;
        } else {

            int remain = W - currentWeight;
            maxValue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }

    return maxValue;
}

int main() {
    int W = 50;
    vector<Item> arr = {{60, 10}, {100, 20}, {120, 30}};
    int n = arr.size();

    cout << "Maximum possible value = " << fractionalKnapsack(W, arr, n) << endl;
    return 0;
}

