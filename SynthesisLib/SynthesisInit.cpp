//
// Created by Administrator on 2019/6/29.
//
#include "../SynthesisH/SynthesisInit.h"

#include <iostream>
#include <string>
#include <vector>
#include <io.h>
#include <string.h>

using namespace std;



//void getFiles( string path, vector<string>& files )
//{
//    //文件句柄
//    long hFile = 0;
//    //文件信息
//    struct _finddata_t fileinfo;   //大家可以去查看一下_finddata结构组成
//    //以及_findfirst和_findnext的用法，了解后妈妈就再也不用担心我以后不会编了
//    string p;
//    if((hFile = _findfirst(p.assign(path).append("/*").c_str(),&fileinfo)) != -1) {
//        do {
//            if( string(fileinfo.name) != "." and string(fileinfo.name) != "..")
//            {
//                files.push_back(p.assign(path).append("/").append(fileinfo.name) );
//            }
//        }
//        while(_findnext(hFile, &fileinfo) == 0);_findclose(hFile);
//    }
//}







