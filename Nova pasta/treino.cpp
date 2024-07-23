#include <bits/stdc++.h>

using namespace std;

int main()
{
    string arqe, linha;
    cin >> arqe;
    ifstream ae(arqe);
    int contalinha = 0, contavogal = 0, contaconso = 0, contacaractere = 0;
    while (getline(ae, linha))
    {
        contalinha++;
        contacaractere += linha.size();
        for (char c : linha)
        {
            if (isalpha(c))
            {
                if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u')
                {
                    contavogal += 1;
                }
                else
                {
                    contaconso++;
                }
            }
        }
    }
    cout << contalinha << " " << endl;
    cout << contacaractere << " " << endl;
    cout << contavogal << " " << endl;
    cout << contaconso << " " << endl;
}