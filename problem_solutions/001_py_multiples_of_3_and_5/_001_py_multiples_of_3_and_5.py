multiple_3 = [x for x in range(3,1000,3)]
multiple_5 = [x for x in range(5,1000,5)]
multiple_15 = [x for x in range(15, 1000, 15)]

print('Sum of all multiples of 3 and 5 is:', sum(multiple_3) + sum(multiple_5) - sum(multiple_15))
