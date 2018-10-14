//playNum.cpp
#include<stdio.h>
#include<math.h>
int main()
{
	int N, q, scan,i;
	scanf("%d %d" , &N, &q);
	long int a[N];
	a[0] = 0;
	for ( i = 1; i <= N; ++i)
	{	do {
			scanf("%d" , &scan);
			a[i] = scan + a[i - 1];
		} while ( a[i] < 1 && a[i] > 1000000000);
	}
	int ql, qr, sum;
	for ( i = 1; i <= q; ++i)
	{
		scanf("%d %d" , &ql, &qr);


		sum = floor((a[qr] - a[ql - 1]) / (qr - ql + 1));
		printf("%d\n", sum);



	}
	return 0;

}