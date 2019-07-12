
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void sayNO(){
    cout << "NO" << endl;
    exit(0);
}

int fill_cross(int b[51][51], int n, int x, int y){
    // validate boundary
    if(x-1 >= 0
    && x+1 <= n-1
    && y-1 >= 0
    && y+1 <= n-1
    // fill the cross
    && b[x][y-1] == '.'
    && b[x][y+1] == '.'
    && b[x-1][y] == '.'
    && b[x+1][y] == '.'
    && b[x][y] == '.'){
        b[x][y-1] = '#';
        b[x][y+1] = '#';
        b[x-1][y] = '#';
        b[x+1][y] = '#';
        b[x][y] = '#';
    } else{
        sayNO();
    }
    return 0;
}

int main(int argc, char **argv){
    int n;
    cin >> n;
    int b[51][51];
    
    int empty_count = 0;
    char c;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> c;
            if(c == '.'){
                ++empty_count;
            }
            b[i][j] = c;
        }
    }
    if(empty_count % 5){
        sayNO();
    }

    int l = 0, r = n-1;
    int u = 0, d = n-1; // quadrant IV as (+, +)
    
    int flag = 0;
    while(u != d){
        for(int i = l; i <= r; ++i){
            if(b[i][u] == '.'){
                if(fill_cross(b, n, i, u+1)) sayNO();
            }
        }
        ++u;
        
    }
    
    cout << "YES" << endl;
}