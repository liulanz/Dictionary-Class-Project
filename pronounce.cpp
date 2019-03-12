/*
 Liu Lan Zheng
 CSCI 135
 Project 2
 Instructor: Genady Maryash
 This program allows user enters a word, and it will
	- Lets the user input a word (let’s call the input word W).
	-If the word is not found in the dictionary, print “Not found”. Otherwise, report:
	
		Pronunciation : the pronunciation of the word W (as given in the dictionary),
		Identical : other words from the dictionary with the same pronunciation as W,
		Replace phoneme : words that can be obtained from W by replacing one phoneme.
		Add phoneme : words that can be obtained from W by adding one phoneme,
		Remove phoneme : words that can be obtained from W by removing one phoneme
*/
 
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void splitOnSpace(string s, string& before, string& after);
void convert(string &s);
string pronunciation(string str);
string identical(string pron, string str);
string addPhoneme(string pronunciation, string str);
string replacePhoneme(string pron, string str);
string remove(string pron, string str);

int coutSpace(string str);
int main()
{	
	string str,afterSpace, beforeSpace;
	cout<<"Enter a word	:";
	cin >>str;    //ser input a word (letâ€™s call the input word W).
	convert(str);
	string pron = pronunciation(str);
	cout<<"Pronunciation	:"<< pron <<endl;
	string iden = identical(pron, str);
	cout<<"Identical	:"<<iden<<endl;
	string replace = replacePhoneme(pron, str);
	cout<<"Replace phoneme	:"<<replace<<endl;
	string addP = addPhoneme(pron, str);
	cout<<"Add phoneme	:"<<addP<<endl;
	string remv = remove(pron, str);
	cout<<"Remove phoneme	:"<<remv<<endl;
}	
string pronunciation(string str)//the pronunciation of the word W (as given in the dictionary),
{
	string line, eachLine;
	int index = 0;
	ifstream file("cmudict.0.7a"); //read text file
	string beforeSpace;
	string pronunciation, pron;
	string afterSpace, same_pronunciation;
	string identical = "";
	if(!file.is_open())  //if file can't be opened
	{
		cerr<<"error"<<endl;
	}
	else
	{
		while(!file.eof())
		{
			getline(file, line);
			eachLine= line; //put every line from the text file into eachLine
			splitOnSpace(eachLine, beforeSpace, afterSpace);
			if(beforeSpace == str)
			{
				break;
			}
			
		}
		if(beforeSpace != str)   //if str is not found, print "Not found"
			cout<<"Not found"<<endl;
		else
		{
			return afterSpace;
		}
	}
}

string identical(string pron, string str)// other words from the dictionary with the same pronunciation as W,
{
	ifstream file("cmudict.0.7a"); //read text file
	string beforeSpace, line, eachLine, afterSpace;
	string identical = "";
	if(!file.is_open())  //if file can't be opened
	{
		cerr<<"error"<<endl;
	}
	else
	{
		while(!file.eof())
		{
			getline(file, line);
			eachLine= line; //put every line from the text file into eachLine
			splitOnSpace(eachLine, beforeSpace, afterSpace);
			
			if(afterSpace == pron && beforeSpace != str)
			{		
	
				identical = identical + " " +beforeSpace;

			}
		}
			return identical;
	}	
}
	
string addPhoneme(string pronunciation, string str) // words that can be obtained from W by adding one phoneme
{
	ifstream file("cmudict.0.7a"); //read text file
	string beforeSpace, line, eachLine, afterSpace, bSpace, aSpace, bPron, aPron;
	string add = "";
	int difference = 0;
	int number= 0;
	int i, k;
	int length = pronunciation.length();
	if(!file.is_open())  //if file can't be opened
	{
		cerr<<"error"<<endl;
	}
	else
	{
                 
		while(!file.eof())
		{
			getline(file, line);
			eachLine= line; //put every line from the text file into eachLine	
			splitOnSpace(eachLine, beforeSpace, afterSpace);
			aSpace = afterSpace;
			aPron = pronunciation;
			
			while(number <10)
			{
            	splitOnSpace(aSpace, bSpace, aSpace);
				splitOnSpace(aPron, bPron, aPron);	
				if(bSpace != bPron)
				{
					difference++;
					splitOnSpace(aSpace, bSpace, aSpace);
					if(bSpace != bPron)
						difference++;
					
				}
				if(difference >1)
					break;
				else
					number++;
				
			}
			number = 0;
			i = coutSpace(afterSpace);//check for number of spaces
			k =  coutSpace(pronunciation);//check for number of spaces	
			if(difference == 1 && i>k && beforeSpace.substr(beforeSpace.length()-1) != ")")
			{	
								
				add = add + " "+ beforeSpace;
				
			}
				difference = 0;
			
		
		}
			
		return add;
	}
}

string replacePhoneme(string pron, string str)//find strings made up of exactly the same sequence of phonemes with just one of them different
{
	ifstream file("cmudict.0.7a"); //read text file
	string beforeSpace, line, eachLine, afterSpace, bSpace, aSpace, bPron, aPron;
	string replace = "";
	int length = pron.length();
	int difference = 0;
	int number= 0;
	int i, k;
	if(!file.is_open())  //if file can't be opened
	{
		cerr<<"error"<<endl;
	}
	else
	{
		while(!file.eof())
		{
			getline(file, line);
			eachLine= line; //put every line from the text file into eachLine	
			splitOnSpace(eachLine, beforeSpace, afterSpace);
			aSpace = afterSpace;
			aPron = pron;
			
			while(number <10)
			{
            	splitOnSpace(aSpace, bSpace, aSpace);
				splitOnSpace(aPron, bPron, aPron);	
				if(bSpace != bPron)
					difference++;	
				if(difference >1)
					break;
				else
					number++;
				
			}
			number = 0;
			i = coutSpace(afterSpace);//check for number of spaces
			k =  coutSpace(pron);//check for number of spaces	
			if(difference == 1 && i ==k && beforeSpace.substr(beforeSpace.length()-1) != ")")
			{	
								
				replace = replace + " "+ beforeSpace;
				
			}
				difference = 0;
			
		
		}
			
		return replace;
	}
}

string remove(string pronunciation, string str) // words that can be obtained from W by removing one phoneme
{
	ifstream file("cmudict.0.7a"); //read text file
	string beforeSpace, line, eachLine, afterSpace, bSpace, aSpace, bPron, aPron;
	string remv  = "";
	int difference = 0;
	int number= 0;
	int i, k;
	int length = pronunciation.length();
	if(!file.is_open())  //if file can't be opened
	{
		cerr<<"error"<<endl;
	}
	else
	{
                 
		while(!file.eof())
		{
			getline(file, line);
			eachLine= line; //put every line from the text file into eachLine	
			splitOnSpace(eachLine, beforeSpace, afterSpace);
			aSpace = afterSpace;
			aPron = pronunciation;
			
			while(number <10)
			{
            	splitOnSpace(aSpace, bSpace, aSpace);
				splitOnSpace(aPron, bPron, aPron);	
				if(bSpace != bPron)
				{
					difference++;
					splitOnSpace(aPron, bPron, aPron);
					if(bSpace != bPron)
						difference++;
					
				}
				if(difference >1)
					break;
				else
					number++;
				
			}
			number = 0;
			i = coutSpace(afterSpace);//check for number of spaces
			k =  coutSpace(pronunciation);//check for number of spaces	
			if(difference == 1 && i<k && beforeSpace.substr(beforeSpace.length()-1) != ")")
			{	
								
				remv = remv + " "+ beforeSpace;
				
			}
				difference = 0;
			
		
		}
			
		return remv;
	}
}

int coutSpace(string str)
{	
	int space = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if(str.substr(i, 1) == " ")
			space++;
	}
	return space;
}

void splitOnSpace(string s, string& before, string& after)  //dividing a string into words
{
	before = "";
	after="";
	int i = 0;
	while(i < s.size() && not isspace(s[i]))
	{
		before += s[i];
		i++;
	}
	i++;
	while( i < s.size())
	{
		after += s[i];
		i++;
	}
}

void convert(string& s)  //capitalize the string
{
	for(int i =0; i<s.length(); i++)
	{
		s[i] = toupper(s[i]);
	}
}