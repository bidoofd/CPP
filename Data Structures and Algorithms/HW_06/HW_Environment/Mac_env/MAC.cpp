#include <iostream>
#include <fstream>
#include <string>
#include "mach.h"

using namespace std;

//checks to see if a string is fully a number or not
//sources from: https://stackoverflow.com/a/4654718
bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int main()
{
    int size, index, value, flag;
    int choice = 1;

    string name, line, stringSize, stringChoice, stringValue;

    bool boolFlag = true;
    
    string recFile = "/Users/trando/Desktop/coding/c++/Data Structures and Algorithms/HW_06/HW_Environment/Mac_env/";

    //Enter filepath for the output file to record
    cout << "Enter the filename for output file: " << endl;
    getline(cin, line);
    recFile.append(line + ".txt");
    ofstream inFile(recFile);

    //clears contents of recording output file
    inFile.open(recFile, ios::trunc);
    inFile.close();

    cout << R"(                     .__.                                 ._. 
    __  _  __  ____  |  |    ____   ____    _____    ____ | | 
    \ \/ \/ /_/ __ \ |  |  _/ ___\ /  _ \  /     \ _/ __ \| | 
     \     / \  ___/ |  |__\  \___(  <_> )|  Y Y  \\  ___/ \| 
      \/\_/   \___  >|____/ \___  >\____/ |__|_|  / \___  >__ 
                  \/            \/      \_/     \/      \/ \/)" << endl;

    cout << "\n\n" << endl;

    // Entering name to create object
    cout << "Enter the name of binary tree object" << endl;
    cin.ignore();
    getline(cin, name);

    // Creates object
    Tree binary(name);

    inFile.open(recFile);

    // Objects writes to recording file
    binary.writeOutput(inFile, R"(                     .__.                                 ._. 
    __  _  __  ____  |  |    ____   ____    _____    ____ | | 
    \ \/ \/ /_/ __ \ |  |  _/ ___\ /  _ \  /     \ _/ __ \| | 
     \     / \  ___/ |  |__\  \___(  <_> )|  Y Y  \\  ___/ \| 
      \/\_/   \___  >|____/ \___  >\____/ |__|_|  / \___  >__ 
                  \/            \/      \_/     \/      \/ \/)");

    binary.writeOutput(inFile, "Enter the name of myQueueADT object");
    binary.writeOutput(inFile, name);

    while(choice != 9)
    {
        boolFlag = true;
        binary.resetInstructions();
        // Menu Options
        cout << "Enter which option you would like to choose by number: \n" << endl;
        cout << "1. Create Binary Tree manually" << endl;
        cout << "2. Create Binary Tree from file" << endl;
        cout << "3. preOrderList of current tree" << endl;
        cout << "4. postOrderList of current tree" << endl;
        cout << "5. inOrderList of current tree" << endl;
        cout << "6. Solve expression from current tree" << endl;
        cout << "7. Delete current tree " << endl;
        cout << "8. Read Expression from String" << endl;
        cout << "9. To Exit. " << endl;

        while(boolFlag)
        {
            getline(cin, stringChoice);
            if(is_number(stringChoice) == false)
            {
                cout << "Not a valid choice." << endl;
                binary.writeOutput(inFile, "Not a valid choice.");
            }
            else if(is_number(stringChoice) == true)
            {
                choice = stoi(stringChoice);
                boolFlag = false;
            }
        }

        boolFlag = true;

        cout << "\n\n" << endl;
        binary.writeOutput(inFile, "\n\n");
        binary.writeOutput(inFile, "Enter which option you would like to choose by number: \n");
        binary.writeOutput(inFile, "1. Create Binary Tree manually");
        binary.writeOutput(inFile, "2. Create Binary Tree from file");
        binary.writeOutput(inFile, "3. preOrderList of current tree");
        binary.writeOutput(inFile, "4. postOrderList of current tree");
        binary.writeOutput(inFile, "5. inOrderList of current tree");
        binary.writeOutput(inFile, "6. Solve expression from current tree");
        binary.writeOutput(inFile, "7. Delete current tree ");
        binary.writeOutput(inFile, "8. Read Expression from String");
        binary.writeOutput(inFile, "9. To exit.");
        binary.writeOutput(inFile, to_string(choice));


        //The if menu and print operations of flags
        if(choice == 1)
        {
            string choice2 = "";
            while(true)
            {
                cout << "Enter the node you want to insert: " << endl;
                cout << "To stop entering values, type \"STOP\"" << endl;
                cin >> choice2;
                //cout << "got the line" << endl;
                if(choice2.compare("STOP") == 0)
                {
                    break;
                }
                else
                {
                    cout << "inserted node " << endl;
                    binary.insertNode(choice2, binary.root);
                }
            }
        }
        else if(choice == 2)
        {
            // Has user enter in file name
            cout << "Enter the filename for the file to read: " << endl;
            getline(cin, line);
            string temp = "/Users/trando/Desktop/coding/c++/Data Structures and Algorithms/HW_06/HW_Environment/Mac_env/" + line;
            cout << temp << endl;
            binary.insertNodeAuto(temp);
        }
        else if(choice == 3)
        {
            cout << "Preorder: " << endl;
            binary.preOrder(binary.root, 0);
            cout << "\n\n" << endl;
            binary.printArray();
            cout << "\n\n" << endl;
        }
        else if(choice == 4)
        {
            cout << "Postorder: " << endl;
            binary.postOrder(binary.root, 0);
            cout << "\n\n" << endl;
            binary.printArray();
            cout << "\n\n" << endl;
        }
        else if(choice == 5)
        {
            cout << "Inorder: " << endl;
            binary.inOrder(binary.root, 0);
            cout << "\n\n" << endl;
            binary.printArray();
            cout << "\n\n" << endl;
        }
        else if(choice == 6)
        {
            cout << "The equation is: " << endl;
            binary.inOrder(binary.root, 0);
            cout << "\nThe solution to the equation is: " << binary.solveExpression(binary.root) << endl;
        }
        else if(choice == 7)
        {
            binary.resetTree();
        }
        else if(choice == 8)
        {
            string temp;
            cout << "Enter the equation: " << endl;
            cin >> temp;
            binary.expressOptionTree(temp, binary.root);
        }
    }

    cout << R"(   ____                     .______.                  ._. 
  / ___\  ____    ____    __| _/\_ |__  ___.__.  ____ | | 
 / /_/  >/  _ \  /  _ \  / __ |  | __ \<   |  |_/ __ \| | 
 \___  /(  <_> )(  <_> )/ /_/ |  | \_\ \\___  |\  ___/ \| 
/_____/  \____/  \____/ \____ |  |___  // ____| \___  >__ 
        \______________/     \/      \/ \/          \/ \/ 
                                                          )" << endl;

    system("pause");
}