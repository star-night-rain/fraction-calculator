#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Fraction
{
    friend Fraction operator+(const Fraction& frac1, const Fraction& frac2); //����+�����
    friend Fraction operator-(const Fraction& frac1, const Fraction& frac2); //����-�����
    friend Fraction operator*(const Fraction& frac1, const Fraction& frac2); //����*�����
    friend Fraction operator/(const Fraction& frac1, const Fraction& frac2); //����/�����
    friend bool operator==(Fraction frac1, Fraction frac2);                  //����==�����
    friend bool operator>(const Fraction& frac1, const Fraction& frac2);     //����>�����
    friend bool operator<(const Fraction& frac1, const Fraction& frac2);     //����<�����
    friend ostream& operator<<(ostream& out, const Fraction& frac);          //����<<�����
    friend istream& operator>>(istream& in, Fraction& frac);                 //����>>�����
    friend void sortFraction(vector<Fraction>& nums);//�Է�����������
    friend bool judgesign(Fraction& frac1, Fraction& frac2);
    friend void handledata1(string input, int size, Fraction& frac1, Fraction& frac2, string& symbol);
    friend void handledata2(string input, int size, vector<Fraction>& nums, string& symbol);
public:
    Fraction();                      //�޲��캯��
    Fraction(int n, int d);          //�����캯��
    Fraction(const Fraction& f);     //�����캯��
    void setFraction(int n, int d);  //���÷����ķ��Ӻͷ�ĸ
    int getNumer();                  //��ȡ�����ķ���
    int getDeno();                   //��ȡ�����ķ�ĸ
    void RdcFrc();                   //��ǰ����Լ��
private:
    int numer; //����
    int deno;  //��ĸ    
};