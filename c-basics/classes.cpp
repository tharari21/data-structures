#include <iostream>
class Rectangle {
    int length;
    int width;
    public:
        // void initialize(int length, int width) {

        // }
        // Rather than have initialize method, use constructor
        Rectangle() {
            std::cout << "Creating" << std::endl;
            length = width = 0;
        }
        Rectangle(int l, int w);

        int area(){
            return length * width;
        }
        void setLength(int l) {
            length = l;
        }
        int getLength() {
            return length;
        }
        //Destructor - if you have any dynamic memory allocated on heap then 
        // this function should call delete on them to clean up
        ~Rectangle() {
            std::cout << "destroying..." << std::endl;
        }
};

// Can define out here as well by using scope resolution outside the class
// we declared this method in the class and outside we can define it
Rectangle::Rectangle(int l, int w)
{
    length = l;
    width = w;
}
int main() {
    // r.initialize(10,5);
    Rectangle r(10,5);
    r.area();
    std::cout << r.getLength();
    r.setLength(15);
    std::cout << r.getLength();
    // When scope ends, destructor is called
}