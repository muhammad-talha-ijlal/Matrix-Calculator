#include <iostream>
#include <math.h>
using namespace std;

int temp[9];
int temp1[3][3];
int temp2[3][3];
int A[3][3];
int B[3][3];
int C[3][3];
int convert(string n)
{
    if (n == "0")
    {
        return 0;
    }
    float num = 0;
    int x;
    for (int i = 0; i < n.length(); i++)
    {
        x = (n[n.length() - i - 1]) - 48;
        num = num + x * pow(10, i);
    }

    return num;
}
string slice(string line, int field)
{
    string word;
    int comma = 0;

    for (int i = 3; i < line.length() - 1; i++)
    {
        if (line[i] == ',')
        {
            comma++;
        }
        else if (comma == field)
        {
            word += line[i];
        }
    }
    return word;
}
void initialize(char mat, string input)
{
    for (int i = 0; i < 9; i++)
    {
        temp[i] = convert(slice(input, i));
    }
    if (mat == 'A')
    {
        int count = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                A[i][j] = temp[count];
                count++;
            }
        }
    }
    if (mat == 'B')
    {
        int count = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                B[i][j] = temp[count];
                count++;
            }
        }
    }
    if (mat == 'C')
    {
        int count = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                C[i][j] = temp[count];
                count++;
            }
        }
    }
}

string fun(string input)
{
    if (input[2] == '{')
    {
        return "initialize";
    }

    if (input[3] == '+')
    {
        return "add";
    }
    else if (input[3] == '-')
    {
        cout << "here";
        return "sub";
    }
    else if (input[3] == '*')
    {
        return "mul";
    }
    else if (input[3] == '/')
    {
        return "div";
    }
    if (input[0] == 'p')
    {
        return "print";
    }
    if (input[0] == 'i')
    {
        if (input[2] == 'D')
        {
            return "checkDiagonal";
        }
        else if (input[2] == 'I')
        {
            return "checkIdentity";
        }
        else if (input[2] == 'S')
        {
            return "checkSymmetry";
        }
    }
    if (input[0] == 't')
    {
        return "transpose";
    }
    for (int i = 48; i < 58; i++)
    {
        if (input[0] == char(i))
        {
            return "scalar";
        }
    }
}
void add(char mat, char mat1, char mat2)
{
    if (mat == 'A')
    {
        if (mat1 == 'B')
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    A[i][j] = B[i][j] + C[i][j];
                }
            }
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    A[i][j] = B[i][j] + C[i][j];
                }
            }
        }
    }
    if (mat == 'B')
    {
        if (mat1 == 'A')
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    B[i][j] = A[i][j] + C[i][j];
                }
            }
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    B[i][j] = A[i][j] + C[i][j];
                }
            }
        }
    }
    if (mat == 'C')
    {
        if (mat1 == 'A')
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    C[i][j] = B[i][j] + A[i][j];
                }
            }
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    C[i][j] = B[i][j] + A[i][j];
                }
            }
        }
    }
}
void sub(char mat, char mat1, char mat2)
{
    if (mat == 'A')
    {
        if (mat1 == 'B')
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    A[i][j] = B[i][j] - C[i][j];
                }
            }
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    A[i][j] = C[i][j] - B[i][j];
                }
            }
        }
    }
    if (mat == 'B')
    {
        if (mat1 == 'A')
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    B[i][j] = A[i][j] - C[i][j];
                }
            }
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    B[i][j] = C[i][j] - A[i][j];
                }
            }
        }
    }
    if (mat == 'C')
    {
        if (mat1 == 'A')
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    C[i][j] = A[i][j] - B[i][j];
                }
            }
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    C[i][j] = B[i][j] - A[i][j];
                }
            }
        }
    }
}
void mul(char mat, char mat1, char mat2)
{
    if (mat == 'A')
    {
        if (mat1 == 'B')
        {
            for (int k = 0; k < 3; k++)
            {
                for (int i = 0; i < 3; i++)
                {
                    int temp = 0;
                    for (int j = 0; j < 3; j++)
                    {
                        temp = temp + B[k][j] * C[j][i];
                    }
                    A[k][i] = temp;
                }
            }
        }
        else
        {
            for (int k = 0; k < 3; k++)
            {
                for (int i = 0; i < 3; i++)
                {
                    int temp = 0;
                    for (int j = 0; j < 3; j++)
                    {
                        temp = temp + C[k][j] * B[j][i];
                    }
                    A[k][i] = temp;
                }
            }
        }
    }
    if (mat == 'B')
    {
        if (mat1 == 'A')
        {
            for (int k = 0; k < 3; k++)
            {
                for (int i = 0; i < 3; i++)
                {
                    int temp = 0;
                    for (int j = 0; j < 3; j++)
                    {
                        temp = temp + A[k][j] * C[j][i];
                    }
                    B[k][i] = temp;
                }
            }
        }
        else
        {
            for (int k = 0; k < 3; k++)
            {
                for (int i = 0; i < 3; i++)
                {
                    int temp = 0;
                    for (int j = 0; j < 3; j++)
                    {
                        temp = temp + C[k][j] * A[j][i];
                    }
                    B[k][i] = temp;
                }
            }
        }
    }
    if (mat == 'C')
    {
        if (mat1 == 'A')
        {
            for (int k = 0; k < 3; k++)
            {
                for (int i = 0; i < 3; i++)
                {
                    int temp = 0;
                    for (int j = 0; j < 3; j++)
                    {
                        temp = temp + B[k][j] * C[j][i];
                    }
                    C[k][i] = temp;
                }
            }
        }
        else
        {
            for (int k = 0; k < 3; k++)
            {
                for (int i = 0; i < 3; i++)
                {
                    int temp = 0;
                    for (int j = 0; j < 3; j++)
                    {
                        temp = temp + C[k][j] * B[j][i];
                    }
                    C[k][i] = temp;
                }
            }
        }
    }
}
void print(char mat)
{
    if (mat == 'A')
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << A[i][j] << "\t";
            }
            cout << endl;
        }
    }
    if (mat == 'B')
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << B[i][j] << "\t";
            }
            cout << endl;
        }
    }
    if (mat == 'C')
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << C[i][j] << "\t";
            }
            cout << endl;
        }
    }
}

void transpose(char mat)
{
    if (mat == 'A')
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp1[i][j] = A[i][j];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                A[i][j] = temp1[j][i];
            }
        }
    }
    if (mat == 'B')
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp1[i][j] = B[i][j];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                B[i][j] = temp1[j][i];
            }
        }
    }
    if (mat == 'C')
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp1[i][j] = C[i][j];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                C[i][j] = temp1[j][i];
            }
        }
    }
}

void scalMul(int num, char mat)
{
    if (mat == 'A')
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                A[i][j] = num * A[i][j];
            }
        }
    }
    else if (mat == 'B')
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                B[i][j] = num * B[i][j];
            }
        }
    }
    else if (mat == 'C')
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                C[i][j] = num * C[i][j];
            }
        }
    }
}

bool isIdentity(char mat)
{
    if (mat == 'A')
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == j)
                {
                    if (A[i][j] != 1)
                    {
                        return false;
                    }
                }
                else
                {
                    if (A[i][j] != 0)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    if (mat == 'B')
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == j)
                {
                    if (B[i][j] != 1)
                    {
                        return false;
                    }
                }
                else
                {
                    if (B[i][j] != 0)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    if (mat == 'C')
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == j)
                {
                    if (C[i][j] != 1)
                    {
                        return false;
                    }
                }
                else
                {
                    if (C[i][j] != 0)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}

bool isDiagonal(char mat)
{
    if (mat == 'A')
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i != j)
                {
                    if (A[i][j] != 0)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    if (mat == 'B')
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i != j)
                {
                    if (B[i][j] != 0)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    if (mat == 'C')
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i != j)
                {
                    if (C[i][j] != 0)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}

bool isSymmetry(char mat)
{
    if (mat == 'A')
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp1[i][j] = A[i][j];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp2[i][j] = temp1[j][i];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (A[i][j] != temp2[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    if (mat == 'A')
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp1[i][j] = B[i][j];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp2[i][j] = temp1[j][i];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (B[i][j] != temp2[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    if (mat == 'A')
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp1[i][j] = B[i][j];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp2[i][j] = temp1[j][i];
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (B[i][j] != temp2[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
}

int determinant(char mat)
{
    int det = 0 if (mat == 'A')
    {
        det = (A[1][1] *[2][2] - A[2][1] * A[1][2]) - (A[1][0] * A[2][2] - A[2][0] * A[1][2]) + (A[1][0] * A[2][1] - A[2][0] * A[1][1])
    }
    else if (mat == 'B')
    {
        det = (B[1][1] *[2][2] - B[2][1] * B[1][2]) - (B[1][0] * B[2][2] - B[2][0] * B[1][2]) + (B[1][0] * B[2][1] - B[2][0] * B[1][1])
    }
    else if (mat == 'C')
    {
        det = (C[1][1] *[2][2] - C[2][1] * C[1][2]) - (C[1][0] * C[2][2] - C[2][0] * C[1][2]) + (C[1][0] * C[2][1] - C[2][0] * C[1][1])
    }

    return det;
}
main()
{
    string input;
    char mat, mat1, mat2;
    cout << ">>";
    cin >> input;
    while (input != "Exit" && input != "exit")
    {
        string func = fun(input);
        if (func == "initialize")
        {
            mat = input[0];
            initialize(mat, input);
        }
        else if (func == "add")
        {
            mat = input[0];
            mat1 = input[2];
            mat2 = input[4];
            add(mat, mat1, mat2);
        }
        else if (func == "sub")
        {
            cout << "here2";
            mat = input[0];
            mat1 = input[2];
            mat2 = input[4];
            cout << mat << mat1 << mat2;
            sub(mat, mat1, mat2);
        }
        else if (func == "mul")
        {
            mat = input[0];
            mat1 = input[2];
            mat2 = input[4];
            mul(mat, mat1, mat2);
        }
        else if (func == "print")
        {
            for (int i = 0; input[i] != '\0'; i++)
            {
                if (input[i] == 'A' || input[i] == 'B' || input[i] == 'C')
                {
                    mat = input[i];
                    break;
                }
            }
            print(mat);
        }
        else if (func == "scalar")
        {
            int num = input[0] - 48;
            mat = input[2];

            scalMul(num, mat);
        }
        else if (func == "transpose")
        {
            for (int i = 0; input[i] != '\0'; i++)
            {
                if (input[i] == 'A' || input[i] == 'B' || input[i] == 'C')
                {
                    mat = input[i];
                    break;
                }
            }
            transpose(mat);
        }
        else if (func == "checkDiagonal")
        {
            for (int i = 0; input[i] != '\0'; i++)
            {
                if (input[i] == 'A' || input[i] == 'B' || input[i] == 'C')
                {
                    mat = input[i];
                    break;
                }
            }
            cout << isDiagonal(mat) << endl;
        }
        else if (func == "checkSymmetry")
        {
            for (int i = 0; input[i] != '\0'; i++)
            {
                if (input[i] == 'A' || input[i] == 'B' || input[i] == 'C')
                {
                    mat = input[i];
                    break;
                }
            }
            cout << isSymmetry(mat) << endl;
        }
        else if (func == "checkIdentity")
        {
            for (int i = 0; input[i] != '\0'; i++)
            {
                if (input[i] == 'A' || input[i] == 'B' || input[i] == 'C')
                {
                    mat = input[i];
                    break;
                }
            }
            cout << isIdentity(mat) << endl;
        }

        cout << ">>";
        cin >> input;
    }
}