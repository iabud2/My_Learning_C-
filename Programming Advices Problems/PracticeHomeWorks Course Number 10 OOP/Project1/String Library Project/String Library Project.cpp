#include <iostream>
#include "clsString.h"
#include <vector>
using namespace std;


int main()

{
    clsString String1;
    clsString String2("mohammed abu Hadhoud");
    clsString String3("Alaa Ahmed Mohammed");
    String1.Value = "Ali Ahmed";

    cout << "String1 = " << String1.Value << endl;
    cout << "String2 = " << String2.Value << endl <<endl;


    cout << "Number of words: " << String1.CountWords() << endl;

    cout << "Number of words: " << String1.CountWords("Fadi ahmed rateb omer") << endl;

    cout << "Number of words: " <<
        clsString::CountWords("Mohammed Saqer Abu-Hadhoud") << endl << endl;

    cout << "String Length is : " << String2.Length() << endl;
    cout << "String Length is : " << clsString::Length("Ahmed Mohammed Khaled") << endl << endl;
    

    //Switch Lower/Upper Case Functions :
    String2.Convert_FirstLetter_To_Upper_Case();
    cout << "String After Convert First Letter in Each Word to capital : " << String2.Value << endl;
    cout << "String After Convert First Letter in Each Word to capital : " << clsString::Convert_FirstLetter_To_Upper_Case("ahmed khaled ali") << endl<<endl;

    String2.Convert_FirstLetter_To_Lower_Case();
    cout << "String After Convert First Letter in Each Word To Lower : " << String2.Value << endl;
    cout << "String After Convert First Letter in Each Word To Lower : " << clsString::Convert_FirstLetter_To_Lower_Case("Ahmed Khaled Ali") << endl << endl;
    

    String2.Upper_String();
    cout << "String After Using 'Upper_String Function' : " << String2.Value << endl;
    cout << "String After Using 'Upper_String' function without object : " << clsString::Upper_String("Mohammed Khaled") << endl << endl;

    String2.Lower_String();
    cout << "String After Using 'Lower_String Function' : " << String2.Value<< endl;
    cout << "String After Using 'Lower_String' function without object : " << clsString::Lower_String("Mohammed Khaled") << endl << endl;

    String2.Invert_All_Letters_Case();
    cout << "String After Using 'Invert All Letters Case' :" << String2.Value << endl;
    cout << "String After Using 'Invert All Letters Case' without Object :" << clsString::Invert_All_Letters_Case("aBDULLAH") << endl << endl;

    cout << "Capital Letters Count : " << String2.Count_Capital_Letters() << endl;
    cout << "Capital Letters Count function Without Using Object : " << clsString::Count_Capital_Letters("AHMED") << endl << endl;

    cout << "Small Letters Count : " << String2.Count_Small_Letters() << endl;
    cout << "Small Letters Count function Without Using Object : " << clsString::Count_Small_Letters("Ahmed") << endl << endl;
    
    cout << "Specific Letter Count (A) :" << String2.CountSpecificLetter('a', false) << endl << endl;
    
    //Number Of Vowel Letters :
   
    cout << "Vowel Letters Count In String : " << String2.Count_Vowel() << endl;
    cout << "Vowel Letters Count in String Without Object :" << clsString::Count_Vowel("Ali Younis") << endl << endl;
    
    //----------------------------------
    //Split Function
    vector<string> vString4;
    vString4 = String3.Split(" ");
    cout << "\nTokens : " << vString4.size() << endl;
    for (string& word : vString4)
    {
        cout << word << " ";
    }cout << endl << endl;
   //-----------------------------------
    //Trim Functions :
    String2.Value = "       mohammed abu Hadhoud";
    String2.Trim_Left();
    cout << "String After Trim Left : " << String2.Value << endl;
    String2.Value = "mohammed abu Hadhoud       ";
    String2.Trim_Right();
    cout << "String After Trim Right : " << String2.Value << endl;
    String2.Value = "     mohammed abu Hadhoud     ";
    String2.Trim();
    cout << "String After Trim : " << String2.Value << endl;
    cout << "Trim Function Without Object : " << clsString::Trim("Ahmed Love His Cat") << endl << endl;



    //Join Functions:
    vector <string> vString2 = {"Ahmed", "Love", "His", "Cat"};
    string String5 = clsString::Join_String(vString2, " ");
    cout << "String After Using Join Function By Using Vecor : " << String5 << endl;
    string arr1[] = {"Khaled", "Love", "His", "Dog"};
    string String6 = clsString::Join_String(arr1, 4, " ");
    cout << "String After Using Join Function By Using Array : " << String6 << endl << endl;


    //Reverse String Functions:
    String2.Reverse_String();
    cout << "Object Ater Reverse : " << String2.Value << endl;
    cout << "String After Reverse : " << clsString::Reverse_String("Ahmed Mohammed") << endl << endl;
    
    //Replace String Functions:
    String2.Value = "Mohammed Abu-Hadhoud";
    String2.Replace_Word_in_String("mohammed", "Khaled", false);
    cout << "Object After Replace : " << String2.Value << endl;
    string S10 = "Ahmed Work in Market";
    cout << "String After Replace : " << clsString::Replace_Word_in_String(S10, "Market", "Station", true) << endl << endl;

    //Remove RemovePunctuations Functions:
    S10 = "@#$Ahmed Work in Market#@!";
    String2.Value = "_)(*Mohammed Abu-Hadhoud$#@!";
    String2.RemovePunctuations();
    cout << "Object After Remove Punc Function :" << String2.Value << endl;
    cout << "String After Remove Punc Function :" << clsString::RemovePunctuations(S10) << endl << endl;
    
    cout << "^_^" << endl;
    
    system("pause>0");
    return 0;
};
