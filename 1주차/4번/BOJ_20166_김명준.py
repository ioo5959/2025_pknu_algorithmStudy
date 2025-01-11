import sys, collections

input = sys.stdin.readline
n, m, k = map(int, input().split())
arr = [input().strip() for _ in range(n)]

# 남, 동, 북, 서, 남동, 남서, 북동, 북서
dx = [1, 0, -1, 0, 1, 1, -1, -1]
dy = [0, 1, 0, -1, 1, -1, 1, -1]

like_dict = collections.defaultdict(int)

def bfs(x, y):
  queue = collections.deque([(x, y, arr[x][y])])

  while queue:
    cx, cy, string = queue.popleft()

    # 문자열 빈도 카운트
    like_dict[string] += 1

    # 문자열의 최대 길이가 5라면 더 이상 확장하지 않음
    if len(string) == 5:
      continue

    for d in range(8):
      nx, ny = (cx + dx[d]) % n, (cy + dy[d]) % m
      queue.append((nx, ny, string + arr[nx][ny]))

for i in range(n):
  for j in range(m):
    bfs(i, j)

result = []
for _ in range(k):
  query = input().strip()
  result.append(like_dict[query])

for r in result:
  print(r)