#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void add(vector<long int>& v1, vector<long int>& v2)
{
   for(int i=0;i<11;i++)
   {
      v1.at(i)+=v2.at(i);
   }
}

void subtract(vector<long int>& v1, vector<long int>& v2)
{
   for(int i=0;i<11;i++)
   {
      v1.at(i)-=v2.at(i);
   }
}

long int count(vector<long int> v)
{
   long int count=0;
   for(int i=0;i<11;i++)
   {
      if(v.at(i)!=0)
      count++;
   }
   return count;
}

int main()
{
    vector<int>grid;
    vector< vector<long int> > sets;
    vector<long int> inclusion;
    vector<long int> result1,result2;
    int x1,x2,y1,y2;
    bool first_cut=false,second_cut=false;
    int columns=0;
    long int num_cases;
    cin>>columns;
    grid.resize(columns*columns+1);
    sets.resize(columns*columns+1);
    
    for( int i=1;i<=columns;i++)
     {
       inclusion.clear();
       inclusion.resize(11);
       for( int j=1;j<=columns;j++)
          {
          	cin>>grid[columns*(i-1)+j];
          	inclusion.at(grid[columns*(i-1)+j])++;         
   	        sets[columns*(i-1)+j]=inclusion;
          	if(i>1)
          	{
              add(sets[columns*(i-1)+j],sets[columns*(i-2)+j]);
            }
          }
     }
    cin>>num_cases;
    for(long int j=0;j<num_cases;j++)
    {
    	cin>>x1>>y1>>x2>>y2;
        if(x1>1)
        {
           result1=sets[columns*(x2-1)+y2];
           subtract(result1,sets[columns*(x1-2)+y2]);   
           first_cut=true;     
        }     
        else
          result1=sets[columns*(x2-1)+y2];
          
        if(y1>1)
        {
           result2=result1;
           subtract(result2,sets[columns*(x2-1)+y1-1]);
           second_cut=true;
        }       
        if(first_cut && second_cut)
          {
            add(result2,sets[columns*(x1-2)+y1-1]);
            cout<<count(result2)<<endl;
          }
        else if(second_cut)
          cout<<count(result2)<<endl;
        else
          cout<<count(result1)<<endl;
    	result1.clear();
    	result2.clear();
   	    first_cut=false;
        second_cut=false;
    	
    }
    
    return 0;
}
