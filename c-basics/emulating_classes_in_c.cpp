struct Rectangle {
    int length;
    int width;
};
void initialize(Rectangle *r, int l, int w) {
    r->length = l;
    r->width = w;
}
int area(Rectangle r) {
    // This is pass by value because area does not need to change value of r
    return r.length * r.width;
}
void setLength(Rectangle *r, int length) {
    r->length = length;
}
int main() {
    Rectangle r;

    initialize(&r, 10,20);
    int a = area(r);
    setLength(&r, 30);
    
}