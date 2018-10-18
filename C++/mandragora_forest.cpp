#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long T;
    cin >> T;

    long N;
    for (long t=0; t<T; t++) {
        cin >> N;
        vector<long> monsters(N);

        // Calculate sum of monster health as we gather input
        long sum_health = 0;
        long h;
        for (long n=0; n<N; n++) {
            cin >> h;

            sum_health += h;
            monsters[n] = h;
        }

        // Consider monsters in sorted order
        sort(monsters.begin(), monsters.end());

        long max_xp = -1;
        for (int s=1; s<=N; s++) {
            max_xp = max(s*sum_health, max_xp);
            if (max_xp != s*sum_health)
                break;

            sum_health -= monsters[s-1];
        }

        cout << max_xp << endl;
    }

    return 0;
}
