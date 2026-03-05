#include <stdio.h>

int foo(){
int t8;
printf("%s\n", "function called");
t8 = 100;
return t8;
}

int main(){
int a,b,t0,c,t1,t2,t3,i,t4,t5,t6,t7,t9,x;

printf("%s\n", "Compiler test");
scanf("%d", &a);
scanf("%d", &b);
t0 = a + b;
c = t0;
printf("%d\n", c);
t1 = 10;
t2 = c > t1;
if(!t2) goto L0;
goto L1;
L0:
L1:
t3 = 0;
i = t3;
L2:
t4 = 3;
t5 = i < t4;
if(!t5) goto L3;
printf("%d\n", i);
t6 = 1;
t7 = i + t6;
i = t7;
goto L2;
L3:
t9 = foo();
x = t9;
printf("%d\n", x);

return 0;
}
