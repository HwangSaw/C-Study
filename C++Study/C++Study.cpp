// C++Study.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include<iostream>
#include<cstring>
#include<string>
/*
int MyStringCompare(char *firstString, char* secondString)
{
int i = 0;

//첫번째 문자열을 기준으로 문자열 끝까지 반복
while (firstString[i] != NULL)
{
if (secondString[i] == NULL)
return 1;

if (firstString[i] > secondString[i]) //첫번째가 클때
return 1;
else if (firstString[i] < secondString[i]) //두번째가 클때
return -1;

i++;
}

//뒤에문자열이 더 길고 클경우
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

for (int i = strinLen-1; i >= 0; i--) //문자열뒤에서 앞으로 0번째까지 반복
{
if (inputString[i] == ' ') //스페이스면 거기서부터 뒤로 반복문돌기
{
for (int j = i + 1; inputString[j] != NULL || inputString[j] != ' '; j++)
{
if (strinLen <= destStringCurIndex)
break;

destString[destStringCurIndex] = inputString[j]; // 오류나는곳!
destStringCurIndex++;
}
if (strinLen > destStringCurIndex)
{
destString[destStringCurIndex] = ' '; //마지막 스트링에 ' ' 입력
destStringCurIndex++; //
}

}
}

return destString; //할당한 것이므로 받아서 해제할것
}

void main()
{
char* helloString = "a bc"; // 길이 5
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
			//공백 바로앞부터 글자 수 카운트
			for (int j = i + 1; string[j] != ' ' && string[j] != '\0'; j++)
				stringCount++;

			int spaceNum = (spaceCount) * 2; // 내앞에 20이 오니깐 2칸뒤로 밀면된다 3칸아님! 

			//글자수 만큼 뒤에서 부터 포문 돌면서 두칸씩 뒤로밀기
			for (int j = stringCount; j >0; j--)
			{
				//현재i 는 공백이므로 +1해서 글자인덱스 
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
