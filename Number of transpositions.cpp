#include <iostream>
#include <string>
#include "vector"

using namespace std;

long long int transpositions (string word, char letter);
long long int P (vector<vector<int>> letters);
long long int C (int n, int k);
long long int factorial (int n);

int main() {

    string word;
    cout << "Write word" << endl;
    cin >> word;
    char letter;
    cout << "Needed letter:" << endl;
    cin >> letter;
    /*vector <vector <int>> C;
    for (int i = 0; i <=  100);
        for (int j = 0;)
    */


    cout << "Number of transpositions = " << transpositions(word, letter);

    return 0;
}

long long int transpositions (string word, char letter)
{
    int n = word.length();
    int k = 0;
    int p = 0;
    bool fl;
    vector<vector<int>> letters;
    for (int i = 0; i < n; ++i)
        if (word [i] == letter)
            k += 1;
        else
        {
            fl = 1;
            int let = int (word[i]);
            size_t j = 0;
            while (fl && j < letters.size())
                if (letters [j][0] == let)
                {
                    fl = 0;
                    letters.at(j)[1] += 1;
                }
                else
                    j += 1;
            if (fl)
            {
                vector<int> temp;
                temp.push_back(let);
                temp.push_back(1);
                letters.push_back(temp);
            }
        }
    p = n - k * 2;
    if (p < 0)
        return 0;
    return (C (k + p, p) * (k + 1) * P(letters));
}

long long int P (vector<vector<int>> letters)
{
    long long int denominator = 1;
    for (size_t i = 0; i < letters.size(); ++i)
        denominator *= factorial(letters[i][1]);
    return (factorial (letters.size())/denominator);
}

long long int C (int n, int k)
{
    return (factorial (n) / factorial (k) / factorial(n - k));
}

long long int factorial (int n)
{
    long long int temp = 1;
    for (int i = 2; i <= n; ++ i)
        temp *= i;
    return temp;
}
