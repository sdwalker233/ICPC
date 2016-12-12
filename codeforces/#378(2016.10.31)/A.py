str = input()
str += 'O'
l = len(str)
last = -1
vowel = {'A', 'E', 'I', 'O', 'U', 'Y'}
ans = 0
for i in range(0, l):
    if str[i] in vowel:
        ans = max(ans, i - last)
        last = i
print(ans)