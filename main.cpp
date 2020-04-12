#include <iostream>
#include <map>
using namespace std;

map<int,char, greater<int> > invert(map<char,int> mapa) {
    map<int,char, greater<int> > result;

    map<char,int> :: iterator itr;
    for( itr = mapa.begin() ; itr != mapa.end() ; itr++) {
        result.insert(pair<int,char> (itr->second,itr->first));
    }
    return result;
}

map<char,int> countOccurrences(string text) {
    map<char,int> letters;
    letters.insert(pair<char,int> (text[0],1));

    for (char const &c : text) {
        if(letters.find(c) == letters.end())
            letters.insert(pair<char,int> (c, 1));
        else
            letters.find(c)->second++;
    }

    return letters;
}

void printInvertedMap(map<int,char, greater<int>> mapa ) {
    map<int,char, greater<int>>::iterator itr;
    for(itr = mapa.begin() ; itr != mapa.end(); itr++) {
        cout << itr->first << " : " << itr->second << endl;
    }
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

    cin >> n >> blank;
    cin >> textUncoded >> textCoded;

    printMap(countOccurrences(textUncoded));
    printInvertedMap(invert(countOccurrences(textUncoded)));


    /*for ( int i = 0 ; i < n ; i++) {
        cin >> textUncoded >> textCoded;
    }*/



    return 0;
}