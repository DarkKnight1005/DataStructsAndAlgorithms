#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>


using namespace std;

#define MAX 1000010

char primes[MAX];

long long m[MAX];

void gen_primes(void)

{

  int i, j;

  for(i = 0; i < MAX; i++) primes[i] = 1;

  for(i = 2; i < sqrt(MAX); i++)

    if (primes[i])

      for(j = i * i; j < MAX; j += i) primes[j] = 0;

}

 

int main(){
    
    long long j, n, l, h, tests, i, ptr = 0;
    gen_primes();

    for(i = 2; i < MAX; i++)

  if (primes[i])

  {

    long long temp = 1LL*i*i;

    while(temp < 1LL*MAX*MAX)

    { 

      m[ptr++] = temp;

      temp *= i;

    }

  }

    sort(m,m+ptr);

   scanf("%lld", &tests);

while(tests--)

{

  scanf("%lld %lld", &l, &h);

  printf("%ld\n", upper_bound(m,m+ptr,h) - upper_bound(m,m+ptr,l-1));

}

    return 0;
}