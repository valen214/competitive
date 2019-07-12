



#define NEED_PRIME 0
#if NEED_PRIME

const ull MAX_VAL = 1000000009;
bool p[MAX_VAL];
void init(){
    fill_n(p, MAX_VAL, 1);
    p[0] = p[1] = 0;

    ull i = 2;
    ull sqrt_max = sqrtl(MAX_VAL) + 2;
    while(i < sqrt_max){
        if(p[i]){
            for(ull j = i * 2; j < MAX_VAL; j += i) p[j] = 0;
        }
        ++i;
    }
}

#endif
