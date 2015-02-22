import math

def binomial_coefficent(n, k):
    return math.factorial(n) // ( math.factorial(k) * math.factorial(n-k) )

print(binomial_coefficent(40,20))