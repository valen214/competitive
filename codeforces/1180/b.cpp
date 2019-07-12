#include <bits/stdc++.h>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<ll> v(n);
    ll index_most_negative = 0;
    for(int i = 0; i < n; ++i){
        cin >> v[i];
        if(v[i] == 0) v[i] = -1;
        if(v[i] > 0) v[i] = -v[i] - 1;
        if(v[i] < v[index_most_negative]){
            index_most_negative = i;
        }
    }
    if(n % 2 == 1){
        v[index_most_negative] = -v[index_most_negative] - 1;
    }

    cout << v[0];
    for(int i = 1; i < n; ++i){
        cout << ' ' << v[i];
    }
    cout << endl;
}
