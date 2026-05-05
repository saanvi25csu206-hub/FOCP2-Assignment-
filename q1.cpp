#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool canPerform(int n, int k, const string& bulbs, int L) {
    int operations = 0;
    for (int i = 0; i < n; ) {
        if (bulbs[i] == '1') {
            operations++;
            i += L; 
        } else {
           
        }
    }
    return operations <= k;
}

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;
    string bulbs;
    cin >> bulbs;

    int low = 1, high = n;
    int ans = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPerform(n, k, bulbs, mid)) {
            ans = mid;    // Try to find a smaller L
            high = mid - 1;
        } else {
            low = mid + 1; // Increase L to reduce operations
        }
    }

    cout << ans << endl;

    return 0;
}