#include<iostream>

using namespace std ;
int main()
{
    int a ;
    
    cout << "\n1.C\n2.C++\n3.Python\n4.Java\n5.Ruby\n6.Clipper\n7.C#" ;
    cout << "\n8.Bash\n9.jQuery\n10.Swift\n";
    cout << "Enter Your Choice : " ;
    cin >> a ;
    switch(a)
    {
        case 1 :
                cout << "#include<stdio.h>\nint main()\n{\n\tprintf(\"Hello world\");\n}";
                break ;
        case 2 :
                cout << "#include<stdio.h>\nint main()\n{\n\tcout << \"Hello World \";\n}";
                break ;
        case 3 :
                cout << "print \"Hello World\"";
                break ;
        case 4 :
                cout << "class A {\npublic static void main(String args[]){\n";
                cout << "System.out.println(\"Hello World);\n}\n}";
                break ;
        case 5 :
                cout << "puts(\"Hello World\")";
                break ;
        case 6 :
                cout << "? \"Hello World\"";
                break ;
        case 7 :
                cout << "using System;\nclass Program\n{\n";
                cout << "public static void Main(string[] args)\n";
                cout << "{\nConsole.WriteLine(\"Hello, world\");\n}\n }";
                break ;
                                 
        case 8 :
                cout << "echo \"Hello World\"";    
                break ;
        case 9 : 
                cout << "$(\"body\").append(\"Hello world!\");";                
                break ;
        case 10 :
                cout << "println(\"Hello, world!\")" ;
                break ;
        default :
                cout << "Invalid choice."  ;                    
    }
}
