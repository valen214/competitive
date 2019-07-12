

n = int(input())
x, y = [[None]*n for i in range(2)]


def slope(x, y, a, b):
    if x == a: return None
    return (y - b) / (x - a)

def collin(x, y, a, b, s):
    if x == a and s == None: return True
    return (y - b) / (x - a) == s

ans = 0
for i in range(n):
    x[i], y[i] = [int(i) for i in input().split(" ")]
    
    _x, _y = x[i], y[i]
    
    pts = []
    slopes = []
    
    for j in range(i):
        s = slope(_x, _y, x[j], y[j])
        
        if slope in slopes:
            
            for k, s1 in enumerate(slopes):
                if s == s1 and collin(*pts[k], _x, _y, s):
                    break
            else:
                ans += 1
                
        else:
            slopes.append(s)
            pts.append((x[j], y[j]))
            ans += 1
            
print(ans)