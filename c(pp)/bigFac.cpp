#include<iostream>
#include<windows.h>
#include<stdio.h>
using namespace std;
main(int argv , char *argc[] )
{
	register int *a=new int[1000000]{1},n,i,x=1,j,f;
	register LARGE_INTEGER p,q,r,p2,q2;
    QueryPerformanceFrequency(&r);
 	if(argv == 2)
	{
		n = atoi(argc[1]);
	}
	else
	{
		cout<<"Enter the no: ";
		cin>>n;
 	}
	cout<<n<<" factorial:\n\n";
 	QueryPerformanceCounter(&p);
 	for(i = 2;i <= n;++i)
 	{
	 	j=-1;
   		while(!a[++j]);
    	a[j] *= i;
  		for(;j < x;++j)
    	{
			f = 0;
	  		if(a[j] > 9)
			{
				f = 1;
				a[j+1] = a[j+1]*i+ (a[j] - (a[j] % 10)) / 10;
				a[j] %= 10;
			}
	  		else
			{
				a[j+1] *= i;
			}
	  		if(f&&(j == x-1))
			{
				 ++x;
			} 
	    }
    }
 	QueryPerformanceCounter(&q);
  	QueryPerformanceCounter(&p2);
 	for(i=x-1;i>=0;--i)
	{
		cout<<a[i];
  	}
	QueryPerformanceCounter(&q2);
 	delete[] a;
 	j=0;
 	while(n)
 	{
 		j+=n/5;
		n/=5;
 	}
	n = q.QuadPart-p.QuadPart;
	i = q2.QuadPart - p2.QuadPart;
	cout<<"\n\n\tDetails:\n_______________________\n\n";
	cout<<x<<" digits.\n";
	cout<<j<<" trailing zeroes.\n";
	cout<<"Calculated in: "<<(long double)n/r.QuadPart<<" s\n";
 	cout<<"Displayed in: "<<(long double)i/r.QuadPart<<" s \n";
 	cout<<"Total time costs: "<<(long double)(n + i)/r.QuadPart<<" s \n";
	cout<<"Hinge Factor: "<<(long double) n / i<<'\n';
}
