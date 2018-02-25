template <class T>
class Box{
    private:
        T contents;
    public:
        Box(T newContents);
        T getContents();
        void setContents(T newContents);
        friend ostream& operator <<(ostream &out, Box<T> value)
};