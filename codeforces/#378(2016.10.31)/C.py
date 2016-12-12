import sys

a = [0,]
b = [0,]
ans1 = []
ans2 = []
n = int(input())
s = input()
nums = s.split()
for i in range(0, n):
    a.append(int(nums[i]))

k = int(input())
s = input()
nums = s.split()
for i in range(0, k):
    b.append(int(nums[i]))

def f(x, y, z):
    #print(x,y,z)
    pos1 = x
    pos2 = x
    if x == y:
        return 1
    for i in range(x, y + 1):
        if a[i] > a[pos1]:
            pos1 = i
        if a[i] >= a[pos2]:
            pos2 = i
    for i in range(x, y):
        if a[i] == a[pos2]:
            if a[i + 1] < a[i]:
                pos2 = i
    for i in range(x + 1, y + 1):
        if a[i] == a[pos1]:
            if a[i - 1] < a[i]:
                pos1 = i
    if pos1 != x or a[pos1] > a[pos1 + 1]:
        for i in range(0, pos1 - x):
            ans1.append(pos1 - x + z - i)
            ans2.append('L')
        for i in range(0, y - pos1):
            ans1.append(z)
            ans2.append('R')
    elif pos2 != y or a[pos2] > a[pos2 - 1]:
        for i in range(0, y - pos2):
            ans1.append(pos2 - x + z)
            ans2.append('R')
        for i in range(0, pos2 - x):
            ans1.append(pos2 - x + z - i)
            ans2.append('L')
    else:
        return 0

    return 1

lasti = 0
j = 1
sum = 0
for i in range(1, n+1):
    if j > k:
        print('NO')
        sys.exit()
    sum += a[i]
    #print(i, sum, j)
    if sum > b[j]:
        print('NO')
        sys.exit()
    if sum == b[j]:
        if f(lasti + 1, i, j) == 0:
            print('NO')
            sys.exit()
        lasti = i
        j += 1
        sum = 0

if j <= k:
    print('NO')
    sys.exit()

print('YES')
for i in range(0, len(ans1)):
    print(ans1[i], ans2[i])