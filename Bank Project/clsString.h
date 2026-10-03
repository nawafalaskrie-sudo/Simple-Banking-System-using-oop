#pragma once

#include <iostream>
#include<vector>
using namespace std;

class clsString
{

private:
    string _Value;

public:

    enum enWhatToCount { SmallLetter = 0, CapitalLetter = 0, All = 3 };

    clsString()
    {

        _Value = "";
    }

    clsString(string Value)
    {

        _Value = Value;
    }


    void SetValue(string Value) {
        _Value = Value;
    }

    string GetValue() {
        return _Value;
    }

    __declspec(property(get = GetValue, put = SetValue)) string Value;

    static short Length(string S1)
    {
        return S1.length();
    };

    short Length()
    {
        return _Value.length();
    };


    static short CountWords(string S1)
    {

        string delim = " "; // delimiter  
        short Counter = 0;
        short pos = 0;
        string sWord; // define a string variable  

        // use find() function to get the position of the delimiters  
        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word   
            if (sWord != "")
            {
                Counter++;
            }

            //erase() until positon and move to next word.
            S1.erase(0, pos + delim.length());
        }

        if (S1 != "")
        {
            Counter++; // it counts the last word of the string.
        }

        return Counter;

    }

    short CountWords()
    {
        return CountWords(_Value);
    };


    static void PrintFirstLeterFromString(string name) {

        bool isFirstLater = true;

        for (short i = 0; i < name.length(); i++) {
            if (name[i] != ' ' && isFirstLater) {

                cout << name[i] << endl;
            }
            isFirstLater = name[i] == ' ' ? true : false;
        }
    }


    void PrintFirstLeterFromString() {
        PrintFirstLeterFromString(_Value);
    }



    static string UperFirstLeterOfEachWord(string name) {
        bool isFirstLater = true;

        for (short i = 0; i < name.length(); i++) {
            if (name[i] != ' ' && isFirstLater) {

                name[i] = toupper(name[i]);
            }
            isFirstLater = name[i] == ' ' ? true : false;
        }
        return name;
    }

    void UperFirstLeterOfEachWord() {
        _Value = UperFirstLeterOfEachWord(_Value);
    }


    static string LowerFirstLeterOfEachWord(string name) {
        bool isFirstLater = true;

        for (short i = 0; i < name.length(); i++) {
            if (name[i] != ' ' && isFirstLater) {

                name[i] = tolower(name[i]);
            }
            isFirstLater = name[i] == ' ' ? true : false;
        }
        return name;
    }

    void LowerFirstLeterOfEachWord() {
        _Value = LowerFirstLeterOfEachWord(_Value);
    }

    static string UpperAllString(string name) {


        for (short i = 0; i < name.length(); i++) {
            if (name[i] != ' ') {

                name[i] = toupper(name[i]);
            }

        }
        return name;
    }

    void UpperAllString() {
        _Value = UpperAllString(_Value);
    }
    static string LowerAllString(string name) {


        for (short i = 0; i < name.length(); i++) {
            if (name[i] != ' ') {

                name[i] = toupper(name[i]);
            }

        }
        return name;
    }

    void LowerAllString() {
        _Value = LowerAllString(_Value);
    }

    static  char invertLetterCase(char Char) {
        return isupper(Char) ? tolower(Char) : toupper(Char);
    }

    static  string invertLetterCase(string ST) {
        for (int i = 0; i < ST.length(); i++)
            ST[i] = invertLetterCase(ST[i]);
        return ST;
    }

    void invertLetterCase() {
        _Value = invertLetterCase(_Value);
    }


    static short CountLetter(string St, enWhatToCount WhatToCaount = enWhatToCount::All) {
        if (WhatToCaount == enWhatToCount::All) {
            return St.length();

        }
        short count = 0;
        for (short i = 0; i < St.length(); i++) {
            if (WhatToCaount == enWhatToCount::CapitalLetter && isupper(St[i]))
                count++;
            else if (WhatToCaount == enWhatToCount::SmallLetter && islower(St[i]))
                count++;

        }
        return count;
    }

    short CountLetter() {
        return   CountLetter(_Value);
    }

    static  short CountCapitalLetter(string ST) {
        short Count = 0;
        for (short i = 0; i < ST.length(); i++)
        {
            if (isupper(ST[i]))
                Count++;
        }
        return Count;
    }

    short CountCapitalLetter() {
        return   CountCapitalLetter(_Value);
    }

    static  short CountSmallLetter(string ST) {
        short Count = 0;
        for (short i = 0; i < ST.length(); i++)
        {
            if (islower(ST[i]))
                Count++;
        }
        return Count;
    }

    short CountSmallLetter() {
        return CountSmallLetter(_Value);
    }



    static short CountSpecificLetter(string st, char Letter, bool MatchCase = true) {
        short count = 0;
        for (short i = 0; i < st.length(); i++) {
            if (MatchCase) {
                if (Letter == st[i])
                    count++;
            }
            else if (toupper(Letter) == toupper(st[i]))
                count++;
        }

        return count;
    }




    short CountSpecificLetter(char c, bool MatchCase = true) {
        return CountSpecificLetter(_Value, c, MatchCase);
    }

    static bool isVowel(char letter) {
        letter = tolower(letter);

        return((letter == 'a') || (letter == 'e') || (letter == 'u') || (letter == 'o') || (letter == 'i'));
    }

    static short CountVowelLetter(string st) {
        short count = 0;
        for (short i = 0; i < st.length(); i++)
            if (isVowel(st[i]))
                count++;
        return count;
    }

    short CountVowelLetter() {
        return  CountVowelLetter(_Value);
    }

    static void PrintVowelLetter(string st) {
        cout << "the vowel letter = ";

        for (short i = 0; i < st.length(); i++)
            if (isVowel(st[i]))
                cout << st[i] << "  ";
    }

    void PrintVowelLetter() {
        PrintVowelLetter(_Value);
    }

    static void PrintEachWordInString(string S1) {
        string deline = " ";
        cout << "yor string word are : \n";
        short pos = 0;
        string sWord;
        while ((pos = S1.find(deline)) != std::string::npos) {
            sWord = S1.substr(0, pos);
            if (sWord != "") {
                cout << sWord << endl;
            }
            S1.erase(0, pos + deline.length());
        }
        if (S1 != "")
            cout << S1 << endl;

    }

    void PrintEachWordInString() {
        PrintEachWordInString(_Value);
    }

    static short CountEachWordInString(string S1) {
        short count = 0;
        string deline = " ";
        cout << "yor string word are : \n";
        short pos = 0;
        string sWord;
        while ((pos = S1.find(deline)) != std::string::npos) {
            sWord = S1.substr(0, pos);
            if (sWord != "") {
                count++;
            }
            S1.erase(0, pos + deline.length());
        }
        if (S1 != "")
            count++;
        return count;
    }

    short CountEachWordInString() {
        return CountEachWordInString(_Value);

    }

    static vector<string> Split(string S1, string Delim)
    {

        vector<string> vString;

        short pos = 0;
        string sWord; // define a string variable  

        // use find() function to get the position of the delimiters  
        while ((pos = S1.find(Delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word   
            if (sWord != "")
            {
                vString.push_back(sWord);
            }

            S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
        }

        if (S1 != "")
        {
            vString.push_back(S1); // it adds last word of the string.
        }

        return vString;

    }

    vector<string> Split(string Delim)
    {
        return Split(_Value, Delim);
    }

    static string TrimLeft(string s1) {
        for (short i = 0; i < s1.length(); i++) {
            if (s1[i] != ' ')
                return s1.substr(i, s1.length());
        }
        return "";
    }
    void TrimLeft() {
        _Value = TrimLeft(_Value);
    }

    static string TrimRight(string s1) {
        for (short i = s1.length(); i >= 0; i--) {
            if (s1[i] != ' ')
                return s1.substr(0, i);
        }
        return "";
    }



    void TrimRight() {
        _Value = TrimRight(_Value);
    }

    static string Trim(string s1) {
        s1 = TrimLeft(s1);
        s1 = TrimRight(s1);
    }

    void Trim() {
        _Value = TrimLeft(_Value);
        _Value = TrimRight(_Value);
    }

    static string  JoinString(vector<string> vString, string deline) {
        string S1 = "";
        for (string& line : vString) {
            S1 += line + deline;
        }
        return S1.substr(0, S1.length() - deline.length());
    }


    static string  JoinString(string  arrString[], short size, string deline) {
        string S1 = "";
        for (short i = 0; i < size; i++)
            S1 += arrString[i] + deline;
        return S1.substr(0, S1.length() - deline.length());
    }

    static string ReverseWordsInString(string s1) {
        vector<string> veString;
        veString = Split(s1, " ");
        vector<string>::iterator iter = veString.end();
        string s2 = "";
        while (iter != veString.begin()) {
            iter--;
            s2 += *iter + " ";
        }
        s2 = s2.substr(0, s2.length() - 1);
        return s2;
    }

    void ReverseWordsInString() {
        _Value = ReverseWordsInString(_Value);
    }

    static string ReplaceWord(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
    {

        vector<string> vString = Split(S1, " ");

        for (string& s : vString)
        {

            if (MatchCase)
            {
                if (s == StringToReplace)
                {
                    s = sRepalceTo;
                }

            }
            else
            {
                if (LowerAllString(s) == LowerAllString(StringToReplace))
                {
                    s = sRepalceTo;
                }

            }

        }

        return JoinString(vString, " ");
    }

    string ReplaceWord(string StringToReplace, string sRepalceTo)
    {
        return ReplaceWord(_Value, StringToReplace, sRepalceTo);
    }

    static string RemovePunctuations(string S1)
    {

        string S2 = "";

        for (short i = 0; i < S1.length(); i++)
        {
            if (!ispunct(S1[i]))
            {
                S2 += S1[i];
            }
        }

        return S2;

    }

    void RemovePunctuations()
    {
        _Value = RemovePunctuations(_Value);
    }





};




