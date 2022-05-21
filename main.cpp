#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int count_banans(int * edge_tab,int s){
     int output=0;

     for(int i=0;i<s;i++){
        int temp=edge_tab[i];
        int counter=0;
        for(int j=0;j<s;j++){
            if(temp==edge_tab[j]) counter=counter+1;
        }
        if(counter==1) output=output+1;


     }
     cout<<"mamy "<<output<<" bananow";
return 0;

}

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

    int edge_tab [m];

    int counter=1;
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
                        edge_tab[counter-1]=i;
                        edge_tab[counter]=j;
                        check=check+temp2;
                        counter=counter+2;

                        }
                    }
                    else{
                        string temp2=to_string(j)+" "+to_string(i)+",";

                        if (check.find(temp2) != string::npos) {
                        }
                        else{
                        edge_tab[counter-1]=j;
                        edge_tab[counter]=i;
                        check=check+temp2;
                        counter=counter+2;

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

    for(int i=1;i<=m;i++){

        cout<<edge_tab[i-1]<<" "<<edge_tab[i]<<endl;
        i++;
    }

    cout<<"========================================="<<endl;


    count_banans(edge_tab,m);




    return 0;
}
