#include <QCoreApplication>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int binString2Int(string a)
{
    int x = 0;
    for(int i = 0 ; i < a.size(); i++)
    {
        if ( (a[i]-'0') == 1)
        {
            int t = 1<<(a.size()-i-1);
            x |= t;
        }
    }
    return x;
}

string addBinary1(string a, string b)
{
    int x = binString2Int(a);
    int y = binString2Int(b);
    cout << "x: " <<x<<endl;
    std::string binary = std::bitset<8>(x+y).to_string();
    if (binary.find_first_of('1') == -1) return "0";
    return binary.substr(binary.find_first_of('1'));

}

void addRemaing(string& a, int& promo, vector<int>& res)
{
    for(int i = a.size() - res.size() -1; i>= 0; i--)
    {
        int x = a[i] - '0';
        int sum = promo + x;
        if (promo != 0 ) promo--;
        if (sum > 1)
        {
            promo++;
            res.insert(res.begin(),sum-2);
        }
        else
        {
            res.insert(res.begin(),sum);
        }
    }
}

string addBinary(string a, string b)
{
    vector<int> res;
    int size = a.size() > b.size()? b.size() : a.size();
    int promo = 0;
    int sum = 0;

    for ( int i = a.size()-1, j = b.size()-1; i>=0 && j>=0 ; i--,j--)
    {
        int x = a[i] - '0';
        int y = b[j] - '0';
        sum = x+y+promo;
        if (promo != 0) promo--;
        if(sum > 1)
        {
            promo++;
            res.insert(res.begin(),sum-2);
        }
        else
        {
            res.insert(res.begin(),sum);
        }
    }

    if (a.size() != b.size())
    {
        addRemaing(a.size()>b.size()? a: b, promo,res);
    }

    if (promo > 0)
    {
        res.insert(res.begin(),1);
    }

    //format res
   string str;
   for(int t : res)
   {
       str.append(to_string(t));
   }
    return str;
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    string a = "10";
    string b = "101111";
    cout << "Binary sum: "<< addBinary(b,a) << endl;
    return app.exec();
}
