// 

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main(int argc, char** argv)
{

	ifstream fileone("text1.txt");
	ifstream filetwo("text2.txt");
	ofstream filer("text3.txt");
	string s;

	while (fileone || filetwo)
	{
		if (fileone >> s)
			filer << s << " " << endl;
		if (filetwo >> s)
			filer << s << " " << endl;
	}
	return 0;
}