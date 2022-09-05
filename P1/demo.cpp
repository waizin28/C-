/**
 Author: Wai Zin Linn
 Email: wlinn@wisc.edu
 NetID: 9082616286
 Description: This program is to test all of the functions from MathLib.cpp
 Credits: None
 */

#include "demo.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "MathLib.h"

using namespace std;

int main(){
    
    int x = -9;
    double y = -4.3;
    long z = -4;
    double d = 0.1;
    double r = -0.3;
    
    cout << absVal(x) << endl;
    cout << absVal(y) << endl;
    cout << absVal(z) << endl;
    cout << ceiling(y) << endl;
    cout << floor(y) << endl;
    cout << round(d,ROUND_HALF_AWAY_ZERO) << endl;
    cout << round(r,ROUND_HALF_UP) << endl;
    cout << toString(42,2,true) << endl;
    cout << gcd(-2,-14) << endl;
    
    return 0;
}
