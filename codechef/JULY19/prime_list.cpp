
#include "prime_list.h"
#include <bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

ull MAX = 0;

vector<bool> cache;
void fill_cache(ull length){
    if(length > MAX){
        MAX = length;
        cache.resize(length);
    }
    fstream f("prime_list.txt", fstream::in | fstream::out | fstream::app);
    if(f){
        f.seekg(0, ios_base::end);
        cout << f.tellg() << endl;
    }

    auto p = cache;
    // fill_n(p, length, 1);
    p[0] = p[1] = 0;

    ull i = 2;
    ull sqrt_max = sqrtl(length) + 2;
    while(i < sqrt_max){
        if(p[i]){
            for(ull j = i * 2; j < length; j += i) p[j] = 0;
        }
        ++i;
    }
}

void gen_prime_list(bool p[], ull length){
    fill_cache(length);

    for(ull i = 0; i < length; ++i){
        p[i] = cache[i];
    }
}
