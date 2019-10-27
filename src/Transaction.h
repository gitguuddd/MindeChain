//
// Created by Mindaugas K on 10/17/2019.
//

#ifndef MINDECHAIN_TRANSACTION_H
#define MINDECHAIN_TRANSACTION_H

#include <string>
#include <ctime>
#include <chrono>
#include <sstream>

class Transaction {
private:
    std::string m_ID;
    int m_intID;
    std::string m_senderName;
    std::string m_receiverName;
    std::string m_senderPKey;
    std::string m_receiverPKey;
    long double m_sent;
    std::string m_timeStamp;
public:

    Transaction(int ID, std::string senderName, std::string receiverName, std::string senderPKey,
                std::string receiverPKey,
                long double sent)
            : m_senderName(std::move(senderName)), m_receiverName(std::move(receiverName)),
              m_senderPKey(std::move(senderPKey)), m_receiverPKey(std::move(receiverPKey)), m_sent(sent), m_intID(ID) {
        MindeHash::genHash(this->getRawData());
        m_ID = MindeHash::getHash();

    }

    int getUserName() {
        int i = 0;
        std::stringstream (m_senderName) >> i;
        return i;
    }

    int getReceiverName() {
        int i = 0;
        std::stringstream (m_receiverName) >> i;
        return i;
    }

    long double getAmount() {
        return m_sent;
    }

    std::string toString() {
        auto end = std::chrono::system_clock::now();
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);
        m_timeStamp = std::ctime(&end_time);
        std::string str = std::to_string(m_intID) + " " + m_senderName + " " + m_senderPKey + " ------> " +
                          std::to_string(m_sent) + " ------> " + m_receiverName + " " + m_receiverPKey + " at " +
                          m_timeStamp;
        str.resize(str.size() - 1);
        return str;
    }

    std::string getRawData() {
        return m_senderName + m_senderPKey + m_receiverPKey + m_receiverName + m_timeStamp + std::to_string(m_sent) +
               std::to_string(m_intID);
    }

    std::string getId() {
        return m_ID;
    }

    void setID(int ID) {
        m_ID = std::to_string(ID);
    }

};


#endif //MINDECHAIN_TRANSACTION_H
