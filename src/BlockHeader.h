//
// Created by Mindaugas K on 10/18/2019.
//

#ifndef MINDECHAIN_BLOCKHEADER_H
#define MINDECHAIN_BLOCKHEADER_H

#include <string>
#include <sstream>
class BlockHeader {
private:
    std::string m_prevHash;
    std::string m_timestamp;
    int m_target;
    std::string m_merkleRoot;
    double m_version;
    long long m_nonce;
public:
    BlockHeader( std::string  prevHash, int target, std::string  merkleRoot, double version)
        :m_prevHash(prevHash),m_merkleRoot(merkleRoot),m_version(version),m_target(target){
        m_nonce=0;
        m_timestamp="";
    }
    void setTimestamp(std::string tS){
        tS.resize(tS.size()-1);
        std::stringstream ss;
        ss<<std::hex<<tS;
        m_timestamp = "0x"+ss.str();
    }
    void setNonce(long long nO){
        m_nonce=nO;
    }
    int getTarget(){
        return m_target;
    }
    std::string stringify(){
        std::string str =std::to_string(m_version)+"00"+m_prevHash+"00"+m_merkleRoot+"00"+m_timestamp+"00"+std::to_string(m_target)+"00"+std::to_string(m_nonce);
        return str;
    }


};


#endif //MINDECHAIN_BLOCKHEADER_H
