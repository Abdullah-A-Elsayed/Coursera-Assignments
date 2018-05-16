#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

ull hash_str(string s){//let x = 263, p 1000000007, no m, so card=p
    ull hash=0;
    for(int i=s.length()-1; i>-1; i--)
        hash = ((hash*263)+ s[i] )%1000000007;
    return hash;
}

Data read_input() {
    Data data;
    cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const vector<int>& output) {
    for (int i = output.size()-1; i >-1; --i)
        cout << output[i] << " ";
    cout << "\n";
}

vector<int> get_occurrences_naive(const Data& input) {
    const string& s = input.pattern, t = input.text;
    vector<int> ans;
    for (size_t i = 0; i + s.size() <= t.size(); ++i)
        if (t.substr(i, s.size()) == s)
            ans.push_back(i);
    return ans;
}

vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    vector<int> ans;
    ull s_hash = hash_str(s);
    ull T_hash = hash_str(t.substr(t.length()-s.length()));
    //h(i) = h(i+1)x+ int(t(i)) - x^p * int(t(i+|p|))
    //x^p
    ull p =1000000007;
    int x = 263;
    ull x_to_p = x;

    for(int i=0;  i<s.length()-1; ++i) x_to_p= (x_to_p * x) %p;
    //cout<<"x^p = "<<x_to_p<<endl;
    //cout<<t.substr(t.length()-s.length())<<" hash: "<<T_hash<<endl;

    for (int i = t.length()-s.length(); i>-1 ; --i){
        if(s_hash == T_hash){
            if (t.substr(i, s.size()) == s)
            ans.push_back(i);
        }
        //cout<<t.substr(i, s.size())<<" hash1: "<<hash_str(t.substr(i, s.size()))<<endl;
        //cout<<t.substr(i, s.size())<<" hash2: "<<T_hash<<endl<<endl;

        if(i!=0){
            T_hash =(  (T_hash * x) + t[i-1] - (x_to_p * t[i-1+s.size()])%p +p ) %p;
        }
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
