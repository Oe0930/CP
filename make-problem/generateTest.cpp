#include<bits/stdc++.h>
#include"testlib.h"
using namespace std;
using ll = long long;

struct testcase{
    int n;
    vector<long long> A, B, C;
};

int main(int argc, char** argv)
{
    registerGen(argc,argv,1);
    auto output = [](ofstream& out, testcase test)
    {
        // test を出力する
        // out << test.N << endl;
        // out << test.S << endl;
        // など
        // out << と書くことに注意（ cout << ではない！ ）

        out << test.n << endl;
        for (int i = 0; i < test.n; i++)
        {
            out << test.A[i] << " " << test.B[i] << " " << test.C[i] << endl;
        }
    };

    int cnt = 0;

    // handmade, random などを作る
    auto random_gen = [&](ll number_of_testcases)
    {
        for (ll t = 1; t <= number_of_testcases; t++){
            // `-02` は 0 埋めして 2 桁にすることを表す
            // t = 1 だと "random-01.txt" になる
            // t = 22 だと "random-22.txt" になる
            // ofstream out(format("random-%02d.txt",t));
            // string s = rnd.next("[a-z]{1,100}");
            // int n = s.size();
            // testcase test({n,s});
            // output(out,test);

            if(t == 1)
            {
                ofstream out(format("max.txt"));

                int n = 1000000;
                vector<long long>   A(n, 1000000000),
                                    B(n, 1000000000),
                                    C(n, 1000000000);
                testcase test{n, A, B, C};
                output(out, test);
                continue;
            }

            ofstream out(format("random-%02d.txt", t-1));

            int n = rnd.next(1, 1000000);
            vector<long long> A(n), B(n), C(n);
            bool ans = false;

            bool expectedAns = rnd.next(0, 1);

            for(int i = 0; i < n; i++)
            {
                A[i] = rnd.next(1, 1000000000);
                B[i] = rnd.next(1, 1000000000);
                if(!expectedAns)
                {
                    C[i] = rnd.next((long long)1, min(B[i] + A[i] - 1, (long long)1000000000));
                }
                else
                {
                    C[i] = rnd.next(1, 1000000000);
                }

                if (C[i] - B[i] >= A[i])
                {
                    ans = true;
                }
            }
            testcase test{n, A, B, C};
            output(out, test);

            if(ans) cnt++;
        }
    };
    random_gen(20);

    cout << cnt << endl;
}