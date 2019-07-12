#!/bin/python

"""

https://codeforces.com/contest/1077/standings/page/1
"""

def main():
    t = int(input())
    while t > 0:
        a, b, k = [int(x) for x in input().split(" ")]
        
        if k % 2 == 0:
            print((a - b) * int(k / 2))
        else:
            print((a - b) * int(k / 2) + a)
        t -= 1
    
    
    
if __name__ == "__main__":
    main()