import math

def isprime(number):
    if number == 2:
        return True
    elif number % 2 == 0:
        return False
    limit = math.ceil(math.sqrt(number))
    for x in range (3, limit, 2):
        if number % x == 0:
            return False
    return True

def generate_primes(number):
    primes = []
    limit = math.ceil(math.sqrt(number))
    for x in range(2, limit):
        if isprime(x):
            primes.extend([x])
    return primes

def number_to_primes(number):
    primes = []
    if number < 0:
        primes.extend([-1])
        number = abs(number)    
    primes.extend(generate_primes(number))

    prime_factors = []
    for x in primes:
        while number % x == 0:
            prime_factors.extend([x])
            number /= x
        if number == 1:
            break
    return prime_factors

def main():
    print('Largest prime factor of 600851475143 is:', max(number_to_primes(600851475143)))

main()