//
// Created by Mindaugas K on 10/17/2019.
//
#include "Helperfuncs.h"

std::uniform_int_distribution<S_LENGTH> dist(0, ranChrs.length() - 1);
std::uniform_real_distribution<long double> dist2(100.000000, 10000000.000000);
std::uniform_int_distribution<int> dist3(0, 10);
std::uniform_int_distribution<long long> dist4(0, 100000000000000000);
std::uniform_int_distribution<int> dist5(0, 10);
std::uniform_int_distribution<int> dist6(0, 10);
std::string genesisFifth = "20 Dievas tarė: „Tegul vandenys knibždėte knibžda gyvūnais ir paukščiai teskraido virš žemės, padangėse!21 Taip Dievas sutvėrė didelius jūros gyvūnus ir visus kitus gyvius, kurie atsirado iš vandens, ir visus paukščius pagal jų rūšį. Ir Dievas matė, kad tai buvo gerai. 22 Dievas juos palaimino, tardamas: „Būkite vaisingi, dauginkitės ir pripildykite vandenis jūrose, o paukščiai tepripildo žemę! 23 Tai buvo vakaras ir rytas – penktoji diena.";
int timeSinceBirth = 939334200;
std::string JBCFriday = "Kaip visada, kaip visada Vieną dieną sekasi, o kitą jau ne. Du draugeliai ieško pinigų kišenėj, Bet neranda, nes jie nesupranta: Kai lengvai gauna, tai lengvai praranda. Taip jau būna, kad žmonės nesupranta. Maximas buvo geras, Vadimas buvo blogas Maximas mėgo stringus, o Vadimas – šortus. Abu buvo klasiokai, visai ne dvyliktokai Ir mėgo fizinį lavinimą. Penktadienis, artėja vakaras Maximas skambina Vadimui Ne šiaip sau, jis turi pakvietimą Šiandiena tūsas, pas gerą draugą Mišą Bet deja problema, reikia spręst dilemą Iš kur gauti litų, gal laimėt loterijoj? Taip ir buvo, Vadimas pirko bilietą Už paskutines šaibas. Laimėjo ir nusipirko daug alaus Greičiau pas Mišą – tūsas nelauks Jei tau šiandien penktadienis Rytoj – labanaktis 2x Kaip visada, kaip visada Maksimas ir Vadimas lankosi čia Nelegalios lenktynės ir adrenalinas Mentai suuodė staigiai, viską sugadino. Gerai, kad jie turėjo paną, gerą. Nulėkė tuoj pat pas ją žiūrėti kašio finalą. Pasiėmė draugų, pora alaus butelių, Vadimas prikabino keletą mergų, panelių Viskas tvarkoj, viskas gerai Mašina pastatyta po langais Kaimynai nepatenkinti, Nes žino, kad tai nesibaigs Taip lengvai, paprastai, tyliai. Makas kala į klyną new style‘ą gryną Garsink aparatūrą. O ryte pajuto, kad burna išdžiuvo. Nerado piniginių, telefonų, viso kito š**o Jei tau šiandien penktadienis Rytoj – labanaktis 4x";

bool isAlpha(const std::string &str) {
    return std::all_of(str.begin(), str.end(), ::isalpha);
}

void progress(int max, int current) {
    std::cout << "Atlikta " << current / (max / 100) << " % darbo \n";
}

int getAscii(std::string hash) {
    int asciiSum = 0;
    for (char ch:hash) {
        asciiSum += (int) ch;
    }
    return asciiSum - 3136;
}

std::string genTS() {
    std::string timeStamp;
    auto end = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    timeStamp = std::ctime(&end_time);
    timeStamp.resize(timeStamp.size() - 2);
    return timeStamp;
}

std::string random_string(S_LENGTH length) {
    std::string s;
    s.reserve(length);
    while (length--)
        s += ranChrs[dist(mt)];
    return s;

}

std::string inputString() {
    std::string str;
    std::cin >> str;
    if (!isAlpha(str)) {
        do {
            std::cout << "Ivestyje turi buti tik raides, bandykite dar karta \n";
            std::cin >> str;
        } while (!isAlpha(str));
    }
    return str;
}

long double inputBound() {
    long double bound;
    std::cin >> bound;
    if (std::cin.fail()) {
        do {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "Ivestis gali buti tik skaicius, bandykite is naujo\n";
            std::cin >> bound;
        } while (std::cin.fail());
    }
    return bound;
}

int inputNum() {
    int num;
    std::cin >> num;
    if (std::cin.fail()) {
        do {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "Ivestis gali buti tik skaicius, bandykite is naujo\n";
            std::cin >> num;
        } while (std::cin.fail());
    }
    return num;
}

bool checkBounds(long double bound1, long double bound2) {
    if (bound1 < 0 || bound2 < 0 || bound1 >= bound2) {
        return false;
    } else
        return true;
}

std::vector<Miner> genMiners(int count) {
    std::vector<Miner> miners;
    for (int i = 1; i <= count; i++) {
        miners.emplace_back(Miner(i));
    }
    return miners;
}

std::vector<User> genUsers(long double &low, long double &high) {
    std::vector<User> users;
    std::string name;
    std::string privKey;
    std::string publicKey;
    long double mindeCoins;
    std::cout << "Iveskite kiek noresite generuoti vartotoju (>2) \n";
    int count = inputNum();
    if (count <= 2) {
        do {
            std::cout << "Per mazas skaicius (>2), bandykite is naujo";
            count = inputNum();
        } while (count <= 2);
    }
    std::cout << "Iveskite vartotojo vardo pagrinda, bus naudojama formuleje vardas=pagrindas+n \n";
    std::string base = inputString();
    std::cout << "Iveskite kiek minimaliai Mindecoins tures vartotojas (gali buti nesveikasis skaicius)\n";
    low = inputBound();
    std::cout << "Iveskite kiek maksimaliai Mindecoins tures vartotojas (gali buti nesveikasis skaicius)\n";
    high = inputBound();
    if (!checkBounds(low, high)) {
        std::cout << "Ivestos netinkamos min/max Mindecoins reiksmes, bandykite dar karta\n";
        std::cout
                << "Iveskite kiek minimaliai Mindecoins is pradziu tures vartotojas (gali buti nesveikasis skaicius)\n";
        low = inputBound();
        std::cout
                << "Iveskite kiek maksimaliai Mindecoins is pradziu tures vartotojas (gali buti nesveikasis skaicius)\n";
        high = inputBound();
    }
    while (!checkBounds(low, high));
    dist2.param(std::uniform_real_distribution<long double>::param_type(low, high));
    for (int i = 0; i < count; i++) {
        name = base + std::to_string(i);
        privKey = random_string(64);
        MindeHash::genHash(privKey);
        publicKey = MindeHash::getHash();
        mindeCoins = dist2(mt);
        users.emplace_back(User(name, privKey, publicKey, mindeCoins));
        if (count / 100 > 0) {
            if ((i % ((count / 100) * 5) == 0))
                progress(count, i);
        }
    }
    return users;
}

std::vector<Transaction> genTransactions(std::vector<User> &users, long double low, long double high) {
    dist2.param(std::uniform_real_distribution<long double>::param_type(0.69420 * low, 0.69420 * high));
    dist3.param(std::uniform_int_distribution<int>::param_type(0, users.size() - 1));
    std::cout << "Kiek sugeneruoti transakciju (5<)\n";
    int count = inputNum();
    std::vector<Transaction> transactions;
    int sender;
    int receiver;
    long double amount;
    if (count <= 5) {
        do {
            std::cout << "Ivestas per mazas transakciju skaicius\n";
            count = inputNum();
        } while (count <= 5);
    }
    for (int i = 1; i <= count; i++) {
        amount = dist2(mt);
        sender = dist3(mt);
        receiver = dist3(mt);
        if (sender == receiver) {
            do {
                sender = dist3(mt);
                receiver = dist3(mt);
            } while (sender == receiver);
        }
        transactions.emplace_back(
                Transaction(i, users[sender].getName(), users[receiver].getName(), users[sender].getPkey(),
                            users[receiver].getPkey(), amount));
        if (count / 100 > 0) {
            if ((i % ((count / 100) * 5) == 0))
                progress(count, i);
        }

    }
    return transactions;
}

void balanceVerify(std::vector<Transaction> &trans, std::vector<User> &users) {
    int senderID;
    int receiverID;
    long double coinsSent;
    for (int i = 0; i < trans.size(); i++) {
        senderID = trans[i].getUserName();
        receiverID = trans[i].getReceiverName();
        coinsSent = trans[i].getAmount();
        if (users[senderID].getCoins() < coinsSent)
            trans.erase(trans.begin() + i);
        else {
            users[senderID].decrCoins(coinsSent);
            users[receiverID].incrCoins(coinsSent);
        }
    }
    for (int i = 0; i < trans.size(); i++) {
        trans[i].setID(i);
    }
}

void IDHashVerify(std::vector<Transaction> &trans) {
    for (int i = 0; i < trans.size(); i++) {
        MindeHash::genHash(trans[i].getRawData());
        if (trans[i].getId() != MindeHash::getHash())
            trans.erase(trans.begin() + i);
    }
}

int pickMiner(std::set<int> &picked) {
    int rand = dist6(mt);
    while (picked.find(rand) != picked.end()) {
        rand = dist6(mt);
    }
    picked.insert(rand);
    return rand;
}

void removeTransacs(std::vector<std::string> &trans, std::vector<Transaction> &transs, std::vector<int> IDs) {
    for (int id:IDs) {
        trans.erase(trans.begin() + id);
        transs.erase(transs.begin() + id);
    }
    for (int i = 0; i < transs.size(); i++)
        transs[i].setID(i);
    trans = tranToString(transs);
}

std::vector<std::string> select100(std::vector<std::string> trans, std::vector<Transaction> transs) {
    int rand;
    std::vector<std::string> picked;
    if (trans.size() > 100) {
        for (int i = 0; i < 100; i++) {
            dist5.param(std::uniform_int_distribution<int>::param_type(0, trans.size() - 1));
            rand = dist5(mt);
            picked.emplace_back(trans[rand]);

        }
    } else {
        dist5.param(std::uniform_int_distribution<int>::param_type(0, trans.size() - 1));
        picked = trans;

    }
    return picked;
}

std::vector<std::string> tranToString(std::vector<Transaction> trans) {
    std::vector<std::string> strings;
    for (Transaction tran : trans) {
        strings.emplace_back(tran.toString());
    }
    return strings;
}

std::vector<std::string> mRoot(std::vector<std::string> trans) {
    std::string concat;
    std::vector<std::string> results;
    if(trans.empty()){
        MindeHash::genHash("");
        trans[0]=MindeHash::getHash();
        return trans;
    }
    else if(trans.size()==1){
        MindeHash::genHash(trans[0]);
        trans[0]=MindeHash::getHash();
        return trans;
    }
    if (trans.size() % 2 != 0)// tikrina ar lyginis dydis
        trans.emplace_back(
                trans[trans.size() - 1]);// jei ne prideda dar viena paskutiniai transakcijai lygia transakciją
    for (int i = 0; i <= trans.size() - 2; i++) {// i+2 nes sujungiamos transakciju poros ir kartu hashuojamos
        concat = trans[i] + trans[i + 1];// sujungia
        MindeHash::genHash(concat);
        results.emplace_back(MindeHash::getHash());// papildomas patikrinimas,
        i++;
    }
    if (results.size() != 1)// jei yra daugiau nei vienas hashas - rekursija
        mRoot(results);
    if (results.size() == 1)// jei yra tik vienas hashas - returninam
        return results;
}

void mineBlock(Miner &miner, int target, bool &status, int multiplier) {
    int attempt = 1;
    std::vector<std::string> merkleroot;
    std::string blockHash;
    long long nonce = dist4(mt);
    std::string timeStamp = genTS();
    miner.setNonce(nonce);
    miner.setTimestamp(timeStamp);
    miner.setHeader();
    blockHash = miner.getBlockHash();
    while (getAscii(blockHash) < MAX_ASCII * (0.42 +
                                              0.02 * target)) {//https://stackoverflow.com/a/8095276/11198444
        nonce = dist4(mt);
        timeStamp = genTS();
        miner.setNonce(nonce);
        miner.setTimestamp(timeStamp);
        if (attempt % 100 == 0) {
            miner.shuffleTrans();
            merkleroot = mRoot(miner.getTrans());
            MindeHash::genHash(merkleroot[0]);
            miner.setMerkle(MindeHash::getHash());
            attempt = 0;
        }
        miner.setHeader();
        blockHash = miner.getBlockHash();
        if (attempt == 50 * multiplier)
            return;
        attempt++;
    }
    status = true;

}

void mineGenesis(MindeBlock &block, int target, BlockHeader &head) {
    std::string pattern;
    std::string blockHash;
    long long nonce = dist4(mt);
    head.setNonce(nonce);
    block.setHeader(head.stringify());
/*    for(int i=0;i<head.getTarget();i++){
        pattern+=std::to_string(1);
    }*/
    blockHash = block.getBlockHash();
    while (getAscii(blockHash) < MAX_ASCII * (0.3 + 0.02 * target)) {//https://stackoverflow.com/a/8095276/11198444
        nonce = dist4(mt);
        head.setNonce(nonce);
        block.setHeader(head.stringify());
        blockHash = block.getBlockHash();
    }

}

void generateBlock(std::vector<MindeBlock> &blocks, std::vector<std::string> &trans, double version, int target,
                   std::vector<Transaction> &transs, std::vector<Miner> &miners) {
    std::vector<std::string> transax;
    std::set<int> picked;
    int pick =0;
    MindeBlock block;
    bool status = false;
    int multiplier = 1;
    if (blocks.empty()) {
        std::vector<std::string> geneTrans;
        MindeHash::genHash(genesisFifth);
        std::string prevBlock = MindeHash::getHash();
        MindeHash::genHash(JBCFriday);
        std::string merkle = MindeHash::getHash();
        std::time_t end_timE = timeSinceBirth;
        std::string timeStamp = std::ctime(&end_timE);
        timeStamp.resize(timeStamp.size());
        BlockHeader genhead(prevBlock, target, merkle, version);
        genhead.setTimestamp(timeStamp);
        MindeBlock genes(geneTrans);
        mineGenesis(genes, target, genhead);
        std::cout << "Iskastas genesis blockas\n";
        blocks.emplace_back(genes);
    } else {
        std::string prevBlock = blocks[blocks.size() - 1].getBlockHash();
        for (Miner &miner:miners) {
            transax = select100(trans, transs);
            miner.setMindeBlock(MindeBlock(transax));
            miner.setHeaderInit(BlockHeader(prevBlock, target, mRoot(transax)[0], version));
        }
        while (!status) {
            if (picked.size() == miners.size()) {
                multiplier *= 2;
                picked.clear();
            }
            pick = pickMiner(picked);
            mineBlock(miners[pick], target, status, multiplier);
        }
        removeTransacs(trans, transs, miners[pick].getTranIds());
        block = miners[pick].getBlock();
        miners[pick].incrMined();
        std::cout << "Iskastas " << blocks.size() + 1 << " as blokas \n";
        blocks.emplace_back(block);

    }
}

void outputBlock(std::vector<MindeBlock> blocks) {
    std::ofstream fv("BlockLog.txt");
    for (const MindeBlock & Block : blocks) {
        fv << Block;
    }
}

void outputMiners(std::vector<Miner> miners) {
    std::ofstream fv("MinerLog.txt");
    for (const Miner & miner:miners) {
        fv << miner;
    }
}

