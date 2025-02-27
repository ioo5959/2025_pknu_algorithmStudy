
n = int(input())
num = list(map(int, input().split()))

#dp[i]는 num[i]를 마지막 원소로 하는 가장 긴 증가하는 부분 수열의 길이 저장
dp = [1] *  n  #dp는 만들 수 있는 수열의 최소값인 1로 초기화

for i in range(n):
    for j in range(i):
        if num[j] < num[i]: #0 ~ i-1까지 num[i]보다 작은 값이 있으면
            dp[i] = max(dp[i], dp[j] + 1) #dp[i](가장 긴 증가하는 부분 수열의 길이) 갱신

print(max(dp)) #dp중 최댓값 출력