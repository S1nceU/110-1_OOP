#ifndef FRC_H
#define FRC_H
#include <string>
#include "gcd.h"
class Fraction {
public:
  // default value is +0/1
  // i.e., _sign='+', _numerator=0, _denominator=1,
Fraction() {
  _denominator = 1;
  _numerator = 0;
  _sign = '+';
}

  // default value is an integer (denominator=1)
  // e.g., Fraction f(-3) has its _sign='-', _numerator=3, _denominator=1
Fraction(int num) {
  if ( num < 0){
      _sign = '-';
  }
  else _sign = '+';
  _denominator = 1;
  _numerator   = abs(num);
}
  // hint: use gcd
  // throw exception when the denominator is 0
Fraction(int numerator, int denominator) {
  if (denominator == 0){
      throw std::string("undefined.");
  }
  if(numerator * denominator < 0){
      _sign = '-';
  }
  else{
    _sign = '+';
  }
  int s;
  s = gcd(denominator,numerator);
  numerator /= s;
  denominator /= s;
  _numerator = abs(numerator);
  _denominator = abs(denominator);
}

  // get the numerator of the fraction
int numerator() const {
  return _numerator;
}

  // get the denominator of the fraction
int denominator() const {
  return _denominator;
}

  // get positive or negative sign of the fraction
char sign() const {
  return _sign;
}

  // display the fraction by string
std::string toString() const{
  std::string si ;
  if(_sign == '-'){
    si += _sign;
  }
  
  si += std::to_string(abs(_numerator));
  if(_denominator == 1){
    return si; 
  }
  si+='/';
  si += std::to_string( abs(_denominator));
  return si;
}

  // addition of two Fractions
Fraction operator + (Fraction const & f) const {
  Fraction op;
  op._denominator = this->_denominator * f._denominator;
  int thnu,fnu;
  if(this->_sign == '-'){
    thnu = this->_numerator * -1;
  }
  else thnu = this->_numerator;
  if(f._sign == '-'){
    fnu = f._numerator * -1;
  }
  else fnu = f._numerator;
  op._numerator   = thnu * f._denominator + this->_denominator * fnu;
  if(op._numerator < 0){
    op._sign = '-';
  }
  int s;
  s = gcd(op._denominator,op._numerator);
  op._numerator /= s;
  op._numerator = abs(op._numerator);
  op._denominator /= s;
  return op;
}
    
  // subtraction of two Fractions
Fraction operator - (Fraction const & f) const {
  Fraction op;
  op._denominator = this->_denominator * f._denominator;
  int thnu,fnu;
  if(this->_sign == '-'){
    thnu = this->_numerator * -1;
  }
  else thnu = this->_numerator;
  if(f._sign == '-'){
    fnu = f._numerator * -1;
  }
  else fnu = f._numerator;
  op._numerator   = thnu * f._denominator - this->_denominator * fnu;
  if(op._numerator < 0){
    op._sign = '-';
  }
  int s;
  s = gcd(op._denominator,op._numerator);
  op._numerator /= s;
  op._numerator = abs(op._numerator);
  op._denominator /= s;
  return op;
}

  // division of two Fractions
Fraction operator / (Fraction const & f) const {
  Fraction op;
  if(this->_sign == '-' ^ f._sign == '-' ){
    op._sign = '-';
  }
  op._denominator = this->_denominator * f._numerator;
  op._numerator   = this->_numerator   * f._denominator;
  int s;
  s = gcd(op._denominator,op._numerator);
  op._numerator /= s;
  op._denominator /= s;
  return op; 
}

  
private:
  // both numerator and denominator should be positive
int _numerator;  // 分子
int _denominator;// 分母
char _sign;      // 正負號
};
#endif