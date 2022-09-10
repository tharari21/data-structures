#include <iostream>
struct Rectangle
{
    int length;
    int width;
};
int area(Rectangle r) {
    // pass by value - entire structure is copied to r 
    // changing r in here does not change r in main
    r.length++;
    return r.length * r.width;
}
int area2(Rectangle r) {
    // pass by reference - simply an alies
    // changing r in here does change r in main
    r.length++;
    return r.length * r.width;
}

void changeLength(Rectangle *p, int l) {
    // p is a pointer pointing to r
    p->length = l;
    
}
struct Test {
    int A[5];
    int n;
};
void fun(Test t1) {
    // In the arrays lesson we said that arrays can't be passed by values since by 
    // default they are passed as pointers, however structs with can be passed by value
    // So entire Test object in main is copied into t1
    // This is valid but t in main does not change because we passed by value
    t1.A[0] = 10;

}
Rectangle *getRectBoy(int l, int w) {
    Rectangle *p;
    p = new Rectangle;
    // p = (Rectangle *)malloc(sizeof(Rectangle));
    p->length = l;
    p->width = w;
    return p;
}
Rectangle getRectAgain(int l, int w) {
    Rectangle r = {l,w};
    return r;
}
int main() {
    Rectangle r = {10,5};
    changeLength(&r, 20);
    int a = area(r);
    int a2 = area2(r);

    Test t = {{2,4,6,8,10}, 5};
}