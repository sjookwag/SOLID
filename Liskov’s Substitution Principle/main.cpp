// 3. Liskov¡¯s Substitution Principle
// The principle was introduced by Barbara Liskov in 1987 and according to this principle ¡°Derived or child classes must be substitutable for their base or parent classes¡°.This principle ensures that any class that is the child of a parent class should be usable in place of its parent without any unexpected behavior.
// Let¡¯s understand Liskov¡¯s Substitution Principle using an example :
// One of the classic examples of this principle is a rectangle having four sides.A rectangle¡¯s height can be any value and width can be any value.A square is a rectangle with equal width and height.So we can say that we can extend the properties of the rectangle class into square class.
// In order to do that you need to swap the child(square) class with parent(rectangle) class to fit the definition of a square having four equal sides but a derived class does not affect the behavior of the parent class so if you will do that it will violate the Liskov Substitution Principle.

// Rectangle Class : This is the base class that has properties for width and height.It has methods for calculating the area and for setting width and height.
// Square Class : This class inherits from Rectangle but overrides the setWidth and setHeight methods to ensure that changing one dimension affects the other, maintaining the property that all sides are equal.
#include <iostream>

// Base class for shapes
class Rectangle {
protected:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    virtual double area() const {
        return width * height;
    }

    double getWidth() const {
        return width;
    }

    double getHeight() const {
        return height;
    }

    void setWidth(double w) {
        width = w;
    }

    void setHeight(double h) {
        height = h;
    }
};

// Derived class for squares
class Square : public Rectangle {
public:
    Square(double size) : Rectangle(size, size) {}

    void setWidth(double w) {
        width = height = w; // Ensure both width and height remain the same
    }
};

using namespace std;

int main() {
    Rectangle rt(10, 5);
    Square sq(10);

    cout << "Rectangle area: " << rt.area() << endl;
    cout << "Square area: " << sq.area() << endl;
    return 0;
}
