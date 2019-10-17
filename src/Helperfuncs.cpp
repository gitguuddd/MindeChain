//
// Created by Mindaugas K on 10/17/2019.
//
#include "Helperfuncs.h"
long long seed=std::chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 mt(seed);
std::uniform_int_distribution<S_LENGTH> dist(0, ranChrs.length()-1);
std::uniform_real_distribution<long double> dist2(100.000000,10000000.000000);
std::uniform_int_distribution<int> dist3(0,10);
bool isAlpha( const std::string & str){
    return std::all_of(str.begin(), str.end(), ::isalpha);
}
std::string random_string(S_LENGTH length){
    std::string s;
    s.reserve(length);
    while(length--)
        s+=ranChrs[dist(mt)];
    return s;

}
std::string inputString(){
    std::string str;
    std::cin>>str;
    if(!isAlpha(str)){
        do{
        std::cout<<"Ivestyje turi buti tik raides, bandykite dar karta \n";
        std::cin>>str;}
        while(!isAlpha(str));
    }
    return str;
}

long double inputBound(){
    long double bound;
    std::cin>>bound;
    if(std::cin.fail()){
       do{ std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout<<"Ivestis gali buti tik skaicius, bandykite is naujo\n";
        std::cin>>bound;}
       while(std::cin.fail());
    }
    return bound;
}
int inputNum(){
    int num;
    std::cin>>num;
    if(std::cin.fail()){
        do{ std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cout<<"Ivestis gali buti tik skaicius, bandykite is naujo\n";
            std::cin>>num;}
        while(std::cin.fail());
    }
    return num;
}
bool checkBounds(long double bound1, long double bound2){
    if(bound1<0||bound2<0||bound1>=bound2){
        return false;
    }
    else
        return true;
}
std::vector<User>genUsers(){
    std::vector<User> users;
    std::string name;
    std::string privKey;
    std::string publicKey;
    long double mindeCoins;
    std::cout<<"Iveskite kiek noresite generuoti vartotoju (>2) \n";
    int count=inputNum();
    if(count<=2){
        do{
            std::cout<<"Per mazas skaicius (>2), bandykite is naujo";
            count=inputNum();
        }
        while(count<=2);
    }
    std::cout<<"Iveskite vartotojo vardo pagrinda, bus naudojama formuleje vardas=pagrindas+n \n";
    std::string base=inputString();
    std::cout<<"Iveskite kiek minimaliai Mindecoins tures vartotojas (gali buti nesveikasis skaicius)\n";
    long double low=inputBound();
    std::cout<<"Iveskite kiek maksimaliai Mindecoins tures vartotojas (gali buti nesveikasis skaicius)\n";
    long double high=inputBound();
    if(!checkBounds(low,high)){
        std::cout<<"Ivestos netinkamos min/max Mindecoins reiksmes, bandykite dar karta\n";
        std::cout<<"Iveskite kiek minimaliai Mindecoins tures vartotojas (gali buti nesveikasis skaicius)\n";
        low=inputBound();
        std::cout<<"Iveskite kiek maksimaliai Mindecoins tures vartotojas (gali buti nesveikasis skaicius)\n";
        high=inputBound();
    }
    while(!checkBounds(low,high));
    dist2.param(std::uniform_real_distribution<long double>::param_type(low,high));
    for(int i=0;i<count;i++){
        name=base+std::to_string(i);
        privKey=random_string(64);
        MindeHash::genHash(privKey);
        publicKey=MindeHash::getHash();
        mindeCoins=dist2(mt);
        users.emplace_back(User(name,privKey,publicKey,mindeCoins));

    }
    return users;
}

