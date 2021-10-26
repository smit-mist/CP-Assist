ll binaryexponention(ll a,ll b)
{
    ll result=1;
    while(b>0)
    {
        if(b%2==1)
        {
            result*=a;
        }
        a*=a;
        b/=2;
    }
    return result;
}
