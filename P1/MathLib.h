/**
 Author: Wai Zin Linn
 Email: wlinn@wisc.edu
 NetID: 9082616286
 Description: This is header file for MathLib which contains all the fuction declaration,
 Credits: None
 */

#ifndef MathLib_h
#define MathLib_h

/**
 Enum declaration for round method
 */
enum RoundingRule {ROUND_DOWN, ROUND_UP, ROUND_TO_ZERO, ROUND_AWAY_ZERO, ROUND_HALF_UP, ROUND_HALF_DOWN, ROUND_HALF_TO_ZERO, ROUND_HALF_AWAY_ZERO, ROUND_HALF_TO_EVEN, ROUND_HALF_TO_ODD};

/**
 This function should take a number of int type and return the absolute value of that number.
 
 @param val the value of int type
 @return absolute value of int type number
 */
int absVal(int val);

/**
 This function should take a number of long type and return the absolute value of that number.

 @param val the value of long type
 @return absolute value of long type number
 */
long absVal(long val);

/**
 This function should take a number of double type and return the absolute value of that number.

 @param val the value of double type
 @return absolute value of double type number
 */
double absVal(double val);

/**
 This function returns the ceiling of the double parameter.
 
 @param input a double type param inputed by user
 @return ceiling of inputted double parameter
 */
long ceiling(double input);

/**
 This function returns the floor of the double parameter.
 
 @param input a double type param inputed by user
 @return floor of inputted double parameter
 */
long floor(double input);

/**
 This function will round the double parameter based on the RoundingRule.
 
 @param input a double tupe param to be rounded
 @param e to define the RoundingRule
 @return value inputted parameter is rounded to based on RoundingRule
 */
long round(double input, RoundingRule e = ROUND_HALF_UP);

/**
 Raise the double value to the longest exponents.
 
 @param base the base to be power
 @param power number to power the base
 @return the value of base powered by the power
 */
double pow(double base, long power);

/**
 This function builds a std::string representation of the int (first) parameter using the unsigned int (second) parameter as the radix (i.e. numerical base).
 
 @param num int parameter
 @param radix numerical base
 @param flag true when return value is lower case, false if it's upper case
 @return std::string representation of the int (first) parameter using the unsigned int (second) parameter as the radix (i.e. numerical base).
 */
std::string toString(int num, unsigned int radix = 10, bool flag = true);

/**
 This function returns the greatest common divisor of two parameters
 
 @param x first parameter
 @param y second parameter
 @return greatest common divisor of two parameters
 */
int gcd(int x, int y);

#endif /* MathLib_h */
