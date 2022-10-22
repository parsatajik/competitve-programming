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
 
    int t;
 
    cin >> t;
 
    while (t) {
 
        int n;
        char c;
        string s;

        cin >> n >> c >> s;

        if (c == 'g') {
            cout << "0\n";
        } else {
            vector<int> g, cv;

            for (int i = 0; i < n; i++) {
                if (s[i] == 'g') {
                    g.push_back(i);
                    g.push_back(i + n);
                } else if (s[i] == c) { 
                    cv.push_back(i);
                }
            }

            sort(g.begin(), g.end());

            int ans = -1;

            for (int i = 0; i < cv.size(); i++) {
                ans = max(ans, *upper_bound(g.begin(), g.end(), cv[i]) - cv[i]);
            }

            cout << ans << '\n';
        }


        t--;
    }
}