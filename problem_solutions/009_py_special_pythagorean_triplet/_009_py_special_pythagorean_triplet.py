
def pythagorean_triplet():
    for a in range(1, 998 + 1):
        for b in range(a + 1, 998):
            for c in range(b + 1, 998):
                if a + b + c == 1000 and a*a + b*b == c*c:
                    return a*b*c

print(pythagorean_triplet())
