{"filter":false,"title":"submission.cpp","tooltip":"/submission.cpp","undoManager":{"mark":0,"position":0,"stack":[[{"group":"doc","deltas":[{"action":"insertText","range":{"start":{"row":0,"column":0},"end":{"row":0,"column":19}},"text":"#include <iostream>"},{"action":"insertText","range":{"start":{"row":0,"column":19},"end":{"row":1,"column":0}},"text":"\n"},{"action":"insertLines","range":{"start":{"row":1,"column":0},"end":{"row":46,"column":0}},"lines":["#include <fstream>","#include <string>","","using namespace std;","","int main(int argc, char* argv[])","{","\tif(argc != 3)","\t{","\t\tcout << \"Usage: exe <input_file> <output_file>\" << endl;","\t\treturn -1;","\t}","\t//get number of elements","\tint numElements = 0;","\tstring line = \"\";","\tifstream in(argv[1]);","\twhile(getline(in, line))","\t\t++numElements;","\tin.close();","\t","\t//open file and store in array","\tint* data = new int[numElements];","\tint i = 0;","\tifstream in2(argv[1]);","\twhile(!in2.eof() || in2.peek() != EOF)","\t{","\t\tin2 >> ws;","\t\tif(in2.eof() || in2.peek() == EOF)","\t\t\tbreak;","\t\tin2 >> data[i];","\t\t++i;","\t}","\tin2.close();","","\t//write array to file","\tFILE* fp = fopen(argv[2], \"w\");","\tfor(int i=0; i<numElements; ++i)","\t\tfprintf(fp, \"%d\\n\", data[i]);","\tfclose(fp);","","\t//cleanup","\tdelete [] data;","","\treturn 0;","}"]}]}]]},"ace":{"folds":[],"scrolltop":0,"scrollleft":0,"selection":{"start":{"row":46,"column":0},"end":{"row":46,"column":0},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":0},"timestamp":1411511654711,"hash":"80593cf9ca7050d700c8d36cea493f9ecfb6daff"}