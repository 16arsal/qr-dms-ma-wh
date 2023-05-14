#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <ctime>

struct Record {
    std::string name;
    std::string accountNumber;
    std::string phoneNumber;
    std::string address;
    std::string email;
    std::string citizenshipNumber;
    double depositAmount;
};

// Function to generate a random string of given length
std::string generateRandomString(int length) {
    static const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    static std::mt19937 randomEngine(static_cast<unsigned int>(time(nullptr)));
    static std::uniform_int_distribution<int> distribution(0, characters.size() - 1);

    std::string result;
    for (int i = 0; i < length; ++i) {
        result += characters[distribution(randomEngine)];
    }

    return result;
}

// Function to generate a random phone number
std::string generateRandomPhoneNumber() {
    static std::mt19937 randomEngine(static_cast<unsigned int>(time(nullptr)));
    static std::uniform_int_distribution<int> distribution(100000000, 999999999);

    return std::to_string(distribution(randomEngine));
}

int main() {
    std::vector<Record> records(100);

    for (int i = 0; i < 100; ++i) {
        Record& record = records[i];
        record.name = generateRandomString(5);
        record.accountNumber = generateRandomString(10);
        record.phoneNumber = generateRandomPhoneNumber();
        record.address = generateRandomString(4);
        record.email = generateRandomString(5) + "@gmail.com";
        record.citizenshipNumber = generateRandomString(3);
        record.depositAmount = static_cast<double>(rand() % 10000 + 1);
    }

    // Open the file for writing in binary mode
    std::ofstream outputFile("record.bin", std::ios::binary);

    // Check if the file opened successfully
    if (!outputFile) {
        std::cerr << "Failed to open the file for writing!" << std::endl;
        return 1;
    }

    // Write the records to the file
    for (const Record& record : records) {
        outputFile.write(reinterpret_cast<const char*>(&record), sizeof(record));
    }

    // Close the file
    outputFile.close();

    std::cout << "Records created successfully!" << std::endl;

    return 0;
}
