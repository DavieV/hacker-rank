#include<iostream>

using namespace std;

int main()
{
   int n,sum;
   cin>>n>>sum;
   int ans=0;
   for(int a=1;a<=n;a++)
   {
      for(int b=1;b<=n;b++)
      {
        int c = sum - b - a;
        if (c <= n && c >= 1) {
            ++ans;
        }
      }
   }
   cout<<ans<<endl;
   return 0;
}
