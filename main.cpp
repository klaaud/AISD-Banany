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
return output;

}
int count_banans_single(int * edge_tab,int s,int num){
     int output=0;


        for(int j=0;j<s;j++){
            if(num==edge_tab[j]) output=output+1;
        }

     cout<<"tutaj dla num "<<num<<"waga to "<<output<<endl;

return output;

}


struct graphEdge {
    int ver, weight;

};

void is_banan_tree(int * edge_tab2,int s2){


    int **points_arr = new int*[s2];
    for(int i = 0; i < s2; ++i) {
        points_arr[i] = new int[2];
    }

    for(int i=0;i<s2;i++){
        points_arr[i][0]=edge_tab2[i];

        if(count_banans_single(edge_tab2,s2,points_arr[i][0])==1){

            points_arr[i][1]=0;
        }
        else{
                points_arr[i][1]=5;

        }


    }
    cout<<"==================================="<<endl;


    int weight=0;


while(weight<s2/4){
    for(int i=0;i<s2;i++){

        if(points_arr[i][1]>weight){

            for(int j=0;j<s2;j++){

                if(points_arr[i][0]==edge_tab2[j])

                  if((j==0 || j%2==0) && points_arr[j+1][1]==weight){
                        points_arr[i][1]=weight+1;
                  }
                  else if((j==1 || j%2!=0) && points_arr[j-1][1]==weight){
                        points_arr[i][1]=weight+1;
                  }

            }


        }


    }

    weight=weight+1;
}


   for(int i=0;i<s2;i++){

        cout<<"tutaj printujemuy strcut"<<endl;

        cout<<points_arr[i][0]<<endl;
        cout<<points_arr[i][1]<<endl;



    }

    string * points_array=new string [s2];

       for(int i=0;i<s2;i++){

        cout<<"tutaj printujemuy strcut"<<endl;
        points_array[i]=to_string(points_arr[i][0])+"-"+to_string(points_arr[i][1]);

       }
       vector<string> points_vec;



        for(int i=0;i<s2;i++){
        points_vec.push_back(points_array[i]);
       }
        sort(points_vec.begin(),points_vec.end());
        points_vec.erase(unique(points_vec.begin(),points_vec.end()),points_vec.end());

        cout<<"VECTOR==========================="<<endl;

        for(int i=0;i<points_vec.size();i++){

            cout<<points_vec[i]<<endl;
        }
        int new_size=points_vec.size();
        graphEdge graphEdge_arr [new_size];

        for(int i=0;i<new_size;i++){
            string str=points_vec[i];
            size_t pos = str.find("-");
            graphEdge_arr[i].ver=stoi(str.substr(0,pos));
            graphEdge_arr[i].weight=stoi(str.substr(pos+1));
        }

        for(int i=0;i<new_size;i++){

            cout<<graphEdge_arr[i].ver<<" ";
            cout<<graphEdge_arr[i].weight<<endl;
        }
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
    is_banan_tree(edge_tab,m);



    return 0;
}
