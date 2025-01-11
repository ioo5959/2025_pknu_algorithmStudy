MOD = 10_007
n = int(input())
rectangular = [0] * 1001
rectangular[1] = 1
rectangular[2] = 3

if n >= 3:
  for i in range(3, n+1):
    rectangular[i] = ((rectangular[i-2]*2) + rectangular[i-1]) % MOD

print(rectangular[n])