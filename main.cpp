#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
using namespace std;

class file
{
public:
    void create(string File_name)
    {
        ofstream cre;
        cre.open(File_name);
        cout << "File Created Successfully\n";
        cre.close();

        cout << endl;
    }
    void write(string File_name)
    {
        ofstream cre;
        string c;
        string data;
        cre.open(File_name);

        cout << "Enter text. Type 'END' or 'end' on a new line to finish:\n";
        while (getline(cin, c))
        {
            if (c == "END" or c == "end" or c == "End")
                break;
            cre << c << endl;
        }
        cout << "data entered succeessfully\n\n";
        cre.close();
        cout << endl;
    }
    void read(string File_name)
    {
        ifstream cre;
        string data;
        cre.open(File_name);
        cout << "Your " << File_name << "'s data is :" << endl
             << endl;
        while (getline(cre, data))
        {
            cout << data << endl;
        }
        cout << endl;
        cre.close();
        cout << endl;
    }
    void copy(string File_name, string fn)
    {
        ofstream ofc;
        ifstream cre;
        string data;
        cre.open(File_name);
        ofc.open(fn);
        while (getline(cre, data))
        {
            ofc << data << endl;
        }
        cout << endl;
        ofc.close();
        cre.close();
        cout << "Your File " << File_name << " Is Copied Successfully" << endl;
        cout << endl;
    }
    void move(string File_name, string fn)
    {
        ofstream ofc;
        ifstream cre;
        string data;
        cre.open(File_name);
        ofc.open(fn);
        while (getline(cre, data))
        {
            ofc << data << endl;
        }
        cout << endl;
        ofc.close();
        cre.close();

        filesystem::remove(File_name);

        cout << "Your File " << File_name << " Is Moved Successfully" << endl;
        cout << endl;
    }
    void remove(string File_name)
    {
        if (filesystem::remove(File_name))
        {
            cout << "Your File " << File_name << " Is Removed/Deletd Successfully" << endl;
        }
        else
        {
            cout << "No File found matching .Make sure to provide a proper name with extension." << endl;
        }
    }
    void folder_creat(string File_name)
    {
        if (filesystem::create_directory(File_name))
        {
            cout << "Your Directory " << File_name << " Is Created Successfully" << endl;
        }
        else
        {
            cout << "Your Directory " << File_name << " Is Not Created Successfully" << endl;
        }
    }
    void folder_del(string Folder_name)
    {
        if (filesystem::remove(Folder_name))
        {
            cout << "Your Directory " << Folder_name << " Is Created Successfully" << endl;
        }
        else
        {
            cout << "No directory found matching .Make sure to provide a proper name." << endl;
        }
    }
};
int main()
{
    cout << endl;
    file f1;
    cout << "Welcome to MyFileManager!" << endl;
    cout << "---------------------------------" << endl;
    cout << "MyFileManager is a simple command-line tool" << endl;
    cout << "that allows you to manage files and directories." << endl;
    cout << "You can create, delete, copy, move, and list files and directories." << endl;
    cout << "Use the commands listed below to navigate through the file system:" << endl;
    cout << "---------------------------------" << endl;
    cout << "Commands:" << endl;
    int cse;
    while (true)
    {

        cout << "Select an option:" << endl;
        cout << "1. Create a new file" << endl;
        cout << "2. Write to a file" << endl;
        cout << "3. Read from a file" << endl;
        cout << "4. Copy data from one file to another" << endl;
        cout << "5. Move data from one file to another" << endl;
        cout << "6. Remove/Delete a file" << endl;
        cout << "7. Create a new Directory" << endl;
        cout << "8. Remove/Delete a new Directory" << endl;
        cout << "9. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> cse;

        switch (cse)
        {
        case 1:
        {
            string file;
            cout << "Enter Your File Name with extension: ";
            cin >> file;
            cout << endl;
            f1.create(file);
            break;
        }
        case 2:
        {
            string file;
            cout << "Enter Your File Name with extension: ";
            cin >> file;
            cout << endl;
            f1.write(file);
            break;
        }
        case 3:
        {
            string file;
            cout << "Enter Your File Name with extension: ";
            cin >> file;
            cout << endl;
            f1.read(file);
            break;
        }
        case 4:
        {
            string file, file2;
            cout << "Enter the name of the source file with extensionto copy data from: ";
            cin >> file;
            cout << endl;
            cout << "Enter the name of the destination file with extensionto copy data to: ";
            cin >> file2;
            cout << endl;
            f1.copy(file, file2);
            break;
        }
        case 5:
        {
            string sourceFile, destinationFile;
            cout << "Enter the name of the source file with extensionto move: ";
            cin >> sourceFile;
            cout << endl;
            cout << "Enter the name of the destination file with extension: ";
            cin >> destinationFile;
            cout << endl;

            f1.move(sourceFile, destinationFile);

            break;
        }
        case 6:
        {
            string file;
            cout << "Enter Your File Name with extension: ";
            cin >> file;
            cout << endl;
            f1.remove(file);
            break;
        }
        case 7:
        {
            string folder;
            cout << "Enter Your Directory Name : ";
            cin >> folder;
            cout << endl;
            f1.folder_creat(folder);
            break;
        }
        case 8:
        {
            string folder;
            cout << "Enter Your Directory Name Which You Want to Delete: ";
            cin >> folder;
            cout << endl;
            f1.folder_del(folder);
            break;
        }

        case 9:
        {
            cout << "Exiting the program........." << endl;
            return 0;
        }
        default:
            cout << "Please Enter Valid Detail" << endl;
        }
    }
}
