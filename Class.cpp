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
			}
			
		}
		return result;
	}
	
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
				}
			}
	for(int i=0;i<dimension;i++)
		{
		for(int l=i+1;l<dimension;l++)
			{
			
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
				
				p++;
				result=matricesMultiplication(result,data);
			
				data.resize(dimension,vector <double>(dimension,0));
			}
		}
	return result;
}
