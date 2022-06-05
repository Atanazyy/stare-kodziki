from random import *;

n = 7
q = 3
w = 5

tab = ['P','Z']

print(n, q)

for i in range(q - 1):
    z = choice(tab)
    print(z , end = ' ')
    if(z == 'P'):
        print(randint(1, n), randint(1, w), randint(1, w))
    if(z == 'Z'):
        a = randint(1, n)
        b = randint(a, n)
        print(a, b)
print("Z 1 1")
