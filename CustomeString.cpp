#include <string.h>

class Custome_String
{
    private:
        char *buff = nullptr;
        unsigned int size = 0;

    public:
        Custome_String():buff(nullptr),size(0)
        {}

        Custome_String(const char* buffer);
        Custome_String::Custome_String(const Custome_String &iCopy) //Copy Constructor
        {
            size = iCopy.size;
            buff = new char[size];
            strncpy_s(buff,size+1,iCopy.buff,iCopy.size);
        }

        Custome_String::Custome_String(Custome_String && iCopy)
        {       
            size = iCopy.size;
            buff= iCopy.buff;
            iCopy.buff = nullptr;
        }

        Custome_String& operator=(Custome_String && iCopy);
        Custome_String& operator = (const Custome_String &iCopy);
        Custome_String operator+(const Custome_String& iStr);


        unsigned int length()
        {
            return this->size;
        }

        const char* c_str() const
        {
            return buff;
        }

        ~Custome_String()
        {
            __cleanup__();
        }
    private:

        void __cleanup__()
        {
            if(buff != nullptr)
            {
                delete[] buff;
            }
            size = 0;
        }
  
};

Custome_String::Custome_String(const char* buffer)  //parameterized constructor
{
    size = strlen(buffer);
    buff = new char[size+1];
    strncpy_s(buff,size+1,buffer,size);
}

Custome_String& Custome_String::operator = (const Custome_String &iCopy) //Copy Assingment
{
    if(this != &iCopy)
    {
        size = iCopy.size;
        buff = new char[size+1];
        strncpy_s(buff,size+1,iCopy.buff,size); 
    }
    return *this;
}

Custome_String& Custome_String::operator=(Custome_String&& iCopy)
{
		size = iCopy.size;
		buff = iCopy.buff;
		iCopy.buff = nullptr;
		return *this;
}

Custome_String Custome_String::operator+(const Custome_String& iStr)
{   
    Custome_String s;
    s.size = this->size + iStr.size;
    s.buff = new char[s.size + 1];
    strncpy_s(s.buff, this->size+1, this->buff,this->size);
    strncpy_s(s.buff+this->size, iStr.size+1, iStr.buff,iStr.size);

    return s;
}