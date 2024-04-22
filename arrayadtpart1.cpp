#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Array
{
    int A[20];
    int size;
    int length;
};
void insert(Array *arr,int x,int d)
{
    int i;
    if(d>0 && d<=arr->length)
    {
    for(int i=arr->length-1;i>=d;i--)
    {
        arr->A[i+1]=arr->A[i];
    }
    arr->A[d]=x;
    arr->length++;
    }
}
void append(Array *arr,int x)
{
    if(arr->size>arr->length)
    {
        arr->A[arr->length]=x;
        arr->length++;
    }
}
void Delete(struct Array *arr,int index)
{
    if(index<arr->length)
    {
        for(int i=index;i<(arr->length-1);i++)
        {
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
    }
}
int linearsearch(Array arr,int x)
{
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]==x)
        {
            return i;
        }
    }
    return -1;
}
void swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int linearsearch1(Array *arr,int x)
{
    for(int i=0;i<arr->length;i++)
    {
        if(arr->A[i]==x)
        {
            swap(&arr->A[i],&arr->A[i-1]);
            return i-1;
        }
    }
    return -1;
}
int binary(Array arr,int key)
{
    int l,h;
    l=0;
    h=arr.length-1;
    int m=(l+h)/2;
    while(l<=h)
    {
        int m=(l+h)/2;
        if(arr.A[m]==key)
        {
            return m;
        }
        else
        if(arr.A[m]>key)
        {
            h=m-1;
        }
        else
        {
            l=m+1;
        }
    }
    return -1;
}
int binary1(Array arr,int l,int h,int key)
{
    if(l<=h)
    {
        int mid=(l+h)/2;
        if(arr.A[mid]==key)
        {
            return mid;
        }
        else 
        if(arr.A[mid]>key)
        {
            return binary1(arr,l,mid-1,key);
        }
        else
        {
            return binary1(arr,mid+1,h,key);
        }
    }
    return -1;

}
int get(struct Array arr,int x)
{
    if(x>=0 && x<arr.length)
    {
        return arr.A[x];
    }
    return -1;
}
void Set(struct Array *arr,int x,int key)
{
    if(key>=0 && key<arr->length)
    {
        arr->A[key]=x;
    }
}
int max(struct Array arr)
{
    int max=arr.A[0];
    for(int i=1;i<arr.length;i++)
    {
        if(arr.A[i]>max)
        {
            max=arr.A[i];
        }
    }
    return max;
}
int min(struct Array arr)
{
    int min=arr.A[0];
    for(int i=1;i<arr.length;i++)
    {
        if(arr.A[i]<min)
        {
            min=arr.A[i];
        }
    }
    return min;
}
int sum(struct Array arr)
{
    int sum=0;
    for(int i=0;i<arr.length;i++)
    {
        sum+=arr.A[i];
    }
    return sum;
}
float average(struct Array arr)
{
    return (float)(sum(arr))/arr.length;
}
void reverse(struct Array *arr)
{
    int *a;
    a=(int *)malloc(arr->length*sizeof(int));
    int i,j;
    for(i=0,j=arr->length-1;i<arr->length;i++,j--)
    {
        a[i]=arr->A[j];
    }
    int k;
    for(k=0;k<arr->length;k++)
    {
        arr->A[k]=a[k];
    }
}
void reverse1(struct Array *arr)
{
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
}
void Add(struct Array *arr,int x)
{
    if(arr->size>arr->length)
    {
        int m=arr->length-1;
        while(arr->A[m]>x)
        {
            arr->A[m+1]=arr->A[m];
            m--;
        }
        arr->A[m+1]=x;
        arr->length++;
    }
}
bool sorted(struct Array arr)
{
    int i;
    for(i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]>arr.A[i+1])
        {
            return -1;
        }
    }
    return 1;
}
void rearrange(struct Array *arr)
{
    int i=0;
    int j=arr->length-1;
    while(i<j)
    {
        while(arr->A[i]<0)
        i++;
        while(arr->A[j]>=0)
        j--;
        if(i<j)
        swap(&arr->A[i],&arr->A[j]);
    }
}
struct Array *merge(Array *arr,Array *abb)
{
    struct Array *c;
    c=(struct Array *)malloc(sizeof(struct Array));
    int i,j,k;
    i=j=k=0;
    while(i<arr->length && j<abb->length)
    {
        if(arr->A[i]<abb->A[j])
        c->A[k++]=arr->A[i++];
        else
        if(arr->A[i]>abb->A[j])
        c->A[k++]=abb->A[j++];
        else
        {
            c->A[k++]=arr->A[i++];
            c->A[k++]=abb->A[j++];
        }
        
        
    }
    for(;i<arr->length;i++)
        {
            c->A[k++]=arr->A[i];
        }
        for(;j<abb->length;j++)
        {
            c->A[k++]=abb->A[j];
        }
    c->length=arr->length+abb->length;
    c->size=20;
    return c;
}
struct Array *Union(Array *arr,Array *abb)
{
    struct Array *c;
    c=(struct Array *)malloc(sizeof(struct Array));
    int i,j,k;
    i=j=k=0;
    while(i<arr->length && j<abb->length)
    {
        if(arr->A[i]<abb->A[j])
        c->A[k++]=arr->A[i++];
        else
        if(arr->A[i]>abb->A[j])
        c->A[k++]=abb->A[j++];
        else
        {
            c->A[k++]=arr->A[i++];
            j++;
        }
        
        
    }
    for(;i<arr->length;i++)
        {
            c->A[k++]=arr->A[i];
        }
        for(;j<abb->length;j++)
        {
            c->A[k++]=abb->A[j];
        }
    c->length=k;
    c->size=20;
    return c;
}
struct Array *intersection(Array *arr,Array *abb)
{
    struct Array *c;
    c=(struct Array *)malloc(sizeof(struct Array));
    int i,j,k;
    i=j=k=0;
    while(i<arr->length && j<abb->length)
    {
        if(arr->A[i]<abb->A[j])
        i++;
        else
        if(arr->A[i]>abb->A[j])
        j++;
        else
        {
            c->A[k++]=arr->A[i++];
            j++;
        }
        
        
    }
    c->length=k;
    c->size=20;
    return c;
}
struct Array *subtraction(Array *arr,Array *abb)
{
    struct Array *c;
    c=(struct Array *)malloc(sizeof(struct Array));
    int i,j,k;
    i=j=k=0;
    while(i<arr->length && j<abb->length)
    {
        if(arr->A[i]<abb->A[j])
        c->A[k++]=arr->A[i++];
        else
        if(arr->A[i]>abb->A[j])
       j++;
        else
        {
            i++;
            j++;
        }
        
        
    }
    for(;i<arr->length;i++)
        {
            c->A[k++]=arr->A[i];
        }
       
    c->length=k;
    c->size=20;
    return c;
}


void display(struct Array arr)
{
    printf("elements are\n");
    for(int i=0;i<arr.length;i++)
    {
        printf("%d \n",arr.A[i]);
    }
}

int main()
{
   Array arr={{2,5,7,9,10},20,5};
   printf("array 1\n");
   insert(&arr,8,3);
   append(&arr,11);
   Delete(&arr,1);
   printf("%d\n",linearsearch(arr,9));
   printf("%d\n",linearsearch1(&arr,9));
   display(arr);
   printf("array change\n");
   Array acc={{1,2,3,4,5,6,7},20,7};
   printf("%d\n",binary1(acc,0,6,5));
   display(acc);
   printf("array change\n");
   Array abb={{2,5,1,7,9},20,5};
   printf("%d\n",get(abb,4));
   Set(&abb,6,2);
   printf("%d\n",max(abb));
   printf("%d\n",min(abb));
   printf("%d\n",sum(abb));
   printf("%f\n",average(abb));
   display(abb);
   printf("array change");
   Array add={{1,6,2,9,16,3},20,6};
   reverse1(&add);
   display(add);
   printf("array change\n");
   Array aee={{2,4,6,8,10},20,5};
   Add(&aee,5);
   printf("%d\n",sorted(aee));
   display(aee);
   printf("array change\n");
   struct Array ass={{2,-4,3,4,-5,10,-2},20,7};
   rearrange(&ass);
   display(ass);
   printf("merging of arrays");
   Array a={{1,3,5,6,7},20,5};
   Array b={{2,4,5,7,8,9},20,6};
   Array *c;
   c=merge(&a,&b);
   display(*c);
   printf("elements of union are");
   c=Union(&a,&b);
   display(*c);
   printf("elements of intersection are");
   c=intersection(&a,&b);
   display(*c);
  printf("elements of subtraction are");
   c=subtraction(&b,&a);
   display(*c);
  
   return 0;

}
