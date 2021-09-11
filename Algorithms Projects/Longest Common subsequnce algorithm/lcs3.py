import sys

dp = [[[-1 for i in range(100)]
           for j in range(100)]
           for k in range(100)]

def lcs(i, j, k):

    if (i == -1 or j == -1 or k == -1):
        return 0

    if (dp[i][j][k] != -1):
        return dp[i][j][k]

    if(x[i] == y[j] and y[j] == z[k]):
        dp[i][j][k] = 1+lcs(i-1, j-1, k-1)

        return dp[i][j][k]
    else:
        dp[i][j][k] = max(max(lcs(i-1, j, k),
                              lcs(i, j-1, k)),
                              lcs(i, j, k-1))

        return dp[i][j][k]


if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    an = data[0]
    data = data[1:]
    x = data[:an]
    data = data[an:]
    bn = data[0]
    data = data[1:]
    y = data[:bn]
    data = data[bn:]
    cn = data[0]
    data = data[1:]
    z = data[:cn]
    print(lcs(len(x)-1, len(y)-1, len(z)-1))
