n = int(input())
sum = 0
a = []
b = []
for i in range(0, n):
    c = input()
    c = c.split()
    a.append(int(c[0]))
    b.append(int(c[1]))
    sum += a[i] - b[i]
v = abs(sum)
ans = -1
for i in range(0, n):
    vv = sum - 2*(a[i] - b[i])
    vv = abs(vv)
    if(vv > v):
        v = vv
        ans = i
print(ans + 1)