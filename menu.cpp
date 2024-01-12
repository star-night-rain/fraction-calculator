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
        cout << "分数计算" << endl;
        cout << "-----------------------------------" << endl;
        cout << "请输入分数计算式（如1/2+1/3回车），" << endl;
        cout << "输入#号键返回上一层目录:" << endl;
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
        cout << "分数排序" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "请输入一组分数，用逗号隔开，" << endl;
        cout << "如需由小到大排列用符号<结尾，" << endl;
        cout << "由大到小排列用符号>结尾（如1/2,1/4,3/5<回车），" << endl;
        cout << "输入#号键返回上一层目录:" << endl;
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
            cout << "输入错误！" << endl;
        system("pause");
    }
}

void menu()
{
    bool exit, end;
    while (1)
    {
        system("cls");
        cout << "欢迎使用分数计算器！" << endl;
        cout << "--------------------------" << endl;
        cout << "功能菜单" << endl;
        cout << "1.分数计算" << endl;
        cout << "2.分数排序" << endl;
        cout << "0.退出程序" << endl;
        cout << "--------------------------" << endl;
        end = false;
        exit = false;
        cout << "请选择功能：";
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
                cout << "输入错误！" << endl;
                system("pause");
                break;
            }
        }
        if (end)
            break;
    }
}
