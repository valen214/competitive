
#ifdef WTF
/*

*/
#endif

#include <bits/stdc++.h>

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

#define forab(i, a, b) for(ll i=a, max=b; i < max; ++i)
#define fori(i, n) for(ll i=0, max=n; i < max; ++i)
#define forr(i, n) for(ll i = n; i >= 0; --i)
#define bit(n, i) ((n >> i) & 1)
#define bin(n, l) ( bitset<l>(n).to_string() )
#define dbg(x) cout << #x << ": " << x << endl;
// #define INT_MAX numeric_limits<int>::max()

// http://www.prime-numbers.org/
#define LARGE_PRIME1 2147483647
#define LARGE_PRIME2 1000000007
#define LARGE_PRIME3 999999937
#define LARGE_PRIME4 500004991

using namespace std;

uint N;
uint Z;
uint A[1000005];

void func1(){
    uint now = Z - 1;
    while(now+1 < N && A[now] == A[now+1]) ++now;

    ull hit = (N - now) * A[now];
    fori(i, Z-1){
        hit += A[now - i];
    }

    cout << hit << endl;
}

int main(int argc, char **args){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    uint T; cin >> T;
    fori(_t, T){
        cin >> N >> Z;
        fori(i, N) cin >> A[i];
        sort(A, A+N);

        ull hit = 0;
        ull acc = 0;
        fori(i, Z){
            ull cur = A[i] - acc;
            if(i == Z-1){
                hit += cur;
            } else{
                hit += cur * (N - i);
            }
            acc += cur;
        }

        cout << hit << endl;
    }
}
