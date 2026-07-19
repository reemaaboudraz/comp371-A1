/**
 * Reema Aboudraz - 40253549
 * Wissem Oumsalem - 40291712
 * Assignment 1, COMP 371
 * Summer 2026
 * Professor Nagi Basha
 */

#include <iostream>
#include <cmath>

class Point
{
private:
    int x;
    int y;
    int z;

public:
    Point()
    {
        x = 0;
        y = 0;
        z = 0;
    }

    Point(int xValue, int yValue, int zValue)
    {
        x = xValue;
        y = yValue;
        z = zValue;
    }

    int getX() const { return x;}

    int getY() const { return y;}

    int getZ() const { return z;}

    int translate(int d, char axis)
    {
        if (axis == 'x')
            x += d;
        else if (axis == 'y')
            y += d;
        else if (axis == 'z')
            z += d;
        else
            return -1;

        return 0;
    }

    void display() const
    {
        std::cout << "(" << x << ", " << y << ", " << z << ")";
    }

    ~Point(){}
};

class Triangle
{
private:
    Point* vertex_1;
    Point* vertex_2;
    Point* vertex_3;

public:
    Triangle()
    {
        vertex_1 = nullptr;
        vertex_2 = nullptr;
        vertex_3 = nullptr;
    }

    Triangle(const Point& p1, const Point& p2, const Point& p3)
    {
        vertex_1 = new Point(p1);
        vertex_2 = new Point(p2);
        vertex_3 = new Point(p3);
    }

    int translate(int d, char axis)
    {
        if (vertex_1 == nullptr || vertex_2 == nullptr || vertex_3 == nullptr)
            return -1;

        if (axis != 'x' && axis != 'y' && axis != 'z')
            return -1;

        vertex_1->translate(d, axis);
        vertex_2->translate(d, axis);
        vertex_3->translate(d, axis);

        return 0;
    }

    double calcArea() const
    {
        if (vertex_1 == nullptr || vertex_2 == nullptr || vertex_3 == nullptr)
            return 0;

        double ax = vertex_2->getX() - vertex_1->getX();
        double ay = vertex_2->getY() - vertex_1->getY();
        double az = vertex_2->getZ() - vertex_1->getZ();

        double bx = vertex_3->getX() - vertex_1->getX();
        double by = vertex_3->getY() - vertex_1->getY();
        double bz = vertex_3->getZ() - vertex_1->getZ();

        double crossX = ay * bz - az * by;
        double crossY = az * bx - ax * bz;
        double crossZ = ax * by - ay * bx;

        return 0.5 * std::sqrt(crossX * crossX +
                               crossY * crossY +
                               crossZ * crossZ);
    }

    void display() const
    {
        if (vertex_1 == nullptr || vertex_2 == nullptr || vertex_3 == nullptr)
        {
            std::cout << "The triangle has not been created.\n";
            return;
        }

        std::cout << "Vertex 1: ";
        vertex_1->display();
        std::cout << "\nVertex 2: ";
        vertex_2->display();
        std::cout << "\nVertex 3: ";
        vertex_3->display();
        std::cout << "\n";
    }

    ~Triangle()
    {
        delete vertex_1;
        delete vertex_2;
        delete vertex_3;
    }
};

Point readPoint(int number)
{
    int x, y, z;

    std::cout << "\nEnter point " << number << ":\n";
    std::cout << "x: ";
    std::cin >> x;
    std::cout << "y: ";
    std::cin >> y;
    std::cout << "z: ";
    std::cin >> z;

    return Point(x, y, z);
}

void showMenu()
{
    std::cout << "\n1. Create a triangle\n";
    std::cout << "2. Display the triangle\n";
    std::cout << "3. Translate the triangle\n";
    std::cout << "4. Calculate the area\n";
    std::cout << "5. Exit\n";
    std::cout << "Choice: ";
}

//=======Main=======

int main()
{
    std::cout << "============================================================\n";
    std::cout << "                 COMP 371 - COMPUTER GRAPHICS\n";
    std::cout << "                       ASSIGNMENT 1\n";
    std::cout << "                         PART 2\n";
    std::cout << "============================================================\n";
    std::cout << "Submitted by:\n";
    std::cout << "  1. Aboudraz, Reema      - 40253549\n";
    std::cout << "  2. Wissem Oumsalem      - 40291712\n";
    std::cout << "============================================================\n";
    std::cout << "Point and Triangle Class Program\n";
    std::cout << "============================================================\n";

    Triangle* triangle = nullptr;
    int choice;

    do
    {
        showMenu();
        std::cin >> choice;

        if (choice == 1)
        {
            Point p1 = readPoint(1);
            Point p2 = readPoint(2);
            Point p3 = readPoint(3);

            delete triangle;
            triangle = new Triangle(p1, p2, p3);
            std::cout << "Triangle created.\n";
        }
        else if (choice == 2)
        {
            if (triangle == nullptr)
                std::cout << "Create a triangle first.\n";
            else
                triangle->display();
        }
        else if (choice == 3)
        {
            if (triangle == nullptr)
            {
                std::cout << "Create a triangle first.\n";
            }
            else
            {
                int distance;
                char axis;

                std::cout << "Distance: ";
                std::cin >> distance;
                std::cout << "Axis (x, y or z): ";
                std::cin >> axis;

                if (triangle->translate(distance, axis) == -1)
                    std::cout << "Invalid axis.\n";
                else
                    std::cout << "Triangle translated.\n";
            }
        }
        else if (choice == 4)
        {
            if (triangle == nullptr)
                std::cout << "Create a triangle first.\n";
            else
                std::cout << "Area: " << triangle->calcArea() << "\n";
        }
        else if (choice != 5)
        {
            std::cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    delete triangle;
    std::cout << "Program ended.\n";

    return 0;
}
