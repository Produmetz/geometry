#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


vector <vector <double>> matricesMultiplication(vector <vector <double>> m1,vector <vector <double>> m2)
{
	int h1=m1.size(),w1=m1[0].size(),h2=m2.size(),w2=m2[0].size();
	if(w1==h2)
	{
		vector <vector <double>> result(h1,vector <double>(w2,0));
		for(int i=0;i<h1;i++)
		{
			for(int j=0;j<w2;j++)
			{	
				for(int k=0;k<h2;k++)
				{	
					result[i][j]+=m1[i][k]*m2[k][j];	
				}
				//cout<<result[i][j]<<" ";
			}
			//cout<<endl;
		}
		return result;
	}
	//vector <vector <double>> result();
}


vector <vector <double>> matrixRotation(int dimension,vector <double> angles)
{
	vector <vector <double>> result(dimension,vector <double>(dimension,0));
	vector <vector <double>> data(dimension,vector <double>(dimension,0));
	
	int n=(dimension*(dimension-1)/2),p=0;
		for(int j=0;j<dimension;j++)
			{
			for(int k=0;k<dimension;k++)
				{	
					if(j==k){
						result[j][k]=1;
								
					}
					//cout<<result[j][k]<<" ";
				}
				//cout<<endl;
			}
	for(int i=0;i<dimension;i++)
		{
		for(int l=i+1;l<dimension;l++)
			{
			//cout<<i<<" "<<l<<" "<<endl;
			for(int j=0;j<dimension;j++)
				{
				for(int k=0;k<dimension;k++)
					{	
						if(j==k){
							if((j==i)||(k==l)){
								data[j][k]=cos(angles[p]);
							}else{
								data[j][k]=1;
							}
						}else if((j==i)&&(k==l)){
							data[i][l]=-sin(angles[p]);
						}else if((j==l)&&(k==i)){
							data[l][i]=sin(angles[p]);
						}else{
							data[j][k]=0;
						}
					}
				}
				//cout<<p<<endl;
				p++;
				result=matricesMultiplication(result,data);
			/*	for(int j=0;j<dimension;j++)
				{
					for(int k=0;k<dimension;k++)
					{	
						//cout<<data[j][k]<<" ";
						cout<<result[j][k]<<" ";
								
					}
					cout<<endl;
					//cout<<result[j][k]<<" ";
				}
				//cout<<endl;
			*/
				data.resize(dimension,vector <double>(dimension,0));
			}
		}
	return result;
}



int main() {
	
	int n=3;
	vector <vector <double>> arr2={
		{1,0,0,0}
	};
	vector <double> angles={0,0,0};
	vector <vector <double>> arr1=matrixRotation(n,angles);
	for(int j=0;j<n;j++)
	{
		for(int k=0;k<n;k++)
		{	
				cout<<arr1[j][k]<<" ";			
		}
		cout<<endl;
	}
	
	//matricesMultiplication(matricesMultiplication2(arr2,arr1),arr1);
	/*Matrix matrix1(4,4);
	Matrix matrix2(1,4);
	//Matrix matrix3(1,4);
	matrix1.inputMatrix(arr1);
	matrix2.inputMatrix(arr2);
	matrix1.print();
	cout<<endl;
	matrix2.print();
	cout<<endl;
	matricesMultiplication(matrix2,matrix1);*/
//	matricesMultiplication(matrix1,matricesMultiplication(matrix1,matrix2));

	
    return 0;
}