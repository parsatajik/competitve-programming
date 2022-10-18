#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <numeric>
#include <math.h>
 
#define pii pair<int, int>
#define ll long long
 
#define N 1e9
 
using namespace std;
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t, n, a;
 
    cin >> t;
 
    while (t) {
        cin >> n; 

        int a[n];

        vector < pii > v;

        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i = n - 1; i > 0; i--) {
            int diff = a[i] - a[i-1];

            if (diff < 0)
                v.push_back(pii(diff, i));
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < v.size(); i++) {
            cout << v[i].first << ' ' << v[i].second << endl;
        }

        t--;
    }
}