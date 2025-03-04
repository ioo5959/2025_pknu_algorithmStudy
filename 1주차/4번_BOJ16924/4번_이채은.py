import copy
n, m = map(int, input().split())
lis = [list(input()) for _ in range(n)]
lis2 = copy.deepcopy(lis)
result = []
count = 0
flag = True

for i in range(n):
    for j in range(m):
        for k in range(1,min(n,m)):
            if i + k < n and j + k < m and i - k >= 0 and j - k >= 0:
                if lis[i][j] == '*' and lis[i+k][j] == '*' and lis[i-k][j] == '*' and lis[i][j-k] == '*' and lis[i][j+k] == '*':
                    count += 1
                    result.append([i, j, k])
                    lis2[i][j] = '.'
                    lis2[i+k][j] = '.'
                    lis2[i-k][j] = '.'
                    lis2[i][j-k] = '.'
                    lis2[i][j+k] = '.'
                else:
                    break

for i in range(n):
    for j in range(m):
        if lis2[i][j] == '*':
            flag = False
            break

result.sort(key=lambda x:(x[0], x[1], -x[2]))

if not flag:
    print(-1)
else:
    print(count)
    for i in range(len(result)):
        print(result[i][0] + 1, result[i][1] + 1, result[i][2])