#include "stdio.h"
#include "stdlib.h"
#include <fstream>
#include <iostream>
#include "math.h"
#include "string.h"
#include "time.h"
#include <cmath>
#include <iomanip>

using namespace std;

int main( int argc, char** argv ) {
  
  double ddx=0.0002;
  
  std::remove( "k_and_pi.txt" );
  ofstream k_and_pi;
    
  double x = 0;
  double y = 0;
  double dx = 1;
  double pi_act = M_PI;
  double a_c = 0;
  double v_disk = 0;
  double v_sphere_i = 0;
  double v_sphere_f = 0;
  double radius = 0.5;
  double v_cube = pow(2*radius , 3 );
  double k = 0;

  for ( k = 0; k <= 25; k += 0.5) {
 

    dx = pow( 0.5, k );
    x = 0;
    y = 0;
    a_c = 0;
    v_disk = 0;
    v_sphere_i = 0;
    v_sphere_f =0;
    
    
  
    for ( x = -radius; x < radius ; x += dx ) {
      
      y = sqrt( pow(radius,2) - pow(x,2)); 
      a_c = pi_act * pow(y,2);
      v_disk = a_c * dx;
      v_sphere_f = v_sphere_i + v_disk;
      v_sphere_i = v_sphere_f;
      
    }
    
    double pi_approx = ( 3 * v_sphere_f ) / ( 4 * pow(radius,3));
    double cube_frac = v_sphere_f / v_cube;
    
    
    k_and_pi.open ("k_and_pi.txt", ios::app);
    k_and_pi << std::setprecision(15) << k << "\t" << pi_approx << endl;
    k_and_pi.close();
    
    std::cout << std::setprecision(15)<< k << "\t" << dx << "\t" << v_sphere_f << "\t"<< cube_frac << "\t" << pi_approx << endl;
  
  }
  
  return 0;
  
}
