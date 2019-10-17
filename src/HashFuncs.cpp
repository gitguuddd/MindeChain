//
// Created by Mindaugas K on 9/13/2019.
//
#include "HashFuncs.h"
#include "MindeHash.h"
std::string MindeHash::m_hash;
std::string MindeHash::m_precursorKey;
std::string MindeHash::m_sumKey;


std::string charToInt(const std::string &str) {
    int sum=0;
    std::string sub;
    for (const char a:str){
        if(MindeHash::isSumEmpty())
            sum+=(unsigned int) a;
        sub += std::to_string((unsigned int) a);}
    if(MindeHash::isSumEmpty())
        MindeHash::iToSumKey(sum);

    return sub;
}

void divideString( std::vector<int> &vect,  std::string &str) {
    std::string sub;
    int len = str.length();
    if (str.length() < 5) {
        for (int i = 0; i < 5 - len; i++)
            str+=str[i];
    } else if (str.length() % 5 != 0) {
        int mod = str.length() % 5;
        for (int i = 0; i < 5 - mod; i++)
            str+=str[i];
    }
    for (int i = 0; i < str.length() / 5; i++) {
        sub = str.substr((uint8_t) (i * 5), 5);
        vect.push_back(std::stoi(sub));
    }
}

void leftRotate(std::string &s, int d) {
    reverse(s.begin(), s.begin() + d);
    reverse(s.begin() + d, s.end());
    reverse(s.begin(), s.end());
}

void rightRotate(std::string &s, int d) {
    leftRotate(s, s.length() - d);
}

void deNullnShift(std::vector<std::string> &vect) {
    std::size_t pos;
    int i=0;
    for(std::string &s:vect){
    while (s.find('0') != std::string::npos) {
        pos = s.find('0');
        if (pos % 2 == 0) {
            s.erase(s.begin() + pos);
            rightRotate(s, pos);
        } else if (pos % 2 != 0) {
            s.erase(s.begin() + pos);
            leftRotate(s, pos);
        }
    }
    if(i<=s.length())
    i%2==0? leftRotate(s, i): rightRotate(s, i);
    else
        i%2==0? leftRotate(s, i%s.length()): rightRotate(s, i%s.length());
    i++;
    }
}
std::string vectToString(const std::vector<std::string> & vect){
    std::stringstream stream;
    for(std::string s : vect)
        stream<<s;
    return stream.str();
}



int fixRange(char a){
    int code=a;
    if(code>=58&&code<=64)
        code=64+code%57;
    else if(code>=91&&code<=96)
        code=96+code%90;
    return code;
}
void convertRange(int oldMin, int oldMax, int newMin, int newMax, char &a){
    int oldVal=fixRange(a);
    int oldRange=oldMax-oldMin;
    int newRange=newMax-newMin;
    int newVal=(((oldVal-oldMin)*newRange)/oldRange)+newMin;
    a=CHARACTER_SET[newVal];
}
void cutnCypher(std::string &s,const std::string &pKey, const std::string &sKey) {
    std::string key;
    int ascii;
    key = s.substr(64);
    s.erase(64,key.length());
    int keyMult = 0;
    int trueIndex;
    for (int i = 0; i < key.length(); i++) {
        trueIndex = i - keyMult * 64;
       s[trueIndex] = static_cast<char>(((int) (s[trueIndex]) + (int) (key[i])) /
                                         2);/*char is sum of the chars found in main hash and key*/
        convertRange(48,122,0,61,s[trueIndex]);
        std::abs((int) (s[trueIndex]) % 2) == 0 ? rightRotate(s, trueIndex) : leftRotate(s, trueIndex);
        keyMult = i / 64;
    }
    keyMult = 0;
    for(int i=0;i<pKey.length();i++){
        trueIndex=i-keyMult*64;
        ascii=(int)s[trueIndex]+(int)pKey[i]-48;
        if(ascii>122){
            ascii=48+ascii%122;
        }
        s[trueIndex]= static_cast<char>(ascii);
        convertRange(48,122,0,61,s[trueIndex]);
        keyMult = i / 64;
    }
    keyMult = 0;
    for(int i=0;i<sKey.length();i++){
        trueIndex=i-keyMult*64;
        ascii=(int)s[trueIndex]-((int)sKey[i]-48);
        if(ascii<48)
            ascii=122-(48-ascii);
        s[trueIndex]= static_cast<char>(ascii);
        convertRange(48,122,0,61,s[trueIndex]);
        keyMult = i / 64;
    }
    for(int a:pKey){
        a=a-48;
        a%2==0?leftRotate(s,a):rightRotate(s,a);
    }
    for(int b:sKey){
        b=b-48;
        b%2==0?rightRotate(s,b):leftRotate(s,b);
    }
    if(s.length()>64)
        cutnCypher(s,pKey,sKey);
    if (s.length() < 64) {
        MindeHash::genHash(s);
    }


}


