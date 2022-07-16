// Homework 4. Task 2.

#include <iostream>
#include <string>
#include <fstream>
#include <clocale>
#include <windows.h>

class Address
{
private:
    std::string city;
    std::string street;
    std::string building;
    std::string appartment;

public:
    Address(std::string city, std::string street, std::string building, std::string appartment)
    {
        this->city = city;
        this->street = street;
        this->building = building;
        this->appartment = appartment;
    }

    Address() {}

    std::string outputAddress()
    {
        return city + ", " + street + ", " + building + ", " + appartment;
    }
};

int getAddressCount(std::ifstream& dataFile)
{
    int addressCount = 0;
    dataFile >> addressCount;

    return addressCount;
}

void getAddress(std::ifstream& dataFile, int addressCount, Address* addressArr)
{
    std::string city;
    std::string street;
    std::string building;
    std::string appartment;
    for (int i = 0; i < addressCount; ++i)
    {
        dataFile >> city;
        dataFile >> street;
        dataFile >> building;
        dataFile >> appartment;
        addressArr[i] = Address(city, street, building, appartment);
    }
}

void outputAddress(std::ofstream& outFile, int addressCount, Address* addressArr)
{
    outFile << addressCount << std::endl;
    for (int i = addressCount - 1; i >= 0; --i)
    {
        outFile << addressArr[i].outputAddress() << std::endl;
    }
}

void sortArray(Address* addressArr, int addressCount) 
{
    std::string foo = addressArr[0].outputAddress();
    char fff = foo[0];
    std::cout << foo;
    /*
    Address tmp;
    do
    {
        for (int i = 0; i < addressCount; ++i)
        {
            if (addressArr[i].outputAddress()[0] > addressArr[i + 1].outputAddress()[0])
            {
                tmp = addressArr[i + 1];
                addressArr[i + 1] = addressArr[i];
                addressArr[i] = tmp;
                sort = true;
            }
            //std::cout << addressArr[i].outputAddress().substr(0, 2) << std::endl;
        }
    } while (sort);*/
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, ".UTF8");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    
    std::ifstream dataFile("in.txt");
    
    if (!dataFile.is_open())
    {
        std::cout << "Could not open the file in.txt. Check the file name.";
    }
    else
    {
        int addressCount = getAddressCount(dataFile);
        Address* addressArr = new Address[addressCount];
        getAddress(dataFile, addressCount, addressArr);
        dataFile.close();
        std::ofstream outFile("out.txt");
        sortArray(addressArr, addressCount);
        //outputAddress(outFile, addressCount, addressArr);
        outFile.close();
        delete[] addressArr;
    }

    return 0;
}