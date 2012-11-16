
def facto(x): 
    return (1 if x==0 else x * facto(x-1))

def comb(x, y):
    return facto(x)/(facto(x-y)*facto(y))


s = 0
for i in range(45):
    c = comb(i+7, i+1)
    print c
    s += c

print s  % 1000000007
