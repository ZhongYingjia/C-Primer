#ifndef M
#define M
#include <vector>
#include <string>

class Screen;

class Windows_mgr{
    public:
        using ScreenIndex = std::vector<Screen>::size_type;
        void clear(ScreenIndex);

    private:
        std::vector<Screen> screens{Screen(24, 80, ' ')};


};



class Screen
{
    //friend class Windows_mgr;
    friend void Windows_mgr::clear(ScreenIndex);
    public:
        using pos = std::string::size_type;
        Screen() = default;
        Screen(pos ht, pos wd):width(wd),height(ht),contents(wd * ht,' '){}
        Screen(pos ht, pos wd,char c):width(wd),height(ht),contents(wd * ht,c){}

        char get() const 
            { return contents[cursor]; }
        char get(pos wd,pos ht) const;
        Screen& move(pos r,pos c);

        Screen& set(char);
        Screen& set(char c,pos r,pos col);

        Screen& display(std::ostream &os)
                { do_dispaly(os);return *this; }
        const Screen& display(std::ostream &os) const
                { do_dispaly(os);return *this; }

    private:
        void do_dispaly(std::ostream & os) const {
            os << contents;

        }
        pos cursor = 0;
        pos width = 0, height = 0;
        std::string contents;

};
inline
char Screen::get(pos r, pos c) const{
    return contents[width * r + c];
}
inline
Screen& Screen::move(pos r,pos c){
    cursor = r * width + c;
    return *this;

}
inline
Screen& Screen::set(char c)
{
    contents[cursor] = 'c';
    return *this;
}
inline
Screen& Screen::set(char c,pos r,pos col)
{
    contents[r * width + col] = 'c';
    return *this;

}

void Windows_mgr::clear(ScreenIndex i){
    Screen& s=screens[i];
    s.contents = std::string(s.height * s.width, ' ');

}
#endif

