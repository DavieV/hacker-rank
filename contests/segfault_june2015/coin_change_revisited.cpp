#include <iostream>
#include <cstring>
using namespace std;
int coin[] = {1,5,10,20,50};
const int max_n=10000;
int memo[10][max_n+5],N;
int coinChange(int index,int current_value)
{
   if(current_value==N)return 1;
   if(current_value>N)return 0;
   if (index==5) return 0;
   if (memo[index][current_value]!=-1) return memo[index][current_value];
   int ans=coinChange(index,current_value + coin[index])+coinChange(index+1,current_value);
   ans=ans%10000000;
   memo[index][current_value]=ans;
   return ans;
}

int main()
{
   memset(memo,-1,sizeof memo);
   int t;
   cin>>t;
   for(int i=0;i<t;i++)
   {
      cin>>N;
      cout<<coinChange(0,0)<<endl;
      memset(memo,-1,sizeof memo);
   }
   return 0;
}
