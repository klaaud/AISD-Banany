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
return output;

}
int count_banans_single(int * edge_tab,int s,int num){
     int output=0;


        for(int j=0;j<s;j++){
            if(num==edge_tab[j]) output=output+1;
        }

return output;

}


struct graphEdge {
    int ver, weight;

};
struct Edge{
  int x;
  int x_lvl;
  int y;
  int y_lvl;
};

bool is_banan_tree(int * edge_tab2,int s2, int counted_bananas){
    bool output=true;
    // tutaj wyznaczamy tablice z wierzcho³kami ktore moga byc bananami
    int * bananas=new int[counted_bananas];
    int counter_b=0;

    for(int i=0;i<=s2/2;i++){
        if(count_banans_single(edge_tab2,s2,i)==1){
            bananas[counter_b]=i;
            counter_b=counter_b+1;
        }
    }





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
                points_arr[i][1]=s2;

        }


    }

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


    string * points_array=new string [s2];

       for(int i=0;i<s2;i++){

        points_array[i]=to_string(points_arr[i][0])+"-"+to_string(points_arr[i][1]);

       }
       vector<string> points_vec;



        for(int i=0;i<s2;i++){
        points_vec.push_back(points_array[i]);
       }
        sort(points_vec.begin(),points_vec.end());
        points_vec.erase(unique(points_vec.begin(),points_vec.end()),points_vec.end());

        int new_size=points_vec.size();
        graphEdge * graphEdge_arr =new graphEdge[new_size];

        for(int i=0;i<new_size;i++){
            string str=points_vec[i];
            size_t pos = str.find("-");
            graphEdge_arr[i].ver=stoi(str.substr(0,pos));
            graphEdge_arr[i].weight=stoi(str.substr(pos+1));
        }


        //wyznaczam root
         int root=0;
         int idx=0;
        for(int i=0;i<new_size;i++){
            if(graphEdge_arr[i].weight>root){
                root=graphEdge_arr[i].weight;
                idx=i;
            }

        }

        int root_point=graphEdge_arr[idx].ver;

        int root_point_count=0;

        for(int i=0;i<new_size;i++){
            if(graphEdge_arr[i].weight==graphEdge_arr[idx].weight){
                    root_point_count=root_point_count+1;
        }

        }

        if(root_point_count==1){

        //"droga" dla pierwszego banana do root
        int route=0;

        Edge * edges =new Edge[s2/2];
        int itr=0;
        for(int i=0;i<s2;i++){
            edges[itr].x=edge_tab2[i];
            for(int j=0;j<new_size;j++){
                if(edges[itr].x==graphEdge_arr[j].ver) edges[itr].x_lvl=graphEdge_arr[j].weight;
            }


            edges[itr].y=edge_tab2[i+1];
            for(int j=0;j<new_size;j++){
                if(edges[itr].y==graphEdge_arr[j].ver) edges[itr].y_lvl=graphEdge_arr[j].weight;
            }


            i++;
            itr++;

        }


        for(int k=0;k<counted_bananas;k++){
            int connector=bananas[k];
            int route_counter=0;
            int max_itr=graphEdge_arr[idx].weight;
            while(max_itr>0){
                for(int i=0;i<s2/2;i++){
                    if(edges[i].x==connector && edges[i].y_lvl>route_counter) {connector=edges[i].y;route_counter=edges[i].y_lvl;}

                    else if (edges[i].y==connector && edges[i].x_lvl>route_counter)  {connector=edges[i].x;route_counter=edges[i].x_lvl;}

                }
                max_itr--;
            }

            if(route_counter==graphEdge_arr[idx].weight) {output=true;}
            else {output=false;break;}
        }

        bool is_banana;
        int bananas_parents=0;


        for(int i=0;i<s2/2;i++){
           if(graphEdge_arr[idx].weight!=1){
            if(edges[i].x_lvl==1 && edges[i].y_lvl==2) bananas_parents=bananas_parents+1;
            else if (edges[i].y_lvl==1 && edges[i].x_lvl==2) bananas_parents=bananas_parents+1;
           }
           else{
            if(edges[i].x_lvl==1 && edges[i].y_lvl==0) bananas_parents=bananas_parents+1;
            else if (edges[i].y_lvl==1 && edges[i].x_lvl==0) bananas_parents=bananas_parents+1;
           }

        }




            if(counted_bananas%bananas_parents==0 && output) is_banana=true;

            else is_banana=false;


        return is_banana;

        }
    else{
        return false;
    }
}


    struct Data{
        int x;
        string text;

    };
int main()
{

    int lines;
    cin>>lines;
    Data * data=new Data[lines];
    for(int i=0;i<lines;i++){
        int x_temp;
        string text_temp;
        cin>>x_temp;
        cin>>text_temp;

        data[i].x=x_temp;
        data[i].text=text_temp;

    }

 for(int i=0;i<lines;i++){
    string init_text=data[i].text;
    string newinput=data[i].text;
    int n=data[i].x;
    int ** tab=new int *[n];

    for(int s = 0; s < n; ++s){
        tab[s] = new int[n];
    }
    char ch = '1';

    int m = count(init_text.begin(), init_text.end(), ch);

    int * edge_tab=new int[m];

    int counter=1;
    string check="";
        for (int l= 0; l < n; l++) {
            for(int j=0;j<n;j++){

                int num=newinput.at(j)-48;
                tab[l][j]=num;
                if(tab[l][j]==1){
                    if(j>l){
                        string temp2=to_string(l)+" "+to_string(j)+",";

                        if (check.find(temp2) != string::npos) {
                        }
                        else{
                        edge_tab[counter-1]=l;
                        edge_tab[counter]=j;
                        check=check+temp2;
                        counter=counter+2;

                        }
                    }
                    else{
                        string temp2=to_string(j)+" "+to_string(l)+",";

                        if (check.find(temp2) != string::npos) {
                        }
                        else{
                        edge_tab[counter-1]=j;
                        edge_tab[counter]=l;
                        check=check+temp2;
                        counter=counter+2;

                        }

                    }
                }

                if(j==n-1){
                    newinput=newinput.substr(j+1);

                }

            }

    }




    int bananas=count_banans(edge_tab,m);
if(n>2){
    if(is_banan_tree(edge_tab,m,bananas)){
         cout<<bananas<<" bananas :)"<<endl;
         }
    else{
        cout<<"0 bananas :("<<endl;

    }
}
else{
    cout<<bananas<<" bananas :)"<<endl;
}



 }

    return 0;
}
