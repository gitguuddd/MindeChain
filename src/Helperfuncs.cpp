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
void progress(int max, int current){
    std::cout<<"Atlikta "<<current/(max/100)<<" % darbo \n";
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
std::vector<User>genUsers(long double & low, long double & high){
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
     low=inputBound();
    std::cout<<"Iveskite kiek maksimaliai Mindecoins tures vartotojas (gali buti nesveikasis skaicius)\n";
     high=inputBound();
    if(!checkBounds(low,high)){
        std::cout<<"Ivestos netinkamos min/max Mindecoins reiksmes, bandykite dar karta\n";
        std::cout<<"Iveskite kiek minimaliai Mindecoins is pradziu tures vartotojas (gali buti nesveikasis skaicius)\n";
        low=inputBound();
        std::cout<<"Iveskite kiek maksimaliai Mindecoins is pradziu tures vartotojas (gali buti nesveikasis skaicius)\n";
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
        if((i%((count/100)*5)==0))
            progress(count,i);
    }
    return users;
}
std::vector<Transaction>genTransactions(std::vector<User> & users,long double low, long double high){
    dist2.param(std::uniform_real_distribution<long double>::param_type(low+0.00000001*high,low+0.69420*high));
    dist3.param(std::uniform_int_distribution<int>::param_type(0,users.size()-1));
    std::cout<<"Kiek sugeneruoti transakciju (5<)\n";
    int count=inputNum();
    std::vector<Transaction> transactions;
    int sender;
    int receiver;
    long double amount;
    if(count<=5){
        do{
            std::cout<<"Ivestas per mazas transakciju skaicius\n";
            count=inputNum();
        }
        while(count<=5);
    }
    for(int i=1; i<=count;i++){
        amount=dist2(mt);
        sender=dist3(mt);
        receiver=dist3(mt);
        if(amount>users[sender].getCoins()){
            do{
                amount=dist2(mt);
                sender=dist3(mt);
                receiver=dist3(mt);
        if(sender==receiver){
            do{
                sender=dist3(mt);
                receiver=dist3(mt);
            }
            while(sender==receiver);
        }}
        while(amount>users[sender].getCoins());}
        transactions.emplace_back(Transaction(i,users[sender].getName(),users[receiver].getName(),users[sender].getPkey(),users[receiver].getPkey(),amount));
        users[sender].decrCoins(amount);
        users[receiver].incrCoins(amount);
        if((i%((count/100)*5)==0))
            progress(count,i);

    }
    return transactions;
}

