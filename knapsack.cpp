#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int id;
    float profit, weight;
    float ratio;
};

void solve(vector<Item> items, float capacity, string method) {
    float totalProfit = 0.0;

    cout << "\n===== " << method << " =====\n";
    cout << "Item\tTaken\tProfit\tWeight\n";

    for (auto &item : items) {
        if (capacity <= 0)
            break;

        if (item.weight <= capacity) {
            capacity -= item.weight;
            totalProfit += item.profit;

            cout << item.id << "\t1\t"
                 << item.profit << "\t"
                 << item.weight << endl;
        } else {
            float frac = capacity / item.weight;
            totalProfit += item.profit * frac;

            cout << item.id << "\t" << frac << "\t"
                 << item.profit * frac << "\t"
                 << capacity << endl;

            capacity = 0;
        }
    }
    cout << "Total Profit = " << totalProfit << endl;
}

int main() {
    int n;
    float capacity;

    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter Profit and Weight:\n";
    for (int i = 0; i < n; i++) {
        items[i].id = i + 1;
        cin >> items[i].profit >> items[i].weight;
        items[i].ratio = items[i].profit / items[i].weight;
    }

    cout << "Enter Capacity: ";
    cin >> capacity;

    // ---- Method 1: By Profit ----
    vector<Item> byProfit = items;
    sort(byProfit.begin(), byProfit.end(), [](Item a, Item b) {
        return a.profit > b.profit;
    });

    // ---- Method 2: By Weight ----
    vector<Item> byWeight = items;
    sort(byWeight.begin(), byWeight.end(), [](Item a, Item b) {
        return a.weight < b.weight;
    });

    // ---- Method 3: By Ratio ----
    vector<Item> byRatio = items;
    sort(byRatio.begin(), byRatio.end(), [](Item a, Item b) {
        return a.ratio > b.ratio;
    });

    solve(byProfit, capacity, "Greedy by Profit");
    solve(byWeight, capacity, "Greedy by Weight");
    solve(byRatio, capacity, "Greedy by Profit/Weight Ratio");

    return 0;
}