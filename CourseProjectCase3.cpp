#include <iostream>
using namespace std;

string keyCycle(string str, string key)
{
    int x = str.size();

    for (int i = 0; ; i++)
    {
        if (x == i)
            i = 0;
        if (key.size() == str.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}

string encryptText(string str, string key)
{
    string encryptedText;
    for (int i = 0; i < str.size(); i++)
    {
        int x = (str[i] + key[i]) % 26;
        x += 'A';
        encryptedText.push_back(x);
    }
    return encryptedText;
}

string decryptText(string str, string key)
{
    string decryptedText;

    for (int i = 0; i < str.size(); i++)
    {
        int x = (str[i] - key[i] + 26) % 26;
        x += 'A';
        decryptedText.push_back(x);
    }
    return decryptedText;
}

int main()
{
    string str;
    string keyword;
    char cont = 'Y';
    char decision;
    string key;
    while (cont == 'Y')
    {
        cout << "Would you like to encrypt or decrypt a message? Enter E for encryption, and D for decryption. ";
        cin >> decision;

        if (decision == 'E')
        {
            cout << "Please enter your plaintext string:";
            cin >> str;

            cout << "Please enter the cipher for encryption:";
            cin >> keyword;
            key = keyCycle(str, keyword);
            ;
            cout << "Ciphertext : "
                << encryptText(str, key) << "\n";
        }
        else if (decision == 'D')
        {
            cout << "Please enter your encrypted string: ";
            cin >> str;

            cout << "Please enter the cipher for decryption: ";
            cin >> keyword;
            key = keyCycle(str, keyword);
            cout << "Decrypted Text : "
                << decryptText(str, key) << "\n";
        }
        cout << "Is there anything else you would like to encrypt or decrypt? Enter Y for yes, and N for no. ";
        cin >> cont;
    }
    return 0;
}