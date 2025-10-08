//Program based task
//Code-1:
#include <stdio.h>
int main() {
    int n, x, c = 0;
    printf("Enter size: "); scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    printf("Enter number: "); scanf("%d",&x);
    for(int i=0;i<n;i++) if(a[i]==x){ printf("Found at %d\n",i); c++; }
    printf("Count = %d\n",c);
}

//Code-2:
#include <stdio.h>
int main(){
    int n,x,l=0,h,m,a[100];
    printf("Enter size: "); scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    printf("Enter number: "); scanf("%d",&x);
    h=n-1;
    while(l<=h){
        m=(l+h)/2;
        printf("L=%d H=%d M=%d\n",l,h,m);
        if(a[m]==x){ printf("Found at %d\n",m); return 0; }
        if(a[m]<x) l=m+1; else h=m-1;
    }
    printf("Not found\n");
}

//Code-3:
#include <stdio.h>
#include <math.h>
#include <time.h>
int jumpSearch(int a[], int n, int x){
    int step = sqrt(n), prev = 0;
    while(a[(step<n?step:n)-1]<x){ prev=step; step+=sqrt(n); if(prev>=n) return -1; }
    for(int i=prev;i<step && i<n;i++) if(a[i]==x) return i;
    return -1;
}
int linSearch(int a[], int n, int x){ for(int i=0;i<n;i++) if(a[i]==x) return i; return -1; }
int main(){
    int n=10000,a[n]; for(int i=0;i<n;i++) a[i]=i; int x=9999;
    clock_t t=clock(); linSearch(a,n,x); printf("Linear: %.5f\n",(double)(clock()-t)/CLOCKS_PER_SEC);
    t=clock(); jumpSearch(a,n,x); printf("Jump: %.5f\n",(double)(clock()-t)/CLOCKS_PER_SEC);
}

//Code-4:
#include <stdio.h>
int interp(int a[],int n,int x){
    int low=0,high=n-1,steps=0;
    while(low<=high && x>=a[low]&&x<=a[high]){
        steps++;
        int pos=low+((x-a[low])*(high-low))/(a[high]-a[low]);
        if(a[pos]==x) return steps;
        if(a[pos]<x) low=pos+1; else high=pos-1;
    } return steps;
}
int bin(int a[],int n,int x){
    int l=0,h=n-1,m,steps=0;
    while(l<=h){ steps++; m=(l+h)/2;
        if(a[m]==x) return steps;
        if(a[m]<x) l=m+1; else h=m-1;
    } return steps;
}
int main(){
    int a[100]; for(int i=0;i<100;i++) a[i]=i;
    int x=73;
    printf("Interpolation Steps=%d\n",interp(a,100,x));
    printf("Binary Steps=%d\n",bin(a,100,x));
}

//Code-5:
#include <stdio.h>
int binary(int a[],int l,int h,int x){
    while(l<=h){
        int m=(l+h)/2;
        if(a[m]==x) return m;
        if(a[m]<x) l=m+1; else h=m-1;
    } return -1;
}
int main(){
    int a[1000]; for(int i=0;i<1000;i++) a[i]=i;
    int x=789,i=1;
    while(i<1000 && a[i]<=x) i*=2;
    int idx=binary(a,i/2,i<1000?i:999,x);
    printf("Found at %d\n",idx);
}

//Code-6:
#include <stdio.h>
int main(){
    int a[]={5,3,2,4,1},n=5,pass=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++) if(a[j]>a[j+1]){
            int t=a[j];a[j]=a[j+1];a[j+1]=t;
        } pass++;
    }
    printf("Normal passes=%d\n",pass);
    int b[]={5,3,2,4,1},flag;
    pass=0;
    for(int i=0;i<n-1;i++){
        flag=0;
        for(int j=0;j<n-i-1;j++) if(b[j]>b[j+1]){
            int t=b[j];b[j]=b[j+1];b[j+1]=t;flag=1;
        }
        pass++; if(!flag) break;
    }
    printf("Optimized passes=%d\n",pass);
}
