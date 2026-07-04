/*#include<iostream>
#define Max 500
using namespace std;


int arr[Max];
int brr[Max];
int ans[Max];
int a = 0, b = 0;
void reverse(int arr[], int n)
{
	int i = 0, j = n - 1;
	while (i < j)
	{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i++;
		j--;
	}
}

void Add(int *arr,int *brr)
{

	reverse(arr, a);
	reverse(brr, b);
	int k = 0, carry = 0;
	while (k < a || k < b || carry)
	{
		int sum = carry;
		if (k < a) sum += arr[k];
		if (k < b) sum += brr[k];
		ans[k] = sum % 10;
		carry = sum / 10;
		k++;
	}
	reverse(ans, k);
	for (int l = 0; l < k; l++)
	{
		cout << ans[l];
	}
	cout << endl;
}
int main()
{
	char c = 0;
	while ((c = getchar()) != '\n' && a<Max)
	{
		arr[a] = c - '0';
		a++;
	}
	while ((c = getchar()) != '\n' && b<Max)
	{
		brr[b] = c - '0';
		b++;
	}
	Add(arr, brr);
	return 0;
}
*/
/*
#include<iostream>
 #include<string>
 int A[10000],B[10000];
 int C[10000];
 using namespace std;
 
 void add(int* sz)
 {
     for(int i = 0;i<*sz;i++){
         C[i] += (A[i]+B[i]);
         C[i+1] = C[i]/10;
         C[i]%=10;
     }
     if(C[*sz]) (*sz)++;
 }
 int main(){
     string a,b;
     cin>>a>>b;
     for(int i = a.size()-1;i>=0;i--) A[a.size()-1-i] = a[i]-'0';
     for(int i = b.size()-1;i>=0;i--) B[b.size()-1-i] = b[i]-'0';
     int szc = max(a.size(),b.size());
     add(&szc);
     for(int i = szc-1;i>=0;i--){
         cout<<C[i];
     }
     }
*/
/*
#include<iostream>
 #include<string>
 int A[10000],B[10000];
 using namespace std;
 
 void add(int* sz)
 {
     for(int i = 0;i<*sz;i++){
         B[i+1] += (A[i]+B[i])/10;
         B[i] = (A[i]+B[i])%10;
     }
     if(B[*sz]) (*sz)++;
 }
 int main(){
     string a,b;
     cin>>a>>b;
     for(int i = a.size()-1;i>=0;i--) A[a.size()-1-i] = a[i]-'0';
     for(int i = b.size()-1;i>=0;i--) B[b.size()-1-i] = b[i]-'0';
     int sz = max(a.size(),b.size());
     add(&sz);
     for(int i = sz-1;i>=0;i--){
         cout<<B[i];
     }
 }
 */
/*
#include<iostream>
using namespace std;
int A[500],B[500];
int lenans;
void Add(string x,string y){
    for(int i  = x.size()-1;~i;i--)   A[x.size()-i-1] = x[i]-'0';
    for(int i  = y.size()-1;~i;i--)   B[y.size()-i-1] = y[i]-'0';
    lenans = max(x.size(),y.size());
    for(int i = 0;i<lenans;i++)
    {
        A[i] += B[i];
        A[i+1] += A[i] / 10;
        A[i] %= 10;
        if(A[lenans]||B[lenans])   lenans++;
    }
}
int main(){
    string a,b;
    cin>>a>>b;
    Add(a,b);
    for(int i = lenans-1;~i;i--){
        cout<<A[i];
    }
    return 0;
}
*/
#include<iostream>
#include<vector>
using namespace std;
typedef vector<int> VI;
VI A,B;
void Add(string x,string y){
    int t = 0;
    for(int i  = x.size()-1;~i;i--)   A.push_back(x[i]-'0');
    for(int i  = y.size()-1;~i;i--)   B.push_back(y[i]-'0');
    int i = 0;
    for(i = 0;i<A.size();i++)
    {
        A[i] += B[i];
        A[i+1]+= A[i]/10;
        if(i == A.size()-1&&A[i]/10)   A.push_back(A[i]/10);
        A[i] %= 10;
    }
    for(;i<B.size();i++){
        A.push_back(B[i]);
    } 
}
int main(){
    string a,b;
    cin>>a>>b;
    Add(a,b);
    for(int i = A.size()-1;~i;i--){
        cout<<A[i];
    }
    return 0;
}