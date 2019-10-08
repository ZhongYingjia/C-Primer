#include "ex13.34.h"

void Message::save(Folder& f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder& f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message& m)
{
    for(auto f:m.folders){
        f->addMsg(this);
    }
}

Message::Message(const Message &m):
    contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}

void Message::remove_from_Folders()
{
    for(auto f:folders){
        f->remMsg(this);
    }
}

Message::~Message()
{
    remove_from_Folders();
}

Message& Message::operator=(const Message &rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

void swap(Message& lhs, Message& rhs)
{
    using std::swap;
    for(auto f : lhs.folders){
        f->remMsg(&lhs);
    }
    for(auto f : rhs.folders){
        f->remMsg(&rhs);
    }

    swap(lhs.contents,rhs.contents);
    swap(lhs.folders,rhs.folders);

    for(auto f : lhs.folders){
        f->addMsg(&lhs);
    }
    for(auto f : rhs.folders){
        f->addMsg(&rhs);
    }
}



void Folder::add_to_Messages(const Folder &f)
{
    for(auto m : f.msgs){
        m->addFld(this);
    }
}

Folder::Folder(const Folder &f):
    msgs(f.msgs)
{
    add_to_Messages(f);

}

void Folder::remove_from_Messages()
{
    for(auto m : msgs){
        m->remFld(this);
    }
}

Folder::~Folder()
{
    remove_from_Messages();
}

Folder& Folder::operator=(const Folder& rhs)
{
    remove_from_Messages();
    msgs = rhs.msgs;
    add_to_Messages(rhs);
    return *this;
}

void swap(Folder &lhs, Folder &rhs)
{
    using std::swap;
    for(auto m :lhs.msgs){
        m->remFld(&lhs);
    }
    for(auto m :rhs.msgs){
        m->remFld(&rhs);
    }

    swap(lhs.msgs, rhs.msgs);

    for(auto m :lhs.msgs){
        m->addFld(&lhs);
    }
    for(auto m :rhs.msgs){
        m->addFld(&rhs);
    }
    

    
}