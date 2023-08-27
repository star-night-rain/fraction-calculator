#include "Fraction.h"
#include "menu.h"
#include <cmath>
Fraction::Fraction()
{
    numer = 1;
    deno = 1;
}

Fraction::Fraction(int n, int d)
{
    numer = n;
    deno = d;
}

Fraction::Fraction(Fraction const& f)
{
    numer = f.numer;
    deno = f.deno;
}

void Fraction::setFraction(int n, int d)
{
    numer = n;
    deno = d;
    return;
}

int Fraction::getNumer()
{
    return numer;
}

int Fraction::getDeno()
{
    return deno;
}

void Fraction::RdcFrc()
{
    int factor = 1;
    int n1 = fabs(numer), n2 = fabs(deno);
    int min = n1 < n2 ? n1 : n2;
    for (int i = 2; i <= min; i++)
        if (n1 % i == 0 && n2 % i == 0)
            factor = i;
    numer /= factor;
    deno /= factor;
}

Fraction operator+(const Fraction& frac1, const Fraction& frac2)
{
    int n1 = frac1.numer * frac2.deno + frac2.numer * frac1.deno;
    int n2 = frac1.deno * frac2.deno;
    Fraction m(n1, n2);
    m.RdcFrc();
    return m;
}

Fraction operator-(const Fraction& frac1, const Fraction& frac2)
{
    int n1 = frac1.numer * frac2.deno - frac2.numer * frac1.deno;
    int n2 = frac1.deno * frac2.deno;
    Fraction m(n1, n2);
    m.RdcFrc();
    return m;
}

Fraction operator*(const Fraction& frac1, const Fraction& frac2)
{
    int n1 = frac1.numer * frac2.numer;
    int n2 = frac1.deno * frac2.deno;
    Fraction m(n1, n2);
    m.RdcFrc();
    return m;
}

Fraction operator/(const Fraction& frac1, const Fraction& frac2)
{
    int n1 = frac1.numer * frac2.deno;
    int n2 = frac1.deno * frac2.numer;
    Fraction m(n1, n2);
    m.RdcFrc();
    return m;
}

bool operator==(Fraction frac1, Fraction frac2)
{
    Fraction x = frac1, y = frac2;
    x.RdcFrc();
    y.RdcFrc();
    if (x.getNumer() == y.getNumer() && x.getDeno() == y.getDeno())
        return true;
    return false;
}

bool operator>(const Fraction& frac1, const Fraction& frac2)
{
    if (frac1.numer * frac1.deno < 0 && frac2.numer * frac2.deno>0)
        return false;
    else if (frac1.numer * frac1.deno > 0 && frac2.numer * frac2.deno < 0)
        return true;
    int x = frac1.numer * frac2.deno;
    int y = frac2.numer * frac1.deno;
    if (frac1.numer * frac1.deno < 0 && frac2.numer * frac2.deno < 0)
    {
        if (fabs(x) < fabs(y))
            return true;
        return false;
    }
    if (x > y)
        return true;
    return false;
}

bool operator<(const Fraction& frac1, const Fraction& frac2)
{
    if (frac1.numer * frac1.deno < 0 && frac2.numer * frac2.deno>0)
        return true;
    else if (frac1.numer * frac1.deno > 0 && frac2.numer * frac2.deno < 0)
        return false;
    int x = frac1.numer * frac2.deno;
    int y = frac2.numer * frac1.deno;
    if (frac1.numer * frac1.deno < 0 && frac2.numer * frac2.deno < 0)
    {
        if (fabs(x) > fabs(y))
            return true;
        return false;
    }
    if (x < y)
        return true;
    return false;
}

ostream& operator<<(ostream& out, const Fraction& frac)
{
    if (frac.numer == 0)
    {
        out << "0";
        return out;
    }
    if (frac.numer > 0 && frac.deno < 0)
    {
        out << frac.numer * (-1) << "/" << frac.deno * (-1);
        return out;
    }
    out << frac.numer << "/" << frac.deno;
    return out;
}

istream& operator>>(istream& in, Fraction& frac)
{
    string line;
    in >> frac.numer >> line >> frac.deno;
    return in;
}

void sortFraction(vector<Fraction>& nums)
{
    int pos = nums.size() - 1;
    int bound;
    if (pos == 0)
    {
        if (nums[0] > nums[1])
        {
            Fraction test = nums[0];
            nums[0] = nums[1];
            nums[1] = test;
        }
    }
    while (pos)
    {
        bound = pos;
        pos = 0;
        Fraction test;
        for (int i = 0; i < bound; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                test = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = test;
                pos = i;
            }
        }
    }
}

bool judgesign(Fraction& frac1, Fraction& frac2)
{
    if (frac1.numer * frac1.deno < 0 && frac2.numer * frac2.deno>0)
        return true;
    else if (frac2.numer * frac2.deno < 0 && frac1.numer * frac1.deno>0)
        return true;
    return false;
}

void handledata1(string input, int size, Fraction& frac1, Fraction& frac2, string& symbol)
{
    int i = 0, x1 = 0, x2 = 0, y = 1;
    int k = 0;
    int num[100] = { 0 };
    string sign1, sign2, sign3, sign4;
    if (input[i] == '-')
    {
        sign1 = "-";
        i++;
    }
    if (input[i] == '+')
        i++;
    while (input[i] >= 48 && input[i] <= 57)
    {
        num[k++] = input[i] - 48;
        i++;
    }
    for (int j = k - 1; j >= 0; j--)
    {
        x1 += num[j] * y;
        y *= 10;
    }
    k = 0;
    if (sign1 == "-")
        x1 *= -1;
    if (input[i] == '/')
    {
        i++;
        y = 1;
        if (input[i] == '-')
        {
            sign2 = "-";
            i++;
        }
        if (input[i] == '+')
            i++;
        while (input[i] >= 48 && input[i] <= 57)
        {
            num[k++] = input[i] - 48;
            i++;
        }
        for (int j = k - 1; j >= 0; j--)
        {
            x2 += num[j] * y;
            y *= 10;
        }
        k = 0;
        if (sign2 == "-")
            x2 *= -1;
        if (x2 == 0)
                throw exception("分数计算式输入错误!\n");
        frac1.setFraction(x1, x2);
        x1 = 0, x2 = 0, y = 1;
        symbol = input[i++];
        if (judgesymbol(symbol))
        {
            if (input[i] == '-')
            {
                sign3 = "-";
                i++;
            }
            if (input[i] == '+')
                i++;
            while (input[i] >= 48 && input[i] <= 57)
            {
                num[k++] = input[i] - 48;
                i++;
            }
            for (int j = k - 1; j >= 0; j--)
            {
                x1 += num[j] * y;
                y *= 10;
            }
            k = 0;
            if (sign3 == "-")
                x1 *= -1;
            y = 1;
            if (input[i] == '/')
            {
                i++;
                if (input[i] == '-')
                {
                    sign4 = "-";
                    i++;
                }
                if (input[i] == '+')
                    i++;
                while (input[i] >= 48 && input[i] <= 57)
                {
                    num[k++] = input[i] - 48;
                    i++;
                }
                for (int j = k - 1; j >= 0; j--)
                {
                    x2 += num[j] * y;
                    y *= 10;
                }
                k = 0;
                if (i != size)
                    throw exception("分数计算式输入错误!\n");
                if (sign4 == "-")
                    x2 *= -1;
                if (x2 == 0)
                        throw exception("分数计算式输入错误!\n");      
                frac2.setFraction(x1, x2);
                return;
            }
        }
    }
    throw exception("分数计算式输入错误!\n");
}

void handledata2(string input, int size, vector<Fraction>& nums, string& symbol)
{
    int i = 0, x1, x2, y,k=0;
    int num[100] = { 0 };
    string sign;
    while (1)
    {
        x1 = 0, x2 = 0, y = 1;
        if (input[i] == '-')
        {
            sign = "-";
            i++;
        }
        if (input[i] == '+')
            i++;
        while (input[i] >= 48 && input[i] <= 57)
        {
            num[k++] = input[i] - 48;
            i++;
        }
        for (int j = k - 1; j >= 0; j--)
        {
            x1 += num[j] * y;
            y *= 10;
        }
        k = 0;
        if (sign == "-")
        {
            x1 *= -1;
            sign = "/";
        }
        if (input[i] == '/')
        {
            i++;
            y = 1;
            if (input[i] == '-')
            {
                sign = "-";
                i++;
            }
            if (input[i] == '+')
                i++;
            while (input[i] >= 48 && input[i] <= 57)
            {
                num[k++] = input[i] - 48;
                i++;
            }
            for (int j = k - 1; j >= 0; j--)
            {
                x2 += num[j] * y;
                y *= 10;
            }
            k = 0;
            if (sign == "-")
            {
                x2 *= -1;
                sign = "/";
            }
            if (x2 == 0)
                    throw exception("输入错误!\n");
            Fraction test(x1, x2);
            nums.push_back(test);
            if (input[i] == '<')
            {
                if (i != size - 1)
                    throw exception("输入错误！\n");
                symbol = '<';
                return;
            }
            else if (input[i] == '>')
            {
                if (i != size - 1)
                    throw exception("输入错误！\n");
                symbol = '>';
                return;
            }
            if (input[i] == ',')
            {
                if (i > size - 5)
                    throw exception("输入错误!\n");
                i++;
                continue;
            }
        }
        throw exception("输入错误!\n");
    }
}