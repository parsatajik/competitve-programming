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
 
    int t, n;
 
    cin >> t;
 
    while (t) {

        cin >> n; 

        int a[n], l = 0, r = n - 1, ans = 0;
        
        for (int i = 0; i < n; i++)
            cin >> a[i];

        while (l < r) {
            if (a[r] == 0 && a[l] == 1) {
                ans++;
                r--;
                l++;
            } else if (a[r] == 1 && a[l] == 1) {
                r--;
            } else if (a[r] == 0 && a[l] == 0) {
                l++;
            } else {
                r--;
                l++;
            }
        }
        cout << ans << '\n';

        t--;
    }
}