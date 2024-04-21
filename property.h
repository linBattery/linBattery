#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

float compare_property(string property_1,string property_2){
    if(property_1=="water"&&property_2=="fire"){
        return 1.5;
    }
    else if(property_1=="fire"&&property_2=="grass"){
        return 1.5;
    }
    else if(property_1=="grass"&&property_2=="water"){
        return 1.5;
    }
    else if(property_1=="water"&&property_2=="grass"){
        return 0.6;
    }
    else if(property_1=="fire"&&property_2=="water"){
        return 0.6;
    }
    else if(property_1=="grass"&&property_2=="fire"){
        return 0.6;
    }
    else if(property_1=="fire"&&property_2=="fire"){
        return 1.0;
    }
    else if(property_1=="grass"&&property_2=="grass"){
        return 1.0;
    }
    else if(property_1=="water"&&property_2=="water"){
        return 1.0;
    }
}



