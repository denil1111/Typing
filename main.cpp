//
//  main.cpp
//  srf
//
//  Created by zyhc on 14-3-12.
//  Copyright (c) 2014年 zyhc. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <sstream>
using namespace std;
struct qwpy{
    int q,w;
    string py;
}hz[10000];
int compare(struct qwpy a,struct qwpy b)
{
    int t;
    return a.py<b.py;
}
int main(int argc, const char * argv[])
{
    int n;
    string str;
    int qw;
    int i=0;
    string text;
    stringstream tex;
    ifstream ifile("ziku.txt");
    ofstream ofile("text.txt");
    while (ifile>>str>>qw)
    {
        i++;
        hz[i].q=qw /100;
        hz[i].w=qw %100;
        hz[i].py=str;
        //cout<<hz[i].py<<hz[i].q<<hz[i].w<<endl;
    }
    //cout<<i;
    int len=i;
    sort(hz,hz+i,compare);
    string inpy;
    int t;
    for (int i=0;i<80;i++)
    cout<<"-";
    cout<<endl; 
    cout<<"Welcome to Typing!"<<endl;
    cout<<"                                          --created by zhangyuhao"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"                  *******   *     *   *****     ******     "<<endl;
    cout<<"                     *       *   *    *    *    *          "<<endl;
    cout<<"                     *        * *     *    *    *          "<<endl;
    cout<<"                     *         *      *****     ******     "<<endl;
    cout<<"                     *         *      *         *          "<<endl;
    cout<<"                     *         *      *         *          "<<endl;
    cout<<"                     *         *      *         ******     "<<endl;
    cout<<endl;
    for (int i=0;i<80;i++)
    cout<<"-";
    cout<<endl;

    while (1)
    {
        cin>>inpy;
        if (inpy=="Q")
            break;
        if (inpy=="B")
        {   
            ofile<<"\b\b";
            text.erase(text.end()-2,text.end());
            continue;
        }
        if (inpy=="T")
        {
            cout<<text<<endl;
            continue;
        }
        string ss;
        getline(cin,ss);
        int num=0;
        char b[1000][3];
        int choose;
        choose=0;
        for (i=0;i<=len;i++)
        {
            t=0;
            for (int j=0;j<inpy.length();j++)
            {
                if (inpy[j]!=hz[i].py[j])
                {
                    t=1;
                    break;
                }
            }
            if (!t)
            {
                //cout<<hz[i].q<<" "<<hz[i].w<<" ";
                char c[3];
                c[0]=hz[i].q+0xA0;
                c[1]=hz[i].w+0xA0;
                c[2]=0;
                cout<<++num<<"."<<c<<"\t";
                if (num %10==0)
                {
                    string ss;
                    cout<<endl;
                    getline(cin,ss);
                    if (ss.length()!=0)
                    {
                        stringstream sss;
                        sss<<ss;
                        sss>>choose;
                        break;
                    }
                    //cout<<endl;
                }
                b[num][0]=c[0];
                b[num][1]=c[1];
                b[num][2]=c[2];
            }
            
        }
        cout<<endl;
        for (int i=0;i<80;i++)
        {
            cout<<"#";
        }
        cout<<endl;
        if (choose==0)
        {
            cin>>choose;
            ofile<<b[choose];
        }
        text=text+b[choose];
        cout<<b[choose]<<endl;
    }
    ofile<<endl;
    ifile.close();
    ofile.close();
    return 0;
}

