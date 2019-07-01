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
#include <list>
using namespace std;

#ifndef INC_1_0_1_SYNTHESISINIT_H
#define INC_1_0_1_SYNTHESISINIT_H






//void getFiles(string foler, vector<string>& files);
class ToneLib
{



    public:
        void getFiles( string path,vector<string>&files )
        {
            list<int> toneLibList;
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
            string programName;
            string intensity;
            string Note;
            string beginSeek;
            string seekLen;

            unsigned int j=0;
            int index1;

            char str1[256];
            std::string str;
            ifstream inf;
            string toneLibFile;
            string toneLibDict;
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
                cout<< toneLibDict <<endl;
                outFile.getline(buffer,256,'}');
                cout<< buffer <<endl;
                while( !outFile.eof() )
                {
                    outFile.getline(buffer,256,'}');
                    str = buffer;
                    //按—字符进行切分
                    std::replace(str.begin(), str.end(), '{', '-');
                    std::replace(str.begin(), str.end(), '"', '-');
                    std::replace(str.begin(), str.end(), ':', '-');
                    std::replace(str.begin(), str.end(), ',', '-');
                    std::replace(str.begin(), str.end(), '-', '-');
                    std::replace(str.begin(), str.end(), ' ', '-');

                    // 第一步，获取音色名
                    for(j=0;j<3;j++)
                    {
                        str[j] = '\0';
                    }
                    std::remove(str.begin(), str.end(),'\0');
                    index1 = str.find('-');
                    programName = str.substr(0,index1);
                    cout<< str <<endl;
                    cout<< programName <<endl;


                    for(j=0;j<index1;j++)
                    {
                        str[j] = '\0';
                    }
                    std::remove(str.begin(),str.end(),'\0');


                }

//                while( !outFile.eof() )
//                {
//                    outFile.getline(buffer,256,'}');//getline(char *,int,char) 表示该行字符达到256个或遇到换行就结束
//                    cout << buffer << endl;
//                    str = buffer;
//                    // 第一步，获取音色名
//                    cout << toneLibDict << endl;
//                    for(j=0;j<=str.size() -3;j++)
//                    {
//                        str[j]=str[j+3];
//                        str[j+3] = '\0';
//                    }
//                    index = str.find('-');
//                    programName = str.substr(0,index);
//                    // 第二步，获取力度
////                    for( int j =0;j<=str.size()-index;j++)
////                    {
////                        str[j]=str[j+index+1];
////                        str[j+index] = '\0';
////                    }
////                    index = str.find('-');
////                    intensity = str.substr(0,index);
//
//                    cout << programName<< " " << intensity << endl;
//                    cout << str << endl;
//
//                }

//                cout << toneLibDict << endl;
//                cout << toneLibFile << endl;

            }
        }

};



#endif //INC_1_0_1_SYNTHESISINIT_H