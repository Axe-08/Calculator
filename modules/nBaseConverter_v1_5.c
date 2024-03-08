#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
void decimal_to_binary_unsigned()
{
    int decimal_representation, output_decimal, index = 0;
    char reverse_binary_representation[50] = "";
    printf("Enter a decimal number:\n");
    scanf("%d", &decimal_representation);
    output_decimal = decimal_representation;
    // using algorithm to find reverse order of binary representaion
    if (decimal_representation == 0)
    {
        printf("Binary representation of %d is :\n0\n", output_decimal);
    }
    else
    {

        while (decimal_representation != 0)
        {
            reverse_binary_representation[index] = (decimal_representation % 2) + '0';
            index++;
            decimal_representation /= 2;
        }

        char binary_representation[50] = "";

        // reversing the order of reversed string to get correct string
        for (int i = 0; i < index; i++)
        {
            binary_representation[i] = reverse_binary_representation[index - i - 1];
        }
        binary_representation[index] = '\0'; // null terminating the string

        printf("Binary representation of %d is :\n%s\n", output_decimal, binary_representation);
    }
    
}
void decimal_to_binary_signed()
{
    int quotient, remainder, decimal_representation, output_decimal, index;
    char reverse_binary_representation[50] = "";
    char binary_representation[50] = "";
    bool neg;
    printf("Enter a decimal number:\n");
    scanf("%d", &decimal_representation);
    output_decimal = decimal_representation;

    if (decimal_representation < 0)
    {
        decimal_representation = -(decimal_representation);
        neg = true;
    }
    else
    {
        neg = false;
    }

    // using algorithm to find reverse order of binary representaion
    if (decimal_representation == 0)
    { // special case for 0
        binary_representation[0] = '0';
    }
    else
    {
        index = 0;
        while (decimal_representation != 0)
        {
            reverse_binary_representation[index] = (decimal_representation % 2) + '0';
            decimal_representation /= 2;
            index++;
        }
                //adding the case for negetive
        if (neg)
        {
            reverse_binary_representation[index] = '1';
        }
        else
        {
            reverse_binary_representation[index] = '0';
        }
        // reversing the order of reversed string to get correct string
        for (int i = 0; i < index + 1; i++)
        {
            binary_representation[i] = reverse_binary_representation[index - i];
        }
        binary_representation[index + 1] = '\0'; // null terminating the string
    }
    printf("Binary representation of %d is :\n%s\n\n\t\t\t**first digit of binary number represents sign 1 reps -ve while 0 reps +ve**", output_decimal, binary_representation);

    
}
void binary_to_decimal_unsigned()
{
    
    char binstr[50];
    printf("enter binary number\n");
    scanf("%49s", binstr);

    
    int length = strlen(binstr);
    /*printf("%d", length);
     */
    if (binstr[0] == '0')
    {
        printf("Please provide a binary expression without any uneccesary bits! i.e. write '1'as greatest significant digit");
    }
    else{
            long b, a;
            for (int i = 0; i < length; i++)
            {
                int digit = binstr[i] - '0';
                /*printf("\ncharacter: %c, integer:%d", binstr[i], digit);
                 */
                b = digit * pow(2, length - i - 1);
                a = a + b;
            }
            printf("\ndecimal representation is:\n%ld", a);
        }
    
}
void hexadecimal_to_binary()
{
    char hexastr[50];
    printf("enter hexadecimal number\n");
    scanf("%49s", hexastr);

    
    int length = strlen(hexastr);
    /*printf("%d", length);
     */
    if (hexastr[0] == '0')
    {
        printf("Please provide a hexadecimal expression without any uneccesary bits! i.e. write '0'as not the greatest significant digit");
    }
    else{
            long b, a;
            int digit;
            for (int i = 0; i < length; i++)
            {switch (hexastr[i])
            {
            case 'F':
                digit=15;
                break;
            case 'E':
                digit=14;
                break;
            case 'D':
                digit=13;
                break;
            case 'C':
                digit=12;
                break;
            case 'B':
                digit=11;
                break;
            case 'A':
                digit=10;
                break;
            default:
                 digit = hexastr[i] - '0';
                /*printf("\ncharacter: %c, integer:%d", binstr[i], digit);
                 */
                
                break;
            }
               b = digit * pow(16, length - i - 1);
                a = a + b;
            }
            
             
             int decimal_representation, output_decimal, index = 0;
    char reverse_binary_representation[50] = "";
    decimal_representation = a;
    output_decimal = decimal_representation;
    // using algorithm to find reverse order of binary representaion
    if (decimal_representation == 0)
    {
        printf("Binary representation of %s is :\n0\n", hexastr);
    }
    else
    {

        while (decimal_representation != 0)
        {
            reverse_binary_representation[index] = (decimal_representation % 2) + '0';
            index++;
            decimal_representation /= 2;
        }

        char binary_representation[50] = "";

        // reversing the order of reversed string to get correct string
        for (int i = 0; i < index; i++)
        {
            binary_representation[i] = reverse_binary_representation[index - i - 1];
        }
        binary_representation[index] = '\0'; // null terminating the string

        printf("Binary representation of %s is :\n%s\n", hexastr, binary_representation);
    }
        }
    
}
void binary_to_hexadecimal()
{
    long b, a;
    char binstr[50];
    printf("enter binary number\n");
    scanf("%49s", binstr);

    
    int length = strlen(binstr);
    /*printf("%d", length);
     */
    if (binstr[0] == '0')
    {
        printf("Please provide a binary expression without any uneccesary bits! i.e. write '1'as greatest significant digit");
    }
    else{
            
            for (int i = 0; i < length; i++)
            {
                int digit = binstr[i] - '0';
                /*printf("\ncharacter: %c, integer:%d", binstr[i], digit);
                 */
                b = digit * pow(2, length - i - 1);
                a = a + b;
            }
           

        }
     int quotient, remainder, output_decimal;
    char reverse_hexa_representation[50] = "";
    long decimal_representation=a;
        output_decimal = decimal_representation;
    // using algorithm to find reverse order of binary representaion

    if (decimal_representation==0)
    {
        printf("Hexa decimal representation of 0 is :\n0\n");
    }
    else
    {
        while (decimal_representation != 0)
        {
            char hexabuff[3], hexachar[2]; // buffer to add character to string
            quotient = decimal_representation / 16;
            remainder = decimal_representation % 16;
            decimal_representation = quotient;
            switch (remainder)
            {
            case 10:
                hexachar[0] = 'A';
                hexachar[1] = '\0';
                strcat(reverse_hexa_representation, hexachar);
                break;

            case 11:
                hexachar[0] = 'B';
                hexachar[1] = '\0';
                strcat(reverse_hexa_representation, hexachar);
                break;
            case 12:
                hexachar[0] = 'C';
                hexachar[1] = '\0';
                strcat(reverse_hexa_representation, hexachar);
                break;
            case 13:
                hexachar[0] = 'D';
                hexachar[1] = '\0';
                strcat(reverse_hexa_representation, hexachar);
                break;
            case 14:
                hexachar[0] = 'E';
                hexachar[1] = '\0';
                strcat(reverse_hexa_representation, hexachar);
                break;
            case 15:
                hexachar[0] = 'F';
                hexachar[1] = '\0';
                strcat(reverse_hexa_representation, hexachar);
                break;

            default:

                sprintf(hexabuff, "%d", remainder);
                strcat(reverse_hexa_representation, hexabuff);
                break;
            }
        }

              int length = strlen(reverse_hexa_representation);
              char hexa_representation[50] = "";

              // reversing the order of reversed string to get correct string
              for (int i = 0; i < length; i++)
              {
                  hexa_representation[i] = reverse_hexa_representation[length - i - 1];
              }
              hexa_representation[length] = '\0'; // null terminating the string

                printf("Hexa decimal representation of %s is :\n%s\n", binstr, hexa_representation);
    }
}
void decimal_to_hexadecimal_unsigned()
{
    
    int quotient, remainder, decimal_representation, output_decimal;
    char reverse_hexa_representation[50] = "";
    printf("Enter a decimal number:\n");
    scanf("%d", &decimal_representation);
    output_decimal = decimal_representation;
    // using algorithm to find reverse order of binary representaion

    if (decimal_representation==0)
    {
        printf("Hexa decimal representation of 0 is :\n0\n");
    }
    else
    {
        while (decimal_representation != 0)
        {
            char hexabuff[3], hexachar[2]; // buffer to add character to string
            quotient = decimal_representation / 16;
            remainder = decimal_representation % 16;
            decimal_representation = quotient;
            switch (remainder)
            {
            case 10:
                hexachar[0] = 'A';
                hexachar[1] = '\0';
                strcat(reverse_hexa_representation, hexachar);
                break;

            case 11:
                hexachar[0] = 'B';
                hexachar[1] = '\0';
                strcat(reverse_hexa_representation, hexachar);
                break;
            case 12:
                hexachar[0] = 'C';
                hexachar[1] = '\0';
                strcat(reverse_hexa_representation, hexachar);
                break;
            case 13:
                hexachar[0] = 'D';
                hexachar[1] = '\0';
                strcat(reverse_hexa_representation, hexachar);
                break;
            case 14:
                hexachar[0] = 'E';
                hexachar[1] = '\0';
                strcat(reverse_hexa_representation, hexachar);
                break;
            case 15:
                hexachar[0] = 'F';
                hexachar[1] = '\0';
                strcat(reverse_hexa_representation, hexachar);
                break;

            default:

                sprintf(hexabuff, "%d", remainder);
                strcat(reverse_hexa_representation, hexabuff);
                break;
            }
        }

              int length = strlen(reverse_hexa_representation);
              char hexa_representation[50] = "";

              // reversing the order of reversed string to get correct string
              for (int i = 0; i < length; i++)
              {
                  hexa_representation[i] = reverse_hexa_representation[length - i - 1];
              }
              hexa_representation[length] = '\0'; // null terminating the string

              printf("Hexa decimal representation of %d is :\n%s\n", output_decimal, hexa_representation);
    }       
    

}
void hexadecimal_to_decimal()
{
    char hexastr[50];
    printf("enter hexadecimal number\n");
    scanf("%49s", hexastr);

    
    int length = strlen(hexastr);
    /*printf("%d", length);
     */
    if (hexastr[0] == '0')
    {
        printf("Please provide a hexadecimal expression without any uneccesary bits! i.e. write '0'as not the greatest significant digit");
    }
    else{
            long b, a;
            int digit;
            for (int i = 0; i < length; i++)
            {switch (hexastr[i])
            {
            case 'F':
                digit=15;
                break;
            case 'E':
                digit=14;
                break;
            case 'D':
                digit=13;
                break;
            case 'C':
                digit=12;
                break;
            case 'B':
                digit=11;
                break;
            case 'A':
                digit=10;
                break;
            default:
                 digit = hexastr[i] - '0';
                /*printf("\ncharacter: %c, integer:%d", binstr[i], digit);
                 */
                
                break;
            }
               b = digit * pow(16, length - i - 1);
                a = a + b;
            }
            printf("\ndecimal representation of %s is:\n%ld",hexastr, a);
        }
    
}
void decimal_to_any_converter_unsigned()
{
    int decimal_representation, output_decimal, base,index = 0;
    char reverse_binary_representation[50] = "";
    printf("Enter a decimal number:\n");
    scanf("%d", &decimal_representation);
    printf("Enter the base you want to convert it into (between 2 and 10): \n");
    scanf("%d", &base);
    output_decimal = decimal_representation;
    // using algorithm to find reverse order of binary representaion
    if (decimal_representation == 0)
    {
        printf("base %d representation of %d is :\n0\n",base, output_decimal);
    }
    else
    {

        while (decimal_representation != 0)
        {
            reverse_binary_representation[index] = (decimal_representation % base) + '0';
            index++;
            decimal_representation /= base;
        }

        char base_representation[50] = "";

        // reversing the order of reversed string to get correct string
        for (int i = 0; i < index; i++)
        {
            base_representation[i] = reverse_binary_representation[index - i - 1];
        }
        base_representation[index] = '\0'; // null terminating the string

        printf("Representation of %d in base %d is :\n%s\n", output_decimal, base, base_representation);
    }
    
}

void nBasemain()
 {
    int dec1;
     printf("Welcome!\n Choose the type of conversion you want:\n\n");
    printf("1.decimal to binary\t\t2.binary to decimal\n3.binary to hexadecimal\t\t4.hexadecimal to binary\n");
    printf("5.decimal to hexadecimal\t6.hexadecimal to decimal\n7.decimal to any base\n");
    scanf("%d",&dec1);
    system("cls");
    switch (dec1)
    {
    case 1:
       int dec2;
        printf("you want 1.signed decimal to binary or 2.unsigned decimal to binary?");
        scanf("%d",&dec2);
        system("cls");
        switch (dec2)
        {
        case 1:
            decimal_to_binary_signed();
            break;
        case 2:
            decimal_to_binary_unsigned();
            break;
        default:
            break;
        }
        break;
    case 2:
        binary_to_decimal_unsigned();
        break;
    
    case 3:
        binary_to_hexadecimal();
        break;

    
    case 4:
        
        hexadecimal_to_binary();
        break;
    case 5:
        decimal_to_hexadecimal_unsigned();
        break;
    case 6:
        hexadecimal_to_decimal();
        break;
        
    case 7:
        decimal_to_any_converter_unsigned();
        break;
    default:
        break;
    }

 }

 // by Akshit S Bansal 
 // 24-08-2023
 // read the Readme


 //add return function in case of input error