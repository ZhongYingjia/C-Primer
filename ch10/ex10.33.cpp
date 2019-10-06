#include <iterator>

#include <fstream>


#include <algorithm>



int main(int argc, char **argv)
{
    if(argc != 4){
        return -1;
    }
    std::ifstream ifs(argv[1]);
    std::ofstream ofs1(argv[2]),ofs2(argv[3]);

    std::istream_iterator<int> in_iter(ifs),eof_iter;
    std::ostream_iterator<int> odd(ofs1," "),even(ofs2,"\n");

    std::for_each(in_iter, eof_iter,
                    [&odd,&even](const int i){
                        *(i & 1? odd : even)++ = i;

                    });

    
    
    return 0;
}