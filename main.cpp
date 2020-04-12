#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

string makeString(multimap<int,char, greater<int>> mapaCoded,
        multimap<int,char, greater<int>> mapaUncoded) {

    string finalText = "";
    multimap<int,char, greater<int>>::iterator itr;
    multimap<int,char, greater<int>>::iterator it;

    for( itr = mapaCoded.begin() ; itr != mapaCoded.end() ; itr++) {
        it = mapaUncoded.begin();
        finalText + string(itr->first, (it->second));
        it++;
    }
    return finalText;
}

multimap<int,char, greater<int>> translate(multimap<int,char, greater<int>> mapCoded, multimap<int,char, greater<int>> mapUncoded) {
    multimap<int,char, greater<int>> :: iterator itr;
    multimap<int,char, greater<int>> :: iterator it;

    for( itr = mapCoded.begin() ; itr != mapCoded.end() ; itr++) {
        it = mapUncoded.begin();
        itr->second = it->second;
        it++;
    }
    return mapCoded;
}

multimap<int,char, greater<int> > invert(map<char,int> mapa) {
    multimap<int,char, greater<int> > result;

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

void printInvertedMap(multimap<int,char, greater<int>> mapa ) {
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
    string textCoded, textUncoded, textFinal;
    int n ;

    cin >> n >> blank;
    cin >> textUncoded >> textCoded;
    sort(textCoded.begin(),textCoded.end());
    sort(textUncoded.begin(),textUncoded.end());

    printMap(countOccurrences(textUncoded));
    printInvertedMap(invert(countOccurrences(textUncoded)));
    cout << endl;

    printMap(countOccurrences(textCoded));
    printInvertedMap(invert(countOccurrences(textCoded)));
    cout << endl;

    printInvertedMap(translate(invert(countOccurrences(textUncoded)), invert(countOccurrences(textCoded))));


    /*for ( int i = 0 ; i < n ; i++) {
        cin >> textUncoded >> textCoded;
    }*/



    return 0;
}