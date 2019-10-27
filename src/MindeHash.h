//
// Created by Mindaugas K on 9/13/2019.
//

#ifndef HASH_GEN_MINDEHASH_H
#define HASH_GEN_MINDEHASH_H

#include "HashFuncs.h"

void cutnCypher(std::string &s, const std::string &pKey, const std::string &sKey);

class MindeHash {
private:
    static std::string m_hash;//hashed input
    static std::string m_precursorKey; //key that is equal to original input after chartoint was used on it
    static std::string m_sumKey;//key that is equal to the sum of original input after chartoint was used on it
public:
    MindeHash() = delete;

    friend void cutnCypher(std::string &s, const std::string &pKey,
                           const std::string &sKey);// cornerstone function of MindeHash, compreses the processed input into a hash

    static void clearKey() {// clears precursor key
        m_precursorKey.clear();
    }

    static void clearSumKey() {// clears sum key
        m_sumKey.clear();
    }

    static bool isSumEmpty() {// checks if sum key is empty
        return m_sumKey.empty();
    }

    static void iToSumKey(int a) {// converts passed int value to sum key
        m_sumKey = std::to_string(a);
    }

    static void
    genHash(const std::string &s) {// runs all functions needed to generate a from input hash, runs the program recursively if it's necessary

        std::vector<int> vect;
        if (s.empty())
            m_hash = charToInt(DEFAULT_INPUT);
        else
            m_hash = charToInt(s);
        if (m_precursorKey.empty())
            m_precursorKey = m_hash;
        divideString(vect, m_hash);
        std::vector<std::string> hexVect = toHex(vect);
        deNullnShift(hexVect);
        m_hash = vectToString(hexVect);
        m_hash.length() >= 64 ? cutnCypher(m_hash, m_precursorKey, m_sumKey) : genHash(m_hash);
        MindeHash::clearSumKey();
        MindeHash::clearKey();
    }

    static std::string getHash() {
        return m_hash;
    }

};

#endif //HASH_GEN_MINDEHASH_H
