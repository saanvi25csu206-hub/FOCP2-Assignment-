#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 10000000;

vector<int> spf(MAXN + 1);

void sieve() {
    for (int i = 0; i <= MAXN; i++)
        spf[i] = i;

    for (long long i = 2; i * i <= MAXN; i++) {
        if (spf[i] == i) {
            for (long long j = i * i; j <= MAXN; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int distinctPrime = 0;

        while (n > 1) {
            int p = spf[n];
            distinctPrime++;

            while (n % p == 0)
                n /= p;
        }

        cout << (1 << distinctPrime) << '\n';
    }

    return 0;
}