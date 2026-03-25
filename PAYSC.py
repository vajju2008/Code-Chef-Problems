import sys

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    X = int(input_data[0])
    
    cost_scheme_1 = 100 + (4 * X) # to find the single integee
    cost_scheme_2 = 300
    
    print(min(cost_scheme_1, cost_scheme_2))

if __name__ == "__main__":
    solve()