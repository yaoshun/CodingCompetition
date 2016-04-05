#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
typedef long long ll;

//1/x+1/y=1/N! => x=y*N!/(y-N!) => if z=y-N!, x=N!+N!^2/z
//find how many positive factors are for N!^2
int main()
{
    unsigned int i,j;
    unsigned int n;
    cin >> n;

    //find how many primes are there between 1 and n
    vector<bool> array(n, true);
    array[0] = false;
    array[1] = false;
    
    for(i = 2; i * i <= n; i++)
    {
        if(array[i])
        {
            j = i * i;
            while(j <= n)
            {
                array[j] = false;
                j += i;
            }
        }
    }

    ll count = 1;
    ll factor = 0;
    ll sum;
    ll temp;
    
    for(i=2;i<=n;i++)
    {
        if(array[i])
        {
            temp = n;
            sum = 0;
            while (temp != 0)
            {
                sum = sum + temp/i;
                temp = temp/i;
                if(sum > 1000007)
                    sum %= 1000007;
            }
            factor = (sum * 2)%1000007;
            count = (count * (factor+1))%1000007;
        }
    }
    cout << count << endl;
    return 0;
}
