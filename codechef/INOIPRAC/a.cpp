

/*
https://www.codechef.com/INOIPRAC/problems/INOI1402
https://www.codechef.com/INOIPRAC/submit/INOI1402
*/

#include <bits/stdc++.h>


typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define forab(i, a, b) for(ull i=a, max=b; i < max; ++i)
#define fori(i, n) for(ull i=0, max=n; i < max; ++i)
#define forr(i, n) for(ull i = n; i >= 0; --i)
#define bit(n, i) ((n >> i) & 1)
#define bin(n, l) ( bitset<l>(n).to_string() )
#define dbg(x) cout << #x << ": " << x << endl;

using namespace std;

vector<ll> index(235, -1);

const ull MAX_CITIES = 235;

ull cost[MAX_CITIES][MAX_CITIES];
ull count = 0;

int main(int argc, char **args){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ull C, F;
    cin >> C >> F;

    fori(i, MAX_CITIES){
        fori(j, MAX_CITIES){
            cost[i][j] = -1;
        }
    }

    fori(i, F){
        ull c1, c2, p;
        cin >> c1 >> c2 >> p;

        if(index[c1] < 0){
            index[c1] = count;
            ++count;
        }
        if(index[c2] < 0){
            index[c2] = count;
            ++count;
        }

        if(cost[index[c1]][index[c2]] == -1){
            cost[index[c1]][index[c2]] = p;
            cost[index[c2]][index[c1]] = p;
        } else if(p < cost[index[c1]][index[c2]]){
            cost[index[c1]][index[c2]] = p;
            cost[index[c2]][index[c1]] = p;
            fori(j, count){
                if(j == index[c1] || j == index[c2]) continue;
                ull p1 = cost[j][index[c1]];
                ull p2 = cost[j][index[c2]];
                if(p1 != -1 && p2 != -1){
                    if(p1 + p < p2){
                        cost[j][index[c2]] =
                            cost[index[c2]][j] = p1 + p;
                    } else if(p2 + p < p1){
                        cost[j][index[c1]] =
                            cost[index[c1]][j] = p2 + p;
                    }
                } else if(p1 == -1 && p2 != -1){
                    cost[j][index[c1]] =
                        cost[index[c1]][j] = p2 + p;
                } else if(p2 == -1 && p1 != -1){
                    cost[j][index[c2]] =
                        cost[index[c2]][j] = p1 + p;
                }
            }
        }
    }

    return 0;
}
