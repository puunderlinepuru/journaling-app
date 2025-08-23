#include <string>
#include <iostream>
#include <thread>

#include "static_lib/journal_static_lib.h"
#include "dynamic_lib/journal_dynamic_lib.h"

std::string fileName;
int accessLevel;

class Application {
    public:
        static Application& getInstance() {
            static Application instance;
            return instance;
        }

        

        Application(const Application&)     = delete;
        void operator=(Application const&)  = delete;

    private:
        bool useStatic = true;
        Application() {
                journal_static::init(fileName, accessLevel);
                journal_dynamic::init(fileName, accessLevel);

            while (true)
            {
                menu();
            }
            
        }

        ~Application() {}

        void menu() {
            std::cout << "Меню" << std::endl;
            std::cout << "1. Создать запись" << std::endl;
            std::cout << "2. Изменить уровень доступа по-умолчанию" << std::endl;
            std::cout << "3. Изменить используемую библиотеку записи на " << (useStatic ? "динамическую" : "статическую" ) << std::endl;
            std::cout << "4. Выход" << std::endl;
            std::cout << "Выберите опцию: ";

            int choice;
            while (!(std::cin >> choice) || choice < 1 || choice > 4) {
                std::cout << "Неверный ввод" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            }

            switch (choice)
            {
            case 1:
                get_input();
                break;
            
            case 2:
                change_access_level();
                break;

            case 3:
                useStatic = !useStatic;
                std::cout << "Библиотека сменена на " << (useStatic ? "статическую" : "динамическую") << std::endl;
                break;
                
            case 4:
                std::cout << "Закрываюсь..." << std::endl;
                exit(0);
                break;
            }
        }

        void get_input() {
            std::string entry = "";
            std::string readLine;
            std::cout << "Введите сообщение: " << std::endl;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

            while(std::getline(std::cin, readLine)) {
                if (readLine.empty()) {
                    break;
                }
                entry += readLine + "\n";
            }

            int chosenAccessLevel;
            std::cout << "Выберите уровень доступа: 1 - пониженный, 2 - средний, 3 - повышенный \nИли введите 'Enter' для использования уровня по-умолчанию" << std::endl;
            
            do
            {
                std::getline(std::cin, readLine);
                if (readLine.empty()) {
                    chosenAccessLevel = accessLevel;
                    break;
                } else if (readLine.at(0) - '0' >= 1 || readLine.at(0) - '0' <= 3){
                    chosenAccessLevel = readLine.at(0) - '0';
                    break;
                } else {
                    std::cout << "Неверный ввод" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max()); 
                }
            } while (true);
            

            if (useStatic)
            {
                std::thread writeThread([entry, chosenAccessLevel]() {
                    journal_static::write_to_file(entry, chosenAccessLevel);
                });
                writeThread.join();
            } else
            {
                std::thread writeThread([entry, chosenAccessLevel]() {
                    journal_dynamic::write_to_file(entry, chosenAccessLevel);
                });
                writeThread.join();
            }
            

            
        }

        void change_access_level() {
            int chosenAccessLevel;
            std::cout << "Выберите уровень доступа: 1 - пониженный, 2 - средний, 3 - повышенный" << std::endl;
            while (!(std::cin >> chosenAccessLevel) || chosenAccessLevel < 1 || chosenAccessLevel > 3) {
                std::cout << "Неверный ввод" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            }
            accessLevel = chosenAccessLevel;
            journal_static::change_access_level(chosenAccessLevel);
        }
};

int main(int argc, char* argv[])
        {
            fileName = "journal.txt";
            accessLevel = 1;

            if (argc == 2) {
                fileName = argv[1];
            } else if (argc > 2) {
                fileName = argv[1];
                try
                {
                    accessLevel = std::stoi(argv[2]);
                }
                catch(const std::exception& e)
                {
                    std::cerr << "Неверный уровень доступа, будет использован уровень по-умолчанию - 1" << std::endl;
                }
                
                
            }

            if (fileName.find(".txt") == std::string::npos) {
                fileName += ".txt";
            }

            Application& app = Application::getInstance();
            

            return 0;
        }

