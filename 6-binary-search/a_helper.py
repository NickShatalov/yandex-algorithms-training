import numpy as np
import sys


def main():
    ans = np.random.randint(0, 1000000001, 2)
    prev_a, prev_b = None, None
    n = 0
    while True:
        s = input()
        if (s[0] == 'A'):
            _, a, b = s.split()
            if ans[0] == int(a) and ans[1] == int(b):
                sys.stderr.write(f"OK\tattempts:\t{n}")
            else:
                sys.stderr.write("BAD")
            return
        a, b = map(int, s.split())
        n += 1
        if prev_a is None or prev_b is None:
            print(0)
            prev_a = a
            prev_b = b
            continue
        if (a - ans[0]) ** 2 + (b - ans[1]) ** 2 < (prev_a - ans[0]) ** 2 + (prev_b - ans[1]) ** 2:
            print(1)
        else:
            print(0)
        prev_a = a
        prev_b = b


if __name__ == "__main__":
    main()
