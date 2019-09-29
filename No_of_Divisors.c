#include<stdio.h>
long long no_of_div(long long  x)
{
long long count = 0, i;
for(i=1;i*i<=x;i++)
{
    if(i != x/i) {
        if(x % i == 0)
            count = count + 2;
    }
    else {
        count = count + 1;
    }
}
return count;
}


long long main()
{
    long long n,t;
    scanf("%lld",&t);
    while(t) {
        scanf("%lld",&n);
        printf("%lld\n",no_of_div(n));
        t = t - 1;
    }

return 0;
}

