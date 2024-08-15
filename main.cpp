#include <cctype>
#include <complex.h>
#include <iostream>
#include <string.h>
using namespace std;
class Image {
protected:
    int height,width;
    char type[5],name[50];
public:
    Image() {
        this->height=this->width=0;
        strcpy(this->type,".jpg");
        strcpy(this->name,"none");
    }
    Image(int height, int width,char *type) {
        this->height=height;
        this->width=width;
        strcpy(this->type,type);
        strcpy(this->name,name);
    }
    Image(const Image& other) {
        this->height=other.height;
        this->width=other.width;
        strcpy(this->type,other.type);
        strcpy(this->name,other.name);
    }
    Image& operator=(const Image& other) {
        if (this != &other) {
            return *this;
        }
        this->height=other.height;
        this->width=other.width;
        strcpy(this->type,other.type);
        strcpy(this->name,other.name);
        return *this;
    }
    int getHeight() {
        return this->height;
    }
    int getWidth() {
        return this->width;
    }
    char getType() {
        cout << this->type << endl;
    }
    void setType(char *type) {
        strcpy(this->type,type);
    }

    void setName(char *name) {
        strcpy(this->name,name);
    }
    char *getName() {
        return this->name;
    }

    virtual int size(int width,int height) {
        return 4;
    }
    ~Image() {

    }
};
class TransparentImage : public Image {
    protected:
    int size;
    public:
    TransparentImage():Image() {
        this->size=0;
    }
    TransparentImage(int height, int width,char *type,int size):Image(height,width,type) {
        this->size=size;
    }
    TransparentImage(const TransparentImage& other) {
        this->size=other.size;
    }
    int getSize(int s) {
        return (Image::height*Image::width)+s;
    }

    ~TransparentImage() {}
    TransparentImage& operator=(const TransparentImage& other) {
        if (this != &other) {
            return *this;
        }
        this->size=other.size;
        return *this;
    }
};
int main() {
    cout << "test" << endl;
    cout <<"test 2" << endl;
    TransparentImage t1;
    t1.setType(".jpg");
    char name[50];
    cin >> name;
    t1.setName(name);
    cout << t1.getName() << t1.getType() << endl;

    return 0;
}
