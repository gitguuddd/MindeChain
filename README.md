# MindeChain

---
## Link to the requirements of the task
[Blockchain DS](https://github.com/blockchain-group/Blockchain-technologijos/blob/master/pratybos/2uzduotis-Blockchain.md)
## Install instructions
1. Clone repository ```$ git clone https://github.com/gitguuddd/MindeChain.git``` or ```$ git clone git@github.com:gitguuddd/MindeChain.git``` if you're using SSH
1. cd to ```MindeChain``` main directory
2. Compile the program using CMakeLists.txt (cmake . , make)
3. cd to ```build``` folder
5. Start the program  ```./MindeChain.exe```, follow terms of use
---
## Terms of use

- After you start the program you will be greeted with a menu that looks like this:
```
   Pasirinkite ka daryti:
   1. Generuoti vartotojus
   2. Generuoti transakcijas
   3. Generuoti MindeChain blokus
   4. Isvesti bloku informacija blocklog.txt faile
   5. Baigti darba

   ``` 
- Choose the first option to generate a desired number of users, you'll be asked to provide count of generated users, name base, min and max values of MindeCoin a user can have
- Choose the second option to generate transactions, min and max values of Mindecoins  will be equal to ```minMindecoins+0.00000001*maxMindecoins and 0.69420*maxMindecoins```
- Choose the third option to generate blocks
- Choose the fourth option to output block info to blocklog.txt file
- Choose the fifth option to exit the program

---
## Changelog
[v0.0.1](https://github.com/gitguuddd/MindeChain/releases/tag/v0.0.1) - (2019-10-17)

**Added**
- Initial files
- ```genUsers``` function generate users
- README
---
## Program structure
- ```HashFuncs.h and HashFuncs.cpp``` contain functions found in ```MindeHash``` class
- ```MindeHash.h``` contains main body of MindeHash class
- ```Helperfuncs.h and HelperFfuncs.cpp``` contain functions that are used to simulate MindeChain
- ```User.h and User.cpp``` contain user class implementation
