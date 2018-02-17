#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void add(int* a)
{
    int x,d,sw=0;
    int i;
    int k;
    srand((int)time(NULL));
    while(1)
    {
        x=rand()%16;
        for(i=0;i<16;i++)
        {
            if(i==x&&*(a+i)==0)
            {
                sw=1;
                break;
            }
        }
        if(sw==1) break;
    }
    *(a+i)= (rand()%2==0)? 2:1;
}
void w(int *a)
{
    int i,j;
    int k,l;
    int sw=1;
    static int temp[4];
    static int re[4];
    for(j=0;j<4;j++)
    {
        k=0,l=0;
        for(i=0;i<4;i++)
        {
            temp[i]=re[i]=0;
        }
        for(i=0;i<4;i++)
        {
            if((*(a+j+4*i))!=0)
            {
                temp[k]=(*(a+j+4*i));
                k++;
            }
        }
        for(k=0;k<4;k++)
        {
            if((temp[k]!=temp[k+1]&&temp[k]!=0)||k==3)
            {
                re[l]=temp[k];
                l++;
            }
            else if(temp[k]!=0&&temp[k]==temp[k+1])
            {
                re[l]=temp[k]+1;
                k++,l++;
            }
        }
        for(i=0;i<4;i++)
        {
            sw*= (*(a+4*i+j)!=re[i])? 0:1;
            *(a+4*i+j)=re[i];
        }
    }
    if(sw==0) add(a);
}
void s(int *a)
{
    int i,j;
    int k,l;
    int sw=1;
    static int temp[4];
    static int re[4];
    for(j=0;j<4;j++)
    {
        k=0,l=0;
        for(i=0;i<4;i++)
        {
            temp[i]=re[i]=0;
        }
        for(i=3;i>=0;i--)
        {
            if((*(a+j+4*i))!=0)
            {
                temp[k]=(*(a+j+4*i));
                k++;
            }
        }
        for(k=0;k<4;k++)
        {
            if((temp[k]!=temp[k+1]&&temp[k]!=0)||k==3)
            {
                re[l]=temp[k];
                l++;
            }
            else if(temp[k]!=0&&temp[k]==temp[k+1])
            {
                re[l]=temp[k]+1;
                k++,l++;
            }
        }
        for(i=3;i>=0;i--)
        {
            sw*= (*(a+4*i+j)!=re[3-i])? 0:1;
            *(a+4*i+j)=re[3-i];
        }
    }
        if(sw==0) add(a);
}
void A(int *a)
{
    int i,j;
    int k,l;
    int sw;
    static int temp[4];
    static int re[4];
    for(i=0;i<4;i++)
    {
        k=0,l=0;
        for(j=0;j<4;j++)
        {
            temp[j]=re[j]=0;
        }
        for(j=0;j<4;j++)
        {
            if((*(a+j+4*i))!=0)
            {
                temp[k]=(*(a+j+4*i));
                k++;
            }
        }
        for(k=0;k<4;k++)
        {
            if((temp[k]!=temp[k+1]&&temp[k]!=0)||k==3)
            {
                re[l]=temp[k];
                l++;
            }
            else if(temp[k]!=0&&temp[k]==temp[k+1])
            {
                re[l]=temp[k]+1;
                k++,l++;
            }
        }
        for(j=0;j<4;j++)
        {
            sw*= (*(a+4*i+j)!=re[j])? 0:1;
            *(a+4*i+j)=re[j];
        }
    }
        if(sw==0) add(a);
}
void d(int *a)
{
    int i,j;
    int k,l;
    int sw;
    static int temp[4];
    static int re[4];
    for(i=0;i<4;i++)
    {
        k=0,l=0;
        for(j=0;j<4;j++)
        {
            temp[j]=re[j]=0;
        }
        for(j=3;j>=0;j--)
        {
            if((*(a+j+4*i))!=0)
            {
                temp[k]=(*(a+j+4*i));
                k++;
            }
        }
        for(k=0;k<4;k++)
        {
            if((temp[k]!=temp[k+1]&&temp[k]!=0)||k==3)
            {
                re[l]=temp[k];
                l++;
            }
            else if(temp[k]!=0&&temp[k]==temp[k+1])
            {
                re[l]=temp[k]+1;
                k++,l++;
            }
        }
        for(j=3;j>=0;j--)
        {
            sw*= (*(a+4*i+j)!=re[3-j])? 0:1;
            *(a+4*i+j)=re[3-j];
        }
    }
        if(sw==0) add(a);
}
int ex2(int x)
{
    int i,c=1;
    for(i=0;i<x;i++)
    {
        c*=2;
    }
    return c;
}
void pr(int* a)
{
    int i,j;
    printf("-------------------------\n");
    for(i=0;i<4;i++)
    {
        printf("|");
        for(j=0;j<4;j++)
        {
            if(*(a+4*i+j)==0) printf("     |");
            else if(*(a+4*i+j)!=0) printf("%5d|",ex2(*(a+4*i+j)));
        }
        printf("\n-------------------------\n");
    }
    printf("\n");
}
int main()
{
    static int a[4][4];
    char m;
    add(a);
    pr(a);
    while(1)
    {
        scanf("%c",&m);
        switch(m)
        {
            case 'w': {w(a); pr(a); break;}
            case 's': {s(a); pr(a); break;}
            case 'a': {A(a); pr(a); break;}
            case 'd': {d(a); pr(a); break;}
        }
    }
}
