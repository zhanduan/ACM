#include<iostream>
using namespace std;
int dp[201][5001];
//�㷨��� 01����
int max(int x,int y)
{
    return x>y?x:y;
}

int main()
{
    int t,n,v,i,j;
    int va[201],vo[201];
  
        cin>>n>>v;       //����������
        for(i=1;i<=n;i++)
            cin>>vo[i]>>va[i];   //������ֵ
        memset(dp,0,sizeof(dp));//��ʼ������
         for(i=1;i<=n;i++)
        {
            for(j=0;j<=v;j++)
            {
                if(vo[i]<=j)//��ʾ��i����Ʒ�������СΪj�ı�����
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-vo[i]]+va[i]);//��i����Ʒ�������ôǰi-1����Ʒ���ܻ����Ҳ������Ϊʣ��ռ䲻���޷�����
                else //��i����Ʒ�޷�����
                    dp[i][j]=dp[i-1][j];
            }
        }
        cout<<dp[n][v]<<endl;
 
    return 0;
}