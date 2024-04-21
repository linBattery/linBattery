#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

class item{
    private:
        string name;
        int cost;
        string item_function;
        int item_sum;
    public:
        void setname(string name){
            this->name=name;
        }
        string showname(){
            return name;
        }
        void setcost(int cost){
            this->cost=cost;
        }
        int showcost(){
            return cost;
        }
        void setfunction(string item_function){
            this->item_function=item_function;
        }
        string show_function(){
            return item_function;
        }
        void setitem_sum(int itemsum){
            this->item_sum=itemsum;
        }
        int show_item_sum(){
            return item_sum;
        }
};

class evolving_stone:public item{
    public:
        evolving_stone(string name="evolving_stone",int cost=120,string item_function=" (evolving status+1) (Both your attack and defence will be twice as strong as the original)"){
            setname(name);
            setcost(cost);
            setfunction(item_function);
        }
        void enhancement(int &attack,int &defence){
            attack*=2;
            defence*=2;
        }
};

class training_book:public item{
    public:
        training_book(string name="training_book",int cost=10,string item_function=" (Attack+20)"){
            setname(name);
            setcost(cost);
            setfunction(item_function);
        }
        void enhancement(int &attack){
            attack+=20;
        }
};

class dumbbell:public item{
    public:
        dumbbell(string name="dumbbell",int cost=10,string item_function=" (Attack+10, Defence+10)"){
            setname(name);
            setcost(cost);
            setfunction(item_function);
        }
        void enhancement(int &attack,int&defence){
            attack+=10;
            defence+=10;
        }
};

class superbadge:public item{
    public:
        superbadge(string name="superbadge",int cost=20,string item_function=" (HP limit+100)"){
            setname(name);
            setcost(cost);
            setfunction(item_function);
        }
        void enhancement(int &HP_limit){
            HP_limit+=100;
        }
};

class pokemon_protein:public item{
    public:
        pokemon_protein(string name="pokemon_protein",int cost=30,string item_function=" (Defence+10, HP limit+50)"){
            setname(name);
            setcost(cost);
            setfunction(item_function);
        }
        void enhancement(int &defence,int &HP_limit){
            defence+=10;
            HP_limit+=50;
        }
};

class pokemon_fruit:public item{
    public:
        pokemon_fruit(string name="pokemon_fruit",int cost=30,string item_function=" (Detoxify)"){
            setname(name);
            setcost(cost);
            setfunction(item_function);
        }
        void purify(int &poison){
            poison=0;
        }
};

class pork:public item{
    public:
        pork(string name="pork",int cost=5,string item_function=" (Food+20)"){
            setname(name);
            setcost(cost);
            setfunction(item_function);
        }
        void eat(int &food){
            food+=20;
        }
};

class egg:public item{
    public:
        egg(string name="egg",int cost=5,string item_function=" (Food+10, Water+10)"){
            setname(name);
            setcost(cost);
            setfunction(item_function);
        }
        void eat(int &food,int &water){
            food+=10;
            water+=10;
        }
};

class birthday_cake:public item{
    public:
        birthday_cake(string name="birthday_cake",int cost=12,string item_function=" (Food+50,water-20)"){
            setname(name);
            setcost(cost);
            setfunction(item_function);
        }
        void eat(int &food,int &water){
            food+=50;
            water-=20;
        }
};

class weapon{
    private:
        string name;
        string showadvantage;
    public:
        void setname(string name){
            this->name=name;
        }
        string showname(){
            return name;
        }
        virtual void advantage(int &change){
            change+=0;
        }
        void setadvantage(string advantage){
            this->showadvantage=advantage;
        }
        string _showadvantage(){
            return showadvantage;
        }
};

class knife:public weapon{
    public:
        knife(string name="knife",string showadvantage="(attack+50)"){
            setname(name);
            setadvantage(showadvantage);
        }
        void advantage(int &change)override{
            change+=50;
        }
};

class shield:public weapon{
    public:
        shield(string name="shield",string showadvantage="(defence+50)"){
            setname(name);
            setadvantage(showadvantage);
        }
        void advantage(int &change)override{
            change+=50;
        }
};

class armor:public weapon{
    public:
        armor(string name="armor",string showadvantage="(HP+120)"){
            setname(name);
            setadvantage(showadvantage);
        }
        void advantage(int &change)override{
            change+=120;
        }
};

class powerful_knife:public weapon{
    public:
        powerful_knife(string name="powerful_knife",string showadvantage="(attack+150)"){
            setname(name);
            setadvantage(showadvantage);
        }
        void advantage(int &change)override{
            change+=150;
        }
};

class powerful_shield:public weapon{
    public:
        powerful_shield(string name="powerful_shield",string showadvantage="(defence+120)"){
            setname(name);
            setadvantage(showadvantage);
        }
        void advantage(int &change)override{
            change+=120;
        }
};

class super_armor:public weapon{
    public:
        super_armor(string name="super_armor",string showadvantage="(HP+300)"){
            setname(name);
            setadvantage(showadvantage);
        }
        void advantage(int &change)override{
            change+=300;
        }
};


