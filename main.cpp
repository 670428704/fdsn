
#include <iostream>
#include <string>
#include <vector>
#include <io.h>
#include <string.h>
#include "SynthesisH/SynthesisInit.h"

using namespace std;

ToneLib ToneL;


int main() {
    string programPath;
    string ToneLib = "G:/ToneLib";  //此处用的是斜杠，也可以用反斜
    //但需注意的是由于C语言的特点，要用双反斜杠，即"E:\\MATLAB\\LBP\\scene_categories"
    //cin >> folder;   //也可以用此段代码直接在DOS窗口输入地址，此时只需正常的单反斜杠即可

    vector<string> files;
    unsigned int *ToneState;



    ToneL.StateInit(ToneLib,ToneState);

    return 0;
}

