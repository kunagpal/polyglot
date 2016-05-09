n = int(input())
for i in range(2 * n - 1):
 t = int(abs(n - i - 1))
 print('-'.join([chr(97 + t + int(abs(j - (n - t - 1) ))) for j in range(2 * (n - t) - 1)]).center(4 * n - 3, '-'))
