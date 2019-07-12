
#ifdef WTF
/*
/d/GoogleDrive/sync/main-custom-project/code/competitive/codechef/JULY19
d:\GoogleDrive\sync\main-custom-project\code\competitive\codechef\JULY19
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

#include "prime_list.h"
const ull MAX_VAL = 1000000009;
bool p[MAX_VAL];

int main(int argc, char **args){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fstream f("prime_list.txt", fstream::in | fstream::out | fstream::app);
    if(f){
        f.seekg(0, ios_base::end);
        cout << f.tellg() << endl;
    }
    f.seekg(0, ios_base::beg);
    string str;
    f >> str;
    dbg(str);
    exit(0);

    // gen_prime_list(p, MAX_VAL);

    ull product = 1;
    ull i = 2;
    ull b = 2;
    while(b < 1000000000){
        product = b;
        while(!p[++i]);
        b *= i;
    }

    cout << product << endl;
    cout << i << endl;

    ull j = 2;
    while(j < i){
        dbg(((product-1) * (product-1)) % j);
        while(!p[++j]);
    }
    j = 2;

    b = 500004991;
    b *= b;
    while(j < i){
        dbg(b % j);
        while(!p[++j]);
    }



    ull T; cin >> T;
    fori(_t, T){

    }
}
