int primorial()
{
    int number, i, j, sum = 1;
    bool prime;
    cout << "Enter a number: ";
    cin >> number;

    for(i=2;i<=number;i++)
    {
        prime = true;
        for(j=2;j<i;j++)
        {
            if(i%j==0)
            {
                prime=false;
                break;
            }
        }
        if(prime)
        {
            sum *= i;
        }
    }
    cout << number <<"# = " << sum;
    return 0;
}
