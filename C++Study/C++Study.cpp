// C++Study.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include<iostream>
#include<cstring>
#include<string>
/*
int MyStringCompare(char *firstString, char* secondString)
{
int i = 0;

//ù��° ���ڿ��� �������� ���ڿ� ������ �ݺ�
while (firstString[i] != NULL)
{
if (secondString[i] == NULL)
return 1;

if (firstString[i] > secondString[i]) //ù��°�� Ŭ��
return 1;
else if (firstString[i] < secondString[i]) //�ι�°�� Ŭ��
return -1;

i++;
}

//�ڿ����ڿ��� �� ��� Ŭ���
if (secondString[i] != NULL)
return -1;

return 0;
}

void main()
{
char* firstString = new char[100];
char* secondString = new char[100];

while (1)
{
std::cin >> firstString;
std::cin >> secondString;

int myResult = MyStringCompare(firstString, secondString);
int msResult = strcmp(firstString, secondString);

std::cout << "myResult" << myResult << std::endl;
std::cout << "msResult" << msResult << std::endl;
}

getchar();
}
*/



/*

char GetUniqueString(char* inputString)
{

int strinCount[26] = { 0, };

int i = 0;
while (inputString[i] != NULL)
{
int index = inputString[i] - 'a';
strinCount[index]++;
i++;
}

i = 0;
while (inputString[i] != NULL)
{
int index = inputString[i] - 'a';
if (strinCount[index] == 1)
{
return (char)(index + 'a');
}
i++;
}
return NULL;
}

void main()
{
char* inputString = "ab";
std::cout << GetUniqueString(inputString);
getchar();

}
*/

/*

std::string GetReverseString(char* inputString)
{
//do or do not. there is no try .
int strinLen = strlen(inputString);

std::string destString;

int destStringCurIndex = 0;

for (int i = strinLen-1; i >= 0; i--) //���ڿ��ڿ��� ������ 0��°���� �ݺ�
{
if (inputString[i] == ' ') //�����̽��� �ű⼭���� �ڷ� �ݺ�������
{
for (int j = i + 1; inputString[j] != NULL || inputString[j] != ' '; j++)
{
if (strinLen <= destStringCurIndex)
break;

destString[destStringCurIndex] = inputString[j]; // �������°�!
destStringCurIndex++;
}
if (strinLen > destStringCurIndex)
{
destString[destStringCurIndex] = ' '; //������ ��Ʈ���� ' ' �Է�
destStringCurIndex++; //
}

}
}

return destString; //�Ҵ��� ���̹Ƿ� �޾Ƽ� �����Ұ�
}

void main()
{
char* helloString = "a bc"; // ���� 5
std::cout << strlen(helloString);

std::cout << GetReverseString(helloString).c_str();

getchar();
}
*/
/*
#define OUT
#define INOUT

void  _SwapWord(INOUT std::string& str, int startIndex, int endIndex)
{
	for (int i = startIndex, j = endIndex - 1; i < j; ++i, --j)
	{
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}

std::string ReverseString(std::string str)
{
	_SwapWord(str, 0, str.length());

	int prevCursor = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ' || (i == str.length() - 1))
		{
			//if(i == str.length() - 1)
			//_SwapWord(str, prevCursor, i+1);
			//else 
			_SwapWord(str, prevCursor, i);

			prevCursor = i + 1;
		}
	}



	return str;
}

void main()
{
	std::cout << ReverseString("hello world").c_str();
	getchar();

}
*/

/*
bool IsIncludeString(char* includeString,int includeLen, char* sourceString, int sourceLen)
{
char* includeTempString;
char* sourceTempString;

if (includeLen > sourceLen)
{
int temp = includeLen;
includeLen = sourceLen;
sourceLen = temp;

includeTempString = new char[includeLen+1];
sourceTempString = new char[sourceLen+1];

strcpy(includeString, sourceString);
strcpy(sourceTempString, includeString);
}
else
{
includeTempString = new char[includeLen + 1];
sourceTempString = new char[sourceLen + 1];

strcpy(includeTempString, includeString);
strcpy(sourceTempString, sourceString);
}



int includeCount = 0;
for (int i = 0; i <= sourceLen; i++)
{
if (sourceString[i] == includeString[0])
{
for (int j = 0; j <= includeLen; j++)
{
if (includeString[i+j] != sourceString[j])
{
break;
}
return true;
}
}
}

return false;
}

int main()
{
char* firstString = "astring";
char* secondString = "secondstring";
std::cout<<IsIncludeString(firstString, strlen(firstString), secondString, strlen(secondString));

getchar();
return 0;
}
*/

void ChangSpaceStringTo2percentString(char* string, int len)
{
	int spaceCount = 0;
	for (int i = 0; i < len; i++)
	{
		if (string[i] == ' ')
			spaceCount++;
	}
	for (int i = len; i >= 0; i--)
	{
		if (string[i] == ' ')
		{

			int stringCount = 0;
			//���� �ٷξպ��� ���� �� ī��Ʈ
			for (int j = i + 1; string[j] != ' ' && string[j] != '\0'; j++)
				stringCount++;

			int spaceNum = (spaceCount) * 2; // ���տ� 20�� ���ϱ� 2ĭ�ڷ� �и�ȴ� 3ĭ�ƴ�! 

			//���ڼ� ��ŭ �ڿ��� ���� ���� ���鼭 ��ĭ�� �ڷιб�
			for (int j = stringCount; j >0; j--)
			{
				//����i �� �����̹Ƿ� +1�ؼ� �����ε��� 
				string[i + j + spaceNum] = string[i + j ];
			}

			spaceCount--;
			spaceNum = (spaceCount) * 2;

			string[i + spaceNum] = '%';
			string[i + spaceNum + 1] = '2';
			string[i + spaceNum + 2] = '0';

			if (i == 0)
			{
				string[i + spaceNum + 3] = '\0';
			}

		}
	}
}

int main()
{
	char string[100] = { '\0', };
	strcpy(string, "a b c c");
	ChangSpaceStringTo2percentString(string, strlen(string));
	std::cout << string;
	getchar();
	return 0;
}
