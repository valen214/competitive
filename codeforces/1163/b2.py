

n = int(input())
u = [int(i) for i in input().split(" ")]

max_count = 100001

l = [0] * max_count

last_equals = 0

zero = max_count
one = 0
mode = -1
for i, c in enumerate(u):
    lc = l[c-1]
    if lc == 0:
        zero -= 1
        one += 1
    elif lc == 1:
        one -= 1
    
    l[c-1] += 1
    
    if [j for j in l if j != 0].count(max(l) - 1) == max_count - zero - 1:
        if i != n-1:
            last_equals = i
    else:
        mode = max(set([i for i in l if i != 0]), key=l.count)
        if mode == 1:
            if i+1 == one:
                last_equals = i
                
        elif one == 1 and l.count(mode) + zero == max_count-1:
            last_equals = i
        elif one == 0 and l.count(mode) + zero == max_count-1:
            if i != n-1:
                last_equals = i
            
print(last_equals+1)
        
# only one color is one or one more than any other colors
