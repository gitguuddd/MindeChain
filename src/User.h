//
// Created by Mindaugas K on 10/17/2019.
//

#ifndef MINDECHAIN_USER_H
#define MINDECHAIN_USER_H

#include <string>


class User {
private:
    std::string m_name;
    std::string m_privKey;
    std::string m_publicKey;
    long double m_Mindecoins;
public:
    User(std::string name,std::string  privKey,std::string  publicKey, long double Mindecoins)
        :m_name(std::move(name)),m_privKey(std::move(privKey)),m_publicKey(std::move(publicKey)),m_Mindecoins(Mindecoins)
    {

    }
};


#endif //MINDECHAIN_USER_H
