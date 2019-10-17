#include"Helperfuncs.h"

int main() {
    int count=0;
    std::vector<User> users;
    double version=0.01;
    while(count==0){
        std::cout<<"Mindechain versija: V"<<version<<"\n";
        std::cout<<"Sugeneruota "<<users.size()<<" vartotoju, 0 transakciju dar neidetos i blokus\n";
        std::cout<<"Saugoma 0 bloku informacija\n";
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
            }
            while(count!=1&&count!=2&&count!=3&&count!=4&&count!=5);

        }
        switch(count){
            case 1:
                count=0;
                users=genUsers();
                break;
            case 2:
                count=0;
                break;
            case 3:
                count=0;
                break;
            case 4:
                count=0;
                break;
            case 5:
                return 0;
            default:
                count=0;
                break;
        }
    }
}