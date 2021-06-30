#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#include <math.h>

int main()
{
int cotinue=1;
long int org_num=0, org_base=0, valid_org_val, pos_org_num, new_num, base10_num, remainder;
int new_base=0;
int pow_limit, pow_test;
int cur_term=0;
cout<<setiosflags(ios::left);
do
{
do
{
cout<<endl<<"Enter the base that the original number must be converted to\n"<<setw(67)<<"(the value should be between 2 and 16, inclusively).";
cin>>new_base;
} while((new_base < 2) || (new_base > 16));
do
{
cout<<"\n\nInput the integer that must be converted.\n\nIf the new base is 2, then the original number must be\ngreater than or equal to -1,000 and less than or equal to 1,000.\n\nIf the new base is > 2 and < 11, then the initial number\nshould be between -10,000 and 10,000, inclusively.\n\nWhen the new base is larger than 10, the number\n"<<setw(67)<<"must be between -1,000,000 and 1,000,000, inclusively.";
cin>>org_num;
} while((((org_num < -1000) || (org_num > 1000)) && (new_base == 2)) || (((org_num < -10000) || (org_num > 10000)) && ((new_base > 2) && (new_base < 11))) || (((org_num < -1000000) || (org_num > 1000000)) && (new_base > 10)));
cout<<endl;
do
{
cout<<"\nWhat is the base of the initial number\n"<<setw(67)<<"(the base should be between 2 and 10, inclusively)?";
cin>>org_base;
} while((org_base < 2) || (org_base > 10));
clrscr(); //Second Page Begins to Be Processed
//***Full Conversion Process Begins Below
if(org_num < 0)
pos_org_num = org_num * -1;
else
pos_org_num = org_num;
//**Start of Conversion to Base Ten
for(pow_test=0; pow(10, pow_test) <= pos_org_num; ++pow_test);
for(pow_limit=(pow_test - 1), remainder=pos_org_num, base10_num=0, valid_org_val=1; pow_limit >= 0; --pow_limit)
{
cur_term = (remainder / pow(10, pow_limit));
if(cur_term >= org_base)
{
pow_limit=-1;
valid_org_val=0;
}
base10_num = (base10_num + (cur_term * pow(org_base, pow_limit)));
remainder = (remainder - (pow(10, pow_limit) * cur_term));
}
//**End of Base Ten Conversion
if(valid_org_val == 0)
cout<<"\n\n\n\nError: The Base and the Value of the Original Number Do not Coincide";
else
{
cout<<"\n\n\n\nThe conversion of "<<org_num<<" from base "<<org_base<<" to base "<<new_base<<" reads as follows:\n\n";
for(pow_test=0; pow(new_base, pow_test) <= base10_num; ++pow_test);
if(new_base < 11)
{
for(pow_limit=(pow_test-1), remainder=base10_num, new_num=0; pow_limit >= 0; --pow_limit)
{
cur_term = pow(new_base, pow_limit);
new_num = new_num + (pow(10, pow_limit) * (remainder / cur_term));
remainder = (remainder - ((remainder / cur_term) * cur_term));
}
if(org_num < 0)
new_num = new_num * -1;
cout<<new_num; //The user's final, highly desired conversion solution is outputted onto the screen.
}
else
{
for(pow_limit=(pow_test-1), remainder=base10_num; pow_limit >= 0; --pow_limit)
{
cur_term = pow(new_base, pow_limit);
if((remainder / cur_term) < 10)
cout<<(remainder / cur_term);
else
cout<<char(65 + ((remainder / cur_term) - 10));
remainder = (remainder - ((remainder / cur_term) * cur_term));
}
}
}
//***End of Full Base Conversion
cout<<"\n\n\n\n\n\n\n\tWould you like to run the conversion process again?\n\t\t\t\t(1 = Yes, 2 = No)\n\t\t\t\t\t";
cin>>cotinue;
clrscr();
} while(cotinue == 1);
return 0;
}
