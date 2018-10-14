using namespace std;
int main() {
string makeLowerCase(string str) {
        string lowercase = "";
        for (int i = 0; i < str.length(); i++) {
            if (str[i] <= 90 && str[i] >= 65) {
                lowercase += str[i] + 32;
            }
            else {
                lowercase += str[i];
            }
        }
        return lowercase; 
    }
}
