#include <iostream>
#include <string>
using namespace std;
//reversing the numbers.
int reversDigits(int num)
{
    int rev_num = 0;
    while (num > 0)
    {
        rev_num = rev_num * 10 + num % 10;
        num /= 10;
    }
    return rev_num;
}
//Convert Decimal Number to (Binary and Octal) Systems.
int DECtoAll(int num, int Base)
{
    int ans, temp;
    string answer;

    while (num != 0)
    {
        temp = num % Base;
        num /= Base;
        answer += to_string(temp);
    }
    ans = stoi(answer);
    return ans;
}
//Convert Decimal Number to Hexa System.
string DECtoHEX(int num, int Base)
{
    int temp;
    string answer;

    while (num != 0)
    {
        temp = num % Base;
        if (temp == 10)
        {
            answer += "A";
        }
        else if (temp == 11)
        {
            answer += "B";
        }
        else if (temp == 12)
        {
            answer += "C";
        }
        else if (temp == 13)
        {
            answer += "D";
        }
        else if (temp == 14)
        {
            answer += "E";
        }
        else if (temp == 15)
        {
            answer += "F";
        }
        else
        {
            answer += to_string(temp);
        }
        num /= Base;
    }
    return answer;
}
//Converting from (Binary, Octal) systems to Decimal.
int AlltoDec(string num, int Base)
{
    string tempChar;
    int answer = 0, tempBase, tempNum;
    reverse(num.begin(), num.end());

    for (int i = 0; i < num.length(); i++)
    {
        tempChar = num[i];
        tempNum = stoi(tempChar);
        tempBase = (int)(pow(Base, i) + 0.5);
        answer += tempNum * tempBase;
    }

    return answer;
}
//Converting from Hexa to Decimal.
int HexatoDec(string num, int Base)
{
    string tempChar;
    int answer = 0, tempBase, tempNum;
    reverse(num.begin(), num.end());

    for (int i = 0; i < num.length(); i++)
    {
        if (num[i] == 'A')
        {
            tempChar = "10";
        }
        else if (num[i] == 'B')
        {
            tempChar = "11";
        }
        else if (num[i] == 'C')
        {
            tempChar = "12";
        }
        else if (num[i] == 'D')
        {
            tempChar = "13";
        }
        else if (num[i] == 'E')
        {
            tempChar = "14";
        }
        else if (num[i] == 'F')
        {
            tempChar = "15";
        }
        else
        {
            tempChar = num[i];
        }
        tempNum = stoi(tempChar);
        tempBase = (int)(pow(Base, i) + 0.5);
        answer += tempNum * tempBase;
    }

    return answer;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    /*
    -Number is The number that the user will enter with or without the dot(.) as a string.
    -NumericalSys is the System that the user choice to convert to.
    -SysBase is the Numerical system Base.
    -intNumber The Number that the user entered as a Integer.
    -HexaAnswer is the answer for Hexa system as a string.
    -DeciamlNumber is the Number in Decimal Converted from Octal or Hexa.
    */
    string Number, HexaAnswer;
    int NumericalSys = 1, intNumber, answer = 0, SysBase, DeciamlNumber;

    cout << "                                       Welcome To The Numerical System Converter!                    \n\n";
    cout << "Here is The Numerical Systems Numbers :\n";
    cout << "1- Decimal to Binary.\n2- Decimal to Octal.\n3- Decimal to HexaDecimal.\n4- Binary to Decimal.\n5- Octal to Decimal.\n6- HexaDecimal to Decimal.\n7- Octal to HexaDecimal.\n8- HexaDecimal to Octal \n9- Enter zero(" << "0" << ") to Exit.\n";

    while (NumericalSys != 0)
    {
    System:
        cout << "Enter The System Number you want: ";
        //Taking The user System choice.
        cin >> NumericalSys;

        if (NumericalSys > 8 || NumericalSys < 0)
        {
            cout << "Please Enter a System number from the list above!\n";
            goto System;
        }
        //choosing the correct System.
        if (NumericalSys == 1)
        {
            SysBase = 2;
        Enter:
            cout << "Please Enter The Number in Decimal(Without fractions): ";
            //Asking the user to Enter The Number in Decimal.
            cin >> Number;
            //validate the number.
            for (int i = 0; i < Number.length(); i++)
            {
                if (Number[i] < 48 || Number[i] > 57)
                {
                    cout << "You Entered an Invalid Decimal Number!\nPlease try again.\n";
                    goto Enter;
                }
            }

            //converting the number from string to integer.
            intNumber = stoi(Number);
            //converting the number from Decimal to Binary.
            answer = reversDigits(DECtoAll(intNumber, SysBase));
            cout << "The Number in Binary = " << answer << "\n";
        }
        if (NumericalSys == 2)
        {
            SysBase = 8;
        Enter2:
            cout << "Please Enter The Number in Decimal(Without fractions): ";
            //Asking the user to Enter The Number in Decimal.
            cin >> Number;
            //validate the number.
            for (int i = 0; i < Number.length(); i++)
            {
                if (Number[i] < 48 || Number[i] > 57)
                {
                    cout << "You Entered an Invalid Decimal Number!\nPlease try again.\n";
                    goto Enter2;
                }
            }
            //converting the number from string to integer.
            intNumber = stoi(Number);
            //converting the number from Decimal to Octal.
            answer = reversDigits(DECtoAll(intNumber, SysBase));
            cout << "The Number in Octal = " << answer << "\n";
        }

        if (NumericalSys == 3)
        {
            SysBase = 16;
        Enter3:
            cout << "Please Enter The Number in Decimal(Without fractions): ";
            //Asking the user to Enter The Number in Decimal.
            cin >> Number;
            //validate the number.
            for (int i = 0; i < Number.length(); i++)
            {
                if (Number[i] < 48 || Number[i] > 57)
                {
                    cout << "You Entered an Invalid Decimal Number!\nPlease try again.\n";
                    goto Enter3;
                }
            }
            //converting the number from string to integer.
            intNumber = stoi(Number);
            //converting the number from Decimal to Hexa.
            HexaAnswer = DECtoHEX(intNumber, SysBase);
            reverse(HexaAnswer.begin(), HexaAnswer.end());
            cout << "The Number in Hexa = " << HexaAnswer << "\n";
        }
        if (NumericalSys == 4)
        {
            SysBase = 2;
        EnterBi:
            cout << "Please Enter The Number in Binary(Without fractions): ";
            //Asking the user to Enter The Number in Binary.
            cin >> Number;
            //validate the number.
            for (int i = 0; i < Number.length(); i++)
            {
                if (Number[i] < 48 || Number[i] > 49)
                {
                    cout << "You Entered an Invalid Binary Number!\nPlease try again.\n";
                    goto EnterBi;
                }
            }
            //Converting The Binary Number to Decimal.
            answer = AlltoDec(Number, SysBase);
            cout << "The Number in Decimal = " << answer << "\n";
        }
        if (NumericalSys == 5)
        {
            SysBase = 8;
        EnterOct:
            cout << "Please Enter The Number in Octal(Without fractions): ";
            //Asking the user to Enter The Number in Octal.
            cin >> Number;
            //validate the number.
            for (int i = 0; i < Number.length(); i++)
            {
                if (Number[i] < 48 || Number[i] > 55)
                {
                    cout << "You Entered an Invalid Octal Number!\nPlease try again.\n";
                    goto EnterOct;
                }
            }
            //Converting The Octal Number to Decimal.
            answer = AlltoDec(Number, SysBase);
            cout << "The Number in Decimal = " << answer << "\n";
        }
        if (NumericalSys == 6)
        {
            SysBase = 16;
        EnterHexa:
            cout << "Please Enter The Number in Hexa(Without fractions): ";
            //Asking the user to Enter The Number in HexaDecimal.
            cin >> Number;
            //validate the number.
            for (int i = 0; i < Number.length(); i++)
            {
                if (Number[i] < 48 || (Number[i] > 57 && Number[i] < 65) || Number[i] > 70)
                {
                    cout << "You Entered an Invalid HexaDecimal Number!\nPlease try again.\n";
                    goto EnterHexa;
                }
            }
            //Converting The HexaDecimal Number to Decimal.
            answer = HexatoDec(Number, SysBase);
            cout << "The Number in Decimal = " << answer << "\n";
        }
        if (NumericalSys == 7)
        {
            SysBase = 8;
        EnterOct2:
            cout << "Please Enter The Number in Octal(Without fractions): ";
            //Asking the user to Enter The Number in Octal.
            cin >> Number;
            //validate the number.
            for (int i = 0; i < Number.length(); i++)
            {
                if (Number[i] < 48 || Number[i] > 55)
                {
                    cout << "You Entered an Invalid Octal Number!\nPlease try again.\n";
                    goto EnterOct2;
                }
            }
            //Converting The Octal Number to Decimal.
            DeciamlNumber = AlltoDec(Number, SysBase);
            //Converting The Decimal Number to HexaDecimal.
            HexaAnswer = DECtoHEX(DeciamlNumber, 16);
            reverse(HexaAnswer.begin(), HexaAnswer.end());
            cout << "The Number in Hexa = " << HexaAnswer << "\n";
        }
        if (NumericalSys == 8)
        {
            SysBase = 16;
        EnterHexa2:
            cout << "Please Enter The Number in Hexa(Without fractions): ";
            //Asking the user to Enter The Number in HexaDecimal.
            cin >> Number;
            //validate the number.
            for (int i = 0; i < Number.length(); i++)
            {
                if (Number[i] < 48 || (Number[i] > 57 && Number[i] < 65) || Number[i] > 70)
                {
                    cout << "You Entered an Invalid HexaDecimal Number!\nPlease try again.\n";
                    goto EnterHexa2;
                }
            }
            //Converting The HrxaDecimal Number to Decimal.
            DeciamlNumber = HexatoDec(Number, SysBase);
            //Converting The Decimal Number to Octal.
            answer = reversDigits(DECtoAll(DeciamlNumber, 8));
            cout << "The Number in Octal = " << answer << "\n";
        }
    }
    return 0;
}