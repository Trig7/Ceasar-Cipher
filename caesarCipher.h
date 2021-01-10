#pragma once
#include <string>

using namespace std;

string encrypt(string str, int key) {
    string encrypt = str;
    for (int i = 0; i < str.size(); i++) {
        encrypt[i] = encrypt[i] + key;
    }
    return encrypt;
}

string decrypt(string str, int key) {
    string decrypt = str;
    for (int i = 0; i < str.size(); i++) {
        decrypt[i] = decrypt[i] - key;
    }
    return decrypt;
}