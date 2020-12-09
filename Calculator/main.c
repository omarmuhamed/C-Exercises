#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

void ModeSelecting();

void SimpleMode();

void ComplexMode();

int CheckifInt(double number);

double SpecialScan();
double LatestResult;
int main()
{
    printf("Welcome!\n");
    ModeSelecting();
}

int CheckifInt(double number)
{
    return floor(number) == number ? 1 : 0;
}

double SpecialScan()
{
    char x[100];
    scanf("%[^\n]*c",x);
    fflush(stdin);
    if (((int) *x) == 88 || ((int) *x) == 120)
    {
        return LatestResult;
    }
    else
    {
        return atof(x);
    }
}
void ModeSelecting()
{
    int mode;
ModeSelecting:
    printf("Select mode.\n1: Simple\n2: Complex\nMode:");
    scanf("%d", &mode);
    fflush(stdin);
    switch (mode)
    {
    case 1:
        SimpleMode();
        break;
    case 2:
        ComplexMode();
        break;
    default:
        printf("Wrong selection, please try again.\n");
        goto ModeSelecting;
    }

}

void SimpleMode()
{
    int op;
    int i;
    int j;
    int ns;
    char numbers[100];
    double _numbers[50];
    char split[2] = " ";
    char *token;
    double result1;
SelectOperation:
    printf("Select an operation:\n1: +\n2: -\n3: *\n4: /\nOperation: ");
    scanf("%d", &op);
    fflush(stdin);
    switch (op)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        printf("Wrong selection, try again.\n");
        goto SelectOperation;
    }
EnterNumbers:
    i = 0;
    j = 1;
    printf("Enter numbers separated by space\n");

    if (LatestResult)
    {
        printf("If you would like to use the latest result type \"X\"\n");
    }
    printf("Numbers: ");
    scanf("%[^\n]*c", numbers);
    fflush(stdin);
    token = strtok(numbers, split);
    while (token != NULL)
    {
        if (((int) *token) == 88 || ((int) *token) == 120)
        {
            _numbers[i] = LatestResult;
            token = strtok(NULL, split);
            i++;
            continue;
        }
        else
        {
            _numbers[i] = atof(token);
            token = strtok(NULL, split);
            i++;
        }
    }
    switch (op)
    {
    case 1:
        result1 = _numbers[0];
        for (j = 1; j < i; j++)
        {
            result1 += _numbers[j];
        }
        break;
    case 2:
        result1 = _numbers[0];
        for (j = 1; j < i; j++)
        {
            result1 -= _numbers[j];
        }
        break;
    case 3:
        result1 = _numbers[0];
        for (j = 1; j < i; j++)
        {
            result1 *= _numbers[j];
        }
        break;
    case 4:
        result1 = _numbers[0];
        for (j = 1; j < i; j++)
        {
            result1 /= _numbers[j];
        }
        break;
    default:
        break;

    }
    LatestResult = result1;
    printf("Result: %f\n", result1);
    SelectNextStep:
    printf("Select your next step.\n1: Doing the same operation again.\n2: Back to operations menu.\n3: Change the mode.\n4: Exit\nAnswer: ");
    scanf("%d", &ns);
    fflush(stdin);
    switch (ns)
    {
    case 1:
        goto EnterNumbers;
    case 2:
        goto SelectOperation;
    case 3:
        ModeSelecting();
    case 4:
        exit(0);
    default:
        printf("Wrong selection, try again\n");
        goto SelectNextStep;
    }


}

void ComplexMode()
{
    int op,ns,i;
    int sop=0;
    double result;
    double x,y;
    bool issimpleop = false;
    int simpleop;
OperationsSelect:
    printf("Select an operation.\n1: Logarithm\n2: Power\n3: Root\n4: Mod\n5: Floor\n6: Ceil\n7: Trigonometric\n8: Exp(e to the power of x)\n9: Factorial\nOperation: ");
    scanf("%d", &op);
    fflush(stdin);
    if(LatestResult)
    {
        printf("If you would like to use the latest result type \"X\"\n");
    }
OperationsSwitch:
    switch (op)
    {
    case 1:
        goto LogarithmSubOperations;
    case 2:
        goto RootAndPowerOperations;
    case 3:
        goto RootAndPowerOperations;
    case 4:
        goto ModOperation;
    case 5:
        goto CeilAndFloorOperations;
    case 6:
        goto CeilAndFloorOperations;
    case 7:
        goto TrigonometricSubOperations;
    case 8:
        goto ExpOperation;
    case 9:
        goto FactorialOperation;
    default:
        printf("Wrong selection, try again.\n");
        goto OperationsSelect;
    }
LogarithmSubOperations:
    printf("Select operation:\n1: Natural logarithm\n2: Base 10 logarithm\n3: Normal logarithm\nOperation: ");
    scanf("%d", &sop);
    fflush(stdin);
LogarithmSwitch:
    switch (sop)
    {
    case 1:
        printf("Enter a number: ");
        x = SpecialScan();
        result = log(x);
        goto EndOfOperation;
    case 2:
        printf("Enter a number: ");
        x = SpecialScan();
        result = log10(x);
        goto EndOfOperation;
    case 3:
        printf("Enter a number: ");
        x = SpecialScan();
        printf("Enter the base: ");
        y = SpecialScan();
        result = log(x) / log(y);
        goto EndOfOperation;
    default:
        printf("Wrong selection, try again\n");
        goto LogarithmSubOperations;
    }

RootAndPowerOperations:
    printf("Enter a number: ");
    x = SpecialScan();
    if (op == 2)
    {
        printf("Enter the power: ");
        y = SpecialScan();
    }
    else
    {
        printf("Enter the root: ");
        y = SpecialScan();
        if (CheckifInt(y))
        {
            y = 1/y;
        }
    }
    result = pow(x, y);
    goto  EndOfOperation;

ModOperation:
    printf("Enter the first number: ");
    x = SpecialScan();
    printf("Enter the second number: ");
    y = SpecialScan();
    result = fmod(x,y);
    goto EndOfOperation;

CeilAndFloorOperations:
    printf("Enter a number: ");
    x = SpecialScan();
    if (op == 5)
    {
        result = floor(x);
    }
    else
    {
        result = ceil(x);
    }
    goto EndOfOperation;

TrigonometricSubOperations:
    printf("Select operation:\n1: Sine\n2: Cosine\n3: Tangent\n4: Cotangent\n5: Secant\n6: Cosecant\n7: Arc Sine\n8: Arc Cosine\n9: Arc Tangent\nOperation: ");
    scanf("%d", &sop);
    fflush(stdin);
TrigonometricSwitch:
    if (sop <= 6)
    {
        printf("Enter the angle in radian: ");
        x = SpecialScan();
        switch (sop)
        {
        case 1:
            result = sin(x);
            goto EndOfOperation;
        case 2:
            result = cos(x);
            goto EndOfOperation;
        case 3:
            result = tan(x);
            goto EndOfOperation;
        case 4:
            result = 1 / tan(x);
            goto EndOfOperation;
        case 5:
            result = 1 / cos(x);
            goto EndOfOperation;
        case 6:
            result = 1 / sin(x);
            goto EndOfOperation;
        default:
            printf("Wrong selection, try again.\n");
            goto TrigonometricSubOperations;
        }
    }
    else if (sop <= 8)
    {
ArcSCValue:
        printf("Enter a value between -1 and 1: ");
        x = SpecialScan();
        if (x < -1 || x > 1)
        {
            printf("Wrong value, try again.\n");
            goto ArcSCValue;
        }
        switch (sop)
        {
        case 7:
            result = asin(x);
            goto EndOfOperation;
        case 8:
            result = acos(x);
            goto EndOfOperation;
        }
    }
    else
    {
        switch (sop)
        {
        case 9:
            printf("Enter a value: ");
            x = SpecialScan();
            result = atan(x);
            goto EndOfOperation;
        default:
            printf("Wrong selection, try again.\n");
            goto TrigonometricSubOperations;
        }
    }

ExpOperation:
    printf("Enter the power: ");
    x = SpecialScan();
    result = exp(x);
    goto EndOfOperation;
FactorialOperation:
    printf("Enter a number: ");
    x = SpecialScan();
    if (CheckifInt(x) == 0 || x < 0) {
        printf("You should enter an integer higher than 0, try again\n");
        goto FactorialOperation;
    } else if (x == 0) {
        result = 1;
        goto EndOfOperation;
    }
    result = x;
    for (i = ((int) x - 1) ; i >= 1; i--) {
        result *=i;
    }
    goto EndOfOperation;

EndOfOperation:
    if (issimpleop)
    {
        switch (simpleop)
        {
        case 1:
            result = LatestResult + result;
            break;
        case 2:
            result = LatestResult - result;
            break;
        case 3:
            result = LatestResult * result;
            break;
        case 4:
            result =  LatestResult / result;
            break;
        }
        issimpleop = false;
    }
    LatestResult = result;
    printf("Result: %lf\n", result);
NextStepSelect:
    printf("Select your next step\n1: Doing the same operation again\n2: Doing the same operation alongside simple operation\n3: Change operation\n4: Doing another operation alongside simple operation\n5: Change mode\n");

    if (op == 1 || op == 7)
    {
        //sop = 0;
        printf("6: Back to sub-operations menu\n7: Exit\nNext step: ");
        scanf("%d", &ns);
        fflush(stdin);
        switch (ns)
        {
        case 6:
            printf("If you would like to use the latest result type \"X\"\n");
            if (op == 1)
            {
                goto LogarithmSubOperations;
            }
            else
            {
                goto TrigonometricSubOperations;
            }
        case 7:
            exit(0);
        }
    }
    else
    {
        printf("6: Exit\nNext step: ");
        scanf("%d", &ns);
        fflush(stdin);
    }
    switch (ns)
    {
    case 1:
        SameOperation:
        printf("If you would like to use the latest result type \"X\"\n");
        if (op == 1)
        {
            goto LogarithmSwitch;
        }
        else if (op == 7)
        {
            goto TrigonometricSwitch;
        }
        else
        {
            goto OperationsSwitch;
        }
    case 2:
        issimpleop = true;
        printf("Select operation:\n1: +\n2: -\n3: *\n4: /\nOperation: ");
        scanf("%d", &simpleop);
        fflush(stdin);
        goto SameOperation;
    case 3:
        goto OperationsSelect;
    case 4:
        issimpleop = true;
        printf("Select operation:\n1: +\n2: -\n3: *\n4: /\nOperation: ");
        scanf("%d", &simpleop);
        fflush(stdin);
        goto OperationsSelect;
    case 5:
        ModeSelecting();
    case 6:
        exit(0);
    default:
        printf("Wrong selection, try again\n");
        goto NextStepSelect;
    }

}