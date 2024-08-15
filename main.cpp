#include <cctype>
#include <iostream>
#include <string.h>
using namespace std;
class Image {
protected:
    int height,width;
    char type[5];
public:
    Image() {
        this->height=this->width=0;
        strcpy(this->type,".jpg");
    }
    Image(int height, int width,char *type) {
        this->height=height;
        this->width=width;
        strcpy(this->type,type);
    }
    Image(const Image& other) {
        this->height=other.height;
        this->width=other.width;
        strcpy(this->type,other.type);
    }
    ~Image(){}
};
int main() {
    cout << "test" << endl;
    return 0;
}
