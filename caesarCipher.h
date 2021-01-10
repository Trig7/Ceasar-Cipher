#pragma once
#include <string>

using namespace std;

string encrypt(string str, int key) {
    string encrypt = str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 32) {
            continue;
        }
        else {
            if (str[i] > 32 && str[i] < 64) {
                continue;
            }
            else if (str[i] == 46) {
                encrypt[i] = 46;
            }
            else if (str[i] + key > 122) {
                int temp = (str[i] + key) - 122;
                encrypt[i] = 96 + temp;
            }
            else if (str[i] + key > 90 && str[i] <= 96) {
                int temp = (str[i] + key) - 90;
                encrypt[i] = 64 + temp;
            }
            else {
                encrypt[i] += key;
            }
        }
    }
    return encrypt;
}

string decrypt(string str, int key) {
    string decrypt = str;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 32) {
            continue;
        }
        else {
            if (str[i] > 32 && str[i] < 64) {
                continue;
            }
            else if ((str[i] - key) < 97 && (str[i] - key) > 90) {
                int temp = (str[i] - key) + 26;
                decrypt[i] = temp;
            }
            else if ((str[i] - key) < 65) {
                int temp = (str[i] - key) + 26;
                decrypt[i] = temp;
            }
            else {
                decrypt[i] = str[i] - key;
            }
        }
    }
    return decrypt;
}