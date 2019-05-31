#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

bool chkdivis(vector<int> b, int k)
{

    for(int i=0; i<b.size(); ++i)
    {
        int sumvs = 0;
        for(int j=i+1; j<b.size(); ++j)
        {
            sumvs = b[i]+b[j];
            if((sumvs%k)==0)
            {
                //cout<<"Sum of 2 digs is div by "<<k<<endl;
                return 1; //the sum of 2 elems divides by k evenly
            }
        }
    }
    //cout<<"Sum of any 2 digs is not div by "<<k<<endl;
    return 0; //no sum of 2 elems divide by k evenly
}

bool generatebinary(int k, int totnumdig, int reqnumdigs, vector<int> & a)
{
    //vector<int> a(totnumdig);
    int num1ssofar = 0;
    for(int i=0; k>0; i++)
    {
        a[i]=k%2;
        k = k/2;
        if (a[i]==1)
        {
            num1ssofar++;
        }
    }
    if (num1ssofar == reqnumdigs)
        return true;
    else
        return false;
}

// Complete the nonDivisibleSubset function below.
int nonDivisibleSubset(int k, vector<int> S) {

    for(int reqnumdigs=S.size(); reqnumdigs>=2; --reqnumdigs)
    {
    //int reqnumdigs = 3;
        for (int ctnum = 1; ctnum<=pow(2, S.size())-1; ++ctnum)
        {
            vector<int>  a(S.size());
            if(generatebinary(ctnum, S.size(), reqnumdigs, a))
            {
                vector<int> c;
                for(int ll=0; ll<S.size(); ++ll)
                {
                    if (a[ll]==1)
                        c.push_back(S[ll]);
                }


                if(!chkdivis(c, k))
                {
                    //int ctsize = a.size();
                    //for(int oo=0;oo<c.size(); ++oo)
                    //    cout<<c[oo]<<" ";
                    //cout<<endl;
                    //c.clear();
                    //cout<<"working"<<endl;
                    return reqnumdigs;
                }
            }
        }

    }
    return 1;
}

int main()
{
    vector<int> a{1, 7, 2, 4};
    sort(a.begin(), a.end()); //10, 12, 19, 22, 24, 25
    int k = 3;
    cout<<nonDivisibleSubset(k, a);

    //vector<int>  a(5);
    //cout<< generatebinary(7, 5, 3, a)<<endl;
    //cout<<pow(2, a.size())-1;

    //vector<int> b{12, 9, 24};
    //cout<<chkdivis(b, 4);

    /*
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string S_temp_temp;
    getline(cin, S_temp_temp);

    vector<string> S_temp = split_string(S_temp_temp);

    vector<int> S(n);

    for (int i = 0; i < n; i++) {
        int S_item = stoi(S_temp[i]);

        S[i] = S_item;
    }

    int result = nonDivisibleSubset(k, S);

    fout << result << "\n";

    fout.close();

    */
    return 0;
}

/*
vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
*/
