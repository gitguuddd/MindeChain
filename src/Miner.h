//
// Created by Mindaugas K on 10/26/2019.
//

#ifndef MINDECHAIN_MINER_H
#define MINDECHAIN_MINER_H

#include "MindeBlock.h"
#include "BlockHeader.h"

class Miner {
private:
    int m_id;
    int m_mined;
    BlockHeader m_head;
    MindeBlock m_block;
public:
    explicit Miner(int id) : m_id(id), m_mined(0) {}

    void setMindeBlock(MindeBlock block) {
        m_block = std::move(block);
    }

    int getID() const {
        return m_id;
    }

    int getMined() const {
        return m_mined;
    }

    std::vector<int> getTranIds() {
        std::vector<std::string> transactions = m_block.getTransacsVector();
        int id;
        std::vector<int> ids;
        for (const std::string &tran:transactions) {
            std::stringstream(tran.substr(0, ' ')) >> id;
            ids.push_back(id);
        }
        return ids;
    };

    std::vector<std::string> getTrans() {
        return m_block.getTransacsVector();
    }

    void shuffleTrans() {
        m_block.shuffleTransacs();
    }

    void setNonce(long long nonce) {
        m_head.setNonce(nonce);
    }

    void setTimestamp(std::string tS) {
        m_head.setTimestamp(std::move(tS));
    }

    void setHeader() {
        m_block.setHeader(m_head.stringify());
    }

    std::string getBlockHash() {
        return m_block.getBlockHash();
    }

    void setMerkle(const std::string &merkle) {
        m_head.setMerkle(merkle);
    }

    MindeBlock getBlock() {
        return m_block;
    }

    void setHeaderInit(BlockHeader head) {
        m_head = std::move(head);
    }

    void incrMined() {
        m_mined++;
    }

    friend std::ostream &operator<<(std::ostream &fv, const Miner &miner) {
        fv << "Mineris " << miner.getID() << " ismine'ino " << miner.getMined() << "bloku \n";
    }


};


#endif //MINDECHAIN_MINER_H
