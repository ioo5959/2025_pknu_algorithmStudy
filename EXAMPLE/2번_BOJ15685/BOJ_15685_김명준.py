def get_directions(d, g):
  directions = [d]
  for _ in range(g):
    for i in range(len(directions) - 1, -1, -1):
      directions.append((directions[i] + 1) % 4)
  return directions


def draw(x, y, directions, grid):
  grid[x][y] = True

  for direction in directions:
    if direction == 0:  # 우
      x += 1
    elif direction == 1:  # 상
      y -= 1
    elif direction == 2:  # 좌
      x -= 1
    elif direction == 3:  # 하
      y += 1
    grid[x][y] = True


def count_squares(grid):
  count = 0
  for x in range(len(grid) - 1):
    for y in range(len(grid[0]) - 1):
      if grid[x][y] and grid[x + 1][y] and grid[x][y + 1] and grid[x + 1][y + 1]:
        count += 1
  return count


LENGTH = 101
grid = [[False] * LENGTH for _ in range(LENGTH)]

n = int(input())
for _ in range(n):
  x, y, direction, generation = map(int, input().split())
  directions = get_directions(direction, generation)
  draw(x, y, directions, grid)

print(count_squares(grid))
