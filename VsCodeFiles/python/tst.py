import time

start = time.time()
[x^2 for x in range(100000000)]
end = time.time()
print(end - start)