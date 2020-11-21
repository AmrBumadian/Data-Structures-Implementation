#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define EPS 1e-9
#define MOD (int)1e9+7
#define INF (int)1e9
#define pi 3.14
#define el "\n"

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<string, int> mpsi;
typedef map<int, int> mpii;

inline void BOOST() {
    cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0);
}

ll fib[4], m[4];

void multiply(ll F[4], ll M[4]) { // 2x2 Matrix multiplication
    ll x = F[0] * M[0] + F[1] * M[2];
    ll y = F[0] * M[1] + F[1] * M[3];
    ll z = F[2] * M[0] + F[3] * M[2];
    ll w = F[2] * M[1] + F[3] * M[3];
    F[0] = x, F[1] = y, F[2] = z, F[3] = w;
}

void MatrixPower(int n) {
    if (n <= 1) return;
    MatrixPower(n / 2);
    multiply(fib, fib); // square current Fibonacci
    if (n & 1) multiply(fib, m); // if n is odd, multiply Fibonacci matrix by {(1,1),(1,0)} 
}

int main() {
    int n;
    cin >> n;
    fib[0] = fib[1] = fib[2] = m[0] = m[1] = m[2] = 1; // initialize the matrix {(1,1),(1,0)}
    fib[3] = m[3] = 0;
    MatrixPower(n);
    cout << fib[1];
}
