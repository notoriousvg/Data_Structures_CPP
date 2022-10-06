//
//  point.hpp
//  point
//
//  Created by Victor Garcia on 10/4/22.
//
//  THE POINT CLASS - PUTTING EVERYTHING TOGETHER
//  -The constructor
//  -The two original modification functions (shift and roate_90),
//    and the two original constant funcitons (get_x and get_y)
//  -Overlafed comparison operators == and !=
//  -Overloaded arithmetic operator + to add two points
//  -Overloaded output and input operators
//  -Functions midpoint, rotaitons_needed.
//

#ifndef point_hpp
#define point_hpp
#include <iostream>
#include <stdio.h>

namespace garcia_vic_2B
{
  class point
  {
  public:
    //constructor using default parameters
    point(double x = 0.0, double y = 0.0);
    
    //Member functions
    void rotate_90();
    void shift(double x_amount, double y_amount);
    int rotations_needed(const point &p);
    
    //returns a point object
    point midpoint(const point& p1, const point &p2);
    
    //Overloading Operators FRINEND b/c we are accessing the private variables
    friend std::istream& operator >>(std::istream& ins, point& target);
    
    //Accessores
    double get_x() const;
    double get_y() const;
    
  private:
    double x_coor;
    double y_coor;
  };
//NONMEMBER functions of th epoint class
double distance(const point& p1, const point& p2);
bool operator == (const point &lhs, const point &rhs);
bool operator != (const point &lhs, const point &rhs);
point operator + (const point &lhs, const point & rhs);
point operator - (const point &lhs, const point &rhs);
std::ostream& operator <<(std::ostream& outs, const point& source);
}
#endif /* point_hpp */
