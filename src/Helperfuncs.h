//
// Created by Mindaugas K on 10/17/2019.
//

#ifndef MINDECHAIN_HELPERFUNCS_H
#define MINDECHAIN_HELPERFUNCS_H
#include <string>
#include <iostream>
#include <random>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "User.h"
#include "MindeHash.h"
#include "Transaction.h"
#define S_LENGTH std::string::size_type
static std::string ranChrs = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
extern long long seed;
extern std::mt19937 mt;
extern std::uniform_int_distribution<S_LENGTH> dist;
extern std::uniform_real_distribution<long double> dist2;
extern std::uniform_int_distribution<int> dist3;
bool isAlpha( const std::string & str);
void progress(int max, int current);
std::string random_string(S_LENGTH length);
std::string inputString();
long double inputBound();
int inputNum();
bool checkBounds(long double bound1, long double bound2);
std::vector<User>genUsers(long double & min, long double & max);
std::vector<Transaction>genTransactions(std::vector<User> & users, long double low, long double high);



#endif //MINDECHAIN_HELPERFUNCS_H
