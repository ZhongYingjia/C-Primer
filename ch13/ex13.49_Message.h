#ifndef EX13_49_Message_H
#define EX13_49_Message_H

#include <string>
#include <set>
#include <iostream>

class Folder;
class Message{
    friend class Folder;
    friend void swap(Message&, Message&);
    friend void swap(Folder&, Folder&);
public:
    explicit Message(const std::string &str = ""):
        contents(str){ }
    Message(const Message&);
    Message& operator=(const Message&);

    Message(Message&& );
    Message& operator=(Message &&);

    ~Message();

    void save(Folder&);
    void remove(Folder&);

    void print_debug(){ std::cout << contents << std::endl; }    
private:
    std::string contents;
    std::set<Folder*> folders;

    void add_to_Folders(const Message&);
    void remove_from_Folders();

    void addFld(Folder *f){ folders.insert(f); }
    void remFld(Folder *f){ folders.erase(f); }

    void move_Folders(Message *m);

};
void swap(Message&, Message&);

class Folder{
    friend class Message;
    friend void swap(Message&, Message&);
    friend void swap(Folder&, Folder&);
public:
    Folder() = default;
    Folder(const Folder&);
    Folder& operator=(const Folder&);

    Folder(Folder&&);
    Folder& operator=(Folder&&);
    ~Folder(); 

    void print_debug(){
        for(auto m : msgs){
            std::cout << m->contents << std::endl; 
        }
        std::cout << std::endl; 
        
    }    
private:
    std::set<Message*>msgs;
    void addMsg(Message *m){ msgs.insert(m); }
    void remMsg(Message *m){ msgs.erase(m); }

    void add_to_Messages(const Folder &);
    void remove_from_Messages();

    void move_Messages(Folder* f);
};

void swap(Folder&, Folder&);


#endif