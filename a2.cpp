/*
 * main.cpp
 *
 *  Created on: 11‏/04‏/2016
 *      Author: fox
 */
#include <iostream>
#include<cstdlib>
#include <string>
#include "inord_list.h"
#include <fstream>
#include<sstream>
using namespace std;
int main(int argc , char *argv[])
{
    inord_list l;
    listelemtype e;
    int elemnum=0;
    string line;
    string word;
    int charnum=0;
    char ch;
    int count=0;
    string searchfilename=argv[1];
    string file1=searchfilename;
    ifstream searchfile (file1.c_str());
  if (searchfile.is_open())
  {
    while ( getline(searchfile,line))
    {
        elemnum++;
        istringstream iss(line);
    while(iss >> word)
        {
            for(unsigned int f=0;f<word.length();f++)
            {
           word[f]=tolower(word[f]);
            }
   l.insert(word,elemnum);
    count++;
        }

    }
fstream fin(file1.c_str(), fstream::in);
while (fin >> noskipws >> ch) {
    charnum++; // Or whatever
}

  }
  else
  {
    cout<<"File not found";
    return 0;
  }
  searchfile.close();

    string commandsfilename=argv[2];
    string file2=commandsfilename;
    ifstream commandsfile (file2.c_str());
    string comm[100];
    string mostrep;
    string line_c;
    string word_c;
    int co;
    if (commandsfile.is_open())
  {
    while ( getline(commandsfile,line_c))
    {
        istringstream iss(line_c);
        for(int u=0;u<100;u++)
            comm[u]="0";
            co=0;
    while(iss >> word_c)
        {

            for(unsigned int f=0;f<word_c.length();f++)
            word_c[f]=tolower(word_c[f]);
            comm[co]=word_c;
            co++;


        }


    string s1="wordcount";
    string s2="distwords";
    string s3="charcount";
    string s4="frequentword";
    string s5="countword";
    string s6="starting";
    string s7="containing";
    string s8="search";


for(int j=0;j<co;j++)
{
    if(comm[0]!=s1&&comm[0]!=s2&&comm[0]!=s3&&comm[0]!=s4&&comm[0]!=s5&&comm[0]!=s6&&comm[0]!=s7&&comm[0]!=s8)
        {cout<<"Undefined command";
    break;
        }

     if(comm[j]==s1)
    {
         cout<<count<<" "<<"words"<<'\n';

    }
    else if(comm[j]==s2)
    {   string temp;
        int distwords=0;
        bool flag=l.first(e,elemnum);
        while(flag)
        {
            temp=e;
            flag=l.next(e,elemnum);
            if(temp!=e)
                distwords++;
        }

        cout<<distwords+1<<" distinct words"<<'\n';
    }
    else if(comm[j]==s3)
    {
        cout<<charnum<<" "<<"characters"<<'\n';

    }
    else if(comm[j]==s4)
    {


        string arr[count];
        bool flag;
        bool flag3;
        int c=0;
        int temp=0;;
        int occ;
        string mostfreq;
        flag=l.first(e,elemnum);
        while(flag)
        {
            arr[c]=e;
            c++;
            flag=l.next(e,elemnum);
        }

        for(int y=0;y<count;y++)
        {

        flag3=l.first(e,elemnum);
        occ=0;
        while(flag3)
        {
            if(e==arr[y])
                occ++;

            flag3=l.next(e,elemnum);

        }
        if(occ>temp&&arr[y]!="a"&&e!="an"&&e!="the"&&e!="in"&&e!="on"&&e!="of"&&e!="and"&&e!="is"&&e!="are")
        {
            temp=occ;
            mostfreq=arr[y];
        }

        }
        cout<<"Most frequent word is: "<<mostfreq<<'\n';

    }

      if(comm[j]==s5)
    {
         if(comm[j+1]=="0")
            cout<<"Incorrect number of arguments";
        for(unsigned int f=0;f<comm[j+1].length();f++)
           comm[j+1][f]=tolower(comm[j+1][f]);
        string bla=comm[j+1];
        bool flag3=l.first(e,elemnum);
        int occ=0;
        while(flag3)
        {
            if(e==bla)
                occ++;

            flag3=l.next(e,elemnum);

        }

        cout<<comm[j+1]<<" is repeated "<<occ<<" times"<<" "<<'\n';

    }

   if(comm[j]==s6)
    {
         if(comm[j+1]=="0")
            cout<<"Incorrect number of arguments";
        for(unsigned int f=0;f<comm[j+1].length();f++)
           comm[j+1][f]=tolower(comm[j+1][f]);
        string substring=comm[j+1];
        bool flag6;
        string arr[100];
        unsigned int count1;
        int y=0;
        bool check;
        flag6=l.first(e,elemnum);
        while(flag6)
        {
            for(unsigned int b=0;b<substring.length();b++)
            {
                if(e[b]==substring[b])
                    count1++;
            }

            if(count1==substring.length())
            {
                check=true;
                for(int u=0;u<y;u++)
                   {
                     if(arr[u]==e)
                      check=false;
                   }

                if(check)
                    {
                arr[y]=e;
                y++;
                    }
            }

            flag6=l.next(e,elemnum);
            count1=0;
        }
        int a=0;
        for(int o=0;o<100;o++)
        {
          if(!(arr[o].empty()))
            a++;
        }
        int* counts;
        counts=new int(a);
        for(int t=0;t<a;t++)
        {
        flag6=l.first(e,elemnum);
        counts[t]=0;
        while(flag6)
        {
            if(e==arr[t])
            {
                counts[t]++;
            }
            flag6=l.next(e,elemnum);
        }
        }
        for(int q=0;q<a;q++)
        {

            cout<<arr[q]<<": "<<counts[q]<<"    ";
        }
    }
      if(comm[j]==s7)
    {
         if(comm[j+1]=="0")
            cout<<"Incorrect number of arguments";
        for(unsigned int f=0;f<comm[j+1].length();f++)
           comm[j+1][f]=tolower(comm[j+1][f]);
        string substring=comm[j+1];
        bool flag6;
        string arr[100];
        int y=0;
        bool check;
        flag6=l.first(e,elemnum);
        while(flag6)
        {
            for(unsigned int b=0;b<e.length();b++)
            {
              //  if(substring==e.substr(b,b+substring.length()))
              if((e.substr(b,substring.length())).length()==substring.length())
                {
              if((e.substr(b,substring.length())==substring))
              {
                  check=true;
                for(int u=0;u<y;u++)
                   {
                     if(arr[u]==e)
                      check=false;
                   }

                if(check)
                    {
                arr[y]=e;
                y++;
                    }
                }
              }
            }

            flag6=l.next(e,elemnum);
        }
        int a=0;
        for(int o=0;o<100;o++)
        {
          if(!(arr[o].empty()))
            a++;
        }
        int* counts;
        counts=new int[a];
        for(int t=0;t<a;t++)
        {
        flag6=l.first(e,elemnum);
        counts[t]=0;
        while(flag6)
        {
            if(e==arr[t])
            {
                counts[t]++;
            }
            flag6=l.next(e,elemnum);
        }
        }
        cout<<'\n';
        for(int q=0;q<a;q++)
        {
            cout<<arr[q]<<": "<<counts[q]<<"    ";
        }
    }
     if(comm[j]==s8)
    {

       if(comm[j+1]=="0")
            cout<<"Incorrect number of arguments";
       for(unsigned int f=0;f<comm[j+1].length();f++)
           comm[j+1][f]=tolower(comm[j+1][f]);


        string substring=comm[j+1];
        bool flag6;
        string arr[100];
        int y=0;
        int a=0;
        bool check;
        flag6=l.first(e,elemnum);
        while(flag6)
        {
           for(unsigned int b=0;b<e.length();b++)
            {
              //  if(substring==e.substr(b,b+substring.length()))
              if((e.substr(b,substring.length())).length()==substring.length())
                {
              if((e.substr(b,substring.length())==substring))
              {
                  check=true;
                for(int u=0;u<y;u++)
                   {
                     if(arr[u]==e)
                      check=false;
                   }

                if(check)
                    {
                arr[y]=e;
                a++;
                y++;
                    }
                }
              }
            }

            flag6=l.next(e,elemnum);
        }


        bool flag0;
        flag0=l.first(e,elemnum);
        int arrr[100][100];
        for(int y=0;y<100;y++)
        {
            for(int u=0;u<100;u++)
            {
                arrr[y][u]=0;

            }
        }
        int x;
        for(int q=0;q<a;q++)
        {
            x=0;
            while(flag0)
            {
                if(e==arr[q])
                {
                   arrr[q][x]=elemnum;
                }
                x++;
                flag0=l.next(e,elemnum);
            }
            flag0=l.first(e,elemnum);

        }
        cout<<'\n';

        for(int q2=0;q2<a;q2++)
        {
            cout<<arr[q2]<<": "<<"lines ";
            for(int e=100;e>=0;e--)
            {
                if((arrr[q2][e]!=0))
                {
                    cout<<arrr[q2][e]<<" ";
                }

            }
            cout<<'\n';
        }
    }


//cout<<comm[j]<<" "<<j<< " ";
}


}
  }
  else
  {
    cout<<"File not found";
    return 0;
  }
      searchfile.close();

    //test
/*
    bool flag1447;
    flag1447=l.first(e,elemnum);
    cout<<"teeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeest";
    while(flag1447)
    {

        cout<<'\n'<<e<<" "<<elemnum<<'\n';
        flag1447=l.next(e,elemnum);
    }

*/
    return 0;
}

