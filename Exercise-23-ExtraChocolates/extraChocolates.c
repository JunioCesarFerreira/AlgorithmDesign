#include<stdio.h>

typedef long long veryLong;

int main()
{
	int T;
	scanf("%d",&T);

	for(int i=1; i<=T; i++)
    {
		veryLong total = 0, a_i;
		int n,b,s;

		scanf("%d%d",&n,&b);

		for(int j=1; j<=b; j++)
        {
			scanf("%d",&s);
			a_i = 1;
			for(int k=1; k<=s; k++)
            {
				int temp;
				scanf("%d",&temp);
				a_i*=temp;
				a_i%=n;
			}
			total+=a_i;
		}
		printf("%llu\n",total%n);
	}
	return 0;
}