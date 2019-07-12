
#include <iostream>

using namespace std;

int main(int argc, char **argv){
    int n, m, r;

    cin >> n >> m >> r;

    long long min_b;
    long long ll;
    cin >> ll;
    min_b = ll;
    for(int i = 1; i < n; ++i){
        cin >> ll;
        if(ll < min_b){
            min_b = ll;
        }
    }
    long long max_s = 0;
    for(int i = 0; i < m; ++i){
        cin >> ll;
        if(ll > max_s){
            max_s = ll;
        }
    }

    if(min_b < max_s){
        cout << (r / min_b * max_s) + r % min_b;
    } else{
        cout << r;
    }
    
}