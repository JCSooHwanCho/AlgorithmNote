#include<cstdio>


int main() {
    long long n;
    
    scanf("%lld",&n);

    long long sum = n*(n+1) / 2 ;

    int temp;
    for(int i=1;i<n;i++) {
        scanf("%d",&temp);
        sum-=temp;
    }

    printf("%lld\n",sum);
    
    return 0;
}