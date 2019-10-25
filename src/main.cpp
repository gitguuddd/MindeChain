#include"Helperfuncs.h"
int main() {
    int count=0;
    int target;
    int blocksCount=0;
    std::string ts;
    long double low;
    long double high;
    std::vector<User> users;
    std::vector<Transaction> transactions;
    std::vector<std::string> transactionStrings;
    std::vector<MindeBlock> MindeBlocks;
    double version=0.15;
    while(count==0){
        std::cout<<"Mindechain versija: V"<<version<<"\n";
        std::cout<<"Sugeneruota "<<users.size()<<" vartotoju, "<<transactions.size()<<" transakciju dar neidetos i blokus\n";
        std::cout<<"Saugoma "<<MindeBlocks.size()<<" bloku informacija\n";
        std::cout<<"Pasirinkite ka daryti: \n";
        std::cout<<"1. Generuoti vartotojus \n";
        std::cout<<"2. Generuoti transakcijas \n";
        std::cout<<"3. Generuoti MindeChain blokus \n";
        std::cout<<"4. Isvesti bloku informacija blocklog.txt faile \n";
        std::cout<<"5. Baigti darba \n";
        std::cin>>count;
        if(count!=1&&count!=2&&count!=3&&count!=4&&count!=5){
            do{
                std::cout<<"Ivestas netinkamas pasirinkimas, bandykite dar karta";
                std::cin>>count;
            }
            while(count!=1&&count!=2&&count!=3&&count!=4&&count!=5);

        }
        switch(count){
            case 1:
                count=0;
                users=genUsers(low,high);
                break;
            case 2:
                count=0;
                if(users.empty()){
                    std::cout<<"Negalima generuoti transakciju neturint vartotoju \n";
                    break;
                }
                transactions=genTransactions(users,low,high);
                IDHashVerify(transactions);
                balanceVerify(transactions,users);
                break;
            case 3:
                count=0;
                if(transactions.empty()){
                    std::cout<<"Negalima generuoti bloku neturint transakciju \n";
                    break;
                }
                std::cout<<"Iveskite pageidaujama minenimo sunkuma [1;16] (kuo didesnis tuo ilgiau programa uztruks ;) ) \n";
                target=inputNum();
                if(target<=0||target>16){
                    do{
                        std::cout<<"Ivestas sunkumas nepriklauso reziams, bandykite dar karta \n";
                        target=inputNum();
                    }
                    while(target<=0||target>16);
                }
                transactionStrings=tranToString(transactions);
                if(transactionStrings.size()%100!=0)
                    blocksCount++;
                if(MindeBlocks.empty()){
                blocksCount++;}
                blocksCount+=transactionStrings.size()/100;
                for(int i=0;i<blocksCount;i++){

                    generateBlock(MindeBlocks,transactionStrings,version,target,transactions);
                }
                blocksCount=0;
                break;
            case 4:
                count=0;
                if(MindeBlocks.empty()){
                    std::cout<<"Negalima generuoti BlockLog.txt failo neturint saugomų blokų\n";
                    break;
                }
                outputBlock(MindeBlocks);
                std::cout<<"Bloku duomenys išvesti sekmingai\n";
                MindeBlocks.clear();
                break;
            case 5:
                return 0;
            default:
                count=0;
                break;
        }
    }
}