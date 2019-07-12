

/******************************************************************************

https://practice.geeksforgeeks.org/problems/largest-prime-factor/0

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

vector<long long> prime_list(1, 2);
vector<long long> factor_list(1, 0);

long long next_prime(){
    long long n = prime_list.back()+1;
    bool found = false;
    while(!found){
        found = true;
        for(auto const& p : prime_list){
            if((n % p) == 0){
                found = false;
                break;
            }
        }
        if(found){
            prime_list.push_back(n);
        } else{
            ++n;
        }
    }
    return n;
}

int main(int argc, char **argv){
    int T;
    long long N;
    
    cin >> T;
    long long last_factor = prime_list.back(); // 2
    long long max;
    while(T--){
        cin >> N;
        
        max = prime_list.back();
        if(max == N){
            cout << max << endl;
        } else{
            last_factor = prime_list.front();
            for(auto const& p : prime_list){
                if(p >= N){
                    break;
                } else if((N % p) == 0){
                    last_factor = p;
                }
            }
            if(max < N){
                while(max < N){
                    max = next_prime();
                    if((N % max) == 0){
                        last_factor = max;
                    }
                }
            }
            cout << last_factor << endl;
        }
    }
    return 0;
}
