#include <iostream>
#include <vector>
#include <map>
#include <iterator>
using namespace std;

#define SIZE 26

/*bool checkLetter(map<char,int> mapa, char letter) {
    bool result = false;
    for (int i = 0 ; i < mapa.size() ; i++) {
        if( mapa[i] == letter ) {
            result = true;
            return result;
        }
    }
    return result;
}*/

/*vector<char> vec (string text) {
    int size = sizeof(text) / text[0];
    vector<char> result[SIZE];
    for(int i = 0 ; i < size ; i++) {
        (checkLetter(result, text[i])) ? :
    }
    return result;

}*/

map<char,int> countFrequency(string text) {
    map<char,int> letters;
    for (char const &c : text) {
        if(letters.find(c) == letters.end())
            letters.insert(pair<char,int> (c, 1));
        else
            letters.find(c)->second++;
    }
    return letters;
}

void printMap(map<char,int> mapa) {
    map<char,int>::iterator itr;
    for(itr = mapa.begin() ; itr != mapa.end(); itr++) {
        cout << itr->first << " : " << itr->second << endl;
    }
}

int main() {
    char blank;
    string textCoded, textUncoded;
    int n ;
    //cin >> n >> blank;

    cin >> textUncoded >> textCoded;


    printMap(countFrequency(textUncoded));
    printMap(countFrequency(textCoded));

    /*for ( int i = 0 ; i < n ; i++) {
        cin >> textUncoded >> textCoded;
    }*/



    return 0;
}