#include <iostream>
#include <string>
#include <cstdlib>

void displayMenu() {
    std::cout << "\n=====================\n";
    std::cout << "Windows Security Helper\n";
    std::cout << "=====================\n";
    std::cout << "1. Check and Configure Firewall\n";
    std::cout << "2. Set Up a VPN\n";
    std::cout << "3. General System Security Tips\n";
    std::cout << "4. Exit\n";
    std::cout << "Choose an option: ";
}

void firewallSettings() {
    std::cout << "\n=== Firewall Configuration ===\n";
    std::cout << "This tool can help you configure firewall settings.\n";
    std::cout << "Checking if firewall is enabled...\n";
    
    system("netsh advfirewall show allprofiles state");

    std::cout << "\nWould you like to enable the firewall? (y/n): ";
    char choice;
    std::cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        std::cout << "Enabling the firewall...\n";
        system("netsh advfirewall set allprofiles state on");
        std::cout << "Firewall enabled!\n";
    } else {
        std::cout << "Firewall settings were not changed.\n";
    }
}

void vpnSetup() {
    std::cout << "\n=== VPN Setup ===\n";
    std::cout << "We recommend using a trusted VPN service for enhanced security.\n";
    std::cout << "Popular VPN providers include NordVPN, ExpressVPN, and ProtonVPN.\n";
    std::cout << "For setting up a VPN, follow the provider's instructions.\n";
    std::cout << "You can install a VPN client from the official website.\n";
    std::cout << "Would you like more information on a specific VPN? (y/n): ";
    char choice;
    std::cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        std::cout << "Please visit the official website of your chosen VPN for detailed setup instructions.\n";
    } else {
        std::cout << "No VPN setup guide selected.\n";
    }
}

void systemSecurityTips() {
    std::cout << "\n=== General System Security Tips ===\n";
    std::cout << "1. Keep your operating system updated regularly.\n";
    std::cout << "2. Install a trusted antivirus program and keep it up to date.\n";
    std::cout << "3. Use strong, unique passwords for all your accounts.\n";
    std::cout << "4. Use two-factor authentication (2FA) for added security.\n";
    std::cout << "5. Backup your important data regularly.\n";
    std::cout << "6. Be cautious of phishing attempts and suspicious emails.\n";
    std::cout << "7. Ensure your Wi-Fi network is secured with WPA3 or WPA2 encryption.\n";
}

int main() {
    bool running = true;
    int choice;

    while (running) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                firewallSettings();
                break;
            case 2:
                vpnSetup();
                break;
            case 3:
                systemSecurityTips();
                break;
            case 4:
                std::cout << "Exiting the program. Stay secure!\n";
                running = false;
                break;
            default:
                std::cout << "Invalid choice. Please choose a valid option.\n";
                break;
        }
    }

    return 0;
}

