//
// Created by Administrator on 2019/6/29.
//

#include <iostream>
#include <string>
#include <vector>
#include <io.h>
#include <string.h>
#include "fstream"
#include <sstream>
#include <algorithm>

using namespace std;

#ifndef INC_1_0_1_SYNTHESISINIT_H
#define INC_1_0_1_SYNTHESISINIT_H






//void getFiles(string foler, vector<string>& files);
class ToneLib
{


    public:
        void getFiles( string path, vector<string>&files )
        {
            //文件句柄
            string ProgramPath;
            string fileName;
            long hFile = 0;
            //文件信息
            struct _finddata_t fileinfo;
            string p;
            if((hFile = _findfirst(p.assign(path).append("/*").c_str(),&fileinfo)) != -1)
            {
                do
                {
                    if( string(fileinfo.name) != "." and string(fileinfo.name) != "..")
                    {
                        files.push_back( fileinfo.name );
                    }
                }
                while(_findnext(hFile, &fileinfo) == 0);_findclose(hFile);
            }
        };


        //初始化状态机
        void StateInit(string toneLibPath,unsigned int *StateDict)
        {
            string str;
            

            ifstream inf;

            string toneLibFile ;
            string toneLibDict ;
            vector<string> files;
            getFiles( toneLibPath, files );

            for( int i = 0; i < files.size(); i++ )
            {
                toneLibFile = toneLibPath;
                toneLibDict = toneLibPath;
                toneLibFile = toneLibFile.append("/").append(files[i]).append("/").append(files[i]).append(".toneLib");//获取音色库文件
                toneLibDict = toneLibDict.append("/").append(files[i]).append("/").append(files[i]).append(".toneLibList");//获取音色库引导文件

                char buffer[256];
                fstream outFile;
                outFile.open(toneLibDict,ios::in);
                cout<< toneLibDict <<"--- all file is as follows:---"<<endl;
                while(!outFile.eof())
                {
                    outFile.getline(buffer,256,'}');//getline(char *,int,char) 表示该行字符达到256个或遇到换行就结束
                    str = buffer;

                    str.find('-')

                    cout << buffer << endl;
                }





                cout << toneLibDict << endl;
                cout << toneLibFile << endl;


            }
        };

};



#endif //INC_1_0_1_SYNTHESISINIT_H