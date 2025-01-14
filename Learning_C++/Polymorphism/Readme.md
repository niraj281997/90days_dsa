
what are the type of constructor ?
Mainly Two types of constructor we have 
    1. default constructor 
    2. user define constructor

if we create user define constructor as mentioned below then we need to create default constructor. 

Class A 
{
    public:
        A()
        {
            cout<<"We are in default constructor";
        } 
        // just because we have created user define constructor the compiler will not create default consctructor. user has to define it 
        A(int a)
        {
            cout<<"We are in user define constructor ";
        }
}


What is deep copy and shallow copy

Shallow Copy: 

Shallow repetition is quicker. However, it’s “lazy” it handles pointers and references. Rather than creating a contemporary copy of the particular knowledge the pointer points to, it simply copies over the pointer price. So, each of the first and therefore the copy can have pointers that reference constant underlying knowledge.


Deep Copy:
Deep repetition truly clones the underlying data. It is not shared between the first and therefore the copy.


Shallow Copy: Creates a new object but does not create copies of nested objects; instead, it copies references to the nested objects. Thus, changes to nested objects affect both the original and the copied objects.

Deep Copy: Creates a new object and recursively copies all nested objects, so the original and copied objects are completely independent.



