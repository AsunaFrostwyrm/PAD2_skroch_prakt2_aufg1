/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Malinka
 *
 * Created on 6. November 2016, 09:53
 */

#include <cstdlib>
#include "myvector.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    myVector<double> vdouble{10};
    vdouble.get(1);
    
    return 0;
}

