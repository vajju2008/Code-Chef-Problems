def solve():
    try:
        line = input().split()
        if not line: return
        N, A, B = map(int, line)
    except EOFError:
        return

    while N >= A:
        N = N - A + B 
    
    print(N)

if __name__ == "__main__":
    try:
        T_str = input().strip()
        if T_str:
            T = int(T_str)
            for _ in range(T):
                solve()
    except EOFError:
        pass