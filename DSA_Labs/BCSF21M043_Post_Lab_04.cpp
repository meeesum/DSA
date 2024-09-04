#include <iostream>
#include <string>
using namespace std;
string sortString(string s1);
bool isVowel(char ch);
string sortVowels(string s1);
int main()
{
    string s1 = "BCSfMPUCIt";
    string s2 = sortString(s1);
    cout << s2<<endl;

    string s3 = "programming";
    string s4 = sortVowels(s3);
    cout << s4<<endl;
    return 0;
}
string sortString(string s1)
{
    int len = s1.length();
    for (int i = 0; i < len; i++){
        for (int j = i + 1; j < len; j++){
            if (s1[i] > s1[j]){
                char temp = s1[i];
                s1[i] = s1[j];
                s1[j] = temp;
            }
        }
    }
    return s1;
}
bool isVowel(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
    {
        return true;
    }
    else
    {
        return false;
    }
}
string sortVowels(string s1)
{
    int len = s1.length();
    string vowels = "";
    for (int i = 0; i < len; i++)
    {
        if (isVowel(s1[i]))
        {
            vowels += s1[i];
        }
    }
    vowels = sortString(vowels);
    int vowelIndex = 0;
    for (int i = 0; i < len; i++)
    {
        if (isVowel(s1[i]))
        {
            s1[i] = vowels[vowelIndex++];
        }
    }

    return s1;
}