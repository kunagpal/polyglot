r = ['NO', 'YES']
for i in range(int(input())):
    a, b = map(int, input().split())
    g, k, l = [input() for j in range(a)], -1, 0
    x, y = map(int, input().split())
    p = [input() for j in range(x)]

    while k < a - 1 and x - l <= a - k and l < x:
        k += 1
        T = set([j for j, _ in enumerate(g[k]) if g[k].startswith(p[l], j)])

        if not(T) or (l and not(T & Z)):
            if k and Z: k -= 1
            l, Z = 0, set()
        else:
            if l: Z &= T
            else: Z = T

            l += 1   

    print(r[l == x])
