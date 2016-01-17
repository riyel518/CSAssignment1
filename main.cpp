#include <iostream>
#include <string>
#include <iostream>
#include "processor.h"
#include "stack.h"
using namespace std;

int main(int arg, char* argv[]){

startStack automobile;
startStack van;
startQueue employees;

automobile.topNode = NULL;
van.topNode = NULL;
employees.front = NULL;

readFile(argv, automobile, van, employees);

cout << endl;

toString(automobile);

cout << endl << "----van---" << endl;
toString(van);

 return 0;

}
