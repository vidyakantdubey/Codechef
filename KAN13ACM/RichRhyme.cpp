#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

int main(){

long int i,j=0, temp=0, count=0; 
char* str;
char ch='a';  

       while(true)
       {
            
             str=NULL;
              scanf("%s",str);
              fflush(stdin);
              count=0;
              j=0;
              if(strlen(str)==3 && str[0]=='E' && str[1]=='n' && str[2]=='d') 
                 break;      
              printf("%ld",count);
              for(i=1;i<strlen(str);i++)
              {
                if(str[i]==str[j])
                 {
                   count++;
                   printf(" %ld",count);
                   j++;
                 }     
                 else
                 {
                   j=0;
                   count=0;
                   if(str[i]==str[j])
                   {
                     j++;
                     count++;
                   }
                   printf(" %ld",count);
                 }                
              }
            cout<<endl;
      } 
       return 0;
}
