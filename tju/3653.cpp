#include <cstdio>
#include <cstring>
#define MAXN 40000000

bool prime[MAXN + 2];

void sieve()
{
	memset( prime, 1, sizeof prime);
	prime[0] = prime[1] = 0;
	for(int i = 2; i*i <= MAXN; i++)	
		if( prime[i] )
			for(int j = i*i; j <= MAXN; j += i )
				prime[j] = 0;
}

int main()
{
	sieve();
	for(int i = 30000000; i <= MAXN; i++)
		if( prime[i] ) printf("%d\n", i);
}
