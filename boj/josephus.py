def solve(N, k):
    people = list(range(1, N+1))
    order = []
    idx = 0
    while len(people) > 0:
        idx = (idx+k-1)%len(people)
        e = people.pop(idx)
        order.append(e)
    return order

N, k = map(int, input().split())
print("<", end = '')
ans = solve(N, k)
for i in range(N):
    print(ans[i], end='')
    if i != N-1:
        print(", ", end='')
    else:
        print(">\n", end='')
