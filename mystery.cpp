#include<cstdio>

int main()
{
    long long N;

    while (scanf("%lld",&N)!=EOF)

    {

        int output = 0;
        while (N)
        {
            output = output + (N % 2);
            N /= 2;
        }
        printf("%d\n",output);
    }
}
