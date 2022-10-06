//
//  point.cpp
//  point
//
//  Created by Victor Garcia on 10/4/22.
//
#include <cmath>
#include "point.h"

namespace garcia_vic_2B
{
  point::point(double x, double y) : x_coor(x), y_coor(y) { }

  void point::rotate_90()
  {
    double new_x = y_coor;
    double new_y = -x_coor;
    
    x_coor = new_x;
    y_coor = new_y;
  }
  void point::shift(double x_amount, double y_amount)
  {
    x_coor += x_amount;
    y_coor += y_amount;
  }
int point::rotations_needed(const point& p) {
  int rotations = 0;
  
  point copy(p);
  while ((copy.get_x() < 0) || (copy.get_y() < 0))
  {
    copy.rotate_90();
    ++rotations;
  }
  return rotations;
  
}

  point point::midpoint(const point &p1, const point &p2)
  {
    double mid_x, mid_y;
    
    mid_x = (p2.x_coor + p1.x_coor)/ 2.0;
    mid_y = (p2.y_coor + p1.y_coor)/ 2.0;
    
    
    point midpoint(mid_x,mid_y);
    return midpoint;
  }
  double distance(const point &p1, const point &p2)
  {
    double x, y, hyp;
    
    x = (p2.get_x() - p1.get_x());
    y = (p2.get_y() -  p1.get_y());
    
    hyp = sqrt(pow(x, 2) + pow(y,2));
    return hyp;
  }
  bool operator == (const point &lhs, const point &rhs)
  {
    return ((lhs.get_x() == rhs.get_x()) && (lhs.get_y() == rhs.get_y()));
  }
  bool operator != (const point &lhs, const point &rhs)
  {
    return !(lhs == rhs);
  }
  point operator + (const point &lhs, const point & rhs)
  {
    double x_temp, y_temp;
    
    x_temp = lhs.get_x() + rhs.get_x();
    y_temp = lhs.get_y() + rhs.get_y();
    
    point temp(x_temp, y_temp);
    
    return temp;
  }
  point operator - (const point &lhs, const point &rhs)
  {
    double x_temp, y_temp;
    
    x_temp = lhs.get_x() - rhs.get_x();
    y_temp = lhs.get_y() - rhs.get_y();
    
    point temp(x_temp, y_temp);
    
    return temp;
  }
  std::istream& operator >>(std::istream& ins, point& target)
  {
    ins >> target.x_coor >> target.y_coor;
    return ins;
  }
  std::ostream& operator << (std::ostream &outs, const point& source)
  {
    outs << "("<< source.get_x() << "," << source.get_y() << ")";
    return outs;
  }
  double point::get_x() const
  {
    return x_coor;
  }
  double point::get_y() const
  {
    return y_coor;
  }
}
