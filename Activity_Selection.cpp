#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity {
    int id;
    int start;
    int finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n;

    cout << "Enter number of activities: ";
    cin >> n;
    vector<Activity> act(n);
    cout << "Enter start and finish time:\n";
    for (int i = 0; i < n; i++) {
        act[i].id = i + 1;
        cin >> act[i].start >> act[i].finish;
    }
    sort(act.begin(), act.end(), compare);

    cout << "\nSelected Activities:\n";

    int i = 0;
    cout << "Activity " << act[i].id 
         << " (" << act[i].start 
         << ", " << act[i].finish << ")\n";

    int lastFinish = act[i].finish;

    for (int j = 1; j < n; j++) {
        if (act[j].start >= lastFinish) {
            cout << "Activity " << act[j].id 
                 << " (" << act[j].start 
                 << ", " << act[j].finish << ")\n";

            lastFinish = act[j].finish;
        }
    }
    return 0;
}