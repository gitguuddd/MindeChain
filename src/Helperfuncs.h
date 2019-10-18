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
#include "MindeBlock.h"
#include "BlockHeader.h"
#define S_LENGTH std::string::size_type
static std::string ranChrs = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 extern std::string genesisFifth;
//Genesis book text about the fifth day
extern int timeSinceBirth;
//Time since 1970 until my birthday
extern std::string JBCFriday;
//Friday by JBC lyrics
extern long long seed;
extern std::mt19937 mt;
extern std::uniform_int_distribution<S_LENGTH> dist;
extern std::uniform_real_distribution<long double> dist2;
extern std::uniform_int_distribution<int> dist3;
extern std::uniform_int_distribution<long long> dist4;
extern std::uniform_int_distribution<int> dist5;
bool isAlpha( const std::string & str);
void progress(int max, int current);
std::string genTS();
std::string random_string(S_LENGTH length);
std::string inputString();
long double inputBound();
int inputNum();
bool checkBounds(long double bound1, long double bound2);
std::vector<User>genUsers(long double & min, long double & max);
std::vector<Transaction>genTransactions(std::vector<User> & users, long double low, long double high);
std::vector<std::string>select100(std::vector<std::string> & trans,std::vector<Transaction> & transs);
std::vector<std::string>tranToString(std::vector<Transaction> trans);
std::vector<std::string> mRoot(std::vector<std::string> trans);
void mineGenesis(MindeBlock & block, int target, BlockHeader & head);
void mineBlock(MindeBlock & block, int target, BlockHeader & head);
void generateBlock(std::vector<MindeBlock> & blocks,std::vector<std::string>&trans, double version, int target,std::vector<Transaction>&transs);



#endif //MINDECHAIN_HELPERFUNCS_H
