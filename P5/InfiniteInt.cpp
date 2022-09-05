/**
 Author: Wai Zin Linn
 Email: wlinn@wisc.edu
 NetID: 9082616286
 Description:  This is class which represents a non-negative number with an "unlimited" number of digits. Each digit will be stored as a separate unsigned int in an STL vector. This class have implemention some commonly used operators on  new infinite integer class.
 cpp class.
 Credits: None
 */

#include "InfiniteInt.h"
#include <vector>
#include <iostream>

using namespace std;

InfiniteInt::InfiniteInt(): radix(10){
    digits = new vector<unsigned int>(0);
    (*digits).push_back(0);
}

InfiniteInt::InfiniteInt(unsigned long long input): radix(10){
    digits = new vector<unsigned int>(0);
    
    if(input < radix){
        (*digits).insert((*digits).begin(), static_cast<unsigned int>(input));
    }else{
        
        while(input >= radix){
            (*digits).insert((*digits).begin(),input%radix);
            input /= radix;
        }
        
        (*digits).insert((*digits).begin(), static_cast<unsigned int>(input));
    }
}

InfiniteInt::InfiniteInt(vector<unsigned int> &d): radix(10){
    this->digits = new vector<unsigned int>(d);
}

InfiniteInt::InfiniteInt(const InfiniteInt &obj): radix(10){
    this->digits = new vector<unsigned int>(*obj.digits);
}

vector<unsigned int>* InfiniteInt::getDigits(){
    return digits;
}

InfiniteInt& InfiniteInt::operator=(const InfiniteInt &obj){
    if(this != &obj){
        delete digits;
        this->digits = new vector<unsigned int>(*obj.digits);
    }
    return *this;
}

InfiniteInt::~InfiniteInt(){
    delete digits;
}

std::ostream& operator<<(std::ostream& os, const InfiniteInt&obj){
    for(vector<unsigned int>::iterator iter = obj.digits->begin(); iter != obj.digits->end(); iter++){
        os << (*iter);
    }
    return os;
}

istream& operator>>(istream &is, InfiniteInt &obj) {
    unsigned long long input;
    is >> input;
    
    obj.digits = new vector<unsigned int>(0);
    
    if(input < obj.radix){
        (*obj.digits).insert((*obj.digits).begin(), static_cast<unsigned int>(input));
    }else{
        
        while(input > obj.radix){
            (*obj.digits).insert((*obj.digits).begin(),input%obj.radix);
            input /= obj.radix;
        }
        (*obj.digits).insert((*obj.digits).begin(), static_cast<unsigned int>(input));
    }
    
    return is;
}

bool operator<(const InfiniteInt & lhs, const InfiniteInt & rhs){
    if(lhs.digits->size() < rhs.digits->size()){
        return true;
    }else if(lhs.digits->size() > rhs.digits->size()){
        return false;
    }
        for(int i = 0; i < lhs.digits->size(); i++){
            if(lhs.digits->at(i) > rhs.digits->at(i)){
                return false;
            }else if(lhs.digits->at(i) < rhs.digits->at(i)){
                return true;
            }
        }
    return false;
}

bool operator>(const InfiniteInt & lhs, const InfiniteInt & rhs){
    if(lhs.digits->size() < rhs.digits->size()){
        return false;
    }else if(lhs.digits->size() > rhs.digits->size()){
        return true;
    }
    
    for(int i = 0; i < lhs.digits->size(); i++){
        if(lhs.digits->at(i) > rhs.digits->at(i)){
            return true;
        }else if(lhs.digits->at(i) < rhs.digits->at(i)){
            return false;
        }
    }
    return false;
}

bool operator>=(const InfiniteInt & lhs, const InfiniteInt & rhs){
    return !operator<(lhs,rhs);
}

bool operator<=(const InfiniteInt & lhs, const InfiniteInt & rhs){
    return !operator>(lhs,rhs);
}

bool operator==(const InfiniteInt & lhs, const InfiniteInt & rhs){
    if(lhs.digits->size() != rhs.digits->size()){
        return false;
    }else{
        for(int i = 0; i < lhs.digits->size(); i++){
            if(lhs.digits->at(i) != rhs.digits->at(i)){
                return false;
            }
        }
    }
    return true;
}

bool operator!=(const InfiniteInt & lhs, const InfiniteInt & rhs){
    return !operator==(lhs,rhs);
}

InfiniteInt operator+(const InfiniteInt & lhs, const InfiniteInt & rhs){

    vector<unsigned int> lhs_result(0);
    vector<unsigned int> rhs_result(0);

    int carry = 0;
    int overflow = 0;

    for(vector<unsigned int>::iterator iter = lhs.digits->begin(); iter != lhs.digits->end(); iter++){
        lhs_result.insert(lhs_result.begin(), *iter);
    }

    for(vector<unsigned int>::iterator iter = rhs.digits->begin(); iter != rhs.digits->end(); iter++){
        rhs_result.insert(rhs_result.begin(), *iter);
    }

    int maxSize = static_cast<int>((lhs_result.size() <= rhs_result.size()) ? rhs_result.size() : lhs_result.size());

    if(rhs_result.size() < maxSize){

        int shiftCounter = static_cast<int>(maxSize-rhs_result.size());

        for(int i = 0; i < shiftCounter; i++){
            rhs_result.push_back(static_cast<unsigned int>(0));
        }
    }else if(lhs_result.size() < maxSize){

        int shiftCounter = static_cast<int>(maxSize-lhs_result.size());

        for(int i = 0; i < shiftCounter; i++){
            lhs_result.push_back(static_cast<unsigned int>(0));
        }
    }

    vector<unsigned int> result(0);
    vector<unsigned int> modify(maxSize+1);

    for(int i = 0; i < maxSize; i++){
        int add = lhs_result.at(i) + rhs_result.at(i) + carry;
        if(add >= lhs.radix){
            if(i == (maxSize-1)){
                overflow = 1;
            }
            carry = 1;
            modify.at(i) = add-lhs.radix;
        }else{
            carry = 0;
            modify.at(i) = add;
        }
    }

    if(overflow == 1){
        modify.at(maxSize) = carry;
    }

    for(int i = 0; i < maxSize; i++){
        result.insert(result.begin(),modify.at(i));
    }

    if(overflow == 1){
        result.insert(result.begin(),modify.at(maxSize));
    }

    return InfiniteInt(result);
}

InfiniteInt operator-(const InfiniteInt & lhs, const InfiniteInt & rhs){
    
    if(lhs <= rhs){
        return InfiniteInt(static_cast<unsigned int>(0));
    }
    
    vector<unsigned int>* lhs_result = new vector<unsigned int>(0);
    vector<unsigned int>* rhs_result = new vector<unsigned int>(0);
    int shiftCounter = 0;
    int diff = 0;
    int carry = 0;
    int overflow = 0;
    
    for(vector<unsigned int>::iterator iter = lhs.digits->begin(); iter != lhs.digits->end(); ++iter){
        lhs_result->insert(lhs_result->begin(), *iter);
    }
    
    for(vector<unsigned int>::iterator iter = rhs.digits->begin(); iter != rhs.digits->end(); ++iter){
        rhs_result->insert(rhs_result->begin(), *iter);
    }
    
    int maxSize = static_cast<int>(lhs_result->size());
    
    if(rhs_result->size() < maxSize){
        
        shiftCounter = static_cast<int>(maxSize - rhs_result->size());
        
        for(int i = 0; i < shiftCounter; i++){
            rhs_result->push_back(static_cast<unsigned int>(0));
        }
    }
    
    vector<unsigned int> result(0);
    vector<unsigned int> modify(maxSize);
    
    for(int i = 0; i < maxSize; i++){
        diff = lhs_result->at(i) - rhs_result->at(i) - carry;
        if(diff == 0){
            if(i == (maxSize-1)){
                overflow = 1;
            }
            carry = 0;
            modify.at(i) = diff;
        }else if(diff > 0){
            carry = 0;
            modify.at(i) = diff;
        }else{
            carry = 1;
            modify.at(i) = diff + lhs.radix;
        }
    }
    
    for(int i = 0; i < maxSize-1; i++){
        result.insert(result.begin(), modify.at(i));
    }
    
    if(overflow != 1){
        result.insert(result.begin(), modify.at(maxSize-1));
    }
    
    while(result.at(0) == 0){
        result.erase(result.begin());
    }
    
    return InfiniteInt(result);
}

InfiniteInt& InfiniteInt::operator+=(const InfiniteInt &obj){
    *this = *this + obj;
    return *this;
}

InfiniteInt& InfiniteInt::operator-=(const InfiniteInt &obj){
    *this = *this - obj;
    return *this;
}

InfiniteInt& InfiniteInt::operator++(){
    *this = *this + 1;
    return *this;
}

InfiniteInt& InfiniteInt::operator--(){
    *this = *this - 1;
    return *this;
}

InfiniteInt InfiniteInt::operator++(int dummy){
    InfiniteInt saved(*this);
    ++(*this);
    return saved;
}

InfiniteInt InfiniteInt::operator--(int dummy){
    InfiniteInt saved(*this);
    --(*this);
    return saved;
}
