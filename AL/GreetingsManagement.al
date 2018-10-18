codeunit 50110 GreetingsManagement
{
    local procedure GetHelloWorldText(GreetingNo : Integer) : Text;
    begin
        case GreetingNo of
            1:  exit('Arabic: مرحبا بالعالم');
            2:  exit('Bulgarian: Здравей, свят');
            3:  exit('Cantonese: 世界你好');
            4:  exit('Greek: Γεια σου κόσμε');
            5:  exit('Korean: 전 세계 여러분 안녕하세요');
            6:  exit('Thai: หวัดดีชาวโลก');
            7:  exit('Hindi: हैलो वर्ल्ड');
            8:  exit('Japanese: ハローワールド'); 
            9:  exit('Danish: Hej verden');
            10: exit('Polish: Witaj świecie');
            11: exit('Pig Latin: Ellohay Orldway');
            12: exit('Hungarian: Szia, világ!');
            13: exit('Flemish: Hej wereld');
            14: exit('Dutch: Hallo wereld');
            15: exit('French: Bonjour le monde');
            16: exit('Finnish: Hei maailma');
            17: exit('Russian: Привет, мир!');
            18: exit('Czech: Ahoj světe');            
            19: exit('German: Hallo Welt');
            20: exit('Lithuanian: Labas, pasauli!');            
            21: exit('Afrikaans: Hallo wêreld');
            22: exit('Bakke Snavvendt: Wello Horld');
            23: exit('1337 : h3ll0 w0rld!');
            24: exit('|_337: |-|3|_|_0 \\/\\/0|2|_|)!');
            25: exit('Morse code: ...././.-../.-../---//.--/---/.-./.-../-../-.-.--////');
            26: exit('Ballon script: Ⓗⓔⓛⓛⓞ Ⓦⓞⓡⓛⓓ!');
            27: exit('Braille: ⠠⠓⠑⠇⠇⠕ ⠠⠺⠕⠗⠇⠙⠖'); 
            28: exit('Español: Hola Mundo!');
            29: exit('Albanian: Përshëndetje, Botë!');
            30: exit('Turkish: Merhaba Dünya!');
            31: exit('Tamil: வணக்கம்');
            32: exit('Sinhalese: ආයුබෝවන්');
            33: exit('Swahili: Salamu, Dunia');
            34: exit('Catalan: Hola món');
            35: exit('Icelandic: Halló heimur');
            36: exit('Gaeilge: Dia duit an domhan');
            37: exit('Portuguese: Olá Mundo');
        else
            exit('Hello, World'); // Default to the good old one.
        end;
    end;

    procedure GetRandomGreeting() : Text;
    begin
        Randomize;
        exit(GetHelloWorldText(Random(38)));
    end;
}
