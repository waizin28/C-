/**
 Author: Wai Zin Linn
 Email: wlinn@wisc.edu
 NetID: 9082616286
 Description:  This is tester class for InfiniteInt class where the methods can be tested.
 Credits: None
 */

#include "InfiniteInt.h"

#include <iostream>
#include <vector>
using namespace::std;

int main() {
    
    // Make sure to first implement stream insertion operator!
    
    // Testing long param constructor and no-arg constructor
    std::cout << "Constructing n1 and n2..." << std::endl;
    InfiniteInt n1(412);
    InfiniteInt n2;
    std::cout << "n1 should be 412: " << n1 << std::endl;
    std::cout << "n2 should be 0: " << n2 << std::endl;
    std::cout << std::endl;

    // Testing copy Op=
    std::cout << "Changing value of n2..." << std::endl;
    n2 = 3;
    std::cout << "n2 should be 3: " << n2 << std::endl;
    std::cout << std::endl;

    // Testing copy constructor
    std::cout << "Constructing n3..." << std::endl;
    InfiniteInt n3(n2);
    std::cout << "n3 should be 3: " << n3 << std::endl;

    // Add more code here to test InfiniteInt here!
    //preincrement
    
    std::vector<unsigned int>* arr = n1.getDigits();
    cout << "Getting values of n1: " << endl;
    for(int i = 0; i < arr->size(); i++){
        cout << arr->at(i) << " ";
    }
    
    cout << endl;
    
    cout << "n2 < n1: " << (n2 < n1) << endl;
    cout << "n2 > n1: " << (n2 > n1) << endl;
    cout << "n2 >= n1: " << (n2 >= n1) << endl;
    cout << "n2 <= n1: " << (n2 <= n1) << endl;
    cout << "n2 != n1: " << (n2 != n1) << endl;
    cout << "n2 == n1: " << (n2 == n1) << endl;
    
    n3 = n1 - n2;
    cout << "n3 = n1 - n2: " << n3 << endl;
    
    n3 = n1 + n2;
    cout << "n3 = n1 + n2: " << n3 << endl;
    
    n1 = n3++;
    cout << "n1 = n3--: " << n1 << endl;
    
    n1 = n3--;
    cout << "n1 = n3--: " << n1 << endl;
    
    n1 = ++n3;
    cout << "n1 = n3--: " << n1 << endl;
    
    n1 = -- n3;
    cout << "n1 = --n3: " << n1 << endl;
    
    n1 -= n3;
    cout << "n1 -= n3: " << n1 << endl;
    
    n1 += n3;
    cout << "n1 += n3: " << n1 << endl;
    
    cin >> n3;
    cout << "testing >> for n3: " << n3 << endl;
    
    return 0;
}
