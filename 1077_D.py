#!/bin/python

"""

0: 6
1: 7
3: 8
4: 9
5: 9

100 42 33 20 19 5

"""
from math import floor

def main():
    n, k = (int(x) for x in input().split(" "))
    l = input().split(" ")
    
    count = {}
    
    for x in l:
        if x in count:
            count[x] += 1
        else:
            count[x] = 1
    
    sorted_count = sorted(count.items(),
            key=lambda kv: -kv[1])[:k]
    
    # print("; ".join("{}: {}".format(x[0], x[1]) for x in sorted_count))
    
    x = sorted_count[0][1]
    for x in range(sorted_count[0][1], 0, -1):
        s = 0
        invalid = True
        for y in sorted_count:
            if s > k or y[1] < x:
                # if s > k: print("WHO")
                break
            s += floor(y[1] / x)
        if s >= k:
            break
    o = []
    while len(o) < k:
        for y in sorted_count:
            if y[1] < x:
                break
            o += [y[0]] * floor(y[1] / x)
    print(" ".join(o[:k]))
    
    
    
if __name__ == "__main__":
    main()