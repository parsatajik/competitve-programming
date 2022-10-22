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

        ll a, b, c, d;

        cin >> a >> b >> c >> d;
        
        bool f = false;

        for (ll i = a+1; i <= c; i++) {

            if (i % (a*b) == 0) {
                cout << i << ' ' << b+1 << '\n';
                f = true;
                break;
            } else if (i % a == 0) {
                if (2*b <= d) {
                    cout << i << ' ' << 2*b << '\n';
                    f = true;
                    break;
                }
            } else {

                ll k = floor(i*(b+1)/(a*b));

                // cout << k << endl;

                while (a * b * k / i <= d) {
                    if ((a*b*k) % i == 0 && a * b * k / i > b) {
                        cout << i << ' ' << a * b * k / i << '\n';
                        f = true;
                        break;
                    }

                    k++;
                }
            }
            

            if (f)
                break;
        }

        if (!f)
            cout << "-1 -1\n";
 

        t--;
    }
}