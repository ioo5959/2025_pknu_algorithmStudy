import sys
input = sys.stdin.readline

n = int(input())
numbers = [int(input()) for _ in range(n)]

stack = []
result = []
start = 0

for value in numbers:
  if value > start:
    for i in range(start + 1, value + 1):
      stack.append(i)
      result.append('+')
    start = value

  if not stack or stack[-1] != value:
    print("NO")
    break

  stack.pop()
  result.append('-')
else:
  for r in result:
    print(r)
