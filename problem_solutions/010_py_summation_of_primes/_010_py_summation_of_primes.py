import math

numbers = [False, False, True] + 999999*[True, False]
primes = [2]

def sieve():
    limit = round(math.sqrt(len(numbers) - 1)) + 1
    for x in range(3, len(numbers), 2):
        if numbers[x] == True:
            primes.append(x)
            if x < limit:
                for y in range(x + 2, len(numbers), 2):
                    if numbers[y] == True and y % x == 0:
                        numbers[y] = False

def sum_primes():
    sieve()
    sum = 0
    for prime in primes:
        sum += prime
    return sum

print(sum_primes())