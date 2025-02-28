
n = int(input())
road = list(map(int, input().split()))
price = list(map(int, input().split()))
total = 0
min_price = price[0]

for i in range(n-1):
    if price[i] < min_price:
        min_price = price[i]
    total += min_price * road[i]

print(total)