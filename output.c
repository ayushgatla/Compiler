#include <stdio.h>

int main(){
int t0,a,t1,t2,t3,b,t4,t5,t6,c,t7,t8,t9,d,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22;

t0 = 1;
a = t0;
L0:
t1 = 4;
t2 = a < t1;
if(!t2) goto L1;
t3 = 1;
b = t3;
L2:
t4 = 4;
t5 = b < t4;
if(!t5) goto L3;
t6 = 1;
c = t6;
L4:
t7 = 4;
t8 = c < t7;
if(!t8) goto L5;
t9 = 1;
d = t9;
L6:
t10 = 4;
t11 = d < t10;
if(!t11) goto L7;
t12 = a + b;
t13 = t12 + c;
t14 = t13 + d;
printf("%d\n", t14);
t15 = 1;
t16 = d + t15;
d = t16;
goto L6;
L7:
t17 = 1;
t18 = c + t17;
c = t18;
goto L4;
L5:
t19 = 1;
t20 = b + t19;
b = t20;
goto L2;
L3:
t21 = 1;
t22 = a + t21;
a = t22;
goto L0;
L1:

return 0;
}
