#include<bits/stdc++.h>
#define lli long long
using namespace std;

void insertionSort(vector<lli> &v, int n)
{
	int temp, j;
	for(int i=1;i<n;i++){
		temp = v[i];
		j=i-1;
		while(j>=0 && temp<v[j])
		{
			v[j+1]=v[j];

			j--;
		}
		v[j+1]=temp;
	}
}
lli sortandfindmedian(vector<lli> &v, int n){

	insertionSort(v, n);

	return v[((n-1)/2)];
}

int partition(vector<lli> &v, lli mom, int left, int right){
	int i;
	for(i=left; i<right;i++){
		if(v[i]==mom){
			break;
		}
	}
	swap(v[i],v[right]);

	i = left;
	for (int j=left;j<right;j++)
		{if (v[j] <= mom)
			{swap(v[i], v[j]);
				i++;
			}}
			swap(v[i], v[right]);
			return i;
		}


		lli findmedian(vector<lli> &v, int left, int right, int k){

			vector<lli> vt;

			if(k > 0 && k <= right - left + 1){
				int n = right-left+1;
				int it;
				vector<lli> medians;

				{int j=0;
					for(int i=left;i<right+1;i++){
						vt.push_back(v[i]);
						j++;
						if(j%5==0){
							medians.push_back(sortandfindmedian(vt,5));
							vt.clear();
						}
					}
					if(n%5!=0)
						medians.push_back(sortandfindmedian(vt,n%5));
					vt.clear();
				}
				int s = medians.size();
				lli mom;
				if(s==1) mom=medians[0];
				else mom = findmedian(medians, 0, s-1, (s+1)/2);

    
				int index = partition(v, mom,left, right);

				if(index-left == k-1) return v[index];
				if(index-left > k-1) return findmedian(v, left, index-1, k);
				if(index-left < k-1) return findmedian(v, index+1, right, k-index+left-1);
			}
			return 1234;
		}






		int main(){

			lli a,b;
			vector<lli> v;


			int t,n;
			cin>>t;
			while(t--){
				cin>>n;
				for(int i=0;i<n;i++){
					cin>>a>>b;
					v.push_back(a*a+b*b);
				}
				cout<<sqrt(findmedian(v, 0, n-1, (n+1)/2))<<endl;
				v.clear();
			}

		return 0;}
