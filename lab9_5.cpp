// Замена пробельных символов

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream fin("text1.txt");

    ofstream fout("text2.txt");

    string str;

    while (getline(fin, str))
    {
        while (str[0] == ' ' || str[0] == '\t')
        {
            str = str.substr(1, str.length()); // возвращает подстроку данной строки начиная с символа с индексом pos и до конца строки.
        }
        for (int i = 0; i < str.size(); i++) // пробегаем по строке
        {
            if (str[i] == ' ') // если встретили пробел переходим к while
            {
                while (str[i + 1] == ' ') // пока следующий за первым пробелом - также пробел, удаляем его.
                {
                    str.erase(i + 1, 1);
                }
                while (str[i + 1] == '\t') // пока следующий за первым пробелом - также пробел, удаляем его.
                {
                    str.erase(i + 1, 1);
                }
            }
            else if (str[i] == '\t')
            {
                str[i] = ' ';
                while (str[i + 1] == '\t')
                {
                    str.erase(i + 1, 1);
                }
            }
        }
        fout << str << endl;
    }

    return 0;
}