/* Génération de signal sinusoïdal */
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const float PRECISION = 1e-9;
const double TWO_PI = 2 * M_PI;

double factorial (int n) {

  int cpt;
  double fact = 1;

  if (n > 0)
    for (cpt = n; cpt > 1; cpt--)
      fact = fact * cpt;

  return fact;
}

double sine(double x) {

  int n = 1;
  double term, sin_x = x;

  do 
  {
    term = pow(-1, double(n)) * pow(x, double(2*n+1)) / factorial (2*n+1);
//    cout << "sin(x) = " << setw(9) << sin_x << " + " 
//                        << setw(9) << term << " | n = " << n << endl;
    sin_x += term;
    n++;
  }
  while (fabs(term) >= PRECISION);

  return sin_x;
}
  
int main() {

  double Ampl = 1, freq = 10, w, t;
  int cpt, NSamples = 20;

  cout << fixed << showpos << setprecision(4);

  for (cpt = 0; cpt <= NSamples; cpt++) {
    w = TWO_PI*freq; 
    t = cpt / (freq * NSamples);
    cout << "La valeur référence est : " << Ampl * sin(w*t) 
         << " à t = " << t << endl;
    cout << "La valeur calculée est  : " << Ampl * sine(w*t) << endl;
  }

  cout << endl;
  return 0;
}
