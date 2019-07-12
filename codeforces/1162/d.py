
from math import sqrt

n, m = [int(i) for i in input().split(" ")]

diff = [set() for i in range(n)]
n_2 = n / 2
for k in range(m):
    i, j = [int(i) for i in input().split(" ")]
    if i > j:
        i, j = j, i
    
    d = j - i
    if d > n_2:
        d = n - d
        i, j = j, i
    diff[d].add(i)

def fac(n):
    
    l = []
    
    if n % 2 == 0:
        l.append(2)
        n /= 2
        while n % 2 == 0:
            n /= 2
    
    for i in range(3, int(sqrt(n))+2, 2):
        if n % i == 0:
            l.append(int(i))
            n /= i
            while n % i == 0:
                n /= i
    
    if n > 2:
        l.append(int(n))
        
    return l

factors = fac(n)

print(factors)
print(f"diff: {diff}")

found = True
for p in factors:
    found = True
    for d, s in enumerate(diff):
        length = len(s)
        if length == 0: continue
        s = s.copy()
        
        last = n
        
        while length > 0:
            last += p
            if last > n:
                last = min(s)
            
            if last in s:
                s.remove(last)
                length -= 1
            else:
                found = False
                break
        
        if not found:
            break
    
    if found:
        print("Yes")
        break
    
if not found:
    print("No")