//
//  main.cpp
//  point
//
//  Created by Victor Garcia on 10/4/22.
//

#include <iostream>
#include <cstdlib>
#include "point.h"

int main(int argc, const char * argv[])
{
  using namespace garcia_vic_2B;
  using namespace std;
  
  point one(-10,-2.3);
  //testing one of the dafault parameters
  point two(-5);
  //testing both default parameters
  point three;
  
  point mid = one.midpoint(one, two);
  
  cout << one << " " << two << endl;
  cout << "midpoint is " << mid << endl;
  cout << "distance between " << one << " and " << two << " is " << distance(one, two) << endl;
  cout << "rotating point two ";
  two.rotate_90();
  cout << two << endl;
  
  //testing the constructor with default values
  cout << "Point three";
  cout << three << endl;
  cout << "rotations needed to make " << one << " positive are:\n" << one.rotations_needed(one) << endl;
  
  //testing operator overloading
  if(one == three)
    cout << "The two points are equal.\n";
  else
    cout << "The two points are NOT equal.\n";
  
  //testing addition of two point obj
  point new_point = one + two;
  cout << "\n-----------\n" << one << " + " << two << " = " <<  new_point << endl;
  return EXIT_SUCCESS;
}
