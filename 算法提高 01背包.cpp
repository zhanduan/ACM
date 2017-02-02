#include<iostream>
using namespace std;
int dp[201][5001];
//算法提高 01背包
int max(int x,int y)
{
    return x>y?x:y;
}

int main()
{
    int t,n,v,i,j;
    int va[201],vo[201];
  
        cin>>n>>v;       //数量与容量
        for(i=1;i<=n;i++)
            cin>>vo[i]>>va[i];   //体积与价值
        memset(dp,0,sizeof(dp));//初始化操作
         for(i=1;i<=n;i++)
        {
            for(j=0;j<=v;j++)
            {
                if(vo[i]<=j)//表示第i个物品将放入大小为j的背包中
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-vo[i]]+va[i]);//第i个物品放入后，那么前i-1个物品可能会放入也可能因为剩余空间不够无法放入
                else //第i个物品无法放入
                    dp[i][j]=dp[i-1][j];
            }
        }
        cout<<dp[n][v]<<endl;
 
    return 0;
}