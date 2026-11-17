#include <iostream>
#include <cstring>
#include <print>
#include <cstdio>

char *caesar_cipher(const char **input, int shift)
{
    int input_size = std::strlen(*input);
    char *payload = new char[input_size + 1];
    for (int i = 0; i < input_size; i++)
    {
        char new_ch;
        char ch = (*input)[i];
        if (ch >= 'A' && ch <= 'Z')
        {
            int charcode = ch - 'A';
            charcode += shift;
            charcode = charcode % 26;
            new_ch = (char)(charcode + 'A');
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            int charcode = ch - 'a';
            charcode += shift;
            charcode = charcode % 26;
            new_ch = (char)(charcode + 'a');
        }
        else
        {
            new_ch = (char)ch;
        }
        payload[i] = new_ch;
    }

    payload[input_size] = '\0';

    return payload;
}

int main()
{
    std::print("enter shifted payload: ");
    std::string input;
    char ch;
    while (std::cin.get(ch))
    {
        if (ch == '\n')
        {
            break;
        }
        input += ch;
    }

    const char *str_ref = input.c_str();

    for (int i = 0; i < 26; i++)
    {
        char *result = caesar_cipher(&str_ref, i);
        std::print("shift {0:>2}: {1}\n", i, result);
        delete[] result;
    }

    return 0;
}