#include <iostream>
using namespace std;
class Burger
{
private:
    string first;
    string second;
    string third;
public:
    Burger() {}

    virtual string getFrst() { return first; }

    virtual void setFirst(const string& first)
    {
        this->first = first;

    }
    virtual string getSecond() { return second; }

    virtual void setSecond(const string& second)
    {
        this->second = second;
    }

    virtual string getThird() { return third; }

    virtual void setThird(const string& third)
    {
        this->third = third;
    }

    virtual void info()
    {
        cout << "Состав бургера:\n"
            << (second != "" ? "котлета-" + second : "котлета отсутствует") << "\n"
            << (first != "" ? "булочка-" + first : "булочка отсутствует") << "\n"
            << (third != "" ? "специи" + third : "специй нет") << endl;

    }
};

class BurgerBuilder
{
protected:
    Burger* burger;
public:
    BurgerBuilder()
    {
        burger = new Burger();
    }
    virtual void addFirst() = 0;
    virtual void addSecond() = 0;
    virtual void addThird() = 0;
    virtual Burger* getBurger()
    {
        Burger* result = burger;
        burger = new Burger();
        return result;
    }
    ~BurgerBuilder()
    {
        delete burger;
    }
};

class ConcretBuilder1 : public BurgerBuilder
{
public:
    virtual void addFirst() override
    {
        burger->setFirst("вкусненькая");
    }
    virtual void addSecond() override
    {
        burger->setSecond("мясная");
    }
    virtual void addThird() override
    {
        burger->setThird("соль");
    }
};

class ConcretBuilder2 : public BurgerBuilder
{
public:
    virtual void addFirst() override
    {
        burger->setFirst("ржаная");
    }
    virtual void addSecond() override
    {
        burger->setSecond("рыбная");
    }
    virtual void addThird() override
    {
        burger->setThird("невероятно острая смесь");
    }
};
class ConcretBuilder3 : public BurgerBuilder
{
public:
    virtual void addFirst() override
    {
        burger->setFirst("сладкий");
    }
    virtual void addSecond() override
    {
        burger->setSecond("жирный");
    }
    virtual void addThird() override
    {
        burger->setThird("бургер");
    }
};

int main()
{
    setlocale(LC_ALL, "");
    BurgerBuilder* builder = new ConcretBuilder1();

    builder->addFirst();
    builder->addSecond();

    Burger* b = builder->getBurger();
    b->info();
}
