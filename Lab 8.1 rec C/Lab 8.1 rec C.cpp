#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Count(char* str, int i, int k)
{
	if (strlen(str) < 5)
		return -1;

	if (i < strlen(str)) {
		if (str[i] == 'B' || str[i] == 'A' || str[i] == 'S' || str[i] == 'I' || str[i] == 'C') {
			k++;
		}
		return Count(str, i + 1, k);
	}

	return k;
}

char* Change(char* dest, const char* str, char* t, int i)
{
	if (i < strlen(str) != 0)
	{
		if (strncmp(str + i, "BASIC", 5) == 0)
		{
			strcat(t, "DELPHI");
			return Change(dest, str, t += 6, i += 5);
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
			return Change(dest, str, t, i);
		}
	}
	else
	{
		*t++ = str[i++];
		*t++ = str[i++];
		*t = '\0';
		return dest;
	}
}
int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "Number of chars BASIC:    " << Count(str, 0, 0) << endl;
	char* dest1 = new char[151];
	dest1[0] = '\0';
	char* dest2;
	dest2 = Change(dest1, str, dest1, 0);
	cout << "Modified string (param) : " << dest1 << endl;
	cout << "Modified string (result): " << dest2 << endl;
	return 0;
}