#include <iostream>
#include <fstream>
#include <string>

void startcompiled(std::ofstream& compiled) {
    compiled << "#include <iostream>\n";
    compiled << "int main() {\n";
    compiled << "char arr[30000];\n";
    compiled << "char *ptr=&arr[0];\n";
    compiled << "std::fill_n(arr, 30000, 0);\n";
    return;
}

void endcompiled(std::ofstream& compiled) { compiled << "}"; return; }

void charcompiler(char c,std::ofstream& compiled) {
    switch (c) {
        case '+': compiled << "(*ptr)++;\n"; break;
        case '-': compiled << "(*ptr)--;\n"; break;
        case '>': compiled << "ptr++;\n"; break;
        case '<': compiled << "ptr--;\n"; break;
        case '.': compiled << "std::cout << *ptr;\n"; break;
        case ',': compiled << "std::cin >> *ptr;\n"; break;
        case '[': compiled << "while((*ptr)!=0){\n"; break;
        case ']': compiled << "}\n"; break;

    }
    return;
}

int main(int argc, char** argv)
{
    std::string line;
    int loopcont = 0;

    std::cout << "Welcome to brainfuck to c++!\n"<< argv[1] <<"\n"<< argv[2];

    std::ifstream source;
    std::ofstream compiled;

    if (argc<2) {return 1;}
    if (argc==2) {compiled.open("out.c++");}
    else {compiled.open(argv[2]);}
    source.open(argv[1]);
    if (!source.is_open()){return 1;}
    if (!compiled.is_open()) { return 1; }

    startcompiled(compiled);
    while (getline(source, line))
    {
        for (char& c : line) {
            switch (c) {
                case '+': compiled << "(*ptr)++;\n"; break;
                case '-': compiled << "(*ptr)--;\n"; break;
                case '>': compiled << "ptr++;\n"; break;
                case '<': compiled << "ptr--;\n"; break;
                case '.': compiled << "std::cout << *ptr;\n"; break;
                case ',': compiled << "std::cin >> *ptr;\n"; break;
                case '[': compiled << "while((*ptr)!=0){\n";loopcont++; break;
                case ']': compiled << "}\n";loopcont--; break;
            }
        }
    }
    endcompiled(compiled);
    source.close();
    compiled.close();
    //error checking
    if(loopcont<0){std::cout << "] doesn't have its closing brackect";}
    if(loopcont>0){std::cout << "[ doesn't have its closing brackect";}

    return 0;
}
