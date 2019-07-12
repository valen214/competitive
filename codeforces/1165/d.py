
from bisect import *
from math import sqrt, log
t = int(input())

def primeFactors(m):
    prime = {
        0: False,
        1: False
    }
    out = {}
    
    p = 2
    sqrt_m = int(sqrt(m))
    while p <= sqrt_m:
        if not p in prime:
            for i in range(p*2, m, p):
                prime[i] = False
            prime[p] = True
            out[p] = 0
        p += 1
    
    for i in range(sqrt_m-1, m):
        if i in prime and prime[i]:
            out[i] = 0
        elif i not in prime:
            out[i] = 0
    return out

def index(l, x):
    i = bisect_left(l, x)
    if i != len(l) and l[i] == x:
        return i
    return -1

count = primeFactors(1000000)
prime = sorted(count.keys())


while t:
    n = int(input())
    d = [int(i) for i in input().split(" ")]
    largest = 0
    largest_prime = 2

    for i, d1 in enumerate(d):
        if d1 > largest:
            largest = d1

        for p in prime:
            if p > largest_prime:
                largest_prime = p
            
            c = 0
            while d1 % p == 0:
                c += 1
                d1 /= p
            
            if c > count[p]:
                count[p] = c
            
            # print(f"count list: {[count[i] if i in count else 0 for i in range(10)]}")
            if d1 == 1:
                # print(f"list[{i}]={d[i]} break on prime:{p}")
                break

    out = 1
    factors_count = 0
    for i, v in list(count.items()):
        if v:
            factors_count += 1
            out *= i ** v
        count[i] = 0
        if i > largest_prime:
            break
    
    # print(f"largest prime: {largest_prime}")
    if factors_count == 1:
        print(largest_prime * out)
    elif out != min(d) * max(d):
        print(-1)
    else:
        print(out)

    t -= 1