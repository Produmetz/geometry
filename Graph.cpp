#include <graphics.h>
#include <iostream>
#include <fstream>
#include <string> 
#include <cmath>
#include <vector>

using namespace std;


vector <vector <double>> matricesMultiplication(vector <vector <double>> m1,vector <vector <double>> m2)
{
	int h1=m1.size(),w1=m1[0].size(),h2=m2.size(),w2=m2[0].size();
	if(w1==h2)
	{
		vector <vector <double>> result(h1,vector <double>(w2,0.0));
		for(int i=0;i<h1;i++)
		{
			for(int j=0;j<w2;j++)
			{	
				for(int k=0;k<h2;k++)
				{	
					result[i][j]+=m1[i][k]*m2[k][j];
					//cout<<m1[i][k]<<" "<<m2[k][j]<<" "<<result[i][j];	cout<<endl;
				}
				//cout<<" "<<endl;
				cout<<result[i][j]<<" ";
			}
			cout<<" "<<endl;
		}
		cout<<endl;
		return result;
	}
	//vector <vector <double>> result();
}



vector <vector <double>> rotationIn4d(double angle1,double angle2,double angle3,double angle4,double angle5,double angle6)
{
	vector<vector<double>> matrixRotXY={
	{cos(angle1),-sin(angle1),0,0},
	{sin(angle1),cos(angle1),0,0},
	{0,0,1,0},
	{0,0,0,1}
	};
	vector<vector<double>> matrixRotXZ={
	{cos(angle2),0,-sin(angle2),0},
	{0,1,0,0},
	{sin(angle2),0,cos(angle2),0},
	{0,0,0,1}
	};
	vector<vector<double>> matrixRotXW={
	{cos(angle3),0,0,-sin(angle3)},
	{0,1,0,0},
	{0,0,1,0},
	{sin(angle3),0,0,cos(angle3)}
	};
	vector<vector<double>> matrixRotYZ={
	{1,0,0,0},
	{0,cos(angle4),-sin(angle4),0},
	{0,sin(angle4),cos(angle4),0},
	{0,0,0,1}
	};
	vector<vector<double>> matrixRotYW={
	{1,0,0,0},
	{0,cos(angle5),0,-sin(angle5)},
	{0,0,1,0},
	{0,sin(angle5),0,cos(angle5)}
	};
	vector<vector<double>> matrixRotZW={
	{1,0,0,0},
	{0,1,0,0},
	{0,0,cos(angle6),-sin(angle6)},
	{0,0,sin(angle6),cos(angle6)}
	};
	vector< vector <double>> orts4D_in3D={
		{1,1,1},
		{-1,1,-1},
		{1,-1,-1},
		{-1,-1,1}
	};
	//matricesMultiplication(matrixRotXZ,matrixRotXY)
	//matricesMultiplication(matrixRotZW,matricesMultiplication(matrixRotYW,matricesMultiplication(matrixRotYZ,matricesMultiplication(matrixRotXW,matricesMultiplication(matrixRotXZ,matrixRotXY)))));
	//matricesMultiplication(matrixRotZW,matricesMultiplication(matrixRotYW,matricesMultiplication(matrixRotYZ,matricesMultiplication(matrixRotXW,matricesMultiplication(matrixRotXZ,matrixRotXY)))))
	 return matricesMultiplication(matricesMultiplication(matrixRotZW,matricesMultiplication(matrixRotYW,matricesMultiplication(matrixRotYZ,matricesMultiplication(matrixRotXW,matricesMultiplication(matrixRotXZ,matrixRotXY))))),orts4D_in3D);
}
vector <vector <double>> rotationIn3d(double angle1,double angle2,double angle3)
{
	vector<vector<double>> matrixRotXY={
	{cos(angle1),-sin(angle1),0},
	{sin(angle1),cos(angle1),0},
	{0,0,1}
	};
	vector<vector<double>> matrixRotXZ={
	{cos(angle2),0,-sin(angle2)},
	{0,1,0},
	{sin(angle2),0,cos(angle2)}
	
	};
	
	vector<vector<double>> matrixRotYZ={
	{1,0,0},
	{0,cos(angle3),-sin(angle3)},
	{0,sin(angle3),cos(angle3)}
	};
	
	vector< vector <double>> orts3D_in2D={
		{cos(-M_PI/6),sin((-M_PI/6))},
		{cos(M_PI/2),sin(M_PI/2)},
		{cos(7*M_PI/6),sin(7*M_PI/6)}
	};
	//matricesMultiplication(matrixRotXZ,matrixRotXY)
	//matricesMultiplication(matrixRotZW,matricesMultiplication(matrixRotYW,matricesMultiplication(matrixRotYZ,matricesMultiplication(matrixRotXW,matricesMultiplication(matrixRotXZ,matrixRotXY)))));
	//matricesMultiplication(matrixRotZW,matricesMultiplication(matrixRotYW,matricesMultiplication(matrixRotYZ,matricesMultiplication(matrixRotXW,matricesMultiplication(matrixRotXZ,matrixRotXY)))))
	return matricesMultiplication(matricesMultiplication(matrixRotYZ,matricesMultiplication(matrixRotXZ,matrixRotXY)),orts3D_in2D);
}
/*int waitclick(int *x1, int *y1, int *x2, int *y2) {
  int b;
  while((b=mousebuttons())==0) { // ждем нажатия кнопки
     if(kbhit()) return 0; // если нажата клавиша - выйти
  }
  *x1=mousex();
  *y1=mousey();
  while(mousebuttons()==0); // ждем отпускания кнопки
  *x2=mousex();
  *y2=mousey();
  return b;
}
// вызов
int b,x1,y1,x2,y2;
b=waitclick(&x1,&y1,&x2,&y2);
if(b==1) { 
 
}*/
	
int main() {
	vector< vector <double>> coor4D={
		{1,1,1,1}
	
	};
	double fi=0;
	int h=1080,w=1080;
	//cout<<mousex()<<" "<<mousey();
	//initwindow(w,h,"My Graph");

	rotationIn4d(2,0,0,0,0,0);
	//matricesMultiplication(coor4D,rotationIn4d(2,4,0,1,0,0));
	//vector< vector <double>> arr=matricesMultiplication(coor4D,rotationIn4d(2,4,0,1,0,0));
	//vector<vector<double>> coor2D=matricesMultiplication(arr,rotationIn3d(0,fi,0));
	//putpixel(300+coor2D[0][0],300-coor2D[0][1],255);
	/*while(fi<2*M_PI){
		coor2D=matricesMultiplication(arr,rotationIn3d(0,fi,0));
		putpixel(w/2+coor2D[0][0],h/2-coor2D[0][1],255);
		cout<<mousex()<<" "<<mousey();
		fi+=0.025;
	}*/
	getch();  
	//closegraph(); 
    return 0;
}