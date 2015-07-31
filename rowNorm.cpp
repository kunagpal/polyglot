#include <iostream>
#include<windows.h>
using namespace std;
main ()
{
	register int n,m,a[6][6]={},i,j,k;
	LARGE_INTEGER x,y,z;
	QueryPerformanceFrequency(&z);
	cout<<"Enter the order:";
	cin>>m>>n;
	cout<<"Enter "<<n*m<<" elements: ";
 	for(i=0;i<m;i++)
	 {
	 	for(j=0;j<n;j++)
		{
			 cin>>a[i][j];
		}
	 }
	QueryPerformanceCounter(&x);
	for(k=0;k<m;++k)
	{
		for(i=k+1;i<m;++i)
		{
			for(j=n-1;j>=k;--j)
			{
			a[i][j]=a[i][j]*a[k][k]-a[i][k]*a[k][j];
			}
		}
	}
	QueryPerformanceCounter(&y);
	for(i=0;i<m;i++)
	{
		cout<<endl;
		for(j=0;j<n;j++)
		{
			cout<<' '<<a[i][j];}
		}
	cout<<"\n Computed in: "<<double(y.QuadPart-x.QuadPart)/z.QuadPart<<" seconds";
}
