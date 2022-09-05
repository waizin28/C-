/**
 Author: Wai Zin Linn
 Email: wlinn@wisc.edu
 NetID: 9082616286
 Description:  This is header file for InfiniteInt which contains all the fuction declarations which will be implemented in
 cpp class.
 Credits: None
 */

#ifndef InfiniteInt_h
#define InfiniteInt_h

#include <vector>
#include <iostream>

class InfiniteInt{
    
    /**
     Overloaded operator << for ostream and InfiniteInt. This should display the integer value of the InfiniteInt as if it was a regular unsigned int.
     */
    friend std::ostream& operator<<(std::ostream& os, const InfiniteInt&);
    
    /**
     Overloaded operator >> for istream and InfiniteInt. This operator should parse the input stream by skipping any whitespace,
     then parse all digits into the vector of digits, stopping when a non-digit is encountered.
     If no digits are encounter, the value should be set to 0.
     */
    friend std::istream& operator>>(std::istream& os, InfiniteInt&);
    
    /**
     Overloaded operator < that returns whether or not the value of the left hand side InfiniteInt is less than the other InfiniteInt
    
     @return whether or not the value of the left hand side InfiniteInt is less than the other InfiniteInt
     */
    friend bool operator<(const InfiniteInt & lhs, const InfiniteInt & rhs);
    
    /**
     Overloaded operator > that returns whether or not the value of the left hand side InfiniteInt is greater than the other InfiniteInt
     
     @return whether or not the value of the left hand side InfiniteInt is greater than the other InfiniteInt
     */
    friend bool operator>(const InfiniteInt & lhs, const InfiniteInt & rhs);
    
    /**
     Overloaded operator <= that returns whether or not the value of the left hand side InfiniteInt is less than or equal to the other InfiniteInt
     
     @return whether or not the value of the left hand side InfiniteInt is less than or equal to the other InfiniteInt
     */
    friend bool operator<=(const InfiniteInt & lhs, const InfiniteInt & rhs);
    
    /**
     Overloaded operator >= that returns whether or not the value of the left hand side InfiniteInt is greater than or equal to the other InfiniteInt
     
     @return whether or not the value of the left hand side InfiniteInt is greater than or equal to the other InfiniteInt
     */
    friend bool operator>=(const InfiniteInt & lhs, const InfiniteInt & rhs);
    
    /**
     Overloaded operator == that returns whether or not the value of the left hand side InfiniteInt is equal to the other InfiniteInt
     
     @return whether or not the value of the left hand side InfiniteInt is equal to the other InfiniteInt
     */
    friend bool operator==(const InfiniteInt & lhs, const InfiniteInt & rhs);
    
    /**
     Overloaded operator != that returns whether or not the value of the left hand side InfiniteInt is not equal to the other InfiniteInt
     
     @return whether or not the value of the left hand side InfiniteInt is not equal to the other InfiniteInt
     */
    friend bool operator!=(const InfiniteInt & lhs, const InfiniteInt & rhs);
    
    /**
     Overloaded operator + that returns a InfiniteInt that is the sum of two InfiniteInts
     
     @return a InfiniteInt that is the sum of two InfiniteInts
     */
    friend InfiniteInt operator+(const InfiniteInt & lhs, const InfiniteInt & rhs);
    
    /**
     Overloaded operator - that returns a InfiniteInt that is the difference of two InfiniteInts
     
     @return a InfiniteInt that is the difference of two InfiniteInts
     */
    friend InfiniteInt operator-(const InfiniteInt & lhs, const InfiniteInt & rhs);
    
private:
    std::vector<unsigned int>* digits;
    const unsigned int radix;

public:
    std::vector<unsigned int>* getDigits();
    
    /**
    Default constructor that sets the integer value to a default value of 0.
     */
    InfiniteInt();
    
    /**
     Parameterized constructor for InfiniteInt that sets the starting value to val
     */
    InfiniteInt(unsigned long long val);
    
    /**
     Parameterized constructor for InfiniteInt that sets the starting value equal to the digits of d
     */
    explicit InfiniteInt(std::vector<unsigned int> &d);
    
    /**
     Copy constructor for InfiniteInt that allocates new memory for digits and then copies each digit from the obj to the newly allocated vector
     */
    InfiniteInt(const InfiniteInt &obj);
    
    /**
     Copy-assignment operator
     */
    InfiniteInt& operator=(const InfiniteInt &);
    
    /**
     Destructor for InfiniteInt which frees any allocated heap memory
     */
    ~InfiniteInt();

    /**
     An overloaded operator += that adds the right operand and the left operand and stores the new value in the left operand
     
     @return new value in the left operand
     */
    InfiniteInt& operator+=(const InfiniteInt &);
    
     /**
     An overloaded operator -= that subtracts the right operand from the left operand and stores the new value in the left operand
     
     @return new value in the left operand
     */
    InfiniteInt& operator-=(const InfiniteInt &);
    
    /**
     Overloaded pre-incremen toperator,++,that adds 1 to the current InfiniteInt and returns the changed InfiniteInt
     
     @return the changed InfiniteInt value
     */
    InfiniteInt& operator++();
    
    /**
     Overloaded pre-decrement operator, --, that subtracts 1 from the current InfiniteInt and returns the changed InfiniteInt
     
     @return the changed InfiniteInt value
     */
    InfiniteInt& operator--();
    
    /**
     Overloaded post-increment operator ++,that adds 1 to the current InfiniteInt and returns the original InfiniteInt
     
     @return original InfiniteInt value
     */
    InfiniteInt operator++(int);
    
    /**
     Overloaded post-decrement operator, --, that subtracts 1 from the current InfiniteInt and returns the original InfiniteInt
     
     @return original InfiniteInt value
     */
    InfiniteInt operator--(int);
    
};

#endif /* InfiniteInt_h */
