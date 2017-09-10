#include <iostream>

using namespace std;

class Box {
    public:
        // Member functions can be defined within the class definition or seperately.
        // double getVolume(void) {
        // return length * breadth * height;
        // }
        double getVolume(void);
        void setLength(double length);
        void setBreadth(double breadth);
        void setHeight(double height);
        double getLength();
        Box(double length, double breadth, double height);
        // this a destructor
        ~Box();

    private:
        double length;
        double breadth;
        double height;
};

Box::Box(double length, double breadth, double height) {
    cout << "object is being created" << endl;
    length = length;
    breadth = breadth;
    height = height;
}

Box::~Box(void) {
    cout << "object is being destroyed" << endl;
}

// Member functions can be defined within the class definition or seperately.
double Box::getVolume(void) {
   return length * breadth * height;
}

void Box::setLength( double len ) {
   length = len;
}
void Box::setBreadth( double bre ) {
   breadth = bre;
}
void Box::setHeight( double hei ) {
   height = hei;
}

double Box::getLength() {
    return length;
}

int main() {
   Box Box1(15, 20, 30);
   Box Box2(5, 2, 7);

   double volume = 0.0;
 
   // box 1 specification
   Box1.setLength(6.0); 
   Box1.setBreadth(7.0); 
   Box1.setHeight(5.0);

   // box 2 specification
   Box2.setLength(12.0); 
   Box2.setBreadth(13.0); 
   Box2.setHeight(10.0);

   // volume of box 1
   volume = Box1.getVolume();
   cout << "Volume of Box1 : " << volume <<endl;

   // volume of box 2
   volume = Box2.getVolume();
   cout << "Volume of Box2 : " << volume <<endl;
   return 0;
}