
#include <bits/stdc++.h>

#define min(x, y) (x > y ? y : x)
#define max(x, y) (x < y ? y : x)
#define fori(i, len) for(ull i = 0; i < len; ++i)

typedef unsigned long long ull;

using namespace std;



int main(){
    string a, b;
    cin >> a >> b;

    // dumb implementation
    vector<bool> diff_from_prev(a.size());
    fori(i , a.size()-1){
        if(a[i+1] != a[i]) diff_from_prev[i+1] = 1;
    }

    ull b_size = b.size();
    ull len = a.size() - b_size + 1;
    ull out = 0;
    fori(i, len){
        ull diff_odd = 0;
        fori(j, b_size){
            if(a[i+j] != b[j]) diff_odd = !diff_odd;
        }
        if(diff_odd) ++out;
    }
    cout << out << endl;
}
