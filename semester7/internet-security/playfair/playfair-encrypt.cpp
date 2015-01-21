#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <fstream>

using namespace std;

string checking(string a)
{
string temp="";
int i,j;
for(i=0;i<a.length();i++)
{
    if(a.at(i)>='A' && a.at(i)<='Z')
    {
        temp.push_back(a.at(j)+32);
    }
    else if(a.at(i)>='a' && a.at(i)<='z')
    {
        temp.push_back(a.at(i));
    }
    else if(a.at(i)>='0' && a.at(i)<='9')
    {
        temp.push_back(a.at(i));
    }
}
return temp;
}

int lent(string a)
{
    int i;
    for(i=0;i<a.length();i++)
    {
        if(a.at(i)>='0' && a.at(i)<='9')
        {
            return 1;
        }
    }
    return 0;
}

string digraph(string a)
{
    string temp="";
    int i,j;
    temp=a.at(0);
    for(i=1;i<a.length();i++)
    {
        if(a.at(i)==a.at(i-1))
        {
            temp.push_back('x');
            temp.push_back(a.at(i));
        }
        else
        {
            temp.push_back(a.at(i));
        }
    }
    if(temp.length()%2==1)
    {
        temp.push_back('x');
    }
    return temp;
}

int main()
{
ifstream i1,i2;
ofstream o1;
i1.open("input.txt");
i2.open("key.txt");
o1.open("output.txt");
string key="",message="",temp="",encrypted="";
int i,j,k,l,row=5,column=5,r1,r2,c1,c2;
char look[6][6]={},ch;
int track[2][26];
while(!i2.eof())
{
    i2>>ch;
    if(!i2.eof())
    {
        key.push_back(ch);
    }
}
cin.clear();
while(!i1.eof())
{
    i1>>ch;
    if(!i1.eof())
    {
        message.push_back(ch);
    }
}
cin.clear();
key=checking(key);
message=checking(message);
message=digraph(message);
if(lent(key)==1 || lent(message)==1)      // Check For Numbers In String
{
row=6;
column=6;
}
for(i=0;i<row;i++)
{
    for(j=0;j<column;j++)
    {
        look[i][j]=' ';
    }
}
for(i=0;i<26;i++)
{
    track[0][i]=0;        //Numbers
    track[1][i]=0;        //Alphabets
}

k=0;
i=0;
j=0;
while(k<key.length())           //Filling Matrix With Key
{
    l=key.at(k);
    if(row==5 && l=='j')
    {
        l='i';
    }
    if(l/97==0)
    {
        if(track[0][l-48]!=1)
        {
            track[0][l-48]=1;
            if(j<column)
            {
                look[i][j]=l;
                j++;
            }
            else
            {
                i++;
                j=0;
                look[i][j]=l;
                j++;
            }
        }
    }
    else
    {
        if(track[1][l-97]!=1)
        {
            track[1][l-97]=1;
            if(j<column)
            {
                look[i][j]=l;
                j++;
            }
            else
            {
                i++;
                j=0;
                look[i][j]=l;
                j++;
            }
        }
    }
    k++;
}
if(row==5)
{
    temp="abcdefghiklmnopqrstuvwxyz";
}
else if(row==6)
{
    temp="0123456789abcdefghijklmnopqrstuvwxyz";
}
k=0;
while(k<temp.length())           //Filling Matrix With Remaining characters
{
    l=temp.at(k);
    if(row==5 && l=='j')
    {
        l='i';
    }
    if(l/97==0)
    {
        if(track[0][l-48]!=1)
        {
            track[0][l-48]=1;
            if(j<column)
            {
                look[i][j]=l;
                j++;
            }
            else
            {
                i++;
                j=0;
                look[i][j]=l;
                j++;
            }
        }
    }
    else
    {
        if(track[1][l-97]!=1)
        {
            track[1][l-97]=1;
            if(j<column)
            {
                look[i][j]=l;
                j++;
            }
            else
            {
                i++;
                j=0;
                look[i][j]=l;
                j++;
            }
        }
    }
    k++;
}

cout<<"\nKey : "<<key<<"\nMessage : "<<message<<endl;
for(i=0;i<row;i++)
{
    for(j=0;j<column;j++)
    {
        cout<<look[i][j];
    }
    cout<<endl;
}
k=0;
while(k<message.length())
{
    r1=0;
    r2=0;
    c1=0;
    c2=0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            if(row==5)
            {
                if(message.at(k)=='j')
                {
                    if(look[i][j]=='i')
                    {
                        r1=i;
                        c1=j;
                    }
                }
                else
                {
                    if(look[i][j]==message.at(k))
                    {
                        r1=i;
                        c1=j;
                    }

                }
                if(message.at(k+1)=='j')
                {
                    if(look[i][j]=='i')
                    {
                        r2=i;
                        c2=j;
                    }
                }
                else
                {
                    if(look[i][j]==message.at(k+1))
                    {
                        r2=i;
                        c2=j;
                    }

                }

            }
            else
            {
                if(look[i][j]==message.at(k))
                {
                    r1=i;
                    c1=j;
                }
                if(look[i][j]==message.at(k+1))
                {
                    r2=i;
                    c2=j;
                }
            }
        }
    }
    //cout<<message.at(i)<<" = ("<<r1+1<<","<<c1+1<<")"<<endl;
    //cout<<message.at(i+1)<<" = ("<<r2+1<<","<<c2+1<<")"<<endl;
    if(r1==r2)
    {
        encrypted.push_back(look[r1][(c1+1)%row]);
        encrypted.push_back(look[r1][(c2+1)%row]);
    }
    else if(c1==c2)
    {
        encrypted.push_back(look[(r1+1)%column][c1]);
        encrypted.push_back(look[(r2+1)%column][c2]);
    }
    else
    {
        encrypted.push_back(look[r1][c2]);
        encrypted.push_back(look[r2][c1]);
    }
    k+=2;
}
cout<<"Encrypted : "<<encrypted<<endl;
o1<<encrypted<<endl;
i1.close();
o1.close();
return 0;
}
