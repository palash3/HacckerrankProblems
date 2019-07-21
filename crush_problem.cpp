#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void printVector(vector< long long> t){
    int i=0;
    for (;i<t.size();i++){
        cout<<t[i]<<"\t";
    }
    cout<<endl;
}

// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {
    vector< long long> arr(n,0); // intializing vector to zero
    int query_len = queries.size();
    int i=0;
    long long max_val= 0;
    while(i<query_len){
        long long begin = queries[i][0];
        long long end = queries[i][1];
        long long value = queries[i][2];
        //Unoptimized code
        // cout<<begin<<"\t"<<end<<"\t"<<value;
        // int j=0;
        // for (j=begin-1;j<end;j++){
        //     arr[j]+=value;
        //     if(arr[j]>max_val){
        //         max_val=arr[j];
        //     }
        // }
        // printVector(arr);
        //***************/
        //Optimized Code
        arr[begin-1]+=value;
        if(end < n){
            arr[end]+= (-1 * value);
        }
        i++;
    }
    printVector(arr);
    int j=0;
    long long sum=0;
    for(;j<arr.size();j++){
        sum+=arr[j];
        if(max_val < sum){
            max_val = sum;
        }
    }
    return max_val;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
