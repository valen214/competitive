

n, m = [int(i) for i in input().split(" ")]

m1 = [None] * n
m2 = [None] * n


for mtx in [m1, m2]:
    for i in range(n):
        mtx[i] = [int(i) for i in input().split(" ")]

possible = True
for i in range(n):
    for j in range(m):
        if m1[i][j] > m2[i][j]:
            m1[i][j], m2[i][j] = m2[i][j], m1[i][j]
        
        if i > 0:
            if (m1[i][j] <= m1[i-1][j] or
                    m2[i][j] <= m2[i-1][j]):
                possible = False
                break
        
        if j > 0:
            if ( m1[i][j] <= m1[i][j-1] or
                    m2[i][j] <= m2[i][j-1]):
                possible = False
                break
    else:
        break

print("Possible" if possible else "Impossible")
