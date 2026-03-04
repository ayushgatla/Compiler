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
t0 = 5;
a = t0;
t1 = 5;
b = t1;
t2 = a;
t3 = b;
t4 = t2 == t3;
if (!t4) goto L0;
t5 = a;
printf("%d\n", t5);
goto L1;
L0:
L1:
return 0;
}