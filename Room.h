#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

class room{
    private:
        int roomcode;
        string roomname;
        int food_consume;
        int water_consume;
    public:
        void setroomcode(int roomcode){
            this->roomcode=roomcode;
        }
        int showroomcode(){
            return roomcode;
        }
        void setroomname(string roomname){
            this->roomname=roomname;
        }
        string showroomname(){
            return roomname;
        }
        void setfood_consume(int food){
            this->food_consume=food;
        }
        int showfood_consume(){
            return this->food_consume;
        }

        void setwater_consume(int water){
            this->water_consume=water;
        }
        int showwater_consume(){
            return this->water_consume;
        }
        virtual void eat(int &food){
            food-=showfood_consume();
        }
        virtual void drink(int &water){
            water-=showwater_consume();
        }
        virtual void food_HP(int &HP){
            HP-=showfood_consume();
        }
        virtual void water_HP(int &HP){
            HP-=showwater_consume();
        }
};

class nullroom:public room{
    public:
        nullroom(int roomcode=0,string roomname="nullroom",int food_consume=4,int water_consume=4){
            setroomcode(roomcode);
            setroomname(roomname);
            setfood_consume(food_consume);
            setwater_consume(water_consume);
        }
        virtual void eat(int &food)override{
            food-=showfood_consume();
        }
        virtual void drink(int &water)override{
            water-=showwater_consume();
        }
        virtual void food_HP(int &HP)override{
            HP-=showfood_consume();
        }
        virtual void water_HP(int &HP)override{
            HP-=showwater_consume();
        }
};

class Volcano:public room{
    public:
        Volcano(int roomcode=1,string roomname="Volcano",int food_consume=6,int water_consume=6){
            setroomcode(roomcode);
            setroomname(roomname);
            setfood_consume(food_consume);
            setwater_consume(water_consume);
        }
        virtual void eat(int &food)override{
            food-=showfood_consume();
        }
        virtual void drink(int &water)override{
            water-=showwater_consume();
        }
        virtual void food_HP(int &HP)override{
            HP-=showfood_consume();
        }
        virtual void water_HP(int &HP)override{
            HP-=showwater_consume();
        }

};
class Forest:public room{
    public:
        Forest(int roomcode=2,string roomname="Forest",int food_consume=8,int water_consume=2){
            setroomcode(roomcode);
            setroomname(roomname);
            setfood_consume(food_consume);
            setwater_consume(water_consume);
        }
        virtual void eat(int &food)override{
            food-=showfood_consume();
        }
        virtual void drink(int &water)override{
            water-=showwater_consume();
        }
        virtual void food_HP(int &HP)override{
            HP-=showfood_consume();
        }
        virtual void water_HP(int &HP)override{
            HP-=showwater_consume();
        }

};

class Desert:public room{
    public:
        Desert(int roomcode=3,string roomname="Desert",int food_consume=4,int water_consume=10){
            setroomcode(roomcode);
            setroomname(roomname);
            setfood_consume(food_consume);
            setwater_consume(water_consume);
        }
        virtual void eat(int &food)override{
            food-=showfood_consume();
        }
        virtual void drink(int &water)override{
            water-=showwater_consume();
        }
        virtual void food_HP(int &HP)override{
            HP-=showfood_consume();
        }
        virtual void water_HP(int &HP)override{
            HP-=showwater_consume();
        }
};

class Swamp:public room{
    public:
        Swamp(int roomcode=3,string roomname="Swamp",int food_consume=2,int water_consume=2){
            setroomcode(roomcode);
            setroomname(roomname);
            setfood_consume(food_consume);
            setwater_consume(water_consume);
        }
        virtual void eat(int &food)override{
            food-=showfood_consume();
        }
        virtual void drink(int &water)override{
            water-=showwater_consume();
        }
        virtual void food_HP(int &HP)override{
            HP-=showfood_consume();
        }
        virtual void water_HP(int &HP)override{
            HP-=showwater_consume();
        }
};


room checkposition(int p1,int p2){
    nullroom nullroom;
    Volcano volcano;
    Forest forest;
    Desert desert;
    Swamp swamp;
    if(p1==0||p2==0){
        return nullroom;
    }
    else if(p1>0&&p2>0){
        return volcano;
    }
    else if(p1<0&&p2>0){
        return forest;
    }
    else if(p1<0&&p2<0){
        return desert;
    }
    else if(p1>0&&p2<0){
        return swamp;
    }
}


