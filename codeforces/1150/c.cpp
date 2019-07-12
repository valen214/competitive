
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool is_prime[400002];

void gen_prime(int max){
    for(int i = 0; i <= max; ++i){
        is_prime[i] = true;
    }
    is_prime[0] = false;
    is_prime[1] = false;
    int i = 2;
    int sqrt_max = (int)sqrt(max);
    while(i <= sqrt(max)){
        if(is_prime[i]){
            for(int j = 2; i*j < max; ++j){
                is_prime[i*j] = 0;
            }
        }
        ++i;
    }
}

int main(int argc, char **argv){
    int n;
    cin >> n;
    int ones = 0, twos = 0;
    for(int i = 0; i < n; ++i){
        int j;
        cin >> j;
        if(j == 1) ++ones;
        else if(j == 2) ++twos;
    }
    
    int sum = ones + 2 * twos;
    
    gen_prime(sum);
    
    int now = 0;
    while(ones > 0 || twos > 0){
        if(ones == 0){
            cout << "2 ";
            --twos;
            now += 2;
        } else if(twos == 0){
            cout << "1 ";
            --ones;
            now += 1;
        } else if(ones > 0 && is_prime[now + 1]){
            cout << "1 ";
            --ones;
            now += 1;
        } else if(twos > 0){
            cout << "2 ";
            --twos;
            now += 2;
        } else if(ones > 0){
            cout << "1 ";
            --ones;
            now += 1;
        }
        
    }
}