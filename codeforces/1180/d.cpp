#include <bits/stdc++.h>

typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int width;
    int height;
    cin >> width >> height; // interchanged
    int x = 1;
    int y = 1; // interchanged

    int left = 1;
    int right = width;
    while(left < right){
        for(int j = 0; j < height; ++j){
            cout << left << ' ' << (j+1) << endl;
            cout << right << ' ' << (height-j) << endl;
        }
        ++left;
        --right;
        if(left == right){
            int mid = left;
            for(int i = 0; i < height/2; ++i){
                cout << mid << ' ' << (i+1) << endl;
                cout << mid << ' ' << (height-i) << endl;
            }
            if(height%2) cout << mid << ' ' << (height/2+1) << endl;
            break;
        }
    }
}
