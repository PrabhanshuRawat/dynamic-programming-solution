
#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include<map>
#include<algorithm>
#include<iterator>
using namespace std;
typedef long long ll;
 
map<ll,vector<ll>>adj;
vector<ll>s(100055);
 
void sieveoferatosthenes(ll n)
{ ll a=1000000;
  vector<ll>prime(a+1,0);
  for(ll i=2;i*i<=n;i++)
  {
     if(prime[i]==0)
{
   for(ll j=i*i;j<=n;j+=i)
   prime[j]=1;
}
  }
  
  for(ll i=2;i<n;i++)
  {
     if(prime[i]==0)
     cout<<i<<" ";
  }
  
}
void primefactor(ll n)
{
   ll spf[100]={0};
   for(ll i=2;i<=n;i++)
       spf[i]=i;
       for(ll i=2;i<=n;i++)
       {
          if(spf[i]==i)
          {
             for(ll j=i*i;j<=n;j+=i)
             {
                if(spf[j]==j){
                   spf[j]=i;
                }
             }
          }
       }
       while(n!=1)
       {
          cout<<spf[n]<<" ";
          n=n/spf[n];
       }
 
}
ll gcd(ll a,ll b)
{
   if(b==0)
   return a;
   return gcd(b,a%b);
}
bool cmp(pair<ll,ll>a,pair<ll,ll>b)
{  if(a.second!=b.second)
  {if(a.second>b.second)
   return true;
   return false;}
    else
   { if(a.first>b.first) return true;
       return false;
   }
 
   
}
ll res=0;
void dfs(ll source,ll parent)
{  
      
   if(s[source]==-1)
   { if (adj[source].size() == 0) {
			s[source] = s[parent];
			return;}
         else{
      ll mini=s[adj[source][0]];
      for(auto x:adj[source])
      {  
         mini=min(mini,s[x]);
      }
      if(mini<s[parent]) {
         cout<<"-1\n";
         exit(0);
      }
      res+=mini-s[parent];
   
       s[source]=mini;
      
   
         }
   }
   else
   { if(s[source]<s[parent]) {
         cout<<"-1\n";
         exit(0);
      }
      res+=s[source]-s[parent];
      
   }
   for(auto y:adj[source])
    dfs(y,source);
   
   
  
}
ll isPower(ll a)
{
    if (a == 1)
        return 1;
 
    for (ll i = 2; i * i <= a; i++) {
        double val = log(a) / log(i);
        if ((val - (ll)val) < 0.00000001)
            return i;
    }
 
    return false;
}
ll mini(vector<ll>& v,ll mid)
{
   ll sum=0;
   for(ll i=0;i<mid;i++)
   sum=sum+v[i];
   return sum;
}
 ll bt(vector<ll>&v,ll n,ll sum,ll q1)
 {
    ll low=1;
    ll high=n;
    ll ans;
    while(low<=high)
    {
       ll mid=(low+high)/2;
       if(mini(v,mid)>=q1)
       { ans=mid;
        high=mid-1;
 
       }
       else{
         
       low=mid+1;}
    }
    return ans;
 
 }
 
 ll kjump(ll i,vector<ll>& v,ll n,ll k,vector<ll>& dp)
 {
   if(i==0) return 0;
   if(dp[i]!=-1) return dp[i];
   ll mini=INT_MAX;ll jump;
   for(ll j=1;j<=k;j++)
    {  if(i-j>=0)
       jump=kjump(i-j,v,n,k,dp)+abs(v[i]-v[i-j]);
      mini=min(mini,jump);

    }
    return dp[i]=mini;
 }
 
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	//ll n;
  // cin>>n;
   //ll sum=0;
  // while(n)
  // {
    //  ll rem=n%10;
     // sum=sum*10+rem;
    //  n=n/10;
   //}
   //cout<<sum<<"\n";
  
 // sieveoferatosthenes(n);
  //primefactor(n);
//ll t;
//cin>>t;
//while(t--)
//{
   ll n,k;
   cin>>n>>k;
   vector<ll>v(n);
   
   

   for(ll i=0;i<n;i++)
   {cin>>v[i];

   }
   vector<ll>dp(n,-1);
   cout<<kjump(n-1,v,n,k,dp)<<"\n";

   
 
 //}
	return 0;}