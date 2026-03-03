#include <stdio.h>
int main() {
int a;
int b;
int t0;
int t1;
int t2;
int t3;
int t4;
int t5;
int t6;
t0 = 10;
a = t0;
t1 = 3;
b = t1;
t2 = a;
t3 = b;
t4 = t2 > t3;
t5 = a;
printf("%d\n", t5);
if (!t4) goto L0;
L0:
t6 = b;
printf("%d\n", t6);
return 0;
}