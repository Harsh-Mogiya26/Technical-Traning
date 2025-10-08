//Program based task
//1. String Reversal
#include <stdio.h>
#include <string.h>
int main(){
    char s[100]="hello world",a[10]="world",b[10]="C";
    char *p=strstr(s,a);
    if(p){ strncpy(p,b,strlen(a)); }
    printf("%s",s);
}
//2. Replace Substring
#include <stdio.h>
#include <string.h>
int main(){
    char s[100]="hello world",a[10]="world",b[10]="C";
    char *p=strstr(s,a);
    if(p){ strncpy(p,b,strlen(a)); }
    printf("%s",s);
}

//3. Linear Search
#include <stdio.h>
int main(){
    int a[]={1,3,5,7,9},x=7,f=0;
    for(int i=0;i<5;i++) if(a[i]==x) f=1;
    printf(f?"Found":"Not found");
}

//4. Bubble Sort
#include <stdio.h>
int main(){
    int a[]={5,3,2,4,1},n=5,t;
    for(int i=0;i<n-1;i++)
      for(int j=0;j<n-i-1;j++)
        if(a[j]>a[j+1]) t=a[j],a[j]=a[j+1],a[j+1]=t;
    for(int i=0;i<n;i++) printf("%d ",a[i]);
}

//5. Reverse Array
#include <stdio.h>
int main(){
    int a[]={1,2,3,4,5},i,j,t;
    for(i=0,j=4;i<j;i++,j--) t=a[i],a[i]=a[j],a[j]=t;
    for(i=0;i<5;i++) printf("%d ",a[i]);
}

//6. Remove Duplicates
#include <stdio.h>
int main(){
    int a[]={1,2,2,3,3,4,5},n=7;
    for(int i=0;i<n;i++){
        int d=0;
        for(int j=i+1;j<n;j++) if(a[i]==a[j]){d=1;break;}
        if(!d) printf("%d ",a[i]);
    }
}

//7. Merge Two Sorted Arraya
#include <stdio.h>
int main(){
    int a[]={1,3,5},b[]={2,4,6},c[6],i=0,j=0,k=0;
    while(i<3&&j<3) c[k++]=a[i]<b[j]?a[i++]:b[j++];
    while(i<3) c[k++]=a[i++]; while(j<3) c[k++]=b[j++];
    for(i=0;i<6;i++) printf("%d ",c[i]);
}

//8. Read from Text File
#include <stdio.h>
int main(){
    FILE *f=fopen("test.txt","r"); char c;
    while((c=fgetc(f))!=EOF) putchar(c);
    fclose(f);
}

//9. Copy File
#include <stdio.h>
int main(){
    FILE *s=fopen("a.txt","r"),*d=fopen("b.txt","w"); char c;
    while((c=fgetc(s))!=EOF) fputc(c,d);
    fclose(s); fclose(d);
}

//10. Search word in file
#include <stdio.h>
#include <string.h>
int main(){
    FILE *f=fopen("a.txt","r"); char w[50],s[50];
    strcpy(w,"hello");
    while(fscanf(f,"%s",s)!=EOF) if(strcmp(s,w)==0){printf("Found");return 0;}
    printf("Not found");
}

//Project based tasks
//1. Calculator
#include <stdio.h>
int main(){
    float a,b; char o;
    printf("Enter a op b: "); scanf("%f %c %f",&a,&o,&b);
    switch(o){
        case '+': printf("%.2f",a+b); break;
        case '-': printf("%.2f",a-b); break;
        case '*': printf("%.2f",a*b); break;
        case '/': printf(b? "%.2f": "Err",a/b); break;
        default: printf("Invalid");
    }
}

//2. Number Guessing Name
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    int n,g; srand(time(0)); n=rand()%100+1;
    for(int i=1;i<=5;i++){
        printf("Guess: "); scanf("%d",&g);
        if(g==n){printf("Correct!");return 0;}
        printf(g<n?"Too low\n":"Too high\n");
    }
    printf("Number was %d",n);
}

//3. Tic-Tac-Toe
#include <stdio.h>
char b[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
void show(){for(int i=0;i<3;i++){for(int j=0;j<3;j++)printf(" %c ",b[i][j]);puts("");}}
int win(){
 for(int i=0;i<3;i++)
  if(b[i][0]==b[i][1]&&b[i][1]==b[i][2])return 1;
 for(int i=0;i<3;i++)
  if(b[0][i]==b[1][i]&&b[1][i]==b[2][i])return 1;
 return (b[0][0]==b[1][1]&&b[1][1]==b[2][2])||(b[0][2]==b[1][1]&&b[1][1]==b[2][0]);
}
int main(){
 int p=1,m; char s;
 do{
  show(); printf("P%d move: ",p); scanf(" %c",&s);
  for(int i=0;i<3;i++)for(int j=0;j<3;j++)if(b[i][j]==s)b[i][j]=p==1?'X':'O';
  if(win()){show();printf("P%d wins!",p);return 0;}
  p=3-p; m++;
 }while(m<9);
 printf("Draw!");
}

//4. Hangman game
#include <stdio.h>
#include <string.h>
int main(){
 char w[]="code",g[10]="_ _ _ _",c; int miss=0;
 while(miss<6 && strstr(g,"_")){
  printf("%s\nGuess: ",g); scanf(" %c",&c);
  int f=0; for(int i=0;i<4;i++)if(w[i]==c){g[i*2]=c;f=1;}
  if(!f)miss++;
 }
 printf(strstr(g,"_")?"You lose!":"You win!");
}

//5. Quiz game
#include <stdio.h>
int main(){
 int s=0,a;
 printf("1) 2+2=?\n1)3 2)4 3)5\n"); scanf("%d",&a); if(a==2)s++;
 printf("2) Capital of India?\n1)Delhi 2)Mumbai 3)Kolkata\n"); scanf("%d",&a); if(a==1)s++;
 printf("3) C creator?\n1)Bjarne 2)Dennis 3)James\n"); scanf("%d",&a); if(a==2)s++;
 printf("Score=%d/3",s);
}
