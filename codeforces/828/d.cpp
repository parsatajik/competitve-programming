#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <numeric>
#include <math.h>
 
#define pii pair<int, int>
#define ll long long
 
const int N =2000 * 100 + 10;
int lgs[N] = {0};
ll sum[N] = {0};

using namespace std;
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 

    vector < pii > v;

    for (int i = 0; i < N; i++) {
        int j = i;

        while (j%2 == 0 && j) {
            lgs[i]++;
            j /= 2;
        }

        if (i == 0)
            sum[i] = lgs[i];
        else
            sum[i] = sum[i-1] + lgs[i];

        if (lgs[i])
            v.push_back(pii(lgs[i], i));
    }

    sort(v.begin(), v.end());

    int t;
 
    cin >> t;
 
    while (t) {
 
        int n, a, cnt = 0;

        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> a;

            while (a % 2 == 0) {
                cnt++;
                a /= 2;
            }
        }

        if (cnt == n) {
            cout << "0\n";
        } else if (n > cnt + sum[n]) {
            // faster rejects, is this worth it?
            cout << "-1\n";
        } else {
            int curr = n - cnt, pos = v.size() - 1, ans = 0;
            while (curr > 0 && pos >= 0) {
                int idx = v[pos].second, val = v[pos].first;
                if (idx <= n) {
                    ans++;
                    curr -= val;
                }

                pos--;
            }

            cout << ans << '\n';
        }      

        t--;
    }
}