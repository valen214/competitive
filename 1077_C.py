#!/bin/python

"""

"""


def main():
    n = int(input())
    l = [int(x) for x in input().split(" ")]
    
    s = sum(l)
    o = []
    
    save = []
    
    for i in range(n):
        if l[i] in save:
            o.append(str(i+1))
            continue
        s1 = s - l[i]
        s2 = s1 / 2
        b = l.pop(i)
        if s2.is_integer():
            try:
                a = l.index(int(s2))
                
                o.append(str(i+1))
                save.append(b)
            except ValueError as ve:
                pass
        l.insert(i, b)
    
    print(len(o))
    print(" ".join(o))
    
if __name__ == "__main__":
    main()