//By Guo Wei
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char line[30000];
bool IsLetter(char c)
{
	return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}
int main()
{
	cin.getline(line,29000);
	
	int longStart,shortStart;
	int maxLen = 0,minLen = 1<< 30;
	int lastWordStart;
	bool wordMeet = false;
	int len = strlen(line);
	for(int i = 0;i <= len; ++i) {
		if( IsLetter(line[i])) {
			if( !wordMeet) {
				wordMeet = true;
				lastWordStart = i;
			}
		}
		else {
			if( wordMeet ) {
				wordMeet = false;
				int wordLen = i - lastWordStart;
				if( wordLen > maxLen ) {
					maxLen = wordLen;
					longStart = lastWordStart;
				}
				if( wordLen < minLen ) {
					minLen = wordLen;
					shortStart = lastWordStart;
				}
			}
		}
	}
	for(int i = longStart; IsLetter(line[i]); ++ i)
		cout << line[i];
	cout << endl;
	for(int i = shortStart; IsLetter(line[i]); ++ i)
		cout << line[i];
	return 0;
}

