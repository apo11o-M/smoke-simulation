#ifndef __VEC2D_HPP__
#define __VEC2D_HPP__

#include <vector>
#include <cmath>
#include <iostream>

class Vec2d {
    public:
        double x;
        double y;
    
    public: 
        // Default constructor
        Vec2d();

        // Copy constructor
        Vec2d(const Vec2d&);

        // x & y coordinates
        Vec2d(double x, double y);

        // Convert a size 2 vector to a 2D vec object
        Vec2d(std::vector<double>);

        // Convert a size 2 vector to a 2D vec object 
        Vec2d(std::vector<int>);

    public:
        // Calculate the length of the vector
        double length();

        // Calculate the distance squared of the two 2D points
        double distanceSq(Vec2d&);

        // Calculate the dot product of two vectors
        double dot(Vec2d&);

        // Normalize the vector
        Vec2d normalize();

        // Rotate the vector based from the value of rotX and rotY. They are both in degrees
        Vec2d rotation(double rotX, double rotY);

    public:
        // Add two vectors together
        Vec2d operator+(const Vec2d&);

        // Subtract two vectors together
        Vec2d operator-(const Vec2d&);

        // Multiply the x and y values by the input
        Vec2d operator*(double);

        // Divide the x and y values by the input
        Vec2d operator/(double);

        // Copy the value from the input vector and set it to the current vector
        void operator=(const Vec2d&);

        // Print out the vector in a useful form
        friend std::ostream& operator<<(std::ostream& os, const Vec2d&);
};
#endif