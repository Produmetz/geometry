#include <vector>
using namespace std;

void printVector(vector<int> vector){
	cout<<"{";
	for(int i=0;i<vector.size();i++){
		cout<<vector[i];
		if(i!=vector.size()-1){cout<<",";};
	}
	cout<<"}";
}



class MultiVector
{
	public:
		vector<int> type;
		bool minus;
		double value;
	MultiVector() 
    {
        minus=false;value = 0; type = {};
    }
	MultiVector(double value_, vector<int>type_) 
    {
        minus=false;value = value_; type = type_;
    }
    void RemoveMinus(){
		if(minus){value=(-1)*value;minus= !minus;};
	}
    void TypeSimplification(){
    	auto iter = type.cbegin();
		int len=type.size();
		for(int i=0;i<len;i++){
			for(int j=i+1;j<len;j++){
				if(type[i]==type[j]){
					if((j-i)%2==0){
						minus= !minus;
					}
					type.erase(iter+i);
					type.erase(iter+j-1);
					len=type.size();
				//iter = vector.cbegin();
					i--;
				}
				//cout<<i<<" "<<j<<endl;
			}
		}
		RemoveMinus();
	}
	void PrintConsole(){
		RemoveMinus();
		cout<<" "<<value<<" ";
		printVector(type);
	}
	MultiVector operator = (MultiVector v2)
    {
        value = v2.value;
        type =v2.type;
        minus=v2.minus;
        return *this;
    }
    MultiVector operator += (MultiVector v2)
    {
    	RemoveMinus();v2.RemoveMinus();
        value =value + v2.value;
        return *this;
    }
    MultiVector operator -= (MultiVector v2)
    {
    	RemoveMinus();v2.RemoveMinus();
        value =value - v2.value;
        return *this;
    }
    
	
};
vector<bool> TypeComparisonVector1andVector2(MultiVector vector1,MultiVector vector2){
	vector<bool> result;
	if(vector1.type.size()==vector2.type.size()){
		int len=vector1.type.size();
		int inter;
		for(int i=0;i<len;i++){
			for(int j=i;j<len;j++){
				if(vector1.type[i]==vector2.type[j]){
					if((j-i)%2==0){
						vector2.minus= !vector2.minus;
					}
					inter=vector2.type[i];
					vector2.type[i]=vector2.type[j];
					vector2.type[j]=inter;
					//iter = vector.cbegin();	
				}
				//cout<<i<<" "<<j<<endl;
			}
		}
		//if(vector2.minus){vector2.value=(-1)*vector2.value;vector2.minus= !vector2.minus;};
		if(vector1.type==vector2.type){
			result={true,vector2.minus};	
			return result;
		}else{
			result={false,vector2.minus};	
			return result;
		}
		
	}else{
		result={false,vector2.minus};
		return result;
	}
}

MultiVector operator *(MultiVector v1,MultiVector v2){
	vector<int> newType=v1.type;
	v1.RemoveMinus();v2.RemoveMinus();
	for(int i=0;i<v2.type.size();i++){
		newType.push_back(v2.type[i]);
	}
	MultiVector result(v1.value*v2.value,newType);
	result.TypeSimplification();
	return result;
}

class VectorOfMultiVector
{
	public:
		vector<MultiVector>MultiVectors;
		
	VectorOfMultiVector() 
    {
       
    }
	VectorOfMultiVector(vector<MultiVector>_MultiVectors) 
    {
        MultiVectors=_MultiVectors;
    }
    void VectorSimplification(){
		int k=0;
		vector<MultiVector> result;
		int len=MultiVectors.size();
		auto iter = MultiVectors.cbegin();
		for(int i=0;i<len;i++){
			k++;result.resize(k);result[i]=MultiVectors[i];
			for(int j=i+1;j<len;j++){
				vector<bool>Parametr=TypeComparisonVector1andVector2(result[i],MultiVectors[j]);
				if(MultiVectors[i].type==MultiVectors[j].type){
					result[k-1].value=result[i].value+MultiVectors[j].value;
					MultiVectors.erase(iter+j);	
					j--;
				
				}else if(Parametr[0]){
					if(Parametr[1]){
						result[k-1].value=result[k-1].value - MultiVectors[j].value;
					}else{
						result[k-1].value=result[k-1].value + MultiVectors[j].value;
					}
					
					MultiVectors.erase(iter+j);	
					j--;
				}
			
			
				len=MultiVectors.size();
			//cout<<i<<" "<<j<<" "<<" "<<len<<" "<<k<<" "<<endl;
			//cout<<" "<<k<<" "<<endl;
				result.resize(len);
				iter = MultiVectors.cbegin();
			//res[i].PrintConsole();
			}
			//	cout<<endl;
		}
		result.resize(k);
		MultiVectors=result;
	}
	
	void PrintConsole(){
		for(int i=0;i<MultiVectors.size();i++){
			MultiVectors[i].PrintConsole();
			cout<<" ";
		}
		cout<<endl;	
	}
	
	VectorOfMultiVector operator = (VectorOfMultiVector v2)
    {
        MultiVectors=v2.MultiVectors;
        return *this;
    }
    VectorOfMultiVector operator += (VectorOfMultiVector v2)
    {
    	for(int i=0;i<v2.MultiVectors.size();i++){
    		MultiVectors.push_back(v2.MultiVectors[i]);
		}
		VectorSimplification();
        return *this;
    }
    VectorOfMultiVector operator -= (VectorOfMultiVector v2)
    {
    	for(int i=0;i<v2.MultiVectors.size();i++){
    		v2.MultiVectors[i].minus=!v2.MultiVectors[i].minus;
    		MultiVectors.push_back(v2.MultiVectors[i]);
		}
		VectorSimplification();
        return *this;
    }
    
	
};
VectorOfMultiVector operator +(VectorOfMultiVector v1,VectorOfMultiVector v2){
	
	
	for(int i=0;i<v2.MultiVectors.size();i++){
		v1.MultiVectors.push_back(v2.MultiVectors[i]);
	}
	VectorOfMultiVector result(v1.MultiVectors);
	result.VectorSimplification();
	return result;
}
VectorOfMultiVector operator -(VectorOfMultiVector v1,VectorOfMultiVector v2){
	
	
	for(int i=0;i<v2.MultiVectors.size();i++){
		v2.MultiVectors[i].minus=!v2.MultiVectors[i].minus;
		v2.MultiVectors[i].RemoveMinus();
		v1.MultiVectors.push_back(v2.MultiVectors[i]);
	}
	VectorOfMultiVector result(v1.MultiVectors);
	result.VectorSimplification();
	return result;
}
VectorOfMultiVector operator *(VectorOfMultiVector v1,VectorOfMultiVector v2){
	
	VectorOfMultiVector result;
	result.MultiVectors.resize(v1.MultiVectors.size()*v2.MultiVectors.size());
	for(int i=0;i<v1.MultiVectors.size()*v2.MultiVectors.size();i++){
		result.MultiVectors[i]=v1.MultiVectors[i/v2.MultiVectors.size()]*v2.MultiVectors[i%v2.MultiVectors.size()];
	}
	result.VectorSimplification();
	
	return result;
}
