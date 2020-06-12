#include <iostream>
#include "Formula.h"
#include "Car.h"
#include "Integer.h"
#include "IntPtr.h"
#include <string>
#include "Dog.h"
#include "Account.h"
#include "Savings.h"
#include "Checking.h"
#include "Document.h"
#include <typeinfo>
#include "Stream.h"
#include <map>

#define SQUARE(x) (x * x)
enum class Color{ RED, GREEN, YELLOW };
//enum using chars, note that they use char ascii value
enum class letters : char{ RED='x', GREEN, YELLOW };
struct Point{
    int x;
    int y;

    Point(int a, int b): x(a),y(b) {}
    Point(): x(5),y(5) {}
};


int uniformInitialisation();
int pointers();
void ref_lecture();
void const_lecture();
void auto_lecture();
void range_based_for_loop();
void function_overloading();
void inline_functions();
void functionPointers();
void namespace_lecture();
int memory_allocation();
void classesObjects();
void structures();
void copyconstructor();
void delegateconstructor();
void moveconstructor();
void operatorOverloading();
void smartPointers();
void typecasting();
void userdefinedtoPrimitive();
void enumslecture();
void stringInCplusPlus();
void Inheritance();
void bankAccount();
void abstractClass();
void diamondProblem();
void exceptionHandling();

//assignment:
int Add(int *a, int *b) ;    //Add two numbers and return the sum
void AddVal(int *a, int *b, int *result); //Add two numbers and return the sum through the third pointer argument
void Swap(int *a, int *b) ;  //Swap the value of two integers
void Factorial(int *a, int *result);       //Generate the factorial of a number and return that through the second pointer argument
void Swap(int &a, int &b);
void Print(int &a);
void Print(int *a);
void Print(const int *a);
void Print(const int &a);
int sum(int a, int b);
extern "C" double sum(double a, double b); //this overloaded function is not mangled.
inline int compute_Square(int x);
void EndMessage();
namespace average {
    int calcAverageOrSum(int a, int b);
}
namespace sums{
    int calcAverageOrSum(int a, int b);
}
void DrawLine(Point a, Point b);
Integer Add(Integer const &a, Integer const &b);
Integer Add(int a, int b);
namespace global {
    Integer operator+(Integer const &a, Integer const &b);
}
Integer operator+(int a, Integer const &b);
std::ostream & operator <<(std::ostream &out, Integer const &a);
std::istream & operator >>(std::istream &in, Integer &a);
void fillColor(Color color);

int main() {
    using namespace std;
    Formula f1(1,5);
//    cout << "Product = " << f1.product() << endl;
//    cout << "Bla: " << Formula::bla(2) << endl;
//
//    uniformInitialisation();
//    pointers();
//    ref_lecture();
//    const_lecture();
//    auto_lecture();
//    auto_lecture();
//    range_based_for_loop();
//    function_overloading();
//    inline_functions();
//    functionPointers();
//    namespace_lecture();
//    memory_allocation();
//    classesObjects();
//    structures();
//    copyconstructor();
//    delegateconstructor();
//    moveconstructor();
//    operatorOverloading();
//    smartPointers();
//    typecasting();
//    userdefinedtoPrimitive();
//    enumslecture();
//    stringInCplusPlus();
//    Inheritance();
//    bankAccount();
//    abstractClass();
//    diamondProblem();
    exceptionHandling();

    cout << "end of main" << endl;
    return 0;
}

void ProcessRecords(int count){
    int* mem = (int*) malloc(count * sizeof(int));
    if(mem == nullptr){
        throw std::runtime_error("failed to allocate memory");
    }
    if(count <=0 ) {
        throw std::range_error("count should be > 0");
    }
    for (int i=0; i<count; i++) mem[i] = i*2;
    for (int i=0; i<count; i++) std::cout << mem[i] << " ";
    std::cout << std::endl;
    free(mem);

}

void exceptionHandling(){
    ProcessRecords(4);
    try{
        ProcessRecords(0);
    }
    catch(std::runtime_error &ex){
        std::cout << ex.what() <<std::endl;
        //std::cout << "unspecified exception" << std::endl;
    }
    catch(...){
        std::cout << "unspecified exception" << std::endl;
    }

    //map and pairs.
    std::pair<int, int> pairs{2,4};
    std::map<int, std::string> mymap;
    mymap[1] = "Dany";
    mymap.insert(std::pair<int, std::string>(3, "juby"));
    std::cout << mymap[3] << std::endl;

}

void diamondProblem(){
    IOStream io("doc.txt");
    std::string data;
    io >> data;
    io << data << std::endl;
    std::cout << io.GetFileName() << std::endl;
}

void Write(Document *d){
    //check type of object to demonstrate typeinfo RTTI basics
    if ((typeid(*d)) == (typeid(XML))){
        std::cout << "XML type"<< std::endl;
    }
    if ((typeid(*d)) == (typeid(RichText))){
        std::cout << "RichText type" << std::endl;
    }
    if ((typeid(*d)) == (typeid(Text))){
        std::cout << "Text type" << std::endl;
    }
    d->serialize();
}
void abstractClass(){
    Text txt;
    RichText rt;
    XML xml;
    Write(&txt);
    Write(&rt);
    Write(&xml);


}
void bankAccount(){
    using namespace std;
    Account ac;
    Account acc("Bob", 1000.80);
    cout << acc.getAccNum() << endl;
    acc.deposit(800);
    cout << " after deposit 800: " << acc.getBalance() << endl;
    acc.withdraw(300);
    cout << " after withdraw 300: "<< acc.getBalance() << endl;

    Savings s("James", 500, 0.2);
    cout << " balance of James "<< s.getBalance() << endl;
    s.accumulateInterest();
    cout << "after interest accumulated "<< s.getBalance() << endl;

    Checking ch("Martin", 100);
    ch.withdraw(20);
    cout << " balance of Martin "<< ch.getBalance() << endl;
    ch.withdraw(50);
    cout << " balance of Martin "<< ch.getBalance() << endl;
}
void PrintEatWhat (Animal a){
    std::cout << "animal eat??" << std::endl;
    a.Eat();
}
void Inheritance() {
    Dog scoobie;
    scoobie.Eat();
    PrintEatWhat(scoobie);
}
void stringInCplusPlus(){
    using namespace std;
    string s = "Hello";
    s = "HelloWorld";
    cout << s << endl;
    s[0] = 'L';
    char ch = s[0];
    cout << ch << endl;

    //cin >> s;
    cout << s << endl;
    std::getline(cin,s);
    cout << s << endl;

    //constant time as it caches the length
    cout << s.length() << endl;
    string s1{"Hello "}, s2{"World!"};
    cout << s1 + s2 << endl;
    s+=s1;
    cout << s << endl;
    s.insert(0,"Hello");
    cout << s << endl;

    if(s!=s1) cout << "not same" << endl;

    //removal
    s.erase(); //s is now erased
    s.insert(0,"hello");
    cout << s << endl;
    s.erase(0,2); //first 2 char
    cout << s << endl;

    //search
    s = "Hello world world";
    auto pos = s.find("world",0);
    //if not found.
    if(pos != string::npos){
        cout << s << endl;
    }
    //substring

}
void enumslecture(){
    enum Shades{ GREY, BLACK, BROWN};
    int x = static_cast<int>(Color::YELLOW);

    fillColor(Color::RED);

    std::cout << static_cast<char>(letters::YELLOW) << std::endl;
}
void userdefinedtoPrimitive(){
    Integer x(5);
    int y = static_cast<int>(x); //user defined object to primitive-type conversion.
    std::cout << y << std::endl;
}
void typecasting(){
    int a =5, b = 2;
    float c;
    c = a/b;
    //not casted.
    std::cout << c << std::endl;
    //cast now. using CStyle.
    //c = (float)a/b;
    std::cout << c << std::endl;
    //in c++ Style
    c = static_cast<float>(a)/b;
    std::cout << c << std::endl;
    //CStyle
    char* p = (char*) &a;
    //C++ qualifiers are not discarded. const/volatile are kept.
    p = reinterpret_cast<char*>(a);

    const int x = 1;
    //int * ip1 = &x; is not allowed.
    int * ip = const_cast<int*>(&x); //but with this, it works

    //initialisation
    std::cout << "initialisation" << std::endl;
    Integer a2;
    //assignment -> move constructor invoked
    std::cout << "assignment -> move constructor invoked" << std::endl;
    a2 = 5;

}
void smartPointers(){
    IntPtr p(new Integer());
    //this -> works if we have  -> operator overloaded.
    p->setValue(34); //segmentation fault. why??
    std::cout << p->getValue() << std::endl;
}

void operatorOverloading(){
    Integer a(1);
    Integer b(3);
    Integer sum = a + b;
    std::cout << sum.getValue() << std::endl;
    ++sum;
    std::cout << sum.getValue() << std::endl;
    sum++;
    std::cout << sum.getValue() << std::endl;

    if(a==b){
        std::cout << "same" << std::endl;
    }
    else{
        std::cout << "not same" << std::endl;
    }
    std::cout << "assignment operator" << std::endl;
    Integer r = std::move(b);
    std::cout << r.getValue() << std::endl;
    std::cout << "revive b" << std::endl;
    b.setValue(10);
    std::cout << b.getValue() << std::endl;

    //overload <<, >>, () operators
    sum = a + 1;
    std::cout << sum.getValue() << std::endl;
    //but this wont work -> sum = 1 + a;
    sum = 2 + a;
    std::cout << sum.getValue() << std::endl;

    //now try to use << operator
    std::cout << "....<< operator\n" <<sum << std::endl;
    //now try to use >> operator
    std::cin >> sum;
    std::cout << "....after>> operator\n" <<sum << std::endl;
}


void delegateconstructor(){
    Car c1;
//    Car c2(50);
//    Car c3(50,3);
}

void moveconstructor(){
    Integer a(1), b(3);
    b.setValue(Add(a,b).getValue());
    std::cout << b.getValue() <<std::endl;

    Integer c = 5;
    Integer cd(c); //copy constructor invoked
//    Integer cc(static_cast<Integer&&> (c)); //move constructor invoked. C++11
    Integer cc(std::move(c)); //move constructor invoked. C++11
    std::cout << "----------" <<std::endl;
    Integer d = Add(6,4);

}

void copyconstructor(){
    Integer i(5);
    Integer i2(i);
    std::cout << i.getValue() << std::endl;
    std::cout << i2.getValue() << std::endl;

    //shallow copy and p1 and p2 refers to same address!
    int *p1 = new int(5);
    int *p2 = p1;
    std::cout << p1 << std::endl; std::cout << p2 << std::endl;

    //deep copy
    int *p3 = new int(*p1);
    std::cout << p3 << std::endl;
    delete p1;
    //delete p2;
    delete p3;
}
void structures(){
 Point a = {3,6};
 Point b{1,2};
 Point c = Point();
 DrawLine(a,c);
}

void classesObjects() {
    std::cout << "total cars: " << Car::getTotalCars() << std::endl;
    Car audi(4.f);
//    audi.Accelerate();
//    audi.Accelerate();
//    audi.Accelerate();
//    audi.Accelerate();
//    audi.AddPassengers(5);
//    audi.Dashboard();
    Car car2, car3;
    std::cout << "total cars: " << Car::getTotalCars() << std::endl;
}
int memory_allocation(){
    using namespace std;
    //on heap
    int *ptr = (int*) malloc(1 * sizeof(int));
    *ptr = 65;
    cout << *ptr << endl; //65
    free(ptr);
    ptr = nullptr;

    int *ptr1 = (int*) calloc(5,sizeof(int)); //initializes memory to ZERO
    if(ptr1 == nullptr){
        cout << "failed to allocate memory";
        return -1;
    }
    /*for (int i=0; i<5; i++)
    {
        ptr1[i] = i*2+1;
    }
    cout << "Initialized values" << endl;

    for (int i=0; i<5; i++)
    {
        *//* ptr[i] and *(ptr+i) can be used interchangeably *//*
        cout << *(ptr1+i) << endl;
    }*/
    free(ptr1);
    ptr1 = nullptr;

    int *p = new int(4);
    cout << *(p) << endl;
    delete p;
    p = nullptr;

    int *pArray = new int[5]{1,2,3,4,5}; //uniform initialization...
    for (int i=0;i<5;i++){
        //*(pArray+i) = i; //to initialize array
        cout << *(pArray+i) << endl;
    }
    delete []pArray;
    pArray = nullptr;

    char *pChar = new char[4]; //allocate extra byte for null char.
    strcpy(pChar,"C++");
    cout << pChar << endl;
    delete []pChar;
    pChar = nullptr;

    int d[2][3]{1,2,3,
                4,5,6};

    cout << d[0][2] << endl; //3

    int *r1 = new int[3]{1,2,3};
    int *r2 = new int[3]{4,5,6};
    int **pTable = new int* [2]{r1,r2}; //uniform initialisation

    int **pMatrix = new int* [2];
    pMatrix[0] = r1;
    pMatrix[1] = r2;

    cout << pTable[0][2] << endl; //3
    cout << pMatrix[0][0] << endl; //3

    delete[] r1;
    delete[] r2;
    delete[] pTable;
    delete[] pMatrix;

    return 0;
}
void namespace_lecture(){
    std::cout << average::calcAverageOrSum(10,20) <<std::endl;
    std::cout << sums::calcAverageOrSum(10,20) <<std::endl;
}

void functionPointers(){
    using namespace std;
    int (*pFn) (int,int) = &sum;
    cout << pFn(5,6) << endl;
    cout << (*pFn)(5,6) << endl;
    atexit(&EndMessage);
}

void inline_functions(){
    using namespace std;
    cout << compute_Square(5) << endl;
    cout << SQUARE(5 + 1) << endl; //buggy

    cout << compute_Square(5 + 1) << endl;
}
void function_overloading(){
    std::cout << sum(4,5) << std::endl; //add ints
    std::cout << sum(4.3,5.6) << std::endl; //add doubles
}

void range_based_for_loop() {
    using namespace std;
    int arr[] = {1,2,3,4,5,6,7};
    /*for (int x: arr) {
        cout << x << endl;
    }*/
    //no loop termination is required.
    //auto increment
    //less chances for error.
    //no control over iteration.
    /*for (const auto &x: arr) {
        //x = 5; //with const auto &x, this is not allowed.
        cout << x << endl;
    }*/
    int *beg = std::begin(arr);
    int *end = std::end(arr);
    while (beg != end){
        cout << *beg <<endl;
        ++beg;
    }
}
void auto_lecture(){
    using namespace std;
    auto i = 10;
    auto j = sum(5,9);
    cout << j << endl;
    auto k = 5 + 3.14;
    cout << k << endl;

    static auto y = 5;
    cout << y++ << endl;
    const int x = 50;
    auto var1 = x;
    auto &var2 = x;
    auto ptr = &x;
    cout << *ptr << endl;

    //std::initializer_list<int>
    auto list = {1,2,3,4,5};
    for (auto each: list){
        cout << each << endl;
    }
    cout << "list size: " << list.size() << endl;

}
void const_lecture(){
    using namespace std;
    /*
    float radius, area;
    cout << "enter radius: ";
    cin>>radius;
    const float PI{3.141f};
    cout << PI << endl;
    area = PI * radius * radius;
    cout << "area: " << area << endl;
*/
    /*
    const int CHUNK_SIZE = 512;
    //int *ptr = &CHUNK_SIZE; //not allowed.
    const int *ptr = &CHUNK_SIZE;

    cout << *ptr << endl; //512
    //[star]ptr = 5; //this is not allowed
    int x = 10, y  =20;

    Print(ptr);
    Print(90); //constant value is allowed if we use const.
    Print(x);
    cout << "from const lecture: " << x << endl; //10
    ptr = &x; //this is allowed
    cout << *ptr << endl; //10
    cout << x << endl; //10
    int *ptr2 = &y;
    cout << *ptr2 << endl; //20
    *ptr2 = 68;
    cout << *ptr2 << endl; //68
    cout << y << endl; //68
    cout << *ptr2 << endl; //68
*/

    //Try to modify x1 & x2 and see the compilation output
    int x = 5 ;
    const int MAX = 12 ;
    int &ref_x1 = x ;
    const int &ref_x2 = x ;
    cout << ref_x1 << endl;
    cout << ref_x2 << endl;

    //Try to modify the pointer (e.g. ptr1) and the pointee value (e.g. *ptr1)
    const int *ptr1 = &x ;
    cout << ptr1 << endl;
    ptr1 = &MAX; // can modify ptr1 to point to another, eg. MAX
    cout << ptr1 << endl;
    cout << *ptr1 << endl;
    int *const ptr2 = &x ;
    cout << ptr2 << endl;
    *ptr2 = MAX; // can modify *ptr2, but not ptr2.
    cout << ptr2 << endl;
    cout << x << endl; //should be changed
    cout << *ptr2 << endl;

    //const int * const ptr3 = &x ; //can't modify anything.
    //Find which declarations are valid. If invalid, correct the declaration
    //const int *ptr3 = &MAX ; OK
    const int *ptr3 = &MAX ;
    //int *ptr4 = &MAX ; NOK
    const int *ptr4 = &MAX ;

    //const int &r1 = ref_x1 ; OK
    const int &r1 = ref_x1 ;
    //int &r2 = ref_x2 ; NOK
    const int &r2 = ref_x2 ;
    //int *&p_ref1 = ptr1 ;
    const int* &p_ref1 = ptr1 ; //&p_ref1 is a reference to an integer pointer that points to a const.
    cout << *p_ref1 << endl;
    const int* const &p_ref2 = ptr2 ;

}
void ref_lecture(){
    using namespace std;
    int x = 10;
    int &ref = x; //create a reference with x

    cout << x << endl;
    cout << "ref: " << ref << endl;
    ref = 45;
    cout << "ref: " << ref << endl;
    int y = 50;
    ref = y;
    cout << "ref: " << ref << endl;

    cout << &x << endl;
    cout << &ref << endl;

    int a = 5, b = 20;
    Swap(a,b);
    cout << a << endl;
    cout << b << endl;
    int *p1 = &y;
    Print(a);
    Print(p1);

}

void Print(int &a) {
    std::cout << "Print from function Print(int &a) : " << a << std::endl;
}

void Print(const int &a) {
    std::cout << "Print from function Print(const int &a) : " << a << std::endl;
}

void Print(int *a) {
    std::cout << "Print from function Print(int *a) : " << *a << std::endl;
}

void Print(const int *a) {
    std::cout << "Print from function Print(const int *a) : " << *a << std::endl;
}

int uniformInitialisation(){
    using namespace std;

    int a1(10);
    cout << a1 << endl;

    string str = "C++ is not C--";
    cout << str << endl;

    char cStr[10] = {"abc"};
    cout << cStr << endl;

    int b1{}; //value initialisation

    char e1[10]{};

    int *p = new int {};
    cout << *p << endl;
    p = &a1;
    cout << *p << endl;
    char *c = new char[10]{};
    strcpy(c,"test");
    cout << c << endl;

    return 0;

}
int pointers(){
    using namespace std;
    int x = 15;
    int y = 2;
    cout << &x << endl;
    int *p = &x;
    cout << p << endl;
    cout << *p << endl;
    int q = *p;
    cout << q << endl;

    int *a = nullptr;
    cout << a << endl;

    cout << Add(&x,&y) << endl;

    int r;
    AddVal(&x,&y,&r);
    cout << r << endl;

    cout << "Before swap: " <<x << " "<< y << endl;
    Swap(&x,&y);
    cout << "After swap:  " <<x << " "<< y << endl;

    x = 4; // 4,3,2,1
    r = 1;
    Factorial(&x, &r);
    cout << r << endl;

    return 0;

}

void AddVal(int *a, int *b, int *result) {
    *result = *a + *b;
}

int Add(int *a, int *b){
    return *a + *b;
}

void Swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void Swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void Factorial(int *a, int *result){
    for (int i = 1; i<=*a; i++){
        *result *=i;
    }
}

int sum(int a, int b){
    return a + b;
}
//not mangled. can be called from C.
extern "C" double sum(double a, double b){
    return a + b;
}

inline int compute_Square(int x){
    return x * x;
}

void EndMessage(){
    std::cout << "End Message" << std::endl;
}

namespace average {
    int calcAverageOrSum(int a, int b){
        return ((a + b)/2);
    }
}

namespace sums {
    int calcAverageOrSum(int a, int b) {
        return ((a + b));
    }
}

void DrawLine(Point start, Point end){
    std::cout << start.x << std::endl;
    std::cout << end.x << std::endl;
}

Integer Add(Integer const &a, Integer const &b){
    Integer temp;
    temp.setValue(a.getValue() + b.getValue());
    return temp;
}
Integer Add(int a, int b){
    Integer temp (a + b);
    return temp;
}
namespace global{
    Integer operator+(Integer const &a, Integer const &b) {
        std::cout << "global namespace invoked" << std::endl;
        return (Integer(a.getValue() + b.getValue()));
    }
}

Integer operator+(int a, Integer const &b){
    Integer temp;
    temp.setValue(a+b.getValue());
    return temp;
}

std::ostream & operator <<(std::ostream &out, Integer const &a){
    out<< a.getValue();
    return out;
}

std::istream & operator >>(std::istream &in, Integer &a){
    int x;
    in >> x;
    a.setValue(x);
    return in;
}

void fillColor(Color color){
    using namespace std;
    switch(color){
        case Color::RED:
            cout << "RED" << endl;
            break;
        case Color::GREEN:
            cout << "GREEN" << endl;
            break;
        case Color::YELLOW:
            cout << "YELLOW" << endl;
            break;
        default:
            cout << "default" << endl;
    }
}