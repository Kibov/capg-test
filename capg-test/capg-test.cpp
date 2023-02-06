#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>

//struct to hold the phone information
struct Phone
{
    std::string brandName;
    std::string modelName;
    std::string formFactor;
    int yearOfIssue;
    float screenSize;
    float price;
};
std::vector<Phone> phoneList;


//Function to add a phone
void addPhone()
{
	Phone newPhone;
	std::cout << "Enter brand name: ";
	std::cin >> newPhone.brandName;
	std::cout << "Enter model name: ";
	std::cin >> newPhone.modelName;
	std::cout << "Enter form factor: ";
	std::cin >> newPhone.formFactor;
	std::cout << "Enter year of issue: ";
	if (!(std::cin >> newPhone.yearOfIssue) || newPhone.yearOfIssue < 0) {
		std::cout << "Invalid year" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		return;
	}
	std::cout << "Enter screen size: ";
	if (!(std::cin >> newPhone.screenSize) || newPhone.screenSize < 0) {
		std::cout << "Invalid size" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		return;
	}
	std::cout << "Enter price: ";
	if (!(std::cin >> newPhone.price) || newPhone.price < 0) {
		std::cout << "Invalid price" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		return;
	}
	phoneList.push_back(newPhone);
	std::cout << "Phone added successfully" << std::endl;
}

//Function to delete a phone from the list
void deletePhone()
{
    int index;
    std::cout << "Enter the index of the phone to delete: ";
    std::cin >> index;
    if (index >= 0 && index < phoneList.size())
    {
        phoneList.erase(phoneList.begin() + index);
        std::cout << "Phone deleted successfully" << std::endl;
    }
    else
    {
        std::cout << "Invalid index" << std::endl;
    }
}
//Function to display the whole phone list
void displayPhoneList()
{
    std::cout << "Phone List: " << std::endl;
    for (int i = 0; i < phoneList.size(); i++)
    {
        std::cout << "Brand Name: " << phoneList[i].brandName << std::endl;
        std::cout << "Model Name: " << phoneList[i].modelName << std::endl;
        std::cout << "Form Factor: " << phoneList[i].formFactor << std::endl;
        std::cout << "Year of Issue: " << phoneList[i].yearOfIssue << std::endl;
        std::cout << "Screen Size: " << phoneList[i].screenSize << std::endl;
        std::cout << "Price: " << phoneList[i].price << std::endl;
    }
}

//Function to show all phones by the same brand name
void displayPhoneByBrandName()
{
	std::string brandName;
	std::cout << "Enter the brand name: ";
	std::cin >> brandName;
	for (int i = 0; i < phoneList.size(); i++)
	{
		if (phoneList[i].brandName == brandName)
		{
			std::cout << "Brand Name: " << phoneList[i].brandName << std::endl;
			std::cout << "Model Name: " << phoneList[i].modelName << std::endl;
			std::cout << "Form Factor: " << phoneList[i].formFactor << std::endl;
			std::cout << "Year of Issue: " << phoneList[i].yearOfIssue << std::endl;
			std::cout << "Screen Size: " << phoneList[i].screenSize << std::endl;
			std::cout << "Price: " << phoneList[i].price << std::endl;
		}
	}
}

//Function to show all phones of a given form factor and screen size
void displayPhoneByFormFactorAndScreenSize()
{
	std::string formFactor;
	float screenSize;
	std::cout << "Enter the form factor: ";
	std::cin >> formFactor;
	std::cout << "Enter the screen size: ";
	std::cin >> screenSize;
	for (int i = 0; i < phoneList.size(); i++)
	{
		if (phoneList[i].formFactor == formFactor && phoneList[i].screenSize == screenSize)
		{
			std::cout << "Brand Name: " << phoneList[i].brandName << std::endl;
			std::cout << "Model Name: " << phoneList[i].modelName << std::endl;
			std::cout << "Form Factor: " << phoneList[i].formFactor << std::endl;
			std::cout << "Year of Issue: " << phoneList[i].yearOfIssue << std::endl;
			std::cout << "Screen Size: " << phoneList[i].screenSize << std::endl;
			std::cout << "Price: " << phoneList[i].price << std::endl;
		}
	}
}
//Function to show the brand name with the maximum quantity of phones
void displayBrandNameWithMaxQuantity()
{
	std::string brandName;
	int count = 0;
	int maxCount = 0;
	for (int i = 0; i < phoneList.size(); i++)
	{
		for (int j = 0; j < phoneList.size(); j++)
		{
			if (phoneList[i].brandName == phoneList[j].brandName)
			{
				count++;
			}
		}
		if (count > maxCount)
		{
			maxCount = count;
			brandName = phoneList[i].brandName;
		}
		count = 0;
	}
	std::cout << "Brand Name: " << brandName << std::endl;
	std::cout << "Quantity: " << maxCount << std::endl;
}
//Function to show TOP-3 screen sizes, popularity is determined by the number of phones with the screen size
void displayTop3ScreenSizes()
{
	std::map<float, int> screenSizeCount;
	for (int i = 0; i < phoneList.size(); i++)
	{
		screenSizeCount[phoneList[i].screenSize]++;
	}
	std::vector<std::pair<float, int>> screenSizeCountVec(screenSizeCount.begin(), screenSizeCount.end());
	std::sort(screenSizeCountVec.begin(), screenSizeCountVec.end(), [](const auto& a, const auto& b) { return a.second > b.second; });
	std::cout << "Top 3 Screen Sizes: " << std::endl;
	for (int i = 0; i < 3 && i < screenSizeCountVec.size(); i++) {
		std::cout << screenSizeCountVec[i].first << " " << screenSizeCountVec[i].second << std::endl;
	}
}
//Function to save the phone list to a txt file
void savePhoneList()
{
	std::ofstream file;
	file.open("PhoneList.txt");
	for (int i = 0; i < phoneList.size(); i++)
	{
		file << phoneList[i].brandName << std::endl;
		file << phoneList[i].modelName << std::endl;
		file << phoneList[i].formFactor << std::endl;
		file << phoneList[i].yearOfIssue << std::endl;
		file << phoneList[i].screenSize << std::endl;
		file << phoneList[i].price << std::endl;
	}
	file.close();
}
//Function to read and add phones to the phone list from a txt file
void readPhoneList()
{
	std::ifstream file;
	file.open("PhoneList.txt");
	if (file.is_open())
	{
		Phone phone;
		while (file >> phone.brandName)
		{
			file >> phone.modelName;
			file >> phone.formFactor;
			if (!(file >> phone.yearOfIssue)) {
				std::cout << "Error reading year of issue" << std::endl;
				file.clear();
				file.ignore(1000, '\n');
				break;
			}
			if (!(file >> phone.screenSize)) {
				std::cout << "Error reading screen size" << std::endl;
				file.clear();
				file.ignore(1000, '\n');
				break;
			}
			if (!(file >> phone.price)) {
				std::cout << "Error reading price" << std::endl;
				file.clear();
				file.ignore(1000, '\n');
				break;
			}
			phoneList.push_back(phone);
		}
	}
	file.close();
}


int main()
{
    int choice;
    while (true)
    {
        std::cout << "1. Add phone" << std::endl;
        std::cout << "2. Display phone list" << std::endl;
        std::cout << "3. Delete a phone from the list" << std::endl;
		std::cout << "4. Show all phones by the same brand" << std::endl;
		std::cout << "5. Show all phones of a given form factor and screen size" << std::endl;
		std::cout << "6. Show the name of the brand with the maximum quantity of the phones" << std::endl;
		std::cout << "7. Show TOP-3 screen sizes" << std::endl;
		std::cout << "8. Save list to a file" << std::endl;
		std::cout << "9. Read list from a file" << std::endl;
        std::cout << "10. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            addPhone();
            break;
        case 2:
            displayPhoneList();
            break;
		case 3:
            deletePhone();
            break;
		case 4:
			displayPhoneByBrandName();
			break;
		case 5:
			displayPhoneByFormFactorAndScreenSize();
			break;
		case 6:
			displayBrandNameWithMaxQuantity();
			break;
		case 7:
			displayTop3ScreenSizes();
			break;
		case 8:
			savePhoneList();
			break;
		case 9:
			readPhoneList();
			break;
        case 10:
            return 0;
        default:
            std::cout << "Invalid choice" << std::endl;
        }
    }
}