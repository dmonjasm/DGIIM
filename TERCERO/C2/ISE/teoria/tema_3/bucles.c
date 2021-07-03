float a=0.3; float b=0.8; float c=0.1;
void main(void) {
unsigned long i;
for (i=0;i<80000000;i++) a=a*b/(1+c);
bucle1(); bucle1(); bucle2();
}
void bucle1(void) {
unsigned long i;
for (i=0;i<20000000;i++) {
c=(c+c*c)/(1+a*c);c=a*b*c; }
for (i=1;i<=5;i++) bucle3();
}
void bucle2(void) {
unsigned long i;
for (i=0;i<5000000;i++) {
c=(c+c*c+c*c*c)/(1+a*c*c);
c=a*b*c; }
for (i=1;i<=8;i++) bucle3();
}
void bucle3(void) {
unsigned long i;
for (i=0;i<1000000;i++) {
c=a*b*c; c=1/(a+b*c);
}
}
