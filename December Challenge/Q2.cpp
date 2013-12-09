#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
 
string process_string(string query_sentence,vector<char> q_seq,vector<int> h_map)
{
  string result;
  vector<char> c_seq;
  int temp=0,j=0;
  c_seq.resize(26);
  c_seq.at(0)=97;
  for(int i=1;i<h_map.size();i++)
  {
    temp=h_map.at(i);
    j=i-1;
    while(j>=0 && temp<h_map.at(c_seq.at(j)-97))
    {
      c_seq.at(j+1)=c_seq.at(j);
      j--;
    }   
    c_seq.at(j+1)=i+97;
  }
  for(int i=0;i<c_seq.size();i++)
  {
    h_map.at(c_seq.at(i)-97)=static_cast<int>(q_seq.at(i));
  }
  for(int i=0;i<query_sentence.length();i++)
  {
    if(query_sentence.at(i)>=97 && query_sentence.at(i)<=122)
    {
      result.push_back(static_cast<char>(h_map.at(query_sentence.at(i)-97)));
    }
    else if(query_sentence.at(i)>=65 && query_sentence.at(i)<=90)
    {
      result.push_back(static_cast<char>(h_map.at(query_sentence.at(i)-65)-32));
    }
    else
    {
      result.push_back(query_sentence.at(i)); 
    }
  }
  return result;
}
 
int main()
{
    vector<char> f_seq;
    vector<int> h_map;
    char ch;
    string query_sentence;
    int num_cases;
    cin>>num_cases;
    while(num_cases--)
    {
       f_seq.resize(26);
       h_map.resize(26);
       for(int i=0;i<26;i++)
       cin>>f_seq.at(i);
       cin.ignore();
       scanf("%c",&ch);
       while(ch!='\n')
       {
         query_sentence.push_back(ch);
         
         if(ch>=97 && ch<=122)
           h_map.at(ch-97)++;
         else if(ch>=65 && ch<=90)
           h_map.at(ch-65)++;
          scanf("%c",&ch);
       }
       cout<<process_string(query_sentence,f_seq,h_map)<<endl;
       h_map.clear();
       f_seq.clear();
       query_sentence.clear();
    }
   
    return 0;
}
 
