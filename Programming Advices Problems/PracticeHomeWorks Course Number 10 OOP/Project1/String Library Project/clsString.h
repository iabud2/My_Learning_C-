#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

class clsString
{
private:
    string _Value;

public:

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

    static short Length(string s1)
    {
        return s1.length();
    }

    short Length()
    {
        return _Value.length();
    }

    static string Convert_FirstLetter_To_Upper_Case(string Words)
    {
        bool Check_First_Letter = true;
        for (int i = 0; i < Words.length(); i++)
        {
            if (Words[i] != ' ' && Check_First_Letter == true)
            {

                Words[i] = toupper(Words[i]);
            }
            Check_First_Letter = (Words[i] == ' ' ? true : false);
        }
        return Words;
    }

    void Convert_FirstLetter_To_Upper_Case()
    {
       _Value = Convert_FirstLetter_To_Upper_Case(_Value);
    }

    static string Convert_FirstLetter_To_Lower_Case(string Words)
    {
        bool Check_First_Letter = true;
        for (int i = 0; i < Words.length(); i++)
        {
            if (Words[i] != ' ' && Check_First_Letter == true)
            {

                Words[i] = tolower(Words[i]);
            }
            Check_First_Letter = (Words[i] == ' ' ? true : false);
        }
        return Words;
    }

    void Convert_FirstLetter_To_Lower_Case()
    {
        _Value = Convert_FirstLetter_To_Lower_Case(_Value);
    }

    static string Upper_String(string Words)
    {
        for (int i = 0; i < Words.length(); i++)
        {
            Words[i] = toupper(Words[i]);
        }
        return Words;
    }

    void Upper_String()
    {
        _Value = Upper_String(_Value);
    }

    static string Lower_String(string Words)
    {
        for (int i = 0; i < Words.length(); i++)
        {
           Words[i] = tolower(Words[i]);
        }
        return Words;
    }

    void Lower_String()
    {
        _Value = Lower_String(_Value);
    }

    static char Invert_Letter_Case(char ch)
    {
        return isupper(ch) ? tolower(ch) : toupper(ch);
    }

    static string Invert_All_Letters_Case(string Words)
    {
        for (int i = 0; i < Words.length(); i++)
        {
            Words[i] = Invert_Letter_Case(Words[i]);
        }
        return Words;
    }

    void Invert_All_Letters_Case()
    {
        _Value = Invert_All_Letters_Case(_Value);
    }
    
    static int Count_Capital_Letters(string MyString)
    {
        short Counter = 0;
        for (int i = 0; i < MyString.length(); i++)
        {
            if (isupper(MyString[i]))
            {
                Counter++;
            }
        }
        return Counter;
    }

    int Count_Capital_Letters()
    {
        return Count_Capital_Letters(_Value);
    }

    static int Count_Small_Letters(string MyString)
    {
        short Counter = 0;
        for (int i = 0; i < MyString.length(); i++)
        {
            if (islower(MyString[i]))
            {
                Counter++;
            }
        }
        return Counter;
    }

    int Count_Small_Letters()
    {
       return  Count_Small_Letters(_Value);
    }

    static short CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
    {
        short Counter = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (MatchCase)
            {
                if (S1[i] == Letter)
                    Counter++;
            }
            else
            {
                if (tolower(S1[i]) == tolower(Letter))
                    Counter++;
            }
        }
        return Counter;
    }
    
    short CountSpecificLetter(char Letter, bool MatchCase = true)
    {
        return CountSpecificLetter(_Value, Letter, MatchCase);
    }

    static bool Is_Vowel(char Mychar)
    {
        Mychar = tolower(Mychar);
        return ((Mychar == 'a' || Mychar == 'u' || Mychar == 'o' || Mychar == 'e' || Mychar == 'i'));
    }

    static short Count_Vowel(string S1)
    {
        short counter = 0;
        for (int i = 0; i < S1.length(); i++)
        {
            if (Is_Vowel(S1[i]))
                counter++;
        }
        return counter;
    }

    short Count_Vowel()
    {
        return Count_Vowel(_Value);
    }

    static vector<string> Split(string ST1, string delimiter)
    {
        vector<string> MyVector;
        int counter = 0;
        short pos = 0;
        string each_Word;
        while ((pos = ST1.find(delimiter)) != std::string::npos)
        {
            each_Word = ST1.substr(0, pos);
            if (each_Word != "")
            {
                MyVector.push_back(each_Word);
            }
            ST1.erase(0, pos + delimiter.length());
        }
        if (ST1 != "")
        {
            MyVector.push_back(ST1);
        }
        return MyVector;
    }

    vector<string> Split(string delimiter)
    {
        return Split(_Value, delimiter);
    }

    static string Trim_Left(string MyString)
    {
        for (int i = 0; i < MyString.length(); i++)
        {
            if (MyString[i] != ' ')
            {
                return (MyString.substr(i, MyString.length() - i));
            }
        }
        return "";
    }

    void Trim_Left()
    {
       _Value = Trim_Left(_Value);
    }

    static string Trim_Right(string MyString)
    {
        for (short i = MyString.length() - 1; i >= 0; i--)
        {
            if (MyString[i] != ' ')
            {
                return MyString.substr(0, i + 1);
            }
        }
        return "";
    }
    
    void Trim_Right()
    {
        _Value = Trim_Right(_Value);
    }

    static string Trim(string MyString)
    {
        return (Trim_Left(Trim_Right(MyString)));
    }

    void Trim()
    {
        _Value =Trim(Value);
    }

    static string Join_String(vector <string> MyVector, string Delimiter)
    {
        string MyString;
        for (string s1 : MyVector)
        {
            MyString = MyString + s1 + Delimiter;
        }
        return MyString.substr(0, MyString.length() - Delimiter.length());
    }

    static string Join_String(string arr[], short Length,string Delimiter)
    {

        string MyString = "";
        for (int i = 0; i < Length; i++)
        {
            MyString = MyString + arr[i] + Delimiter;
        }
        return MyString.substr(0, MyString.length() - Delimiter.length());
    }

    static string Reverse_String(string MyS)
    {
        string Reversed_String = "";
        vector<string> MyVector = Split(MyS, " ");
        vector<string>::iterator i = MyVector.end();
        while (i != MyVector.begin())
        {
            --i;
            Reversed_String += *i + ' ';
        }
        Reversed_String = Reversed_String.substr(0, Reversed_String.length() - 1);
        return Reversed_String;
    }
    
    void Reverse_String()
    {
        _Value = Reverse_String(_Value);
    }

    static string Replace_Word_in_String(string S1, string Replace_it, string Replace_to, bool Match_Case)
    {
        vector<string> vS1 = Split(S1, " ");
        for (string& S : vS1)
        {
            if (Match_Case)
            {
                if (S == Replace_it)
                {
                    S = Replace_to;
                }
            }
            else
            {
                if (Upper_String(S) == Upper_String(Replace_it))
                {
                    S = Replace_to;
                }
            }
        }
        return Join_String(vS1, " ");
    }

    void Replace_Word_in_String(string Replace_it, string Replace_to, bool Match_Case = true)
    {
        _Value = Replace_Word_in_String(_Value, Replace_it, Replace_to, Match_Case);
    }

    static string RemovePunctuations(string s1)
    {
        string s2;
        for (int i = 0; i < s1.length(); i++)
        {
            if (!ispunct(s1[i]))
            {
                s2 += s1[i];
            }
        }
        return s2;
    }

    void RemovePunctuations()
    {
        _Value = RemovePunctuations(_Value);
    }

};

