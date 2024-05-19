// 9.	WAP to show the use of Manipulators.
#include <iostream>
#include <iomanip>
using namespace std;
int main() {

    // Basic manipulators:
    cout<<"------------------------------------------------------------------"<<endl;
    cout<<"BASIC_MANIPULATORS"<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
    // endl: Inserts a newline character and flushes the output buffer.
    cout<<"Hello"<<endl<<"World"<<endl;
    // setw(width): Sets the minimum field width for the next element to be printed.
    cout<<setw(10)<<"Hello "<<setw(2)<<"World"<<endl;
    // setfill(char): Sets the character used to fill the padding space for setw.
    cout<<setw(10)<<setfill('0')<<"Hello "<<setw(2)<<"World"<<endl;
    // setprecision(precision): Sets the number of digits displayed for floating-point values after the decimal point.
    cout<<setprecision(10)<<1.96789<<" "<<setprecision(3)<<1.96789<<endl;

    // Numeric manipulators:
    cout<<"------------------------------------------------------------------"<<endl;
    cout<<"NUMERIC_MANIPULATORS"<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
    // showpos: Forces the display of a plus sign (+) for positive numbers.
    cout<<showpos<<2429<<" "<<2678<<endl;
    // noshowpos: Prevents the display of a plus sign (+) for positive numbers.
    cout<<noshowpos<<2429<<" "<<2678<<endl;
    // fixed: Use fixed-point notation for floating-point values.
    cout<<fixed<<2.345678<<" "<<0.1<<endl;
    // scientific: Use scientific notation for floating-point values.
    cout<<scientific<<2.345678<<" "<<0.0000000000123<<endl;
    // hex: Reads and writes values in hexadecimal format.
    cout<<hex<<2429<<endl;
    // dec: Reads and writes values in decimal format.
    cout<<dec<<2429<<endl;
    // oct: Reads and writes values in octal format.
    cout<<oct<<2429<<endl;
    // uppercase: Uses uppercase letters for hexadecimal values.
    cout<<uppercase<<hex<<2429<<endl;
    // nouppercase: Uses lowercase letters for hexadecimal values.
    cout<<nouppercase<<hex<<2429<<endl;
    // showbase: Displays the base (e.g., 0x for hexadecimal) for numeric values.
    cout<<showbase<<hex<<2429<<" "<<oct<<12<<endl;
    // noshowbase: Hides the base for numeric values.
    cout<<noshowbase<<hex<<2429<<" "<<oct<<12<<endl;

    cout<<dec<<setfill(' ');

    // Boolean manipulators:
    cout<<"------------------------------------------------------------------"<<endl;
    cout<<"BOOLEAN_MANIPULATORS"<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
    // boolalpha: Uses true/false for boolean values.
    cout<<boolalpha<<true<<" "<<false<<endl;
    // noboolalpha: Uses 1/0 for boolean values.
    cout<<noboolalpha<<true<<" "<<false<<endl;

    // Flags manipulators:
    cout<<"------------------------------------------------------------------"<<endl;
    cout<<"FLAG_MANIPULATORS"<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
    string input1,input2;
    // ios_base::skipws: Skips whitespaces during input.
    // *** By default >> skips whitespace. ***
    cout<<"STRING INPUT: ";
    cin>>input1;
    cout<<input1<<endl;
    cout<<"STRING INPUT: ";
    cin>>skipws>>input2;
    cout<<input2<<endl;
    // ios_base::left: Left-aligns output within the field width.
    // *** By default >> left align. ***
    cout<<setw(10)<<left<<"Hello"<<endl;
    // ios_base::right: Right-aligns output within the field width.
    // *** By default >> right align. ***
    cout<<setw(10)<<right<<"Hello"<<endl;
    // ios_base::internal: Pads numeric output with spaces on the left and the sign (if present) on the right.
    cout<<setw(10)<<100<<endl;
    cout<<setw(10)<<-100<<endl;
    cout<<internal<<setw(10)<<100<<endl;
    cout<<setw(10)<<-100<<endl;
    return 0;
}