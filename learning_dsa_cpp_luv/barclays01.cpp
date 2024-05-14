// Header Files
#include<iostream>
#include<string>
#include<vector>
using namespace std;


/*
 * 
 */
vector<int> commonFootsteps (int fatherPos, int martinPos, int velFather, int steps)  //jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj
{
    vector<int>  answer;
    // Write your code here
    int fs[100];
	fs[0] = fatherPos;
	for (long long int i=1; i<=steps ; i++){
       fs[i] = fs[i-1] + velFather;
	}
	long long int c,h = fatherPos + (velFather*steps),f,max,v2,l=0;
    for (long long int j=1; j<=velFather*steps; j++){
		c = martinPos; f=0; max=0;
       for(long long int i=0; c<= h; ){
		   if(c == fs[i]){
			   f++;
			   c = c + j;
			   i++;
		   }
		   else if(c < fs[i]){
			   c = c+ j;
		   }
		   else{
			   i++;
		   }
	   }
        if (f>= l){
          v2 = j;
		  max = f;
		  l =max;
		}
	}
	answer.push_back(l);
	answer.push_back(v2);
    return answer;
}

int main()
{
    //input for fatherPos
	int fatherPos;
	cin >> fatherPos;
	
	//input for martinPos
	int martinPos;
	cin >> martinPos;
	
	//input for velFather
	int velFather;
	cin >> velFather;
	
	//input for steps
	int steps;
	cin >> steps;
	
	
    //output
	vector<int> result = commonFootsteps(fatherPos, martinPos, velFather, steps);
	for ( int idx = 0; idx < result.size() - 1; idx++ )
	{
		cout << result[idx] << " ";
	}
	cout << result[result.size() - 1];
	
    return 0;
}