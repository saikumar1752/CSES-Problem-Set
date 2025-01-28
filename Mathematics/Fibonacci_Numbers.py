mod=1000000007
def fib(n):
	if n==0:
		return (0, 1)
	p=fib(n>>1)
	c=(p[0]*(2*p[1]-p[0]))%mod
	d=(p[0]*p[0]+p[1]*p[1])%mod
	if n%2==1:
		return (d, (c+d)%mod)
	else:
		return (c, d)
 
n=int(input())
print(fib(n)[0])