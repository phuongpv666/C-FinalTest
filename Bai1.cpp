#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findSecondLargest(const vector<int>& arr) {
    int n = arr.size();
    if (n < 2) {
        return -1;
    }

    int largest = max(arr[0], arr[1]);
    int secondLargest = min(arr[0], arr[1]);

    for (int i = 2; i < n; ++i) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    return secondLargest;
}

int main() {
    int n;
    cin >> n;

    if (n < 2 || n > 100) {
        cout << "Invalid input. n must be between 2 and 100." << endl;
        return 1;
    }

    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int max1 = *max_element(arr.begin(), arr.end());
    int max2 = findSecondLargest(arr);

    cout << max1 << endl;
    cout << max2 << endl;

    return 0;
}
