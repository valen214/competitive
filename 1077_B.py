#!/bin/python

"""

00000
00001
00010
00011
00100
00101: 00100
00110
00111
01000
01001
01010: 01000
01011: 00011
01100
01101: 









"""


def main():
    t = int(input())
    l = [x == "1" for x in input().split(" ")]
    
    s = 0
    for i in range(1, t-1):
        if l[i-1] and not l[i] and l[i+1]:
            s += 1
            l[i+1] = 0
    print(s)
    
    
if __name__ == "__main__":
    main()