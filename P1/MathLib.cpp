/**
 Author: Wai Zin Linn
 Email: wlinn@wisc.edu
 NetID: 9082616286
 Description: This program is to test all of the functions from MathLib.cpp
 Credits: None
 */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "MathLib.h"

using namespace std;

int absVal(int val){
    return ((val<0)?(-val):(val));
}

long absVal(long val){
    return ((val<0)?(-val):(val));
}

double absVal(double val){
    return ((val<0.0)?(-val):(val));
}

long ceiling(double input){
    if(input >= 0.0){
        if(input - static_cast<double>(absVal(static_cast<long>(input))) == 0){
            return static_cast<long>(input);
        }else{
            return static_cast<long>(input + 1.0);
        }
    }else{
        return static_cast<long>(input);
    }
}

long floor(double input){
    if(input >= 0.0){
        return static_cast<long>(input);
    }else{
        if(input + static_cast<double>(absVal(static_cast<long>(input))) == 0){
            return static_cast<long>(input);
        }else{
            return static_cast<long>(input - 1.0);
        }
    }
}

long helperRoundToZero(double input){
    if(input > 0.0){
        return floor(input);
    }else{
        return ceiling(input);
    }
}

long helperRoundAwayZero(double input){
    if(input > 0.0){
        return ceiling(input);
    }else{
        return floor(input);
    }
}

long helperHalfUp(double input){
    if(absVal(input) - floor(absVal(input)) > 0.5){
        return helperRoundAwayZero(input);
    }else if(absVal(input) - floor(absVal(input)) < 0.5){
        return helperRoundToZero(input);
    }else{
        return ceiling(input);
    }
}

long helperHalfDown(double input){
    if(absVal(input) - floor(absVal(input)) > 0.5){
        return helperRoundAwayZero(input);
    }else if(absVal(input) - floor(absVal(input)) < 0.5){
        return helperRoundToZero(input);
    }else{
        return floor(input);
    }
}

long helperHalfToZero(double input){
    if(absVal(input) - floor(absVal(input)) > 0.5){
        return helperRoundAwayZero(input);
    }else if(absVal(input) - floor(absVal(input)) < 0.5){
        return helperRoundToZero(input);
    }else{
        return round(input,ROUND_TO_ZERO);
    }
}

long helperHalfAwayZero(double input){
    if(absVal(input) - floor(absVal(input)) > 0.5){
        return helperRoundAwayZero(input);
    }else if(absVal(input) - floor(absVal(input)) < 0.5){
        return helperRoundToZero(input);
    }else{
        return round(input,ROUND_AWAY_ZERO);
    }
}

long helperHalfToEven(double input){
    if(absVal(input) - floor(absVal(input)) > 0.5){
        return helperRoundAwayZero(input);
    }else if(absVal(input) - floor(input) < 0.5){
        return helperRoundToZero(input);
    }else{
        if(absVal(static_cast<long>(input)) % 2 == 0){
            if(input >= 0.0){
                return floor(input);
            }else{
                return ceiling(input);
            }
        }else{
            if(input <= 0.0){
                return floor(input);
            }else{
                return ceiling(input);
            }
        }
    }
}

long helperHalfToOdd(double input){
    if(absVal(input) - floor(absVal(input)) > 0.5){
        return helperRoundAwayZero(input);
    }else if(absVal(input) - floor(absVal(input)) < 0.5){
        return helperRoundToZero(input);
    }else{
        if(absVal(static_cast<long>(input)) % 2 == 0){
            if(input >= 0.0){
                return ceiling(input);
            }else{
                return floor(input);
            }
        }else{
            if(input <= 0.0){
                return ceiling(input);
            }else{
                return floor(input);
            }
        }
    }
}

long round(double input, RoundingRule e){
    if(e == ROUND_UP){
        return ceiling(input);
    }else if(e ==  ROUND_DOWN){
        return floor(input);
    }else if(e == ROUND_TO_ZERO){
        return helperRoundToZero(input);
    }else if(e == ROUND_AWAY_ZERO){
        return helperRoundAwayZero(input);
    }else if(e == ROUND_HALF_UP){
        return helperHalfUp(input);
    }else if(e == ROUND_HALF_DOWN){
        return helperHalfDown(input);
    }else if(e == ROUND_HALF_TO_ZERO){
        return helperHalfToZero(input);
    }else if(e == ROUND_HALF_AWAY_ZERO){
        return helperHalfAwayZero(input);
    }else if( e == ROUND_HALF_TO_EVEN){
        return helperHalfToEven(input);
    }else{
        return helperHalfToOdd(input);
    }
}

double pow(double base, long power){
    
    // algorithm from https://www.geeksforgeeks.org/write-a-c-program-to-calculate-powxn/
    
    if(power >= 0){
        if(power == 0){
            return 1.0;
        }else if(power % 2 == 0){
            return pow(base,power/2) * pow(base,power/2);
        }else{
            return base * pow(base,power/2) * pow(base,power/2);
        }
    }else{
        if(power == 0){
            return 1.0;
        }else if(power % 2 == 0){
            return 1.0 / (pow(base,power/2) * pow(base,power/2));
        }else{
            return 1.0 / base * pow(base,power/2) * pow(base,power/2);
        }
    }
}

std::string helperToString(char arr[], int num, int radix){
    int idx;
    char buffer[66];
    
    if(!num){
        return strdup("0");
    }
    
    buffer[65] = '\0';
    idx = 65;
    
    int absNum = absVal(num);
    
    while(absNum){
        buffer[--idx] = arr[absNum%radix];
        absNum /= radix;
    }
    
    if(num < 0){
        buffer[--idx] = '-';
    }

    return strdup(buffer + idx);
}

std::string toString(int num, unsigned int radix, bool flag){
    
    if(radix > 36){
        return "Radix too large.";
    }
    
    if(flag == true){
        char arr[] = "0123456789abcdefghijklmnopqrstuvwxyz";
        return helperToString(arr,num,radix);
        
    }else{
        char arr[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        return helperToString(arr,num,radix);
    }
}

int gcd(int x, int y){
    
    int smallest;
    x = absVal(x);
    y = absVal(y);
    
    if(x < y){
        smallest = x;
    }else if(y < x){
        smallest = y;
    }else{
        return x;
    }
    
    int gcdiv = 1;
    for(int i = 1; i <= smallest; i++){
        if(x % i == 0 && y % i == 0 && i > gcdiv){
            gcdiv = i;
        }
    }
    return gcdiv;
}









