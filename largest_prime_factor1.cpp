

/******************************************************************************

https://practice.geeksforgeeks.org/problems/largest-prime-factor/0

*******************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

map<long long, long long> factor_map;
map<long long, long long>::iterator it;

long long factor(long long n){
    if(factor_map.empty()){
        factor_map[0] = 0;
        factor_map[1] = 1;
    }
    
    long long factor = 1;
    
    it  = factor_map.find(n);
    if(it == factor_map.end()){
        long long l, m;
        for(l = 2; l <= n; ++l){
            it = factor_map.find(l);
            if(it == factor_map.end()){
                for(m = l; m <= n; m+=l){
                    factor_map[m] = l;
                }
            }
        }
    } else{
        factor = factor_map[n];
    }
    return factor;
}

int main(int argc, char **argv){
    int T;
    long long N;
    vector<long long> inputs;
    long long max = 0;
    
    cin >> T;
    while(T--){
        cin >> N;
        inputs.push_back(N);
        if(N > max){
            max = N;
        }
    }
    
    factor(max);
    for(auto const& n : inputs){
        cout << factor(n) << endl;
    }
    
    return 0;
}
