//
//  main.cpp
//  md1_cpp
//
//  Created by Arta Zidele on 24/10/2024.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    
    ifstream file("ieeja.txt");
    if(file.is_open()) {
        // nolasa datus
        string rinda;
        getline(file, rinda);
        int k = stoi(rinda);
        int a[k];
        int m[k];
        for (int i=0; i<k; i++) {
            getline(file, rinda);
            m[i] = stoi(rinda);
        }
        for (int i=0; i<k; i++) {
            getline(file, rinda);
            a[i] = stoi(rinda);
        }
        // izmantoju ķīniešu teorēmu par atlikumiem
        int mMultiplication = 1;
        for (int i=0; i<k; i++) {
            mMultiplication *= m[i];
        }
        int aSum = 0;
        for (int i=0; i<k; i++) {
            int n = mMultiplication/m[i];
            for (int j=1; j<m[i]; j++) {
                if ((n*j)%m[i] == a[i]%m[i]) {
                    aSum += n*j;
                    break;
                }
            }
        }
        if (aSum >= mMultiplication) {
            aSum %= mMultiplication;
        }
        cout << aSum << endl;
    }
    file.close();
    return 0;
}
