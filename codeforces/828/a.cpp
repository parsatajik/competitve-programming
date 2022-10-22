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
        string s;
        cin >> n;

        int a[n];

        map <int, char> mp;

        for (int i = 0; i < n; i++) 
            cin >> a[i];

        cin >> s;
        
        bool f = false;

        for (int i = 0; i < n; i++) {
            auto ch = mp.find(a[i]);

            if (ch == mp.end())
                mp[a[i]] = s[i];
            else if (ch->second != s[i]) {
                cout << "NO\n";
                f = true;
                break;
            }
        }

        if (!f)
            cout << "YES\n";

        t--;
    }
}