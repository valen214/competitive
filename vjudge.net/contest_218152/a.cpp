
// #include <bits/stdc++.h>
#include <cstdio>

// https://vjudge.net/contest/218152#problem

// cd $(cygpath -u "D:\workspace\main-custom-project\code\competitive\vjudge.net\contest_218152")
// explorer $(cygpath -w $(pwd))

int main(int argc, char **argv){
    int i;
    int j;
    int n;
    
    scanf("%d", &n);
    
    int *x = new int[n];
    int *y = new int[n];
    int *lv = new int[n];
    int *amt = new int[n];
    
    for(i = 0; i < n; ++i){
        x[i] = y[i] = lv[i] = amt[i] = 0;
    }
    
    for(i = 0; i < n; ++i){
        scanf("%d %d", &x[i], y+i);
        
        for(j = 0; j < i; ++j){
            if(x[i] == x[j]){
                if(y[i] > y[j]){
                    lv[i]++;
                }
                if(y[i] < y[j]){
                    lv[j]++;
                }
            } else if(x[i] < x[j]){
                if(y[i] <= y[j]){
                    lv[j]++;
                }
            } else if(y[i] >= y[j]){
                lv[i]++;
            }
        }
    }
    
    for(i = 0; i < n; ++i){
        amt[lv[i]]++;
    }
    
    for(i = 0; i < n; ++i){
        printf("%d\n", amt[i]);
    }
    
    return 0;
}