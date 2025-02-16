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
   4. Isvesti bloku informacija BlockLog.txt faile
   5. Isvesti mineriu informacija MinerLog.txt faile
   6. Baigti darba

   ``` 
- Choose the first option to generate a desired number of users, you'll be asked to provide count of generated users, name base, min and max values of MindeCoin a user can have
- Choose the second option to generate transactions, min and max values of Mindecoins  will be equal to ```0.69420*minMindecoins and 0.69420*maxMindecoins```
- Choose the third option to generate blocks
- Choose the fourth option to output info of all the blocks to ```BlockLog.txt``` file
- Choose the fifth option to output info of all the miners to ```MinerLog.txt``` file
- Choose the sixth option to exit the program

---
## Block header structure
- Block header structure follows this pattern : ```MindeChain version|previous block hash|merkle root hash of all transactions in the block|timestamp when block was mined|difficulty target|nonce value```

---
## A couple of interesting things about MindeChain genesis block
- Mindecoin genesis block contains some interesting hardcoded values that are used as hashing values to generate following block header fields
- Previous block hash is obtained by hashing a part of the bible. More specifically : Genesis ch 1 , lines 20-23 - the lines that talk about the works that God had done on the fifth day (**Friday**)
- Merkle root hash is obtained by hashing the lyrics of a song made by JBC (**J**uoda**B**alta**C**rew) - a Lithuanian hip hop group that was active during the years 2000-2006. The name of the song is **Friday(Penktadienis)**
- The timestamp value is obtained by converting 939334200 seconds that had passed since 1970 January 1st (zero point of POSIX time) into an alphanumeric formatted date. After the conversion the timestamp value is equal to the exact time of my birthday, which also happened on **Friday**


---
## BlockLog test run

- Generated users : **100000**
- Generated transactions : **100000**
- Generated blocks (genesis included) : **1001**
- ```BlockLog.txt``` size after outputting : **21.046 MB**
- [BlockLog contents](https://www.dropbox.com/s/lh3i1aubyeg6p4d/BlockLog.txt?dl=0)


---
## MinerLog test run

- Generated users : **10000**
- Generated transactions : **9251**
- Generated blocks (genesis included) : **94**
- [MinerLog contents](https://www.dropbox.com/s/5nfj02yawgm67jf/MinerLog.txt?dl=0)

## Houston, we have established a connection with bitcoin full node
- ![Bitcoin](src/bitcoincli.png)
- Connection to a full node provided by my good friend [Augustinas Makevičius](https://github.com/AugustinasMK). This guy deserves his 0.1 bonus :)
---
## Changelog

[v0.3.1](https://github.com/gitguuddd/MindeChain/releases/tag/v0.3.1) - (2019-11-22)

**Changed**
- Fixed fatal bugs left in ```mroot()``` function by the last version
- Added the section about connecting to bitcoin full node

**Removed**
- Redundant code


---
[v0.3](https://github.com/gitguuddd/MindeChain/releases/tag/v0.3) - (2019-11-21 - 2019-11-22)

**Changed**
- Added some missing functionality to ```mroot()``` function
- README

---
[v0.2](https://github.com/gitguuddd/MindeChain/releases/tag/v0.2) - (2019-10-27)

**Added**
- ```Miner``` class to store miner info
- ```genMiners()``` function to generate a user chosen number of miners
- ```getAscii()``` function to return the sum of all character ascii codes of a given string
- ```outputMiners()``` function to output miner info to ```MinerLog.txt```
- ```removeTransacs()``` function to remove transactions that were stored by the miner that successfully mined the block

**Changed**
- The POW concept of ```MindeChain``` now relies on the total ascii code sum of all the characters in the block hash. This change allows to
implement a quite effective ```target``` scale from 1 to 10
- ```generateBlocks() and mineBlock()``` functions changed according to mining related implementations
- Reformated code

---
[v0.1.5](https://github.com/gitguuddd/MindeChain/releases/tag/v0.1.5) - (2019-10-25)

**Added**
- ```balanceVerify()``` function used to remove transactions, in which the sender is sending more Mindecoins than he currently has. The function is also responsible for carrying out the transactions - sending Mindecoins from one user to other
- ```IDHashVerify()``` function used to remove transactions, which have been maliciously changed before reaching the transaction pool

**Changed**
- README
- Impaired ```genTransactions()``` - removed amount checking and instant user Mindecoins incrementation/decrementation so that the aforementioned added functions would be of use

---
[v0.1.2](https://github.com/gitguuddd/MindeChain/releases/tag/v0.1.2) - (2019-10-19)

**Added**
- ```outputBlock()``` - a function that outputs all the contents of all the blocks into ```BlockLog.txt``` file located in build directory
- Fixes for a couple of bugs
- ```BlockLog.txt``` example in README

**Changed**
- Block header is now more easier to read - added ```|``` as a separator
- Minimal transaction amount is now equal to ```0.69420*minimum amount of MindeCoins an user can own```
- README


---
[v0.1](https://github.com/gitguuddd/MindeChain/releases/tag/v0.1) - (2019-10-18)

**Added**
- ```MindeBlock.h```
- ```BlockHeader.h```
- ```generateBlocks()``` - the main function of this program
- ```mineBlock() and mineGenesis()``` - functions used for mining new blocks
- ```mRoot()``` - function used to generate a merkel tree hash from a given vector of transaction strings
- ```select100()```- a function that select which random transanctions to include in next block
- ```tranToString``` - a function that converts a vector of transactions to a vector of strings
- Additional input handling logic

**Changed**
- README

**Idea**
- Base my POW on the total ascii value of the generated hash

---
[v0.0.3](https://github.com/gitguuddd/MindeChain/releases/tag/v0.0.3) - (2019-10-18)

**Added**
- Transaction class
- ```genTransactions()``` function

**Changed**
- README

**Removed**
- ```User.cpp```

---
[v0.0.1](https://github.com/gitguuddd/MindeChain/releases/tag/v0.0.1) - (2019-10-17)

**Added**
- Initial files
- ```genUsers``` function for generating users
- README
---
## Program structure
- ```HashFuncs.h and HashFuncs.cpp``` contain functions found in ```MindeHash``` class
- ```MindeHash.h``` contains main body of MindeHash class
- ```Helperfuncs.h and HelperFfuncs.cpp``` contain functions that are used to simulate MindeChain
- ```User.h``` contains user class implementation
- ```Transaction.h``` contains transaction class implementation
- ```BlockHeader.h``` contains an implementation of a block header
- ```MindeBlock.h``` contains an implementation of a MindeChain block
