#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;



int main()
{
    string init_text;
    int n;

    cin>>n;
    cin>>init_text;
    string newinput=init_text;

    int tab[n][n];


    char ch = '1';

    int m = count(init_text.begin(), init_text.end(), ch);

    int edge_tab [m/2][2];

    int counter=0;
    string check="";
        for (int i = 0; i < n; i++) {
            cout<<"Wiersz nr "<<i<<" ";
            for(int j=0;j<n;j++){

                int num=newinput.at(j)-48;
                tab[i][j]=num;
                cout<<tab[i][j]<<" ";
                if(tab[i][j]==1){
                    if(j>i){
                        string temp2=to_string(i)+" "+to_string(j)+",";

                        if (check.find(temp2) != string::npos) {
                        }
                        else{
                        edge_tab[counter][0]=i;
                        edge_tab[counter][1]=j;
                        check=check+temp2;
                        counter=counter+1;

                        }
                    }
                    else{
                        string temp2=to_string(j)+" "+to_string(i)+",";

                        if (check.find(temp2) != string::npos) {
                        }
                        else{
                        edge_tab[counter][0]=j;
                        edge_tab[counter][1]=i;
                        check=check+temp2;
                        counter=counter+1;

                        }

                    }
                }

                if(j==n-1){
                    newinput=newinput.substr(j+1);

                }

            }
            cout<<endl;

    }

    cout<<"sprawdzamy vector"<<endl;

    for(int i=0;i<m/2;i++){

        cout<<edge_tab[i][0]<<" "<<edge_tab[i][1]<<endl;
    }

    cout<<"========================================="<<endl;

    cout<<check<<endl;






    return 0;
}
