#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

string solve(int n, vector<int>& a) {

    sort(a.begin(), a.end(), greater<int>());

    long long alex = 0, bob = 0;

    set<int> sa, sb;

    for (int i = 0; i < n; i++) {

        // Alex's turn
        if (i % 2 == 0) {
            if (sa.find(a[i]) == sa.end()) {
                alex += a[i];
                sa.insert(a[i]);
            }
        }

        // Bob's turn
        else {
            if (sb.find(a[i]) == sb.end()) {
                bob += a[i];
                sb.insert(a[i]);
            }
        }
    }

    if (alex > bob)
        return "Alex";
    else
        return "Bob";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {

        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        cout << solve(n, a) << '\n';
    }

    return 0;
}