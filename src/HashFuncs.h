//
// Created by Mindaugas K on 9/13/2019.
//

#ifndef HASH_GEN_HASHFUNCS_H
#define HASH_GEN_HASHFUNCS_H

#include <string>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>
#define DEFAULT_INPUT "da79bc151a0f3d87ba2ae91a33743075" //md5 salted hash with a salt of my exact birth date
#define CHARACTER_SET "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

std::string charToInt(const std::string &str);// converts string of chars to string of ascii character

void divideString(std::vector<int> &vect, std::string &str);// divides the string of ints into parts of 5 digits length, adds these parts to a single vector

void leftRotate(std::string &s, int d);// borrowed from https://www.geeksforgeeks.org/left-rotation-right-rotation-string-2/, rotates the string to left by d positions

void rightRotate(std::string &s, int d);// borrowed from https://www.geeksforgeeks.org/left-rotation-right-rotation-string-2/, rotates the string to right by d positions

void deNullnShift(std::vector<std::string> &vect);// removes zeroes from parts stored, shifts the parts according to number of zeroes removed

int fixRange(char a);// fixes the ascii codes of chars instead the given ascii code does not belong to an alphanumeric character

void convertRange(int oldMin, int oldMax, int newMin, int newMax, char &a);// converts a value from one range to a corresponding value in another range, calls fixRange to passed char


std::string vectToString(const std::vector<std::string> & vect);// concatenates values of vector into one string

template<typename T>
std::vector<std::string> toHex(const std::vector<T> vect) {// converts the values found  in the vect from dec to hex
    std::vector<std::string> ret;
    std::string out;
    std::stringstream stream;
    stream << std::setfill('0') << std::setw(sizeof(T) * 2)
           << std::hex;
    for (int a:vect) {
        stream << a;
        ret.push_back(stream.str());
        stream.clear();
        stream.str(std::string());
    }
    return ret;
}

#endif //HASH_GEN_HASHFUNCS_H
