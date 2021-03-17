num = 600851475143
prime = 2
while True:
    if prime == num:
        print(num)
        exit()
    if num % prime == 0:
        print(int(num / prime))
        exit()
    prime +=1
