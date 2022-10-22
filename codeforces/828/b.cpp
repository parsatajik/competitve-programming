// lesson learned from this problem:
// do not jump into writing code no matter how easy you think the problem is
// solve it "on paper" first
// then move onto the coding portion

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
 
    // o + o = e
    // e + e = e
    // e + o = o
    // o + e = o

    while (t) {
 
        ll n, o = 0, e = 0, a, q;
        cin >> n >> q;

        ll sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> a;
            sum += a;
            if (a%2)
                o++;
            else
                e++;
        }

        ll type, x;

        for (int i = 0; i < q; i++) {
            cin >> type >> x;

            if (type == 1) {
                sum += o * x;
                if (x % 2 == 1) {
                    // o + o
                    e += o;
                    o = 0;
                } 
            } else {
                sum += e * x;
                if (x % 2 == 1) {
                    // e + o
                    o += e;
                    e = 0;
                }
            }

            cout << sum << '\n';
        }


        t--;
    }
}