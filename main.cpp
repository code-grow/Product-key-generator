#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include<windows.h>
#include<unistd.h>

char generateRandomChar() {
    const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    return characters[rand() % characters.length()];
}

// Function to generate a serial key
std::string generateSerialKey(int length) {
    std::string serialKey;
    for (int i = 0; i < length; ++i) {
        serialKey += generateRandomChar();
    }
    return serialKey;
}

std::string insertDashes(const std::string& word) {
    std::string result;
    for (size_t i = 0; i < word.length(); i++) {
        result += word[i];
        if ((i + 1) % 4 == 0 && i != word.length() - 1) {
            result += '-';
        }
    }
    return result;
}

int main() {
    //while(true){
    srand(static_cast<unsigned int>(time(nullptr)));
    int keyLength;
    std::cout<<"Enter the length of the Product key: "; std::cin>>keyLength;
    while(true){
    std::string serialKey = generateSerialKey(keyLength);
    //std::cout << "Generated Serial Key: " << serialKey <<'\n';
    std::string dashedkey = insertDashes(serialKey);
    //std::cout << "Product key with dashes: " << dashedkey << '\n';//<< '\n'<< '\n';
    std::cout <<dashedkey << '\n';
    Sleep(150);
    }
   return 0;
}
