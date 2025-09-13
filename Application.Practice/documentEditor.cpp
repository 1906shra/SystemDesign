#include <iostream>
#include <string>
#include <vector>
#include<fstream>
using namespace std;

class DocumentEditor{
    private:
    vector<string> document;
    public:
    void addText(string text){
        document.push_back(text);
    }
    void addImage(string path){
        document.push_back("[Image: " + path + "]");
    }
    string renderDocument(){
        if(document.empty()){
            return "";
        }
        string result;
        for(const auto& line : document){
            result += line + "\n";
        }
        return result;
    }
    void saveToFile(string filename){
        ofstream outFile(filename);
        if(outFile.is_open()){
            for(const auto& line : document){
                outFile << line << endl;
            }
            outFile.close();
        } else {
            cout << "Error opening file for writing: " << filename << endl;
        }
    }
};

int main() {
    DocumentEditor editor;
    editor.addText("Hello, World!");
    editor.addImage("path/to/image.png");
    editor.addText("This is a simple document editor.");
    
    cout << "Rendered Document:\n" << editor.renderDocument() << endl;
    
    editor.saveToFile("document.txt");
    cout << "Document saved to document.txt" << endl;
    
    return 0;
}

// This code defines a simple DocumentEditor class that allows adding text and images to a document, rendering the document as a string, and saving it to a file. The main function demonstrates how to use the DocumentEditor class.
//but it is 