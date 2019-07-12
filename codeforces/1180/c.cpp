#include <bits/stdc++.h>

typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int main(){
    ull n, q;
    cin >> n >> q;
    vector<ull> v(2 * n + 5);
    vector<string> out(n + 5);
    int left = 0;
    int right = n-1;
    ull largest = 0;
    for(int i = 0; i < n; ++i){
        cin >> v[i];
        if(v[i] > largest) largest = v[i];
    }
    while(v[left] != largest){
        out[left] = to_string(v[left]) + " " + to_string(v[left+1]);
        if(v[left] > v[left+1]){
            v[right+1] = v[left+1];
            v[left+1] = v[left]; // ABXXX => _AXXXB
        } else{
            v[right+1] = v[left]; // ABXXX => _BXXXA
        }
        ++left;
        ++right;
    }

#if 0
    for(int i = 0; i < left; ++i){
        cout << out[i] << endl;
    }
    for(int i = 0; i < n; ++i){
        cout << v[left+i] << " ";
    }
    cout << endl << "left: " << left << endl;
#endif

    ull m;
    for(ull i = 0; i < q; ++i){
        cin >> m;
        --m;
        if(m < left){
            cout << out[m] << endl;
        } else{
            m -= left;
            m %= (n-1);
            // cout << "m: " << m << endl;
            cout << largest << " " << v[left + m + 1] << endl;
        }
    }
}
