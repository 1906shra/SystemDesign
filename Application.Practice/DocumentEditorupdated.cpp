#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

class DocumentElement {
    public:
    virtual string render() const = 0;
    virtual ~DocumentElement() {}
};
class TabSpace : public DocumentElement {
    public:
    string render() const override {
        return "\t";
    }
};
class TextElement : public DocumentElement {
    private:
    string text;
    public:
    TextElement(const string& txt) : text(txt) {}
    string render() const override {
        return text;
    }
};
class ImageElement : public DocumentElement{
     private:
     string path;
     public:
     ImageElement(string a){
        path=a;
     }
     string render() const override {
        return "[Image: " + path + "]";
     }

};

class Document :public DocumentElement{
       private:
       vector<DocumentElement*>elements;
         public:
            void addElement(DocumentElement* element){
                elements.push_back(element);
            }
            string render() const override {
                string result;
                for(const auto& element : elements){
                    result += element->render() + "\n";
                }
                return result;
            }
};
class persistance{
    public:
    virtual void saveToFile(const Document& doc, const string& filename) = 0;
    virtual ~persistance() {}
};

class  SaveToFile : public persistance
{
  public:
    void saveToFile(const Document& doc, const string& filename ){
            cout<<"data saved to file"<<endl;
        }
};
class SaveToDatabase : public persistance
{
  public:
    void saveToFile(const Document& doc, const string& filename ){
            cout<<"data saved to database"<<endl;
        }
};


class DocumentEditor{
    private:
    Document* document;
    persistance* persistenceHandler;
    public:
    DocumentEditor(persistance* handler) : persistenceHandler(handler) {}
    void addText(const string& text){
        document->addElement(new TextElement(text));
    }
    void addImage(const string& path){
        document->addElement(new ImageElement(path));
    }
    void addTabSpace(){
        document->addElement(new TabSpace());
    }
    string renderDocument() const{
        return document->render();
    }
    void saveDocument(const string& filename){
        if(persistenceHandler){
            persistenceHandler->saveToFile(*document, filename);
        } else {
            cout << "No persistence handler set." << endl;
        }
    }
    ~DocumentEditor(){
        delete persistenceHandler;
    }
};
// This code defines a DocumentEditor class that uses the Dependency Inversion Principle to depend on abstractions for document elements and persistence mechanisms. The main function demonstrates how to use the DocumentEditor class with different persistence handlers.
int main() {
    persistance* fileHandler = new SaveToFile();
    DocumentEditor editor(fileHandler);
    editor.addText("Hello, World!");
    editor.addImage("path/to/image.png");
    editor.addTabSpace();
    editor.addText("This is a simple document editor.");
    
    cout << "Rendered Document:\n" << editor.renderDocument() << endl;
    
    editor.saveDocument("document.txt");
    
    persistance* dbHandler = new SaveToDatabase();
    DocumentEditor dbEditor(dbHandler);
    dbEditor.addText("Hello, Database!");
    dbEditor.saveDocument("database_record");
    
    return 0;
}