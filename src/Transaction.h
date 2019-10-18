//
// Created by Mindaugas K on 10/17/2019.
//

#ifndef MINDECHAIN_TRANSACTION_H
#define MINDECHAIN_TRANSACTION_H
#include <string>
#include <ctime>
#include <chrono>

    class Transaction {
    private:
        int m_ID;
        std::string m_senderName;
        std::string m_receiverName;
        std::string m_senderPKey;
        std::string m_receiverPKey;
        long double m_sent;
        std::string timeStamp;
    public:

        Transaction(int ID,std::string senderName, std::string receiverName, std::string senderPKey, std::string receiverPKey,
                    long double sent)
                : m_senderName(std::move(senderName)), m_receiverName(std::move(receiverName)),
                  m_senderPKey(std::move(senderPKey)), m_receiverPKey(std::move(receiverPKey)), m_sent(sent),m_ID(ID) {


        }

        std::string toString() {
            auto end = std::chrono::system_clock::now();
            std::time_t end_time = std::chrono::system_clock::to_time_t(end);
            timeStamp = std::ctime(&end_time);
            std::string str = std::to_string(m_ID) + " " + m_senderName + " " + m_senderPKey + " ------> " +
                              std::to_string(m_sent) + " ------> " + m_receiverName + " " + m_receiverPKey + " at " +
                              timeStamp;
            str.resize(str.size()-1);
            return str;
        }

    };



#endif //MINDECHAIN_TRANSACTION_H
