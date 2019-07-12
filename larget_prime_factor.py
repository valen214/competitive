#!/bin/python

"""

https://practice.geeksforgeeks.org/problems/largest-prime-factor/0

INPUT:
8
12345678
12301928
12309123
12391245
1231142
54906703
92386574
34694845


"""


from math import sqrt

def main():
    T = int(input())
    v = []
    m = 0
    
    while T > 0:
        v.append(int(input()))
        if v[-1] > m:
            m = v[-1]
        T -= 1
    
    f = [None] * len(v)
    prime = {
        0: False,
        1: False
    }
    
    p = 2
    max_prime = 2
    while p*p <= m:
        if not p in prime:
            for i in range(p*2, int(sqrt(m+1)), p):
                prime[i] = False
            for i, V in enumerate(v):
                tmp = V / p
                if tmp.is_integer():
                    f[i] = p
                    V = tmp
                    tmp /= p
                    while tmp.is_integer():
                        V = tmp
                        tmp /= p
                    
                    v[i] = V
            max_prime = p
        p += 1
    
    for i, V in enumerate(v):
        if V > max_prime and not V in prime:
            f[i] = V
        print(int(f[i]))
    
    

if __name__ == "__main__":
    main()