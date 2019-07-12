#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>

typedef long long ll;

#define forab(i, a, b) for(ll i=a, max=b; i < b; ++i)
#define repeat(i, n) for(ll i=0, max=n; i < max; ++i)
#define bit(n, i) ((n >> i) & 1)
#define bin(n, l) ( bitset<l>(n).to_string() )
#define max(a, b) ( a > b ? a : b )
#define min(a, b) ( a > b ? b : a )

using namespace std;

int main() {
	ll T;
	cin >> T;
	repeat(i, T){
	    ll D;
	    string S;
	    cin >> D >> S;
	    
	    if(D <= 4){
	        int c = 0;
	        repeat(j, D){ if(S[j] == 'P') ++c; }
	        if(c * 4 >= D * 3){
	            cout << 0 << endl;
	        } else{
	            cout << -1 << endl;
	        }
	        continue;
	    }
	    
	    unsigned int cursor = 0;
	    ll realP = 0;
	    ll allP = 0;
	    
	    const ll target = D * 3;
	    
	    repeat(j, 5){
	        if(S[j] == 'P'){
	            cursor += (1 << (4-j));
	            realP += 1;
	            allP += 1;
	        }
	    }
	    
	    forab(j, 2, D-2){
	        if(!( cursor & 0b00100 )){
	            if(( cursor & 0b11000 ) && ( cursor & 0b00011 )){
	                // cursor |= 0b00100;
	                ++allP;
	            }
	        }
            cursor <<= 1;
            if(( j+3 < D ) && ( S[j+3] == 'P' )){
                ++cursor;
                ++realP;
                ++allP;
            }
            cursor &= 0b11111;
	    }
	    
	    
        ll req = ceil(target / 4.0);
        if(allP >= req){
	        cout << min(allP - realP, max(req - realP, 0 )) << endl;
	        // cout << allP << " " << realP << " " << req << " " << S << endl;
        } else{
            cout << -1 << endl;
        }
	}
}
