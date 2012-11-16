
def facto(x): return (1 if x==0 else x * facto(x-1))    

n=int(raw_input("Indique el numero de 'filas' del triangulo: "))

for i in range(n):
	print (n-i)*' ',
	for j in range(i+1):
                if ((facto(i)/(facto(j)*facto(i-j)))%2 == 0):
			print '.',
		else: 
			print 'A',
	print
