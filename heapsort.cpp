#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
void maxheapify(int *a,int n,int i)
{
int left,right,temp,largest=i;
left=2*i+1;
right=2*i+2;
if(a[i]<a[left]&&left<n)
{
largest=left;
}
if(a[right]>a[largest]&&right<n)
largest=right;
if(largest!=i)
{
temp=a[i];
a[i]=a[largest];
a[largest]=temp;
maxheapify(a,n,largest);
}
}
void buildmaxheap(int *a,int n)
{
int i;
for(i=(n-1)/2;i>=0;i--)
maxheapify(a,n,i);
}
void heapsort(int *a,int n)
{
int i,temp;
buildmaxheap(a,n);
int heapsize=n;
for(i=n-1;i>=0;i--)
{
temp=a[0];
a[0]=a[i];
a[i]=temp;
heapsize--;
maxheapify(a,heapsize,0);
}
}
void insertion(int *a,int n,int num)
{
int k;
a[n-1]=num;
heapsort(a,n);
}
void deletion(int *a,int *n,int num)
{
int i;
for(i=0;i<*n;i++)
  {
if(a[i]==num)
break;
  }
if(i==*n)
cout<<"not found\n";
else
  {
int temp;
temp=a[i];
a[i]=a[*n-1];
a[*n-1]=temp;
  (*n)--;
heapsort(a,*n);
  }
}
void printtree(int *,int);
int main()
{
int a[50],i,n,num;
printf("enter no. of elements\n");
scanf("%d",&n);
printf("enter\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
heapsort(a,n);
while(1)
{
cout<<"\nenter your choice\n1.insert\n2.delete\n3.display\n4.exit\n";
cin>>i;
switch(i)
{
case 3:
printtree(a,n);
break;
case 2:
cout<<"enter no. you want to delete\n";
cin>>num;
deletion(a,&n,num);
break;
case 1:
n++;
cout<<"enter no. you want to insert\n";
cin>>num;
insertion(a,n,num);
break;
case 4:
exit(0);
break;
}
}
}
void printtree(int *a,int n)
{
int levels=ceil(log2(n+1));
int j,temp=3,t,k,i,space;
for(j=1;j<=levels-2;j++)
temp=2*temp;
int slash;
space=temp-1;
for(i=0;i<levels;i++)
{
slash=(temp/(int)pow(2,i)-1);
if(i==(levels-1))
slash=1;
if(i==1||i==0)
printf("\n");
if(i==0)
{
for(j=0;j<space;j++)
printf(" ");
printf("%d",a[0]);
t=0;
}
else
{
int l,p;
for(l=0;l<=slash;l++)
{
for(j=0;j<(temp)/(int)pow(2,i-1)-l-2;j++)
{
if(l!=slash)
printf(" ");
}
for(k=(t-pow(2,i-1)+1);k<=t;k++)
{
if(2*k+1<n)
{
if(l!=slash)
printf("/");
else
{
if(k==(t-pow(2,i-1)+1))
    {
cout.width(j+1);
cout<<a[2*k+1];
    }
else{
cout.width(p);
cout<<a[2*k+1];
    }
}
}
for(p=1;p<=(1+(l)*2);p++)
{
if(l!=slash)
printf(" ");
}
if(2*k+2<n)
{
if(l!=slash)
printf("\\");
else
{
cout.width(p);
cout<<a[2*k+2];
}
}
if(i>=2)
{
for(p=1;p<=space-2;p++)
{
if(l!=slash)
printf(" ");
}
}
}
if(i>=2)
space=space-2;
printf("\n");
}
t=2*(k-1)+2;
}
}
}

