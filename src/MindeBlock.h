//
// Created by Mindaugas K on 10/18/2019.
//

#ifndef MINDECHAIN_MINDEBLOCK_H
#define MINDECHAIN_MINDEBLOCK_H

#include <string>
#include <vector>
#include "MindeHash.h"

class MindeBlock {
private:
    std::string m_header;
    std::vector<std::string> m_transacs;
public:
    MindeBlock(std::vector<std::string> transacs)
        :m_transacs(std::move(transacs)){
        m_header=" ";
    }
       std::string getBlockHash(){
           MindeHash::genHash(m_header);
           return MindeHash::getHash();
       }
       void setHeader(std::string head){
           m_header=std::move(head);
       }
       std::string getHeader() const {
           return m_header;
       }
       std::string getTransacs () const {
           std::string str ;
           for(const std::string & tran : m_transacs)
               str+=tran+"\n";
           return str;
       }

    friend std::ostream& operator<<(std::ostream & fv,  const MindeBlock  & block){
        fv<<"{\n";
        fv<<block.getHeader()<<"\n";
        fv<<block.getTransacs()<<"\n";
        fv<<"}\n";
       }

};


#endif //MINDECHAIN_MINDEBLOCK_H
