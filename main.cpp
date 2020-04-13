#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;


string translateText(string text, map<char,char> charMap) {
    string translatedText = "";
    for(char const &c : text) {
        translatedText.push_back(charMap.at(c));
    }
    return translatedText;
}

map<char,char> translateCharacters(multimap<int,char, greater<int>> mapCoded, multimap<int,char, greater<int>> mapUncoded) {
    map<char,char> result;
    multimap<int,char, greater<int>> :: iterator itr;
    multimap<int,char, greater<int>> :: iterator it;
    it = mapUncoded.begin();

    for( itr = mapCoded.begin() ; itr != mapCoded.end() ; itr++) {
        result.insert(pair<char,char> (itr->second,it->second));
        it++;
    }
    return result;
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
    letters.insert(pair<char,int> (text[0],0));

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

void printMap(map<char,char> mapa) {
    map<char,char>::iterator itr;
    for(itr = mapa.begin() ; itr != mapa.end(); itr++) {
        cout << itr->first << " : " << itr->second << endl;
    }
}

string mapToString( multimap <int,char, greater<int>> finalMap) {
    string translatedText = "";
    multimap<int,char, greater<int>> :: iterator itr;

    for(itr = finalMap.begin() ; itr != finalMap.end() ; itr++) {

        for(int i = 0 ; i < itr->first ; i++) {
            translatedText.push_back(itr->second);
        }
    }
    return translatedText;
}

int main() {
    string textCoded, textUncoded, textFinal;
    int n ;
    cin >> n;

    for ( int i = 0 ; i < n ; i++) {
        cin >> textUncoded >> textCoded;
        //printMap(translateCharacters(invert(countOccurrences(textCoded)),invert(countOccurrences(textUncoded))));
        textFinal = translateText(textCoded, translateCharacters(invert(countOccurrences(textCoded)), invert(countOccurrences(textUncoded))));
        cout << textFinal << "\n\n";
    }
    return 0;
}