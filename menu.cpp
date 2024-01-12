#include "menu.h"
#include "Fraction.h"
#include <iostream>
using namespace std;

bool judgesymbol(string x)
{
    if (x == "+" || x == "-" || x == "*" || x == "/")
        return true;
    return false;
}

void menu1(bool& exit)
{
    while (1)
    {
        system("cls");
        cout << "��������" << endl;
        cout << "-----------------------------------" << endl;
        cout << "�������������ʽ����1/2+1/3�س�����" << endl;
        cout << "����#�ż�������һ��Ŀ¼:" << endl;
        cout << "-----------------------------------" << endl;
        int size;
        string input;
        cin >> input;
        if (input == "#")
        {
            exit = true;
            break;
        }
        size = input.size();
        Fraction num1, num2;
        string symbol;
        try
        {
            handledata1(input, size, num1, num2, symbol);
        }
        catch (exception& error)
        {
            cout << error.what();
            system("pause");
            continue;
        }
        if (symbol == "+")
        {
            Fraction num3 = num1 + num2;
            num3.RdcFrc();
            cout << "=" << num3 << endl;
        }
        else if (symbol == "-")
        {
            Fraction num3 = num1 - num2;
            num3.RdcFrc();
            cout << "=" << num3 << endl;
        }
        else if (symbol == "*")
        {
            Fraction num3 = num1 * num2;
            num3.RdcFrc();
            cout << "=" << num3 << endl;
        }
        else if (symbol == "/")
        {
            Fraction num3 = num1 / num2;
            num3.RdcFrc();
            cout << "=" << num3 << endl;
        }
        system("pause");
    }
}

void menu2(bool& exit)
{
    while (1)
    {
        system("cls");
        cout << "��������" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "������һ��������ö��Ÿ�����" << endl;
        cout << "������С���������÷���<��β��" << endl;
        cout << "�ɴ�С�����÷���>��β����1/2,1/4,3/5<�س�����" << endl;
        cout << "����#�ż�������һ��Ŀ¼:" << endl;
        cout << "----------------------------------------------" << endl;
        string input;
        cin >> input;
        if (input == "#")
        {
            exit = true;
            break;
        }
        vector<Fraction> nums;
        string symbol;
        int size = input.size();
        try
        {
            handledata2(input, size, nums, symbol);
        }
        catch (exception& error)
        {
            cout << error.what();
            system("pause");
            continue;
        }
        sortFraction(nums);
        if (symbol == "<")
        {
            for (int i = 0; i < nums.size() - 1; i++)
            {
                if (nums[i] < nums[i + 1])
                    cout << nums[i] << " < ";
                else
                    cout << nums[i] << " = ";
            }
            cout << nums.back() << endl;
        }
        else if (symbol == ">")
        {
            for (int i = nums.size() - 1; i > 0; i--)
            {
                if (nums[i] > nums[i - 1])
                    cout << nums[i] << " > ";
                else
                    cout << nums[i] << " = ";
            }
            cout << nums.front() << endl;
        }
        else
            cout << "�������" << endl;
        system("pause");
    }
}

void menu()
{
    bool exit, end;
    while (1)
    {
        system("cls");
        cout << "��ӭʹ�÷�����������" << endl;
        cout << "--------------------------" << endl;
        cout << "���ܲ˵�" << endl;
        cout << "1.��������" << endl;
        cout << "2.��������" << endl;
        cout << "0.�˳�����" << endl;
        cout << "--------------------------" << endl;
        end = false;
        exit = false;
        cout << "��ѡ���ܣ�";
        string num;
        while (1)
        {
            cin >> num;
            if (num == "1")
            {
                menu1(exit);
                if (exit)
                    break;
            }
            else if (num == "2")
            {
                menu2(exit);
                if (exit)
                    break;
            }
            else if (num == "0")
            {
                end = true;
                break;
            }
            else
            {
                cout << "�������" << endl;
                system("pause");
                break;
            }
        }
        if (end)
            break;
    }
}
