#ifndef CPU_H
#define CPU_H
#include <map>
#include <fstream>
class CPU
{
public:
    CPU() : r1{}, r2{}, r3{}, r4{}, r5{}, r6{}, r7{}, r8{}, r9{}, r10{}
    {
        make();
    }

public:
    typedef void (CPU::*Func_Point)(std::string &, std::string &);
    void make();
    void get(std::string);
    void cut(std::string &);
    bool check_reg(std::string &);
    bool is_number(std::string &);
public:
    void mov(std::string &, std::string &);
    void add(std::string &, std::string &);
    void mul(std::string &, std::string &);
    void div(std::string &, std::string &);
    void sub(std::string &, std::string &);
public:
    void jmp(std::string &, std::string &);
    void jumps_impl(std::string &, std::string &);
    void jl(std::string &, std::string &);// jump if less
    void je(std::string &, std::string &);// jump if equal
    void jg(std::string &, std::string &);// jump if great
    void jle(std::string &, std::string &);// jump if less or equal
    void jge(std::string &, std::string &);// jump if great or equal
    void jne(std::string &, std::string &);// jump if not equal
    void jz(std::string &, std::string &);// jump if zero
    void jnz(std::string &, std::string &);// jump if not zero
    void cmp(std::string &, std::string &);
public:
    void _and(std::string &, std::string &);
    void _or(std::string &, std::string &);
    void _xor(std::string &, std::string &);
    void _not(std::string &, std::string &);
//function for print register's values
     void print()
     {
         std::cout << "R1 " << r1 << std::endl;
         std::cout << "R2 " << r2 << std::endl;
         std::cout << "R3 " << r3 << std::endl;
         std::cout << "R4 " << r4 << std::endl;
         std::cout << "R5 " << r5 << std::endl;
         std::cout << "R6 " << r6 << std::endl;
         std::cout << "R7 " << r7 << std::endl;
         std::cout << "R8 " << r8 << std::endl;
         std::cout << "R9 " << r9 << std::endl;
         std::cout << "R10 " << r10 << std::endl;
     }
  private:
    std::ifstream file;
    std::map<std::string, Func_Point> Func;
    std::map<std::string, int *> reg;
    std::map<std::string, int> label;
    std::map<std::string, bool> Jumps;
    int r1;
    int r2;
    int r3;
    int r4;
    int r5;
    int r6;
    int r7;
    int r8;
    int r9;
    int r10;
};

#endif
