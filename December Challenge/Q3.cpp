#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

void update(vector<int>& give_n_take, vector<long int>& look_up, long int index, long int value)
{
     if(give_n_take.at(index)==0)
     {
         if(look_up.size()>0)
         {
           if(look_up.front()>index)
              look_up.insert(look_up.begin(),index);
           else if(look_up.back()<index)
              look_up.push_back(index);
           else
           {
              look_up.push_back(index);
              sort(look_up.begin(), look_up.end());  
           }
         }
         else
            look_up.push_back(index);
     }
     give_n_take.at(index)+=value;
}

long int get_first_index(vector<long int>& look_up,long int index)
{
  long int mid=0;
  long int low=0,high=look_up.size()-1;
  while(low<=high)
  {
    mid=(low+high)/2;
    if(look_up.at(mid)==index)
       return mid;
    else if(look_up.at(mid) < index)
       low=mid+1;
    else
       high=mid-1;
  }
  return low;
}

long int get_second_index(vector<long int>& look_up,long int index)
{
  long int mid=0;
  long int low=0,high=look_up.size()-1;
  while(low<=high)
  {
    mid=(low+high)/2;
    if(look_up.at(mid)==index)
       return mid;
    else if(look_up.at(mid) < index)
       low=mid+1;
    else
       high=mid-1;
  }
  return high;
}

long long int get_value(vector<long long int>& children, vector<int>& give_n_take, vector<long int>& look_up, long int index1, long int index2)
{
   long long int result=0;
   long int i=0,j=0;
   if(index1>0)
     result=children.at(index2)- children.at(index1-1);
   else
     result=children.at(index2);
   if(look_up.size()>0)
   {
   if(index1>look_up.back() || index2<look_up.front())
       return result;
   if(index1 < look_up.front())
     i=0;
   else
     i=get_first_index(look_up,index1);
   if(index2 > look_up.back())
     j=look_up.size()-1;
   else
     j=get_second_index(look_up,index2);
   
   for(long int k=i;k<=j;k++)
     result+=give_n_take.at(look_up.at(k));
   }
   
   return result;     
}



int main()
{
    vector<long long int> children;
    vector<int> give_n_take;
    vector<long int> look_up;
    char code='S';
    long int index=0,value=0;
    long long int sum=0;
    long int queries=0,num_children=0;
    cin>>num_children;
    cin>>queries;
    children.resize(num_children);
    give_n_take.resize(num_children);
    for(int i=0;i<num_children;i++)
    {
      cin>>children.at(i);
      sum+=children.at(i);
      children.at(i)=sum;
    }
 
    for(int i=0;i<queries;i++)
    {
      cin.ignore();
      cin>>code>>index>>value;
      if(code=='G')
      {
        update(give_n_take,look_up,index,value);
      }
      else if(code=='T')
      {
        update(give_n_take,look_up,index,(-1)*value);
      }
      else
      {
        cout<<get_value(children,give_n_take,look_up,index,value)<<endl;
      }
    }
    return 0;   
}
