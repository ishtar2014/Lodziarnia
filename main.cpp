#include <iostream>
#include <string>
#include <climits>
using namespace std;

void eatline()
{
    cin.ignore(INT_MAX, '\n');
}

class Lody
{
protected:
    string lody;
    double wartosc;

public:
    Lody() { lody = "Przepyszne lody!"; wartosc=0;}

    virtual string napis()
    {
    return lody;
    }

    virtual double cena()
    {
    return wartosc;
    }
};

/// DEKORATOR

class Dekorator : public Lody
{
 public:
    virtual string napis() = 0;
};

class Wafelek : public Lody
{
public:
    Wafelek():Lody()
{   lody= "Chrupiacy wafelek";
    wartosc=0.50;}
};

///DODATKI!!!!!!!! :)

class Smietankowe : public Dekorator
{
Lody *ice;

public:
    Smietankowe(Lody *cream): Dekorator()
    {
        ice = cream;
    }

virtual string napis()
    {
        return ice->napis() + " + galka lodow smietankowych";
    }

double cena()
    {
        return ice->cena()+2.0;
    }
};

class Czekoladowe : public Dekorator
{
    Lody* ice;
public:
    Czekoladowe(Lody*cream) : Dekorator()
{
    ice = cream;
}
    virtual string napis()
    {
        return ice->napis()+ " + galka lodow czekoladowych";
    }
    virtual double cena()
    {
        return ice->cena()+2.0;
    }
};

class Truskawkowe : public Dekorator
{
Lody* ice;
public:
    Truskawkowe(Lody* cream) : Dekorator()
    {
        ice = cream;
    }
    virtual string napis()
    {
        return ice->napis() + "+ galka lodow truskawkowych";
    }
    virtual double cena()
    {
        return ice->cena()+2.0;
    }
};

class BitaSmietana : public Dekorator
{
    Lody *ice;

public: BitaSmietana(Lody *lody):Dekorator()
    {
        ice = lody;
    }

virtual string napis()
        {
            return ice->napis() + " + bita smietana";
        }
        double cena(){
        return ice->cena()+1.5;
    }
};

int main()
{
    Lody *l1 = new Wafelek();
    cout << "Witamy w wirtualnym swiecie lodow! \nMENU: \nWybierz opcje z menu:\n"<< endl;
    cout << "1.\tSam wafelek." << endl;
    cout << "2.\tLody galkowe (smietankowe, czekoladowe, truskawkowe.)"<< endl;
    cout << "3.\tLody full wypas. "<< endl;
    cout << "4.\tPuchary. "<< endl;
    char wybor1;
    cin >> wybor1;

    switch(wybor1)
    {
        case '1':
        {
            cout<<"\nWybrales sam wafelek:"<<endl;
            cout<<l1->napis()<<"\nDo zaplaty: "<<l1->cena()<< " zl. Dziekujemy!" << endl;
            break;
        }
        case '2':
        {
            char wybor2;
            cout << "Jaka galke? 1 - smietankowa, 2- czekoladowa, 3 - truskawkowa" << endl;
            eatline();
            cin >> wybor2;
            switch(wybor2)
            {
                case'1':
                {
                    l1 = new Smietankowe(l1);
                    cout<<"\nWybrales lody smietankowe:"<<endl;
                    cout<<l1->napis()<<"\nDo zaplaty: "<<l1->cena()<< " zl." << endl;
                    cout<<"\n Czy chcesz bita smietane? 1- tak 2- nie." << endl;
                    eatline();
                    char wybor3;
                    cin>>wybor3;
                    switch(wybor3)
                    {
                        case'1':
                        {
                            Lody*l2 = new BitaSmietana(new Smietankowe( new Wafelek()));
                            cout<<"\nWybrales lody smietankowe z bita smietana:"<<endl;
                            cout<<l2->napis()<<"\nDo zaplaty: "<<l2->cena()<< " zl. Dziekujemy!" << endl;
                            break;
                        }
                        case'2':
                        {
                            cout<<"\nDo zaplaty: "<<l1->cena()<< " zl. Dziekujemy!" << endl;
                            break;
                        }
                    }
                    break;
                }
                case'2':
                {
                    l1 = new Czekoladowe(l1);
                    cout<<"\nWybrales lody czekoladowe:"<<endl;
                    cout<<l1->napis()<<"\nDo zaplaty: "<<l1->cena()<< " zl." << endl;
                    cout<<"\n Czy chcesz bita smietane? 1- tak 2- nie." << endl;
                    eatline();
                    char wybor4;
                    cin>>wybor4;
                    switch(wybor4)
                    {
                        case'1':
                        {
                            Lody*l2 = new BitaSmietana(new Czekoladowe( new Wafelek()));
                            cout<<"\nWybrales lody czekoladowe z bita smietana:"<<endl;
                            cout<<l2->napis()<<"\nDo zaplaty: "<<l2->cena()<< " zl. Dziekujemy!" << endl;
                            break;
                            }
                        case'2':
                        {
                            cout<<"\nDo zaplaty: "<<l1->cena()<< " zl. Dziekujemy!" << endl;
                            break;
                        }
                    }
                    break;
                }
                case'3':
                {
                    l1 = new Truskawkowe(l1);
                    cout<<"\nWybrales lody truskawkowe:"<<endl;
                    cout<<l1->napis()<<"\nDo zaplaty: "<<l1->cena()<< " zl." << endl;
                    cout<<"\n Czy chcesz bita smietane? 1- tak 2- nie." << endl;
                    eatline();
                    char wybor4;
                    cin>>wybor4;
                    switch(wybor4)
                    {
                        case'1':
                        {
                            Lody*l2 = new BitaSmietana(new Truskawkowe( new Wafelek()));
                            cout<<"\nWybrales lody truskawkowe z bita smietana:"<<endl;
                            cout<<l2->napis()<<"\nDo zaplaty: "<<l2->cena()<< " zl. Dziekujemy!" << endl;
                            break;
                        }
                        case'2':
                        {
                            cout<<"\nDo zaplaty: "<<l1->cena()<< " zl. Dziekujemy!" << endl;
                            break;
                        }
                    }
                    break;
                }
            }
            break;
        }
        case'3':
        {
            Lody *l3 =  new BitaSmietana(new Smietankowe (new Czekoladowe(new Truskawkowe(new Wafelek()))));
            cout<<l3->napis()<<"\nDo zaplaty: "<<l3->cena()<< " zl. Dziekujemy!"<< endl;
            break;
        }
        case'4':
        {
            cout << "Puchary"<< endl;
            eatline();
            char wybor5;
            cout << "Wybierz puchar: 1- smietankowa oaza gwiazd, 2- truskawkowa galaktyka, 3- czarna dziura;"<< endl;
            cin>>wybor5;

            switch(wybor5)
            {
                case'1':
                {
                    Lody*l2 = new BitaSmietana(new Smietankowe(new Smietankowe (new Wafelek())));
                    cout<<"\nWybrales puchar z dwoma galkami lodow smietankowych z bita smietana:"<<endl;
                    cout<<l2->napis()<<"\nDo zaplaty: "<<l2->cena()<< " zl. Dziekujemy!" << endl;
                    break;
                }
                case'2':
                {
                    Lody*l3 = new BitaSmietana(new Smietankowe(new Truskawkowe(new Truskawkowe(new Wafelek()))));
                    cout<<"\nWybrales puchar z dwoma galkami lodow truskawkowych i jedna smietankowa z bita smietana:"<<endl;
                    cout<<l3->napis()<<"\nDo zaplaty: "<<l3->cena()<< " zl. Dziekujemy!" << endl;
                    break;
                }
                case'3':
                {
                    Lody*l4 = new BitaSmietana(new Smietankowe(new Czekoladowe(new Czekoladowe(new Wafelek()))));
                    cout<<"\nWybrales puchar z dwoma galkami lodow czekoladowych i jedna smietankowa z bita smietana:"<<endl;
                    cout<<l4->napis()<<"\nDo zaplaty: "<<l4->cena()<< " zl. Dziekujemy!" << endl;
                    break;
                }
            }
            break;
        }
    }

    return 0;
}
