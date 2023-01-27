#include <iostream>
#include <vector>


#define for_md(type,name_index,initial_index,final_index,increment) for(vector<type> name_index = initial_index;exit_condition(name_index,final_index);name_index=index_increment(name_index,initial_index,final_index,increment))

using namespace std;

bool exit_condition(vector<int>i,vector<int>condition)
{

    for(int j=0;j<i.size();j++){
        if(i[j]<condition[j]){
            return true;
        }else{
            if(j==0){
                return false;
            }else{
                return true;
            }
        }
    }
}
vector<int> index_increment(vector<int>i,vector<int>initial_index,vector<int>final_index,vector<int> increment)
{
    vector<int> result=i;
    int last=i.size()-1;

    result[last]+=increment[last];
    for(int j=last;j>-1;j--){
        if(result[j]<final_index[j]){
            return result;
        }else if(j!=0){
            result[j]=initial_index[j];
            result[j-1]+=increment[j-1];
        }else{
            return result;
        }
    }

}

int main(int argc, char** argv) {

    vector<int>final_index,increment,initial_index;
    initial_index={-1,-1,-1};
    final_index={2,2,2},increment={1,1,1};
    for_md(int,index,initial_index,final_index,increment)
    // the initial value of the variable "index"
    //this cycle is working while index[0]<final_index[0] and index[1]<final_index[1] and index[2]<final_index[2]
    //  index[i] changes in increments of increment[i]
    {
        cout<<index[0]<<" "<<index[1]<<" "<<index[2]<<endl;
	  }
    /*
        equivalent
        for(vector<int>i=starti;exit_condition(i,condition);i=index_increment(i,condition,increment,starti))
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
    */
    /*
        result in console this sample
        -1 -1 -1
        -1 -1 0
        -1 -1 1
        -1 0 -1
        -1 0 0
        -1 0 1
        -1 1 -1
        -1 1 0
        -1 1 1
        0 -1 -1
        0 -1 0
        0 -1 1
        0 0 -1
        0 0 0
        0 0 1
        0 1 -1
        0 1 0
        0 1 1
        1 -1 -1
        1 -1 0
        1 -1 1
        1 0 -1
        1 0 0
        1 0 1
        1 1 -1
        1 1 0
        1 1 1
    */
    return 0;
}
