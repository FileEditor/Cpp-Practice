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
    Image& operator=(const Image& other) {
        if (this != &other) {
            return *this;
        }
        this->height=other.height;
        this->width=other.width;
        strcpy(this->type,other.type);
        return *this;
    }
    int getHeight() {
        return this->height;
    }
    int getWidth() {
        return this->width;
    }
    char getType() {}
    void setType(char *type) {
        strcpy(this->type,type);
    }

    ~Image() {

    }
};
int main() {
    cout << "test" << endl;
    cout <<"test 2" << endl;
    return 0;
}
