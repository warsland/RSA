#include<iostream>

using namespace std;

int gcd(int a, int b)   //欧几里得算法
{
    if (a % b == 0)
    {
        return b;
    }
    return gcd(b, a % b);
}

int ex_gcd(int a, int b, int& x, int& y)       //扩展欧几里得 
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int r = ex_gcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return r;
}

int mod_reverse(int a, int n)   //求a的逆元x 
{
    int d, x, y;
    d = ex_gcd(a, n, x, y);
    if (d == 1)
        return (x % n + n) % n;
    else
        return -1;
}

int encryp(int M,int e,int n)   //加密
{
    int temp=1;
    for (int i = 0; i < e; i++)
    {
        temp *= M;
        temp %= n;
    }
    return temp;
}

int decrypt(int C,int d,int n)  //解密
{
    int temp=1;
    for (int i = 0; i < d; i++)
    {
        temp *=  C;
        temp %= n;
    }
    return temp;
}

int main()
{
    int p,q,N,e,d;
    int M, C, D;
    cout << "输入两个互质的数: ";
    cin >> p >> q;
    while (gcd(p,q)!=1)
    {
        cout << "输入的两个数不是互质的数，请重新输入:";
        cin >> p >> q;
    }
    N = (p - 1) * (q - 1);
    cout << "请输入整数e: ";
    cin >> e;
    while ((gcd(e,N)!=1)&&(1<e)&&(e<N))
    {
        cout << "输入的整数e不符合要求，请重新输入: " ;
        cin >> e;
    }
    d = mod_reverse(e, N);
    cout << "输入需要加密的数字: ";
    cin >> M;
    C = encryp(M, e, p*q);
    D = decrypt(C, d, p*q);
    cout << "密文：" << C << endl;
    cout << "明文: " << D << endl;
}