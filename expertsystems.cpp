#include <iostream>
#include <string>
using namespace std;

// Kiberxavfsizlik uchun ekspert tizimi
class CyberSecuritySystem {
public:
    void monitorNetwork() {
        bool highTraffic = false, unknownIP = false, multipleLoginAttempts = false;

        cout << "Tarmoqdagi faoliyatlarni belgilang (yes yoki no): " << endl;

        // Foydalanuvchidan simptomlarni kiritishni so‘raymiz
        highTraffic = getNetworkStatus("Tarmoqda kirish-chiqish traffigi yuqorimi?");
        unknownIP = getNetworkStatus("Noma'lum IP manzillardan kirishlar mavjudmi?");
        multipleLoginAttempts = getNetworkStatus("Ko'p login urinishlari kuzatilyaptimi?");

        // Qoidalar asosida xavfsizlik holatini aniqlaymiz
        if (highTraffic && unknownIP) {
            cout << "Ehtimoliy xakerlik xuruji aniqlangan!" << endl;
        } else if (multipleLoginAttempts) {
            cout << "Ruxsatsiz kirishga urinish mavjud!" << endl;
        } else if (highTraffic) {
            cout << "DoS xuruji ehtimoli bor. Tarmoq trafigini tekshiring." << endl;
        } else {
            cout << "Tarmoq xavfsiz ko‘rinmoqda." << endl;
        }
    }

private:
    // Tarmoq holatini tekshirish uchun yordamchi funksiya
    bool getNetworkStatus(string prompt) {
        string response;
        cout << prompt << " (yes/no): ";
        cin >> response;
        return (response == "yes" || response == "Yes");
    }
};

int main() {
    CyberSecuritySystem securitySystem;
    securitySystem.monitorNetwork();
    return 0;
}

