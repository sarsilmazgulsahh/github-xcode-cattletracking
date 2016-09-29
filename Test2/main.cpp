#include <iostream>
#include <string>
#include <vector>

using namespace std;


class MilkCattle;
class BeefCattle;
class Carbohydrate;
class Protein;

class Carbohydrate {
public:
    virtual void Print()=0;
};

// A 'ConcreteProduct A1' class

class Wheat : public  Carbohydrate{
public:
    Wheat() {
        cout << "Carbohydrate is chosen as Wheat " << endl;
    }
    void Print() {cout<<"I am a Carbohydrate";}
};

// A 'ConcreteProduct A2' class
class Corn : public  Carbohydrate{
    
public:
    Corn() {
        cout << "Carbohydrate is chosen as Corn " << endl;
    }
    void Print() {
        
        cout << "I am a Carbohydrate" << endl;
    }
};

// An 'Abstract Product B' class
class Protein {
public:
    virtual void Print2() = 0;
    
};
// A 'ConcreteProduct B1' class
class Canola : public  Protein{
    
public:
    Canola() {
        cout << "Protein is chosen as Canola" << endl;
    }
    void Print2() {
        cout << "I am a protein " << endl;
    }
};


// A 'ConcreteProduct B2' class
class Soybean : public  Protein{
public:
    Soybean(){
        cout << "Soybean is chosen as Protein." << endl;
    }
    void Print2() {
        cout << "I am a protein." << endl;
    }
};


class Visitor {
public:
    bool autumn = true;
    virtual ~Visitor(){};
    virtual void Visit() = 0;
protected:
    Visitor(){};
};
class VetPhysician : public Visitor {
public:
    string _name;
    VetPhysician(string name){_name=name;}
    void Visit(){
        cout<<"Cattles Visited and Vaccined"<<endl;
    };
};

class MinistryofFAL : public Visitor {
public:
    string _name;
    MinistryofFAL(string name){_name=name;}
    
    void Visit(){
        cout<<"Cattles Visited and Tags checked"<<endl;
    };
    
};

class Farmer;

class Cattle
{
public:
    
    static Cattle* getInstance();
    static bool exists();
    virtual int getLocation(){ return 0; };
    virtual void setLocation(int _in){};
    virtual void Attach (Farmer* farmer);
    virtual void Notify();
    virtual void Accept() = 0;
    static Carbohydrate* createCarbohydrate() ;
    static Protein* CreateProtein();
    
protected:
    Cattle(int);
    virtual ~Cattle(){};
    static Cattle* Instance;
    vector<Farmer*> farmers;
private:
    int location_val;
};

Cattle* Cattle::Instance = 0;

Cattle::Cattle(int _location): location_val(_location){}

void Cattle::Attach(Farmer* farmer) {
    farmers.push_back(farmer);
}

void Cattle::Notify() {
    cout<<"Notified"<<endl;
}
bool Cattle::exists(){
    return (Instance != NULL);
}

Cattle* Cattle::getInstance()
{
    if(Instance == 0) std::cout << "Class has not been created" << std::endl;
    
    return Instance;
}

class MilkCattle : public Cattle
{
public:
    static void create(int);
    void setLocation(int _in){ location = _in; Notify();}
    int getLocation(){ return location;}
    void Accept(){cout<<"Accepted"<<endl; }
    Carbohydrate* createCarbohydrate () {
        return new Corn();
    }
    Protein* createProtein() {
        return new Soybean();
    }
    
protected:
    MilkCattle(int);
    virtual ~MilkCattle() {};
private:
    int location;
    
};

MilkCattle::MilkCattle(int _location): Cattle(_location){
    location =_location;
   }

void MilkCattle::create(int cattle_location){
    if(Instance)
        cout << "Recreation" << endl;
    else
        Instance = new MilkCattle(cattle_location);
    }

class Farmers {
public:
    virtual ~Farmers(){};
    virtual void Update() = 0;
};

class Farmer:public  Farmers {
    
private:
    string farmer_name;
    
public:
    Farmer(string n):farmer_name(n){};
    void Update(){
        cout<<"There is an update in function"<<endl;
    }
    
};

class BeefCattle : public Cattle {
public:
    static void create(int);
    
    void setLocation(int _in){ location = _in; Notify();}
    int getLocation(){ return location;}
    void Accept(){cout<<"Accepted"<<endl;}
    Carbohydrate* createCarbohydrate () {
        return new Wheat();
    }
    Protein* createProtein() {
        return new Canola();
    }
protected:
    BeefCattle(int);
    virtual ~BeefCattle() {};
    
private:
    int location;
    
};

BeefCattle::BeefCattle(int _location): Cattle(_location){
    location =_location;
}

void BeefCattle::create(int cattle_location)
    {
    if(Instance)
        cout << "Recreation of object" << endl;
    else
        Instance = new BeefCattle(cattle_location);
    }
class ZigbeeSignals {
public:
    virtual void usingZigbeSignals()= 0;
};


class BluetoothSignals {
public:
    
    void Bluetoothconverter() {
        string device = "Bluetooth";
        cout << "Converting Zigbee to Bluetooth"<<endl;
        cout <<"The new device is : "<< device<< endl;
        
    }
};



class ConnectorAdapter : public ZigbeeSignals, private BluetoothSignals{
public:
    void usingZigbeSignals() {
        
        Bluetoothconverter();
        
    }
};


int main()
{
    Farmer *farmer = new Farmer("Tulin");
    farmer->Update();
    MilkCattle::create(3);
    cout << MilkCattle::getInstance()->getLocation() << endl;
    MilkCattle::getInstance()->setLocation(5);
    cout << MilkCattle::getInstance()->getLocation() << endl;
    farmer->Update();
    cout << BeefCattle::getInstance()->getLocation() << endl;
    BeefCattle::getInstance()->setLocation(8);
    cout << BeefCattle::getInstance()->getLocation() << endl;
    VetPhysician *vet = new VetPhysician("George");
    vet->Visit();
    MinistryofFAL *mstry = new MinistryofFAL("John");
    mstry->Visit();
    ZigbeeSignals *signals = new ConnectorAdapter();
    signals->usingZigbeSignals();
    
    return 0;
 
}



