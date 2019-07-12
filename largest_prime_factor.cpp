

/******************************************************************************

https://practice.geeksforgeeks.org/problems/largest-prime-factor/0

INPUT:
10
123456789
123019284
123091234
123091458
123912453
1231142

*******************************************************************************/

#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

typedef unsigned long long N_TYPE;

vector<N_TYPE> prime_list;
vector<N_TYPE> max_factor_list;

vector<N_TYPE> factor(vector<N_TYPE>& v, N_TYPE max){
    vector<N_TYPE> f(v.size());
    
    bool prime[max+1];
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for(N_TYPE p = 2; p*p <= max; ++p){
        if(prime[p]){
            for(N_TYPE i = p*2; i <= max; i += p){
                prime[i] = false;
            }
            
            // max = 1;
            for(int i = 0; i < v.size(); ++i){
                while((v[i] % p) == 0){
                    f[i] = p;
                    v[i] /= p;
                }
                if(v[i] > max){
                    // max = v[i];
                }
            }
        }
    }
    
    for(int i = 0; i < v.size(); ++i){
        if(prime[v[i]]){
            f[i] = v[i];
        }
    }
    
    return f;
}

int main(int argc, char **argv){
    int T;
    N_TYPE N;
    vector<N_TYPE> inputs;
    N_TYPE max = 0;
    
    cin >> T;
    while(T--){
        cin >> N;
        inputs.push_back(N);
        if(N > 1e7){
            N %= ((long long)1e7+7);
        }
        if(N > max){
            max = N;
        }
    }
    
    vector<N_TYPE> v = factor(inputs, max);
    for(N_TYPE const& n : v){
        cout << n << endl;
    }
    
    return 0;
}
